#include "main.h"
#include "ESPLib.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

I2C_HandleTypeDef hi2c1;
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

#define BME280_ADDR       (0x76 << 1)
#define BME280_ID_REG     0xD0
#define BME280_ID         0x60
#define BME280_RESET_REG  0xE0
#define BME280_CTRL_HUM   0xF2
#define BME280_CONFIG     0xF5
#define BME280_CTRL_MEAS  0xF4
#define BME280_DATA_REG   0xF7

typedef struct
{
    uint16_t dig_T1;
    int16_t dig_T2;
    int16_t dig_T3;

    uint16_t dig_P1;
    int16_t dig_P2;
    int16_t dig_P3;
    int16_t dig_P4;
    int16_t dig_P5;
    int16_t dig_P6;
    int16_t dig_P7;
    int16_t dig_P8;
    int16_t dig_P9;

    uint8_t dig_H1;
    int16_t dig_H2;
    uint8_t dig_H3;
    int16_t dig_H4;
    int16_t dig_H5;
    int8_t dig_H6;

} BME280_Calibration;

BME280_Calibration calib;

int32_t t_fine;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART2_UART_Init(void);
void Error_Handler(void);

static uint8_t BME280_Init(void);
static uint8_t BME280_ReadCalibration(void);
static uint8_t BME280_ReadData(float *, float *, float *);

static float BME280_CompensateTemperature(int32_t);
static float BME280_CompensatePressure(int32_t);
static float BME280_CompensateHumidity(int32_t);

static uint16_t ReadU16(uint8_t *, uint8_t);
static int16_t ReadS16(uint8_t *, uint8_t);
static int16_t SignExtend12(uint16_t);

void Terminal_Print(const char *message)
{
    HAL_UART_Transmit(&huart2,
                      (uint8_t *)message,
                      strlen(message),
                      HAL_MAX_DELAY);
}

void Terminal_PrintFixed(const char *label,
                         int32_t value,
                         const char *unit)
{
    char msg[100];
    uint32_t magnitude;

    if (value < 0)
    {
        magnitude = (uint32_t)(-value);

        sprintf(msg, "%s: -%lu.%02lu %s\r\n",
                label,
                (unsigned long)(magnitude / 100),
                (unsigned long)(magnitude % 100),
                unit);
    }
    else
    {
        magnitude = (uint32_t)value;

        sprintf(msg, "%s: %lu.%02lu %s\r\n",
                label,
                (unsigned long)(magnitude / 100),
                (unsigned long)(magnitude % 100),
                unit);
    }

    Terminal_Print(msg);
}

static uint16_t ReadU16(uint8_t *data, uint8_t index)
{
    return (uint16_t)((uint16_t)data[index] |
                      ((uint16_t)data[index + 1] << 8));
}

static int16_t ReadS16(uint8_t *data, uint8_t index)
{
    return (int16_t)ReadU16(data, index);
}

static int16_t SignExtend12(uint16_t value)
{
    if (value & 0x0800)
    {
        value |= 0xF000;
    }

    return (int16_t)value;
}

static uint8_t BME280_ReadCalibration(void)
{
    uint8_t data1[26];
    uint8_t data2[7];

    if (HAL_I2C_Mem_Read(&hi2c1, BME280_ADDR,
                         0x88, I2C_MEMADD_SIZE_8BIT,
                         data1, 26, 1000) != HAL_OK)
    {
        return 0;
    }

    if (HAL_I2C_Mem_Read(&hi2c1, BME280_ADDR,
                         0xE1, I2C_MEMADD_SIZE_8BIT,
                         data2, 7, 1000) != HAL_OK)
    {
        return 0;
    }

    calib.dig_T1 = ReadU16(data1, 0);
    calib.dig_T2 = ReadS16(data1, 2);
    calib.dig_T3 = ReadS16(data1, 4);

    calib.dig_P1 = ReadU16(data1, 6);
    calib.dig_P2 = ReadS16(data1, 8);
    calib.dig_P3 = ReadS16(data1, 10);
    calib.dig_P4 = ReadS16(data1, 12);
    calib.dig_P5 = ReadS16(data1, 14);
    calib.dig_P6 = ReadS16(data1, 16);
    calib.dig_P7 = ReadS16(data1, 18);
    calib.dig_P8 = ReadS16(data1, 20);
    calib.dig_P9 = ReadS16(data1, 22);

    calib.dig_H1 = data1[25];

    calib.dig_H2 = ReadS16(data2, 0);
    calib.dig_H3 = data2[2];

    calib.dig_H4 = SignExtend12(
        ((uint16_t)data2[3] << 4) | (data2[4] & 0x0F)
    );

    calib.dig_H5 = SignExtend12(
        ((uint16_t)data2[5] << 4) | (data2[4] >> 4)
    );

    calib.dig_H6 = (int8_t)data2[6];

    if (calib.dig_P1 == 0)
    {
        return 0;
    }

    return 1;
}

