//EPD
#include "Display_EPD_W21_spi.h"
#include "Display_EPD_W21.h"
#include "Ap_29demo.h"
#include "Adafruit_TinyUSB.h"

// Heartbeat LED variables
unsigned long previousMillis = 0;
const long heartbeatInterval = 500; // Blink every 500ms
bool ledState = LOW;

void setup() {
  pinMode(EPD_BSY_PIN, INPUT); //BUSY
  pinMode(EPD_RST_PIN, OUTPUT); //RES
  pinMode(EPD_DC_PIN, OUTPUT); //DC
  pinMode(EPD_CS_PIN, OUTPUT); //CS
  pinMode(MOSI_PIN, OUTPUT); //MOSI
  pinMode(CLK_PIN, OUTPUT); //CLK
  
  
  // Setup heartbeat LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);  //flash LED 3 times 
	delay(200);
  digitalWrite(LED_BUILTIN, HIGH);
	delay(200);
  digitalWrite(LED_BUILTIN, LOW);
	delay(200);
  digitalWrite(LED_BUILTIN, HIGH);
	delay(200);
  digitalWrite(LED_BUILTIN, LOW);
	delay(200);
  digitalWrite(LED_BUILTIN, HIGH);
	delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  
  Serial.begin(115200);
  delay(1000);
  Serial.println("=== EPD Display Demo ===");
  Serial.println("Setup Complete - Pins Configured");
  Serial.println("Heartbeat LED Active");
}

// Non-blocking LED heartbeat function
void updateHeartbeat() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= heartbeatInterval) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState);
  }
}

//Tips//
/*
1.Flickering is normal when EPD is performing a full screen update to clear ghosting from the previous image so to ensure better clarity and legibility for the new image.
2.There will be no flicker when EPD performs a partial update.
3.Please make sue that EPD enters sleep mode when update is completed and always leave the sleep mode command. Otherwise, this may result in a reduced lifespan of EPD.
4.Please refrain from inserting EPD to the FPC socket or unplugging it when the MCU is being powered to prevent potential damage.)
5.Re-initialization is required for every full screen update.
6.When porting the program, set the BUSY pin to input mode and other pins to output mode.
*/

void loop() {
  updateHeartbeat(); // Update LED heartbeat
  
  unsigned char i;
  Serial.println("\n--- Starting Display Loop ---");
  
#if 1 //Full screen update, partial update demostration.
  /************Full display*******************/
  Serial.println("Initializing EPD for Image 1...");
  EPD_init(); //Full screen update initialization.
  Serial.println("EPD Init Complete");
  
  Serial.println("Displaying Image 1...");
  PIC_display(gImage_1);//To Display one image using full screen update.
  Serial.println("Image 1 Display Complete");
  EPD_sleep();//Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
  
  Serial.println("Waiting 1 second...");
  for(int i=0; i<10; i++) { delay(100); updateHeartbeat(); } // Blink during delay
  
  Serial.println("Initializing EPD for Image 2...");
  EPD_init(); //Full screen update initialization.
  Serial.println("EPD Init Complete");
  
  Serial.println("Displaying Image 2...");
  PIC_display(gImage_2);//To Display one image using full screen update.
  Serial.println("Image 2 Display Complete");
  //EPD_sleep();//Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
  
  Serial.println("Waiting 1 second...");
  for(int i=0; i<10; i++) { delay(100); updateHeartbeat(); }
  
  Serial.println("Initializing EPD for Image 3...");
  EPD_init(); //Full screen update initialization.
  Serial.println("EPD Init Complete");
  
  Serial.println("Displaying Image 3...");
  PIC_display(gImage_3);//To Display one image using full screen update.
  Serial.println("Image 3 Display Complete");
  //EPD_sleep();//Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
  
  Serial.println("Waiting 1 second...");
  for(int i=0; i<10; i++) { delay(100); updateHeartbeat(); }
  
#if 0 //Partial update demostration.
  //Partial update demo support displaying a clock at 5 locations with 00:00. If you need to perform partial update more than 5 locations, please use the feature of using partial update at the full screen demo.
  //After 5 partial updatees, implement a full screen update to clear the ghosting caused by partial updatees.
  /************Partial display*******************/
  Serial.println("\n--- Starting Partial Update Demo ---");
  Serial.println("Initializing EPD for partial update base...");
  EPD_init(); //Full screen update initialization.
  Serial.println("Displaying partial update base image...");
  PIC_display(gImage_p1);//To Display one image using full screen update.
  Serial.println("Base image displayed");
  
  Serial.println("Initializing partial update mode...");
  EPD_init_Part();
  Serial.println("Partial update mode active");
  
  Serial.println("Partial update 1: p1 -> p2");
  PIC_display_Part_ALL(gImage_p1, gImage_p2);
  updateHeartbeat();
  Serial.println("Partial update 2: p2 -> p3");
  PIC_display_Part_ALL(gImage_p2, gImage_p3);
  updateHeartbeat();
  Serial.println("Partial update 3: p3 -> Image 3");
  PIC_display_Part_ALL(gImage_p3, gImage_3);
  updateHeartbeat();
  
  Serial.println("Entering sleep mode...");
  EPD_sleep();//Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
  Serial.println("EPD in sleep mode");
#endif
  
  Serial.println("Waiting 3 seconds...");
  for(int i=0; i<30; i++) { delay(100); updateHeartbeat(); }
  
  Serial.println("Clearing screen to white...");
  EPD_init(); //Full screen update initialization.
  Display_All_White();
  Serial.println("Screen cleared");
  
  Serial.println("Entering sleep mode...");
  EPD_sleep();//Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
  Serial.println("EPD in sleep mode");
  Serial.println("=== Loop Complete ===\n");
  
#endif
  //while(1); // The program stops here
}
//////////////////////////////////END//////////////////////////////////////////////////