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

### Task 3: Connect circuitry with breadboard (DS18B20 Thermometer)
- Connect the positive pole of DS18B20 -> 3.3V
- Connect the negative pole of DS18B20 -> GND
- Connect the data pole of DS18B20 -> Pin 25 of device
- Add a 4.7K Ohm resistor between positive and data wire

<img width="628" alt="DS18B20 Schematic flow" src="https://user-images.githubusercontent.com/90884001/134019218-d3c20020-0c1b-44cc-a54a-6ead74becbea.png">


### Task 4: Load the script for detecting temperature with DS18B20 Thermometer
Test your device with this sample script Download here: [Monitor_DS18B20.ino](https://github.com/CoWIN-Workshop/Pilot_Training01/blob/main/Samples/Monitor_DS18B20.ino)

or copy and paste the below script:
```
// Include the required Arduino libraries:
#include <SPI.h>
#include <Wire.h>          
#include "SSD1306Wire.h"            //For SSD1306 Monitor

#include <OneWire.h>                //For DS18B20 Thermometer
#include <DallasTemperature.h>      //For DS18B20 Thermometer
#define ONE_WIRE_BUS 25            //Connect DS18B20 to pin 25

SSD1306Wire display(0x3c, 21, 22); //Connect SDA to pin 21 and SCL to pin 22

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void printBuffer(void) {
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_16);
    display.drawString(48, 5, "HKU");  //Try to edit your school name here 
    display.drawHorizontalLine(0, 30, 150);
    sensors.requestTemperatures();
    float tempC = sensors.getTempCByIndex(0);
    display.setFont(ArialMT_Plain_16);

    display.drawString(5, 45, "Temp: "+String(tempC)+" "+(char)247+"C");
    Serial.println(tempC);
    display.display();
  };

void setup() {
  Serial.begin(115200);
  sensors.begin();
  display.init();
  display.clear();
}

void loop() { 
  printBuffer();
  delay(1000);
  }
```

### Task 5: DS18B20 Calibration
