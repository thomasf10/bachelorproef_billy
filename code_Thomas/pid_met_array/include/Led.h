#ifndef Led_h
#define Led_h

#include <arduino.h>

class Led{
  public:
    Led();
    Led(int pin);
    void aan();
    void uit();
  private:
    int pin;
};
#endif
