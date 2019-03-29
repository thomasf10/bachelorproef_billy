#include <arduino.h>
#include "Sensormodule.h"
#define Kp 60 //60
#define Ki 32 //32
#define Kd 40 //40
#define drempel 500
//#define deeltal 10
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
  this->somL1=0;
  this->somL2=0;
  this->somL3=0;
  this->somR1=0;
  this->somR2=0;
  this->somR3=0;
  }
void Sensormodule:: updatesom(){
somL1+=analogRead(0);
somL2+=analogRead(1);
somL3+=analogRead(2);
somR1+=analogRead(3);
somR2+=analogRead(6);
somR3+=analogRead(7);
}
void Sensormodule:: clearsom(){
  somL1=0;
  somL2=0;
  somL3=0;
  somR1=0;
  somR2=0;
  somR3=0;
}
void Sensormodule::update(int deeltal){
  //waarde>=drempel => niet op lijn => digitale waarde=0
  //waarde<drempel => op lijn => digitale waarde=1
  if((somL1/deeltal)>=drempel){
    waarden=waarden&B01111111;
  }
  else{
    waarden=waarden|B10000000;
  };

  if((somL2/deeltal)>=drempel){
    waarden=waarden&B10111111;
  }
  else{
    waarden=waarden|B01000000;
  };

  if((somL3/deeltal)>=drempel){
    waarden=waarden&B11011111;
  }
  else{
    waarden=waarden|B00100000;
  };

  if((somR1/deeltal)>=drempel){
    waarden=waarden&B11101111;
  }
  else{
    waarden=waarden|B00010000;
  };

  if((somR2/deeltal)>=drempel){
    waarden=waarden&B11110111;
  }
  else{
    waarden=waarden|B00001000;
  };

  if((somR3/deeltal)>=drempel){
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
      break;
    case B11000000:
      errorlinks=-2;
    case B01000000:
      errorlinks=-3;
      break;
    case B01100000:
      errorlinks=-4;
      break;
    case B00100000:
      errorlinks=-5;
      break;
    default:
      errorlinks=0;
      break;
  }

//rechter sensoren controleren => stuur naar links
uint8_t rechtersensoren=this->waarden&B00011100;
//TO DO: 00001100,00011000 en eventueel 00011100 toevoegen
switch (rechtersensoren) {
  case B00000100:
    errorrechts=1;
    break;
  case B00001100:
    errorrechts=2;
  case B00001000:
    errorrechts=3;
    break;
  case B00011000:
    errorrechts=4;
    break;
  case B00010000:
    errorrechts=5;
    break;
  default:
    errorrechts=0;
    break;
}
error=errorlinks+errorrechts;


//basic sturing:
/*
  switch (waarden) {
    //rechtdoorrijden:
    case B10000100:
      error=0;
      break;
    case B01001000:
      error=0;
      break;
    case B00110000:
      error=0;
      break;
    //rechts draaien:
    case B10000000:
      error=-1;
      break;
    case B01000000:
      error=-2;
      break;
    case B00100000:
      error=-3;
      break;
    case B11000000:
      error=-4;
      break;
    case B01100000:
      error=-4;
      break;
    case B11100000:
      error=-5;
      break;
    case B11010000:
      error=-4;
      break;
    case B11001000:
      error-3;
      break;
    case B11101000:
      error=-5;
      break;



    //links draaien:
    case B00000100:
      error=1;
      break;
    case B00001000:
      error=2;
      break;
    case B00010000:
      error=3;
      break;
    case B00001100:
      error=4;
      break;
    case B00011000:
      error=4;
      break;
    case B00011100:
      error=5;
      break;
    case B00101100:
      error=4;
      break;
    case B01001100:
      error=3;
      break;
    case B01011100:
      error=5;
      break;

    default:
      error=0;
      break;
  }


/*
uitbereiding:
  switch (waarden) {
    case B10000100:
      error=0;
      break;
    case B01001000:
      error=0;
      break;
    case B00110000:
      error=0;
      break;
    case B10001000:
      error=1;
      break;
    case B10010000:
      error=2;
      break;
    case B10000000:
      error=-3;
      break;
    case B01000100:
      error=-1;
      break;
    case B01010000:
      error=2;
      break;
    case B01000000:
      error=-4;
      break;
    case B00100100:
      error=-2;
      break;
    case B00101000:
      error=-1;
      break;
    case B00100000:
      error=-5;
      break;
    case B00010000:
      error=5;
      break;
    case B00001000:
      error=4;
      break;
    case B00000100:
      error=3;
      break;
    default:
      error=0;
      break;
  }
*/
  int pidvalue=Kp*error+Ki*overtimeerror+Kd*(error-lasterror);
  this->overtimeerror+=error;
  this->lasterror=error;

  return pidvalue;
}

uint8_t Sensormodule::getwaarden(){
  return this->waarden;
}
