#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
unsigned long beginloop;
void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  beginloop=millis();
}

void loop() {
  /*
  lcd.setCursor(0,0);
  lcd.print("dag");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("daan");
  delay(1000);
  lcd.clear();
  delay(1000);
  */

  unsigned long allesec=(millis()-beginloop)/1000;
  int min= allesec/60;
  int overigesec=allesec%60;
  lcd.clear();// duurt 2 ms
  lcd.setCursor(0,0);
  lcd.print("tijd:");
  lcd.setCursor(0,1);
  lcd.print(min);
  lcd.setCursor(2,1);
  lcd.print("min");
  lcd.setCursor(6,1);
  lcd.print(overigesec);
  lcd.setCursor(9,1);
  lcd.print("sec");
  delay(1000);
}
