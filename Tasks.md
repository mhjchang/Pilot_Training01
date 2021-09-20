# Tasks Today
********************************************************************

### Task 1: Test the device
Connect the TTGO deivce to computer and follow [ESP32 Installation Manual](https://github.com/CoWIN-Workshop/Pilot_Training01/blob/main/ESP32_Installation.md) to setup the environment

### Task 2: Load the script for showing text on the monitor (SSD1306)
Test your device with this sample script
Download here: [Monitor_SSD1306.ino](https://github.com/CoWIN-Workshop/Pilot_Training01/blob/main/Samples/Monitor_SSD1306.ino)

or copy and paste the below script:

```
// Include the required Arduino libraries:
#include <Wire.h>  
#include "SSD1306Wire.h"

SSD1306Wire  display(0x3c, 21, 22);

// Adapted from Adafruit_SSD1306
void drawCircle(void) {
  for (int16_t i=0; i<display.getHeight(); i+=2) {
    display.drawCircle(display.getWidth()/2, display.getHeight()/2, i);
    display.display();
    delay(10);
  }
  delay(1000);
  display.clear();

  // This will draw the part of the circel in quadrant 1
  // Quadrants are numberd like this:
  //   0010 | 0001
  //  ------|-----
  //   0100 | 1000
  //
  display.drawCircleQuads(display.getWidth()/2, display.getHeight()/2, display.getHeight()/4, 0b00000001);
  display.display();
  delay(200);
  display.drawCircleQuads(display.getWidth()/2, display.getHeight()/2, display.getHeight()/4, 0b00000011);
  display.display();
  delay(200);
  display.drawCircleQuads(display.getWidth()/2, display.getHeight()/2, display.getHeight()/4, 0b00000111);
  display.display();
  delay(200);
  display.drawCircleQuads(display.getWidth()/2, display.getHeight()/2, display.getHeight()/4, 0b00001111);
  display.display();
}

void printBuffer(void) {
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.setFont(ArialMT_Plain_24);
    display.drawString(65, 5, "HKU");  //Try to edit your school name here 
    display.drawHorizontalLine(0, 35, 150);
    display.setFont(ArialMT_Plain_10);
    display.drawString(65, 40, "Pilot Workshop (Day 1)");
    display.display();
  };

void setup() {
  display.init();

  drawCircle();
  delay(1000);
  display.clear();

  printBuffer();
  delay(1000);
  display.clear();
}

void loop() { }
```

Connecting circuitry with breadboard (
