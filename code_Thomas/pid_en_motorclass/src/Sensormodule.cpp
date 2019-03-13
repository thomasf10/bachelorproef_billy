#include <arduino.h>
#include "Sensormodule.h"
#define Kp 40
#define Kd 0
/* sensor module:
  layout:
    module1(links):
            sensor links: analogepin 0
            sensor midden: analogepin 1
            sensor rechts: analogepin 2
    module2(rechts):
            sensor links: analogepin 3
            sensor midden: analogepin 4
            sensor rechts: analogepin 5
*/

/*mogelijke verbeteringen:
        -update en digitaliseren in 1 functie
        -sensorwaarden in array ipv aparte int's
        -functie kieslijn robuster maken
*/

Sensormodule::Sensormodule(){
  }

Sensormodule::Sensormodule(int pinlinks,int pinmidden,int pinrechts){
  this->pinlinks=pinlinks;
  this->pinmidden=pinmidden;
  this->pinrechts=pinrechts;
  this->actief=true;
  this->lasterror=0;
  }

void Sensormodule::update(){
  waarde_links=analogRead(pinlinks);
  waarde_midden=analogRead(pinmidden);
  waarde_rechts= analogRead(pinrechts);
}
void Sensormodule::print_waarden(){
  Serial.print("waarde links: ");
  Serial.print(waarde_links);
  Serial.print("  waarde midden: " );
  Serial.print(waarde_midden);
  Serial.print("  waarde rechts: ");
  Serial.println(waarde_rechts);

}
void Sensormodule:: digitaliseerwaarden(){
  // likse waarde digitaliseren
  if(waarde_links>=500){
    waarde_links=1;
  }
  else{
    waarde_links=0;
  }
  // rechtse waarde digitaliseren
  if(waarde_rechts>=500){
    waarde_rechts=1;
  }
  else{
    waarde_rechts=0;
  }
  // midden waarde digitaliseren
  if(waarde_midden>=500){
    waarde_midden=1;
  }
  else{
    waarde_midden=0;
  }
}
void Sensormodule::kieslijn(Sensormodule module){
/*to do: kiest linker of rechter lijn aan de hand van?
  zet boolean actief op true van ene module en false
  van andere module

  momenteel: simpel, mischien uitbereiden nodig!
  */

  if(this->waarde_midden==1){
    this->actief=true;
    module.setactief(false);
  }
  else{
    this->actief=false;
    module.setactief(true);
    }

}
bool Sensormodule::getactief(){
  return actief;
}

int Sensormodule::getlinkerwaarde(){
  return waarde_links;
}

int Sensormodule::getrechterwaarde(){
  return waarde_rechts;
}

int Sensormodule::getmiddenwaarde(){
  return waarde_midden;
}
void Sensormodule::setactief(bool a){
  this->actief=a;
}
int Sensormodule::calculatepid(){
  int error=0;
  if(waarde_links==0 && waarde_midden==1 && waarde_rechts==0){
    error=0;
  }
  else{
    if(waarde_links==1){
      if(waarde_midden==0){
        error=2;
      }
      else{
        error=1;
      }
    }
    else{
      if(waarde_rechts==1){
        if(waarde_midden==0){
          error=-2;
        }
        else{
          error=-1;
        }
      }
    }
  }
  int pidvalue=Kp*error+Kd*error-lasterror;
  this->lasterror=error;
  return pidvalue;
}
