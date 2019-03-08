#ifndef PID_h
#define PID_h

#include "arduino.h"

class PID{
	public:
		PID();
    PID(double Kp, double Ki, double Kd);

    double calculatePID(double val);

  private:
    //PID variabelen
    double _Kp;
    double _Ki;
    double _Kd;    
};

#endif

