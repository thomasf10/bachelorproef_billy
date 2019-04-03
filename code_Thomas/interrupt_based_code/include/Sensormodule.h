#ifndef Sensormodule_h
#define Sensormodule_h

#include <arduino.h>

class Sensormodule{
  public:
    Sensormodule();
    Sensormodule(int pinL1,int pinL2, int pinL3, int pinR1, int pinR2, int pinR3);
    void update(int deeltal);
    void print_values();
    int calculatepid();
    void updatesumL1(int waarde);
    void updatesumL2(int waarde);
    void updatesumL3(int waarde);
    void updatesumR1(int waarde);
    void updatesumR2(int waarde);
    void updatesumR3(int waarde);
    void clearsum();
    void updateleds();
  private:
    int pinL1,pinL2,pinL3,pinR1,pinR2,pinR3;
    long sumL1,sumL2,sumL3,sumR1,sumR2,sumR3;
    uint8_t values;
    int lasterror;
    int overtimeerror;

};
#endif
