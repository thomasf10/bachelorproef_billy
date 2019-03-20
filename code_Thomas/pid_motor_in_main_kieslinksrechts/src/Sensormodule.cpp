#include <arduino.h>
#include "Sensormodule.h"
#define Kp 35
#define Kd 5
#define Ki 15

/* sensor module:
  layout:
    module1(links):
            sensor links: analogepin 0
            sensor midden: analogepin 1
            sensor rechts: analogepin 2
    module2(rechts):
            sensor links: analogepin 3
            sensor midden: analogepin 6
            sensor rechts: analogepin 7
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
  this->overtimeerror=0;
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
  // op lijn(wit) = 1
  // niet op lijn (zwart)=0
  // likse waarde digitaliseren
  if(waarde_links>=500){
    waarde_links=0;
  }
  else{
    waarde_links=1;
  }
  // rechtse waarde digitaliseren
  if(waarde_rechts>=500){
    waarde_rechts=0;
  }
  else{
    waarde_rechts=1;
  }
  // midden waarde digitaliseren
  if(waarde_midden>=500){
    waarde_midden=0;
  }
  else{
    waarde_midden=1;
  }
}
void Sensormodule::kieslijn(Sensormodule module){
/*to do: kiest linker of rechter lijn aan de hand van?
  zet boolean actief op true van ene module en false
  van andere module

  momenteel: simpel, mischien uitbereiden nodig!
  */

  if(this->waarde_rechts==0 && this->waarde_midden==0 && this->waarde_links==0){
    /*als alle linker sensoren van de lijn zijn
    */
    this->actief=false; // zet links op niet actief
    module.setactief(true); // zet rechts op actief
  }
  if(module.getlinkerwaarde()==0 && module.getmiddenwaarde()==0 && module.getrechterwaarde()==0){
    /*als alle rechter sensoren van de lijn zijn
    */
    this->actief=true; //zet links op actief
    module.setactief(false); //zet rechts op niet actief
  }
  // blijf bij zelfde module in alle andere gevallen

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
    // middenste sensor op lijn => perfect => error=0
    error=0;
  }
  else{
    if(waarde_links==1){
      if(waarde_midden==0){
        /*linker sensor op lijn, middenste sensor al van lijn
        => veel bijsturen => error=2
        */
        error=2;
      }
      else{
        /* middenste sensor nog op lijn => kleinere fout
          => error=1
          */
        error=1;
      }
    }

    else{
      if(waarde_rechts==1){
        if(waarde_midden==0){
          /*rechter sensor op lijn, middenste sensor al van kieslijn
            => veel bijsturen => error=-2
          */
          error=-2;
        }
        else{
          /*minddenste sensor nog op lijn => kleinere fout
          => error=-1
          */
          error=-1;
        }
      }
    }
  }
  this->overtimeerror+=error;
    int pidvalue=Kp*error+Ki*this->overtimeerror+Kd*(error-this->lasterror);
    this->lasterror=error;

  return pidvalue;
}
