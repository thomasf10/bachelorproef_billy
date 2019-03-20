#include <arduino.h>
#include "Sensormodule.h"
//deftig kp:75 kd=0 ki=0
#define Kp 95
#define Kd 0
#define Ki 8
#define drempel 700
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

Sensormodule::Sensormodule(){
  }

Sensormodule::Sensormodule(int pinlinks,int pinmidden,int pinrechts){
  this->pinlinks=pinlinks;
  this->pinmidden=pinmidden;
  this->pinrechts=pinrechts;
  this->lasterror=0;
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
  if(waarde_links>=drempel){
    waarde_links=0;
  }
  else{
    waarde_links=1;
  }
  // rechtse waarde digitaliseren
  if(waarde_rechts>=drempel){
    waarde_rechts=0;
  }
  else{
    waarde_rechts=1;
  }
  // midden waarde digitaliseren
  if(waarde_midden>=drempel){
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
  int errorrechts=0;
  int errorlinks=0;


//stuur rechts:
if(this->waarde_links==1 && this->waarde_midden==1 && this->waarde_rechts==1){
  errorrechts=-5;
}
else if(this->waarde_links==1 && this->waarde_midden==1){
  errorrechts=-4;
}
else if(this->waarde_links==1){
  errorrechts=-1;
}
else if(this->waarde_midden==1){
  errorrechts=-2;
}
else if(this->waarde_rechts==1){
  errorrechts=-3;
}


//stuur links:
if(rechts.getlinkerwaarde()==1 && rechts.getmiddenwaarde()==1 && rechts.getrechterwaarde()==1){
  errorlinks=5;
}
else if(rechts.getrechterwaarde()==1 && rechts.getmiddenwaarde()==1){
  errorlinks=4;
}
else if(rechts.getlinkerwaarde()==1){
  errorlinks=3;
}
else if(rechts.getmiddenwaarde()==1){
  errorlinks=2;
}
else if(rechts.getrechterwaarde()==1){
  errorlinks=1;
}


//rechtdoor
if(this->waarde_links==1 && rechts.getrechterwaarde()==1){
  /* linker sensor linker module op lijn
    en rechter sensor van rechter module op lijn
    => perfect in het midden => error=0
  */
  error=0;
}
else if(this->waarde_midden==1 && rechts.getmiddenwaarde()==1){
  /* midden sensor linker module op lijn
    en midden sensor van rechter module op lijn
    => perfect in het midden => error=0
  */
  error=0;
}
else if(this->waarde_rechts==1 && rechts.getlinkerwaarde()==1){
  /* rechter sensor linker module op lijn
    en linker sensor van rechter module op lijn
    => perfect in het midden => error=0
  */
  error=0;
}
else if(errorrechts>=errorlinks){
  error=errorrechts;
}
else{
  error=errorlinks;
}

//bereken pid waarde

  int pidvalue=Kp*error+Ki*this->overtimeerror+Kd*(error-this->lasterror);
  this->overtimeerror+=error;
  this->lasterror=error;

  return pidvalue;
}
