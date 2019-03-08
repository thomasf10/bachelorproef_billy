#include "Arduino.h"
#include "PID.h"

//PID variabelen
double _Kp;
double _Ki;
double _Kd;
//PID regeling
double _P,_I,_D;
double _PIDvalue = 0;
double _previousError=0;
double diff=0.01;

PID::PID(){
}

PID::PID(double Kp, double Ki, double Kd){
  _Kp = Kp;
  _Ki = Ki;
  _Kd = Kd;
}

double PID::calculatePID(double error){

  _P = error;
  _I += error;
  if (error==_previousError){
    if(_D>0){
      _D=_D-diff;
    }else if(_D<0){
      _D=_D+diff;
    }
  }else{
  _D =  error-_previousError;
  }
  _PIDvalue = (_Kp*_P) + (_Ki*_I) + (_Kd*_D);
  //Serial.print(" previouserror ");
  //Serial.print(_previousError);
  _previousError = error;
  /*Serial.print(" D: ");
  Serial.print(_D);  
  Serial.print(" error ");
  Serial.print(error);
  Serial.print(" PID ");
  Serial.println(_PIDvalue);*/
  return _PIDvalue;
}



