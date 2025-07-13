# FlyingComputer

## Architecture
<img src="https://raw.githubusercontent.com/therooftopprinz/FlyingComputer/master/Architecture/swcomponents.png" alt="Architecture" width="1080"/>

## Software Components
- [propertytree](https://github.com/therooftopprinz/propertytree/)
- HAL : HAL Interface facing userspace modules (UMOD) to access the connected devices.
  - HAL-WiringPi - Implements interface using WiringPi.
  - HAL-WiringOP - Implements interface using WiringOP.
  - HAL-Arduino - Implements interface using Arduino.
  - HAL-Client - Implements interface to access simulated devices
  - HAL-Server - Implements the simulated devices
    - SIM-ICM42688P
      - Interface : I2C,SPI
    - SIM-GPIO
      - Interface : GPIO
    - SIM-MS4525DO
      - Interface : I2C,SPI
    - SIM-NEO6M
      - Interface : UART
    - SIM-BMP280
      - Interface : I2C,SPI
    - SIM-PCA9685
      - Interface : I2C
    - SIM-HMC5883L
      - Interface : I2C
    - SIM-DSERVO
      - Interface : I2C
    - SIM-DESC
      - Interface : I2C
    - SIM-VL53L0X
      - Interface : I2C
- UMOD : Userspace Modules
  - UMOD-IMU : Handles IMU devices
    - Drivers:
      - DRV-ICMx
      - DRV-MPUx
  - UMOD-NAV : Handles NAV devices
    - Drivers
      -DRV-NEOx
      -DRV-BMPx
      -DRV-VL53L0x
  - UMOD-SRVO : Handles Servos devices
    - Drivers:
      - DRV-GPIO
      - DRV-DSRVO
  - UMOD-ENG : Handles Engine/ESC devices
    - Drivers:
      - DRV-GPIO
      - DRV-DESC
  - UMOD-ASPD : Handles Airspeed and AOA devices
    - Drivers:
      - DRV-MSx
      - DRV-GPIO
  - UMOD-VID : Handles Video/Audio devices

## HAL
HAL is the interface the drivers uses in UMOD. It provides access to device through system implementations (spidev/smbus/esp-idf/arduino).

<img src="https://raw.githubusercontent.com/therooftopprinz/FlyingComputer/master/Architecture/HAL.png" alt="Architecture" width="1080"/>

## Miletones

- [x] PropertyTree Value
- [ ] PropertyTree Node
- [ ] HAL Interface
- [ ] SIM-ICM42688P
- [ ] DRV-ICM42688P
- [ ] UMOD-IMU
- [ ] MSFS2020 SimConnect IMU
- [ ] APP-ORIPOS and APP-IOMIXER