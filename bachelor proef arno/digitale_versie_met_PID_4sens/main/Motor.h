#ifndef motor_h
#define motor_h

#include "arduino.h"
class Motor{
  public:
         Motor();
         void start(int pref_speed);
         void rotate(double PIDvalue,boolean leftright);
         void printValues();
  private:
         void alterSpeed(int PIDvalue);
        
         int _pref_speed;
         int _speed_left_motor;
         int _speed_right_motor;
};
#endif
