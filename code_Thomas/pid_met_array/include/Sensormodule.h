#ifndef Sensormodule_h
#define Sensormodule_h

#include <arduino.h>

class Sensormodule{
  public:
    Sensormodule();
    Sensormodule(int pinL1,int pinL2, int pinL3, int pinR1, int pinR2, int pinR3);
    void update();
    void print_waarden();
    int calculatepid();
    uint8_t getwaarden();
  private:
    int pinL1,pinL2,pinL3,pinR1,pinR2,pinR3;
    uint8_t waarden;
    int lasterror;
    int overtimeerror;

};
#endif