static uint8_t BME280_Init(void)
{
    uint8_t id;
    uint8_t value;

    if (HAL_I2C_Mem_Read(&hi2c1, BME280_ADDR,
                         BME280_ID_REG, I2C_MEMADD_SIZE_8BIT,
                         &id, 1, 1000) != HAL_OK)
    {
        return 0;
    }

    if (id != BME280_ID)
    {
        return 0;
    }

    value = 0xB6;

    if (HAL_I2C_Mem_Write(&hi2c1, BME280_ADDR,
                          BME280_RESET_REG, I2C_MEMADD_SIZE_8BIT,
                          &value, 1, 1000) != HAL_OK)
    {
        return 0;
    }

    HAL_Delay(10);

    if (!BME280_ReadCalibration())
    {
        return 0;
    }

    value = 0x01;

    if (HAL_I2C_Mem_Write(&hi2c1, BME280_ADDR,
                          BME280_CTRL_HUM, I2C_MEMADD_SIZE_8BIT,
                          &value, 1, 1000) != HAL_OK)
    {
        return 0;
    }

    value = 0xA0;

    if (HAL_I2C_Mem_Write(&hi2c1, BME280_ADDR,
                          BME280_CONFIG, I2C_MEMADD_SIZE_8BIT,
                          &value, 1, 1000) != HAL_OK)
    {
        return 0;
    }

    value = 0x27;

    if (HAL_I2C_Mem_Write(&hi2c1, BME280_ADDR,
                          BME280_CTRL_MEAS, I2C_MEMADD_SIZE_8BIT,
                          &value, 1, 1000) != HAL_OK)
    {
        return 0;
    }

    return 1;
}

static float BME280_CompensateTemperature(int32_t adc_T)
{
    float var1;
    float var2;

    var1 = (((float)adc_T / 16384.0f) -
            ((float)calib.dig_T1 / 1024.0f)) *
           (float)calib.dig_T2;

    var2 = ((float)adc_T / 131072.0f -
            (float)calib.dig_T1 / 8192.0f);

    var2 = var2 * var2 * (float)calib.dig_T3;

    t_fine = (int32_t)(var1 + var2);

    return (var1 + var2) / 5120.0f;
}

static float BME280_CompensatePressure(int32_t adc_P)
{
    float var1;
    float var2;
    float pressure;

    var1 = ((float)t_fine / 2.0f) - 64000.0f;

    var2 = var1 * var1 *
           (float)calib.dig_P6 / 32768.0f;

    var2 = var2 + var1 *
           (float)calib.dig_P5 * 2.0f;

    var2 = (var2 / 4.0f) +
           ((float)calib.dig_P4 * 65536.0f);

    var1 = ((float)calib.dig_P3 * var1 * var1 /
            524288.0f +
            (float)calib.dig_P2 * var1) / 524288.0f;

    var1 = (1.0f + var1 / 32768.0f) *
           (float)calib.dig_P1;

    if (var1 == 0.0f)
    {
        return 0.0f;
    }

    pressure = 1048576.0f - (float)adc_P;

    pressure = (pressure - var2 / 4096.0f) *
               6250.0f / var1;

    var1 = (float)calib.dig_P9 *
           pressure * pressure / 2147483648.0f;

    var2 = pressure *
           (float)calib.dig_P8 / 32768.0f;

    pressure = pressure +
               (var1 + var2 + (float)calib.dig_P7) / 16.0f;

    return pressure;
}

static float BME280_CompensateHumidity(int32_t adc_H)
{
    float humidity;

    humidity = (float)t_fine - 76800.0f;

    humidity = ((float)adc_H -
                ((float)calib.dig_H4 * 64.0f +
                ((float)calib.dig_H5 / 16384.0f) * humidity))
                *
                ((float)calib.dig_H2 / 65536.0f *
                (1.0f +
                ((float)calib.dig_H6 / 67108864.0f) *
                humidity *
                (1.0f +
                ((float)calib.dig_H3 / 67108864.0f) *
                humidity)));

    humidity = humidity *
               (1.0f -
               ((float)calib.dig_H1 * humidity / 524288.0f));

    if (humidity > 100.0f)
    {
        humidity = 100.0f;
    }

    if (humidity < 0.0f)
    {
        humidity = 0.0f;
    }

    return humidity;
}

static uint8_t BME280_ReadData(float *temperature,
                               float *pressure,
                               float *humidity)
{
    uint8_t data[8];

    int32_t adc_P;
    int32_t adc_T;
    int32_t adc_H;

    if (HAL_I2C_Mem_Read(&hi2c1, BME280_ADDR,
                         BME280_DATA_REG,
                         I2C_MEMADD_SIZE_8BIT,
                         data, 8, 1000) != HAL_OK)
    {
        return 0;
    }

    adc_P = ((int32_t)data[0] << 12) |
            ((int32_t)data[1] << 4) |
            ((int32_t)data[2] >> 4);

    adc_T = ((int32_t)data[3] << 12) |
            ((int32_t)data[4] << 4) |
            ((int32_t)data[5] >> 4);

    adc_H = ((int32_t)data[6] << 8) |
            (int32_t)data[7];

    *temperature = BME280_CompensateTemperature(adc_T);

    *pressure = BME280_CompensatePressure(adc_P);

    *humidity = BME280_CompensateHumidity(adc_H);

    return 1;
}

