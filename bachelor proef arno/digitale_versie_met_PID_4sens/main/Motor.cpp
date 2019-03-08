#include "Arduino.h"
#include "motor.h"

const int dir_pin_motorL = 12;
const int dir_pin_motorR = 13; 
const int speed_pin_motorL = 3; 
const int speed_pin_motorR = 11;

int _pref_speed;
int _speed_left_motor;
int _speed_right_motor;
int previousPID=0;
int previousSens4;

Motor::Motor(){
  //setup Pinnen
  pinMode(dir_pin_motorL, OUTPUT);
  pinMode(dir_pin_motorR, OUTPUT);
  pinMode(speed_pin_motorL, OUTPUT);
  pinMode(speed_pin_motorR, OUTPUT);  
}

void Motor::start(int pref_speed){
  _pref_speed = pref_speed;
  digitalWrite(dir_pin_motorL, LOW);
  digitalWrite(dir_pin_motorR, LOW);
  
  //eerste snelheid meegeven
  _speed_left_motor = _pref_speed;
  _speed_right_motor = _pref_speed;
}

void Motor::rotate(double PIDvalue,boolean leftright){
  //Left= true, Right= false
  if(!leftright){
    PIDvalue=-1*PIDvalue;
  };
    _speed_left_motor= _pref_speed+(int)(PIDvalue);
    _speed_right_motor = _pref_speed-(int)(PIDvalue);

    alterSpeed(PIDvalue);
};

void Motor::printValues(){

     
    String l = " linkse motor: ";
    String r = " rechtse motor: ";
    Serial.print(l);
    Serial.print(_speed_left_motor);
    Serial.print("   ");
    Serial.print(r);
    Serial.print(_speed_right_motor);
    Serial.print('\n');
    
}

void Motor::alterSpeed(int PIDvalue){

  //printValues();
  analogWrite(speed_pin_motorL, _speed_left_motor);
  analogWrite(speed_pin_motorR, _speed_right_motor);
  
}

