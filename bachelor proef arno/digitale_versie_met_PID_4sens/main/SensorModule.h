#ifndef SensorModule_h
#define SensorModule_h

#include "arduino.h"
#include "PID.h"

class SensorModule{
  public:
	    SensorModule();
      SensorModule(int pin_0, int pin_1,int pin_2, int pin_3);
      double calculatePIDSituatie(PID pid);
      void printValues(PID pid);
      void printSensorValues();
      void RefreshValues(SensorModule module);
      boolean LinksRechts(SensorModule links, SensorModule rechts);
  private:
      int _pin_0, _pin_1,_pin_2, _pin_3;
      int _waarde1,_waarde2,_waarde3,_waarde4;
};
#endif
