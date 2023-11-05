# Pin Assignments


## Peripheral assignments


### gps (MAX-M8C-0)
- [1: datasheet] (https://content.u-blox.com/sites/default/files/MAX-8_DataSheet_%28UBX-16000093%29.pdf)
- [2: datasheet] (https://content.u-blox.com/sites/default/files/products/documents/u-blox8-M8_ReceiverDescrProtSpec_UBX-13003221.pdf)
- DDC Address: 0x42 (default setting, refer to pg. 37 of [2])
- I2C2 + a gpio input as a data ready interrupt (pg. 14)

### accelerometer (ADXL375BCCZ)
- 7-bit I2C Address: 0x1D (pg. 18)
  - Read Address: 0x3B
  - Write Address: 0x3A
- I2C1 + a gpio input as a data ready interrupt

### imu (BMI323)
- SPI1 + a gpio input as a data ready interrupt

### barometer (MS5607) (indirectly but still over I2C)
- [datasheet](https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Data+Sheet%7FMS5607-02BA03%7FB4%7Fpdf%7FEnglish%7FENG_DS_MS5607-02BA03_B4.pdf%7FMS560702BA03-50)
- I2C Address: 111011Cx (pg. 12) 
- I2C1

### magnetometer (BM1422AGMV)
- [datasheet](https://fscdn.rohm.com/en/products/databook/datasheet/ic/sensor/geomagnetic/bm1422agmv-e.pdf)
- I2C2 + a gpio input as a data ready interrupt

### sd card (over SPI)
- USART6 + SPI4 + the SPI4_NSS pin (we may configure it as a gpio output instead, apparently it may be more reliable)

### Inter-board communication
- FDCAN2

### Airbrakes
- driver pins:
  - (TBD)
- motor encoder pins:
  - I2C4


## Pin assignments


### I2C1 (flight-critical sensors)
- PB7 = I2C1_SDA
- PB6 = I2C1_SCL
- PB5 = GPIO_INTERRUPT_ADXL375_DATAREADY

### I2C2 (other sensors)
- PF0 = I2C2_SDA
- PF1 = I2C2_SCL
- PF2 = GPIO_INTERRUPT_MAXM8C_DATAREADY
- PF3 = GPIO_INTERRUPT_BMI1422AGMV_DATAREADY

### SPI1 (other sensors)
- PA5 = SPI1_SCK
- PA6 = SPI1_MISO
- PA7 = SPI1_MOSI
- PC4 = GPIO_INTERRUPT_BMI323_DATAREADY

### SD card
- PE2 = SPI4_SCK
- PE4 = SPI4_NSS (or just a gpio output, but shouldn't make any difference)
- PE5 = SPI4_MISO
- PE6 = SPI4_MOSI
- PC7 = USART6_RX
- PC6 = USART6_TX

### Airbrakes
- driver pins:
  - (TBD)
- motor encoder pins:
  - PF14 = I2C4_SCL
  - PF15 = I2C4_SDA

### Inter-board communication
- PB13 = FDCAN2_TX
- PB12 = FDCAN2_RX

### Debugging
- PA14 = DEBUG_JTCK-SWCLK
- PA13 = DEBUG_JTMS-SWDIO




