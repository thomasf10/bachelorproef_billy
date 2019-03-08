#include "Arduino.h"
#include "SensorModule.h"
#include "PID.h"

int _pin_0, _pin_1,_pin_2, _pin_3;
int grens=450;
int sens1,sens2, sens3,sens4;
boolean uitBaan = false;
const double errorMap[5] = {-.75,.75,1,1.25,2.25};
int change;

SensorModule::SensorModule(){
}

SensorModule::SensorModule(int pin_0, int pin_1,int pin_2, int pin_3){
   _pin_0 = pin_0;
   _pin_1 = pin_1;
   _pin_2 = pin_2;
   _pin_3 = pin_3;
   pinMode(pin_0, INPUT);
   pinMode(pin_1, INPUT);
   pinMode(pin_2, INPUT);
   pinMode(pin_3, INPUT);
}

double SensorModule::calculatePIDSituatie(PID pid){
  
  double temp=0;

  if ((_waarde1>grens)&&(_waarde2>grens)&&(_waarde3>grens)&&(_waarde4>grens)){
    temp= errorMap[0];
    //Serial.print("Zwart");
  } else if (_waarde4<grens){
     temp= errorMap[4];
     //Serial.print("4");
  } else if (_waarde3 <grens){
     temp= errorMap[3];
     //Serial.print("3");
  } else if (_waarde2 <grens){
     temp= errorMap[2];
     //Serial.print("2");
  } else if (_waarde1 <grens){
     temp= errorMap[1];
    //Serial.print("1");
  } 

  return pid.calculatePID(temp);
}

void SensorModule::printValues(PID pid){

    String pidstr = "->  PID ";
    Serial.print(" ");
   
    Serial.print(pidstr);
    Serial.print('\n');

}
void SensorModule::printSensorValues(){
  Serial.print("Waardes   ");
  Serial.print(_waarde1);
  Serial.print("   ");
  Serial.print(_waarde2);
  Serial.print("   ");
  Serial.print(_waarde3);
  Serial.print("   ");
  Serial.println(_waarde4);

}
boolean SensorModule::LinksRechts(SensorModule links, SensorModule rechts){
  //Left= true, Right= false
  //code voor wissel links en rechtse module
  if((links._waarde1>grens)&&(links._waarde2>grens)&&(links._waarde3>grens)&&(links._waarde4>grens)&&(rechts._waarde1>grens)&&(rechts._waarde2>grens)&&(rechts._waarde3>grens)&&(rechts._waarde4>grens)){
    change++;  
  }
  Serial.print(change);
  Serial.print("  ");
  if(change>100){
    if(links._waarde1<grens){
      change=0;
      return true;      
    }else if(rechts._waarde1<grens){
      change=0;
      return false;      
    }
  }
}

void SensorModule::RefreshValues(SensorModule module){
  _waarde1=digitalRead(module._pin_0)*900;
  _waarde2=digitalRead(module._pin_1)*900;
  _waarde3=digitalRead(module._pin_2)*900;
  _waarde4=digitalRead(module._pin_3)*900;

  printSensorValues();
}

