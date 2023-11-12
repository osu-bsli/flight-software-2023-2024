# Pin Assignments


## Peripheral assignments


### GPS (MAX-M8C-0)
- I2C2 + a gpio input as a data ready interrupt (pg. 14)

### Accelerometer (ADXL375BCCZ)
- I2C1 + a gpio input as a data ready interrupt

### IMU (BMI323)
- I2C1 + a gpio input as a data ready interrupt

### Barometer (MS5607) (indirectly but still over I2C)
- I2C1

### Magnetometer (BM1422AGMV)
- I2C2 + a gpio input as a data ready interrupt

## Motor thermometer (MCP9600)
- I2C2

### SD card (over SPI)
- USART6 + SDMMC1

### Inter-board communication
- UART8

### Airbrakes
- stepper motor driver:
  - 8 gpio outputs
- stepper motor encoder:
  - I2C4

### Ematch continuity testing
- ADC3 (3 pins in "single-ended" mode)

### External clock
- RCC (High Speed Clock (HSE) set to "Crystal/Ceramic Resonator")


## Pin assignments


### I2C1 (flight-critical sensors)
- PB7 = I2C1_SDA
- PB6 = I2C1_SCL
- PB5 = GPIO_EXTI5_ADXL375_DATAREADY
- PG15 = GPIO_EXTI15_BMI323_DATAREADY

### I2C2 (other sensors)
- PF0 = I2C2_SDA
- PF1 = I2C2_SCL
- PF2 = GPIO_EXTI2_MAXM8C_DATAREADY
- PF3 = GPIO_EXTI3_BMI1422AGMV_DATAREADY

### SD card
- PC8 = SDMMC1_D0
- PC9 = SDMMC1_D1
- PC10 = SDMMC1_D2
- PC11 = SDMMC1_D3
- PC12 = SDMMC1_CK
- PD2 = SDMMC_CMD
- PC7 = USART6_RX
- PC6 = USART6_TX

### Airbrakes
- stepper motor driver pins:
  - PI4 = GPIO_OUT_A4988_STEP
  - PI5 = GPIO_OUT_A4988_MS1
  - PI6 = GPIO_OUT_A4988_MS2
  - PI7 = GPIO_OUT_A4988_MS3
  - PI8 = GPIO_OUT_A4988_DIR
  - PC13 = GPIO_OUT_A4988_SLEEP
  - PC14-OSC32_IN = GPIO_OUT_A4988_RESET
  - PC15-OSC32_OUT = GPIO_OUT_A4988_ENABLE
- stepper motor encoder pins:
  - PF14 = I2C4_SCL
  - PF15 = I2C4_SDA

### Inter-board communication
- PE1 = UART8_TX
- PE0 = UART8_RX

### Debugging
- PA14 = DEBUG_JTCK-SWCLK
- PA13 = DEBUG_JTMS-SWDIO

### Ematch continuity testing
- PC3_C = ADC3_INP1
- PF9 = ADC3_INP2
- PF7 = ADC3_INP3

### External clock
- PH0-OSC_IN = RCC_OSC_IN
- PH1-OSC_OUT = RCC_OSC_OUT

