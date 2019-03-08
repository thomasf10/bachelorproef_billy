#ifndef RFID_h
#define RFID_h

#include "arduino.h"

class RFID{
  public:
      RFID();

      void RFIDSetup();      
      void RFIDTag();
      uint8_t Tag();
      
  private:
    uint8_t _Tag;

};
#endif
