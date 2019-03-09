#ifndef Motorcontrol_h
#define Motorcontrol_h

#include <arduino.h>
//#include <wire.h>

class Motorcontrol{
public:
  Motorcontrol();

  void set_motor_speed(uint8_t speed_m1,uint8_t speed_m2, uint8_t speed_m3, uint8_t speed_m4);
  void i2C_write_reg(uint8_t address, uint8_t reg, uint8_t instruction);
/*private:
  int pin1,pin2,pin3,pin4;
  */
};
#endif
