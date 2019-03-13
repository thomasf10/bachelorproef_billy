#include <Arduino.h>
#include <Wire.h>
#include "Motorcontrol.h"
/* Motorcontrol

*/
#define I2C_ADDRESS_DIR_MOTORS    0x38
#define I2C_ADDRESS_ADD_PINS      0x39

//  Command Bytes -- Send to control register in the TCA9554
#define CMD_REG_INPUT   0x00
#define CMD_REG_OUTPUT  0x01
#define CMD_REG_POL_INV 0x02
#define CMD_REG_CONFIG  0x03
//  Define PWN PINS
#define PWM_PIN_1 (3)
#define PWM_PIN_2 (5)
#define PWM_PIN_3 (6)
#define PWM_PIN_4 (9)


Motorcontrol::Motorcontrol(){
   // PinMode PWM pinnen speed Motors
   pinMode(PWM_PIN_1, OUTPUT);
   pinMode(PWM_PIN_2, OUTPUT);
   pinMode(PWM_PIN_3, OUTPUT);
   pinMode(PWM_PIN_4, OUTPUT);
}

void Motorcontrol::set_motor_speed(uint8_t speed_m1, uint8_t speed_m2, uint8_t speed_m3, uint8_t speed_m4){
  analogWrite(PWM_PIN_1, speed_m1);
  analogWrite(PWM_PIN_2, speed_m2);
  analogWrite(PWM_PIN_3, speed_m3);
  analogWrite(PWM_PIN_4, speed_m4);
}

void Motorcontrol::i2C_write_reg(uint8_t address, uint8_t reg, uint8_t instruction){
  Wire.beginTransmission(address);
  Wire.write(reg);
  Wire.write(instruction);
  Wire.endTransmission();
}

/*
 *  Determining DC motor rotation direction
 *  Instruction Byte
 *    2 bits for each motor
 *    00  or  11  Stop
 *    01          CCW or CW
 *    10          CCW or CW
 *
 *    Byte: MD MC MB MA
 */
