# WisBlock Base GPIO Definitions

## Digital I/O Pins

| Pin Name | GPIO # | nRF52840 Port | Available Slots |
|----------|--------|---------------|-----------------|
| WB_IO1   | 17     | P0.17         | SLOT_A, SLOT_B  |
| WB_IO2   | 34     | P1.02         | SLOT_A, SLOT_B  |
| WB_IO3   | 21     | P0.21         | SLOT_C          |
| WB_IO4   | 4      | P0.04         | SLOT_C          |
| WB_IO5   | 9      | P0.09         | SLOT_D          |
| WB_IO6   | 10     | P0.10         | SLOT_D          |
| WB_SW1   | 33     | P1.01         | IO_SLOT         |

## Analog Input Pins

| Pin Name | GPIO # | nRF52840 Port | ADC Channel | Available Slots |
|----------|--------|---------------|-------------|-----------------|
| WB_A0    | 5      | P0.05         | AIN3        | IO_SLOT         |
| WB_A1    | 31     | P0.31         | AIN7        | IO_SLOT         |

## I²C Interface Pins

### I2C Bus 1
| Pin Name     | GPIO # | nRF52840 Port | Available Slots           |
|--------------|--------|---------------|---------------------------|
| WB_I2C1_SDA  | 13     | P0.13         | SENSOR_SLOT, IO_SLOT      |
| WB_I2C1_SCL  | 14     | P0.14         | SENSOR_SLOT, IO_SLOT      |

### I2C Bus 2
| Pin Name     | GPIO # | nRF52840 Port | Available Slots |
|--------------|--------|---------------|-----------------|
| WB_I2C2_SDA  | 24     | P0.24         | IO_SLOT         |
| WB_I2C2_SCL  | 25     | P0.25         | IO_SLOT         |

## SPI Interface Pins

| Pin Name      | GPIO # | nRF52840 Port | Function | Available Slots |
|---------------|--------|---------------|----------|-----------------|
| WB_SPI_CS     | 26     | P0.26         | CS       | IO_SLOT         |
| WB_SPI_CLK    | 3      | P0.03         | SCK      | IO_SLOT         |
| WB_SPI_MISO   | 29     | P0.29         | MISO     | IO_SLOT         |
| WB_SPI_MOSI   | 30     | P0.30         | MOSI     | IO_SLOT         |

---

## Quick Reference by Slot

**SLOT_A & SLOT_B:** WB_IO1 (17), WB_IO2 (34)  
**SLOT_C:** WB_IO3 (21), WB_IO4 (4)  
**SLOT_D:** WB_IO5 (9), WB_IO6 (10)  
**IO_SLOT:** All SPI pins, I2C2, WB_SW1, WB_A0, WB_A1, and I2C1 (shared with SENSOR_SLOT)  
**SENSOR_SLOT:** I2C1 (SDA=13, SCL=14)
