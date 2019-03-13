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

int Sensormodule::getlinkerwaarde(){
  return waarde_links;
}

int Sensormodule::getrechterwaarde(){
  return waarde_rechts;
}

int Sensormodule::getmiddenwaarde(){
  return waarde_midden;
}

int Sensormodule::calculatepid(Sensormodule rechts){
  int error=0;
  if(this->waarde_links==1 && rechts.getrechterwaarde()==1){
    /* linker sensor linker module op lijn
      en rechter sensor van rechter module op lijn
      => perfect in het midden => error=0
    */
    error=0;
  }
  if(this->waarde_midden==1 && rechts.getmiddenwaarde()==1){
    /* midden sensor linker module op lijn
      en midden sensor van rechter module op lijn
      => perfect in het midden => error=0
    */
    error=0;
  }
  if(this->waarde_rechts==1 && rechts.getlinkerwaarde()==1){
    /* rechter sensor linker module op lijn
      en linker sensor van rechter module op lijn
      => perfect in het midden => error=0
    */
    error=0;
  }


/*
TO DO:

errors definieren voor andere situaties!!

*/


  int pidvalue=Kp*error+Kd*(error-lasterror);
  this->lasterror=error;
  return pidvalue;
}
