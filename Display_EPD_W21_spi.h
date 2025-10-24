#ifndef _DISPLAY_EPD_W21_SPI_
#define _DISPLAY_EPD_W21_SPI_
#include "Arduino.h"

// Adafruit NRF52840 → RAK4630 (Arduino GPIO numbers)
#define EPD_BSY_PIN  17  //WB_IO1 (P0.17)
#define EPD_RST_PIN  21  //now WB_IO3 (P0.21) 
#define EPD_DC_PIN    4  //now WB_IO4 (P0.04)
#define EPD_CS_PIN   34  //now WB_IO2 (P1.02)   

// Hardware SPI is used by the LoRa chip (SX1262) internally:
// P1.10 (42) - NSS (LoRa CS)
// P1.11 (43) - SCK (LoRa)  
// P1.12 (44) - MOSI (LoRa)
// P1.13 (45) - MISO (LoRa)

// For your e-paper display, use software SPI or available GPIO pins:
#define MOSI_PIN  9   //WB_IO5 (P0.09)
#define CLK_PIN  10   // Was 26, now WB_IO6 (P0.10)
#define READ_PIN  1   // Was 22, now WB_SW1 (P0.01) - or any other available GPIO



//IO settings
#define isEPD_W21_BUSY digitalRead(EPD_BSY_PIN)  //BUSY
#define EPD_W21_RST_0 digitalWrite(EPD_RST_PIN,LOW)  //RES
#define EPD_W21_RST_1 digitalWrite(EPD_RST_PIN,HIGH)
#define EPD_W21_DC_0  digitalWrite(EPD_DC_PIN,LOW) //DC
#define EPD_W21_DC_1  digitalWrite(EPD_DC_PIN,HIGH)
#define EPD_W21_CS_0 digitalWrite(EPD_CS_PIN,LOW) //CS
#define EPD_W21_CS_1 digitalWrite(EPD_CS_PIN,HIGH)

#define EPD_W21_MOSI_0  digitalWrite(MOSI_PIN,LOW) //SCK
#define EPD_W21_MOSI_1  digitalWrite(MOSI_PIN,HIGH) 
#define EPD_W21_CLK_0 digitalWrite(CLK_PIN,LOW) //SDIN
#define EPD_W21_CLK_1 digitalWrite(CLK_PIN,HIGH)
#define EPD_W21_READ digitalRead(READ_PIN)  //SDA


void SPI_Write(unsigned char value);
void EPD_W21_WriteDATA(unsigned char datas);
void EPD_W21_WriteCMD(unsigned char command);
unsigned char EPD_W21_ReadDATA(void);

#endif 