static void MX_USART1_UART_Init(void)
{
    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;

    if (HAL_UART_Init(&huart1) != HAL_OK)
    {
        Error_Handler();
    }
}

static void MQTT_Init(void)
{
    MQTT_InitTypeDef_t mqttSetting;

    if (ESP8266_Init(StationMode, huart1) != funcOk)
    {
        Terminal_Print("ESP8266 INITIALIZATION FAILED!\r\n");
        Error_Handler();
    }

    if (ESP8266_wifiConnect("SNUC", "snu12345") != funcOk)
    {
        Terminal_Print("WIFI CONNECTION FAILED!\r\n");
        Error_Handler();
    }

    Terminal_Print("WIFI CONNECTED!\r\n");

    if (ESP8266_portConnect("TCP", "broker.emqx.io", "1883") != funcOk)
    {
        Terminal_Print("MQTT TCP CONNECTION FAILED!\r\n");
        Error_Handler();
    }

    mqttSetting.keepAlive = 60;
    mqttSetting.connectFlag = CleanSession;
    mqttSetting.clientID = "STM32_BME280_25011102050";
    mqttSetting.username = "";
    mqttSetting.password = "";

    MQTT_connectBroker(&mqttSetting);

    Terminal_Print("MQTT BROKER CONNECTION REQUEST SENT!\r\n");
}

int main(void)
{
    float temperature;
    float pressure;
    float humidity;

    char mqttMessage[100];

    HAL_Init();

    SystemClock_Config();

    MX_GPIO_Init();
    MX_I2C1_Init();
    MX_USART1_UART_Init();
    MX_USART2_UART_Init();

    Terminal_Print("\r\n================================\r\n");
    Terminal_Print("    BME280 SENSOR + MQTT TEST\r\n");
    Terminal_Print("================================\r\n");

    if (!BME280_Init())
    {
        Terminal_Print("BME280 INITIALIZATION FAILED!\r\n");
        Terminal_Print("Check sensor and I2C connection.\r\n");

        while (1)
        {
            HAL_Delay(1000);
        }
    }

    Terminal_Print("BME280 INITIALIZED SUCCESSFULLY!\r\n");
    Terminal_Print("Sensor ID: 0x60\r\n");

    MQTT_Init();

    HAL_Delay(1500);

    while (1)
    {
        if (BME280_ReadData(&temperature, &pressure, &humidity))
        {
            Terminal_Print("\r\n---------- SENSOR DATA ----------\r\n");

            Terminal_PrintFixed(
                "Temperature",
                (int32_t)(temperature * 100.0f),
                "C"
            );

            Terminal_PrintFixed(
                "Pressure",
                (int32_t)(pressure / 100.0f),
                "hPa"
            );

            Terminal_PrintFixed(
                "Humidity",
                (int32_t)(humidity * 100.0f),
                "%"
            );

            snprintf(mqttMessage, sizeof(mqttMessage),
                     "{\"temperature\":%.2f,\"pressure\":%.2f,\"humidity\":%.2f}",
                     (double)temperature,
                     (double)(pressure / 100.0f),
                     (double)humidity);

            MQTT_publishTopic("stm32/ahmed/data", mqttMessage, QoS0);

            Terminal_Print("MQTT PUBLISH CALLED: ");
            Terminal_Print(mqttMessage);
            Terminal_Print("\r\n");
        }
        else
        {
            Terminal_Print("SENSOR READ ERROR!\r\n");
        }

        HAL_Delay(2000);
    }
}

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    __HAL_RCC_PWR_CLK_ENABLE();

    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue =
        RCC_HSICALIBRATION_DEFAULT;

    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLM = 8;
    RCC_OscInitStruct.PLL.PLLN = 84;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 4;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK |
                                  RCC_CLOCKTYPE_SYSCLK |
                                  RCC_CLOCKTYPE_PCLK1 |
                                  RCC_CLOCKTYPE_PCLK2;

    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct,
                            FLASH_LATENCY_2) != HAL_OK)
    {
        Error_Handler();
    }
}

static void MX_I2C1_Init(void)
{
    hi2c1.Instance = I2C1;
    hi2c1.Init.ClockSpeed = 100000;
    hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
    hi2c1.Init.OwnAddress1 = 0;
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c1.Init.OwnAddress2 = 0;
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

    if (HAL_I2C_Init(&hi2c1) != HAL_OK)
    {
        Error_Handler();
    }
}

static void MX_USART2_UART_Init(void)
{
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;

    if (HAL_UART_Init(&huart2) != HAL_OK)
    {
        Error_Handler();
    }
}

static void MX_GPIO_Init(void)
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
}

void Error_Handler(void)
{
    __disable_irq();

    while (1)
    {
    }
}
