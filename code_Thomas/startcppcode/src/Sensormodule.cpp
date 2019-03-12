#include <arduino.h>
#include "Sensormodule.h"

/* sensor module:
  layout:
    module1:
            sensor links: analogepin 0
            sensor midden: analogepin 1
            sensor rechts: analogepin 2
    module2:
            sensor links: analogepin 3
            sensor midden: analogepin 4
            sensor rechts: analogepin 5
*/
//int pinlinks,pinmidden,pinrecht;
//int waarde_links, waarde_midden,waarde_rechts;

Sensormodule::Sensormodule(){
  }

Sensormodule::Sensormodule(int pinlinks,int pinmidden,int pinrechts){
  this->pinlinks=pinlinks;
  this->pinmidden=pinmidden;
  this->pinrechts=pinrechts;
  this->actief=true;
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
  */
}
