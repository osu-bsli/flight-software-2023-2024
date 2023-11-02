## gps (MAX-M8C-0)
- [datasheet] (https://content.u-blox.com/sites/default/files/MAX-8_DataSheet_%28UBX-16000093%29.pdf)
- [2: datasheet] (https://content.u-blox.com/sites/default/files/products/documents/u-blox8-M8_ReceiverDescrProtSpec_UBX-13003221.pdf)
- DDC Address: 0x42 (default setting, refer to pg. 37 of [2])
- which pins do we need?

## accelerometer (ADXL375BCCZ)
- I2C1
  - I2C1_SDA
  - I2C1_SCL
- 7-bit I2C Address: 0x1D (Page 18 of 32)
  - Read Address: 0x3B
  - Write Address: 0x3A
- GPIO_Input (data ready interrupt, either interrupt pin on the sensor can be used)


## imu (BMI323)
 I2C1
  - I2C1_SDA
  - I2C1_SCL

## barometer (MS5607) (indirectly but still over I2C)
- I2C Address: 111011Cx pg. 12 [datasheet](https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Data+Sheet%7FMS5607-02BA03%7FB4%7Fpdf%7FEnglish%7FENG_DS_MS5607-02BA03_B4.pdf%7FMS560702BA03-50)
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
