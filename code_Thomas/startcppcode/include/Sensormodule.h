#ifndef Sensormodule_h
#define Sensormodule_h

#include <arduino.h>

class Sensormodule{
  public:
    Sensormodule();
    Sensormodule(int pinlinks, int pinmidden, int pinrechts);
    void update();
    void print_waarden();
    void digitaliseerwaarden();
  private:
    int pinlinks,pinmidden,pinrechts;
    int waarde_links, waarde_midden,waarde_rechts;


};
#endif
