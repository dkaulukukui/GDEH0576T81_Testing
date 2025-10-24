#ifndef _DISPLAY_EPD_W21_SPI_
#define _DISPLAY_EPD_W21_SPI_
#include "Arduino.h"

//Screeen Pin Assignments
#define EPD_BSY_PIN 12
#define EPD_RST_PIN 13
#define EPD_DC_PIN 10
#define EPD_CS_PIN 9

//SPI pin assignments
#define MOSI_PIN 25
#define CLK_PIN 26
#define READ_PIN 22



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
