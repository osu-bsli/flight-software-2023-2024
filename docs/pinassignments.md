## gps (MAX-M8C-0)
- which pins do we need?

## accelerometer (ADXL375BCCZ)
- I2C1
  - 


## imu (BMI323)


## barometer (MS5607) (indirectly but still over I2C thing)
- I2C1


## sd card (over SPI)
- SPI4
  - SPI4_MISO
  - SPI4_MOSI
  - GPIO_Output or SPI4_NSS
  - SPI4_SCK
- USART1
  - USART1_RX
  - USART1_TX
