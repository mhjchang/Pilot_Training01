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
