#include <arduino.h>
#include "Led.h"

int pin;

Led::Led(){}

Led::Led(int pin){
  this->pin=pin;
  pinMode(pin,OUTPUT);
}
void Led:: aan(){
  Serial.println("in aan");
  digitalWrite(pin, HIGH);
  Serial.println("led hoog");
}

void Led:: uit(){
  Serial.println("in uit");
  digitalWrite(pin, LOW);
  Serial.println("led laag");
}
