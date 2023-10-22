# TODO

## Example tasks
- [ ] this task isn't finished, and isn't assigned to anyone
  - [ ] you can have tasks inside tasks
- [ ] (joe) this task is assigned to joe
- [x] (joe) this task is finished

## Overall

## ADXL375 driver (accelerometer)
- [x] (dersu) (by 2023-10-22) use interrupts instead of blocking functions
- [ ] fix bitshift of i2c address
- [ ] remove i2c address check (the DEVID register is fixed and means something different)

## MS5607 driver (barometer)
- [ ] implement the code
  - [ ] sketch out each function required
  - [ ] brainstorm constants to define
  - [ ] make header and c files
  - [ ] figure out how to initialize sensor
  - [ ] figure out how to read data from sensor

## MAX-M8C-0 (gps) (https://www.digikey.com/en/products/detail/u-blox/MAX-M8C-0/6150635)

## On-board storage
- [ ] research SD card reader interface with STM32
  - SD Card STM32 interfacing tutorial: https://embetronicx.com/tutorials/microcontrollers/stm32/stm32-sd-card-interfacing-with-example/#:~:text=The%20SD%20Card%20is%20connected%20to%20the%20STM32,you%20give%20lesser%20than%20that%2C%20it%20won%E2%80%99t%20work.
  - SPI Overview: https://embetronicx.com/tutorials/tech_devices/spi-serial-peripheral-interface-protocol-basics/
  - https://01001000.xyz/2020-08-09-Tutorial-STM32CubeIDE-SD-card/
- [ ] reseach flash drive interface with STM32
