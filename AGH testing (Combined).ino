#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

const int cooler = 9;
const int heater = 8;
const int dht = A0;

#define Region "India"
#define Plant "Grass"

void setup() {
  Serial.begin(9600);
  
  pinMode(cooler, OUTPUT);
  pinMode(heater, OUTPUT);
  pinMode(dht, INPUT);

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  DateTime now = rtc.now();

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  digitalWrite(cooler, HIGH);
  
  delay(1000);

}
