#include <arduino.h>
#include "Sensormodule.h"
              // met snelheid 200:
#define Kp 65 //60
#define Ki 25 //32
#define Kd 32 //40
#define drempel 500
bool rechts,links;
/* sensor module:
  layout:

            sensor L1 analogepin 0
            sensor L2: analogepin 1
            sensor L3: analogepin 2

            sensor R1: analogepin 3
            sensor R2: analogepin 6
            sensor R3: analogepin 7

  Waarden: L1 L2 L3 R1 R2 R3 0 0
*/

Sensormodule::Sensormodule(){
  }

Sensormodule::Sensormodule(int pinL1,int pinL2, int pinL3, int pinR1, int pinR2, int pinR3){
  this->pinL1=pinL1;
  this->pinL2=pinL2;
  this->pinL3=pinL3;
  this->pinR1=pinR1;
  this->pinR2=pinR2;
  this->pinR3=pinR3;
  this->waarden=B00000000;
  this->lasterror=0;
  this->overtimeerror=0;
  }

void Sensormodule::update(){
  //waarde>=drempel => niet op lijn => digitale waarde=0
  //waarde<drempel => op lijn => digitale waarde=1
  if(analogRead(pinL1)>=drempel){
    waarden=waarden&B01111111;
  }
  else{
    waarden=waarden|B10000000;
  };

  if(analogRead(pinL2)>=drempel){
    waarden=waarden&B10111111;
  }
  else{
    waarden=waarden|B01000000;
  };

  if(analogRead(pinL3)>=drempel){
    waarden=waarden&B11011111;
  }
  else{
    waarden=waarden|B00100000;
  };

  if(analogRead(pinR1)>=drempel){
    waarden=waarden&B11101111;
  }
  else{
    waarden=waarden|B00010000;
  };

  if(analogRead(pinR2)>=drempel){
    waarden=waarden&B11110111;
  }
  else{
    waarden=waarden|B00001000;
  };

  if(analogRead(pinR3)>=drempel){
    waarden=waarden&B11111011;
  }
  else{
    waarden=waarden|B00000100;
  };


}
void Sensormodule::print_waarden(){
  int printVal = 0b0000000100000000;
printVal += (int) waarden;
  Serial.print("sensorwaarden: ");
  Serial.println(printVal, BIN);
}

int Sensormodule::calculatepid(){
  int error=0;
  int errorlinks=0;
  int errorrechts=0;
//linker sensoren controleren => stuur naar rechts
  uint8_t linkersensoren=this->waarden&B11100000;
//TO DO: 11000000,01100000 en eventueel 11100000 toevoegen
  switch (linkersensoren) {
    case B10000000:
      errorlinks=-1;
      links=true;
      break;
    case B11000000:
      errorlinks=-2;
      links=true;
    case B01000000:
      errorlinks=-3;
      links=true;
      break;
    case B01100000:
    if(links==1){
      errorlinks=-4;
    }
      break;
    case B00100000:
    if(links==1){
      errorlinks=-5;
    }
      break;
    default:
      errorlinks=0;
      links=false;
      break;
  }

//rechter sensoren controleren => stuur naar links
uint8_t rechtersensoren=this->waarden&B00011100;
//TO DO: 00001100,00011000 en eventueel 00011100 toevoegen
switch (rechtersensoren) {
  case B00000100:
    errorrechts=1;
    rechts=true;
    break;
  case B00001100:
    errorrechts=2;
    rechts=true;
  case B00001000:
    errorrechts=3;
    rechts=true;
    break;
  case B00011000:
  if(rechts==1){
    errorrechts=4;
  }
    break;
  case B00010000:
  if(rechts==1){
    errorrechts=5;
  }
    break;
  default:
    errorrechts=0;
    rechts=0;
    break;
}

error=errorlinks+errorrechts;

  int pidvalue=Kp*error+Ki*overtimeerror+Kd*(error-lasterror);
  this->overtimeerror+=error;
  this->lasterror=error;

  return pidvalue;
}

uint8_t Sensormodule::getwaarden(){
  return this->waarden;
}
 void Sensormodule::updateleds(){

   if(bitRead(this->waarden, 7)==1){
       digitalWrite(2,HIGH);
     } else {
       digitalWrite(2,LOW);
     }
   if(bitRead(this->waarden, 6)==1){
       digitalWrite(7,HIGH);
     }
     else {
       digitalWrite(7,LOW);
     }
   if(bitRead(this->waarden, 5)==1){
       digitalWrite(8,HIGH);
     }
     else {
       digitalWrite(8,LOW);
     }
   if(bitRead(this->waarden, 4)==1){
       digitalWrite(11,HIGH);
     }
     else {
       digitalWrite(11,LOW);
     }
     if(bitRead(this->waarden, 3)==1){
       digitalWrite(12,HIGH);
     }
     else {
       digitalWrite(12,LOW);
     }
   if(bitRead(this->waarden, 2)==1){
       digitalWrite(13,HIGH);
     }
     else {
       digitalWrite(13,LOW);
     }
 }
