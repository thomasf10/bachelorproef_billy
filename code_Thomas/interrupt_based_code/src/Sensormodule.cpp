#include <arduino.h>
#include "Sensormodule.h"
#define Kp 60 //60
#define Ki 32 //32
#define Kd 40 //40
#define drempel 500

/* sensor module:
  layout:

            sensor L1 analogepin 0
            sensor L2: analogepin 1
            sensor L3: analogepin 2

            sensor R1: analogepin 3
            sensor R2: analogepin 6
            sensor R3: analogepin 7

  values: L1 L2 L3 R1 R2 R3 0 0
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
  this->values=B00000000;
  this->lasterror=0;
  this->overtimeerror=0;
  this->sumL1=0;
  this->sumL2=0;
  this->sumL3=0;
  this->sumR1=0;
  this->sumR2=0;
  this->sumR3=0;
  }
void Sensormodule:: updatesumL1(int waarde){
this->sumL1+=waarde;
}
void Sensormodule:: updatesumL2(int waarde){
this->sumL2+=waarde;
}
void Sensormodule:: updatesumL3(int waarde){
this->sumL3+=waarde;
}
void Sensormodule:: updatesumR1(int waarde){
this->sumR1+=waarde;
}
void Sensormodule:: updatesumR2(int waarde){
this->sumR2+=waarde;
}
void Sensormodule:: updatesumR3(int waarde){
this->sumR3+=waarde;
}
void Sensormodule:: clearsum(){
  sumL1=0;
  sumL2=0;
  sumL3=0;
  sumR1=0;
  sumR2=0;
  sumR3=0;
}
void Sensormodule::update(int deeltal){
  //waarde>=drempel => niet op lijn => digitale waarde=0
  //waarde<drempel => op lijn => digitale waarde=1
  if((sumL1/deeltal)>=drempel){
    values=values&B01111111;
  }
  else{
    values=values|B10000000;
  };

  if((sumL2/deeltal)>=drempel){
    values=values&B10111111;
  }
  else{
    values=values|B01000000;
  };

  if((sumL3/deeltal)>=drempel){
    values=values&B11011111;
  }
  else{
    values=values|B00100000;
  };

  if((sumR1/deeltal)>=drempel){
    values=values&B11101111;
  }
  else{
    values=values|B00010000;
  };

  if((sumR2/deeltal)>=drempel){
    values=values&B11110111;
  }
  else{
    values=values|B00001000;
  };

  if((sumR3/deeltal)>=drempel){
    values=values&B11111011;
  }
  else{
    values=values|B00000100;
  };


}
void Sensormodule::print_values(){
  int printVal = 0b0000000100000000;
printVal += (int) values;
  Serial.print("sensorvalues: ");
  Serial.println(printVal, BIN);
}

int Sensormodule::calculatepid(){
  int error=0;
  int errorlinks=0;
  int errorrechts=0;
//linker sensoren controleren => stuur naar rechts
  uint8_t linkersensoren=this->values&B11100000;
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
uint8_t rechtersensoren=this->values&B00011100;
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

  int pidvalue=Kp*error+Ki*overtimeerror+Kd*(error-lasterror);
  this->overtimeerror+=error;
  this->lasterror=error;

  return pidvalue;
}

void Sensormodule::updateleds(){
  if(bitRead(this->values, 7)==1){
      digitalWrite(2,HIGH);
    } else {
      digitalWrite(2,LOW);
    }
  if(bitRead(this->values, 6)==1){
      digitalWrite(7,HIGH);
    }
    else {
      digitalWrite(7,LOW);
    }
  if(bitRead(this->values, 5)==1){
      digitalWrite(8,HIGH);
    }
    else {
      digitalWrite(8,LOW);
    }
  if(bitRead(this->values, 4)==1){
      digitalWrite(11,HIGH);
    }
    else {
      digitalWrite(11,LOW);
    }
    if(bitRead(this->values, 3)==1){
      digitalWrite(12,HIGH);
    }
    else {
      digitalWrite(12,LOW);
    }
  if(bitRead(this->values, 2)==1){
      digitalWrite(13,HIGH);
    }
    else {
      digitalWrite(13,LOW);
    }
}
