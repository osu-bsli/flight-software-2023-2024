## gps (MAX-M8C-0)
- which pins do we need?

## accelerometer (ADXL375BCCZ)
- I2C1
  - I2C1_SDA
  - I2C1_SCL
- GPIO_Input (data ready interrupt, either interrupt pin on the sensor can be used)


## imu (BMI323)
 I2C1
  - I2C1_SDA
  - I2C1_SCL
- GPIO_Input (data ready interrupt, either interrupt pin on the sensor can be used)

## barometer (MS5607) (indirectly but still over I2C)
- I2C1
  - I2C1_SDA
  - I2C1_SCL

## magnetometer (BM1422AGMV)
- [datasheet](https://fscdn.rohm.com/en/products/databook/datasheet/ic/sensor/geomagnetic/bm1422agmv-e.pdf)
- I2C1
  - I2C1_SDA
  - I2C1_SCL
- GPIO_Input (data ready interrupt)

## sd card (over SPI)
- SPI4
  - SPI4_MISO
  - SPI4_MOSI
  - GPIO_Output or SPI4_NSS
  - SPI4_SCK
- USART1
  - USART1_RX
  - USART1_TX
