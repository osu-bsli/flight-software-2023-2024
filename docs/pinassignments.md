# Pin Assignments


## Peripheral assignments


### gps (MAX-M8C-0)
- I2C2 + a gpio input as a data ready interrupt (pg. 14)

### accelerometer (ADXL375BCCZ)
- I2C1 + a gpio input as a data ready interrupt

### imu (BMI323)
- I2C1 + a gpio input as a data ready interrupt

### barometer (MS5607) (indirectly but still over I2C)
- I2C1

### magnetometer (BM1422AGMV)
- I2C2 + a gpio input as a data ready interrupt

### sd card (over SPI)
- USART6 + SPI4 + the SPI4_NSS pin (we may configure it as a gpio output instead, apparently it may be more reliable)

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
- PB5 = GPIO_IN_ADXL375_DATAREADY
- PB3 = GPIO_IN_BMI323_DATAREADY

### I2C2 (other sensors)
- PF0 = I2C2_SDA
- PF1 = I2C2_SCL
- PF2 = GPIO_IN_MAXM8C_DATAREADY
- PF3 = GPIO_IN_BMI1422AGMV_DATAREADY

### SD card
- PE2 = SPI4_SCK
- PE4 = SPI4_NSS (or just a gpio output, but shouldn't make any difference)
- PE5 = SPI4_MISO
- PE6 = SPI4_MOSI
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

