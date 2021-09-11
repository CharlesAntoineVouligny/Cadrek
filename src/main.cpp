
#include <Arduino.h>
#include <Adafruit_I2CDevice.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix = Adafruit_7segment();

unsigned long time, last_time = 0;
int second = 0, minute = 0, interval;

void setup() {
#ifndef __AVR_ATtiny85__
  Serial.begin(9600);
  Serial.println("7 Segment Backpack Test");
#endif
  matrix.begin(0x70);
  matrix.setBrightness(1);
  matrix.print(35);
  matrix.writeDisplay();
}

void loop() {
    time = millis();
    interval = map(digitalRead(8), 0, 255, 50, 1200);
    

  if (time - last_time >= interval) {
    second++;
    matrix.print(second);
    matrix.writeDisplay();
    matrix.writeDigitNum(1, minute);
    matrix.writeDisplay();
    matrix.drawColon(true);

      if (second == 59) {
        minute++;
        second = 0;
      }

      last_time = time;

  }

}