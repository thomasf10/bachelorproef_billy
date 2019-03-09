#include <Arduino.h>
#include "Led.h"
#include "Sensormodule.h"
#include "Motorcontrol.h"
Motorcontrol motors;
//  Two IO EXPANDERS I2C addresses
#define I2C_ADDRESS_DIR_MOTORS    0x38
#define I2C_ADDRESS_ADD_PINS      0x39

//  Command Bytes -- Send to control register in the TCA9554
#define CMD_REG_INPUT   0x00
#define CMD_REG_OUTPUT  0x01
#define CMD_REG_POL_INV 0x02
#define CMD_REG_CONFIG  0x03
void setup(){
  motors=Motorcontrol();
  //Serial.begin(9600);
}
void loop(){
  //set motor speed
  motors.set_motor_speed(200, 200, 200, 200);
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
  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B01011010); //  Turn right
   delay(800);
  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B00000000); //  Wait
   delay(500);
  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010); //  Move forward
   delay(300);
  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B00000000); //  Wait
   delay(500);
}




/*
code voor sensoren

Sensormodule links;
const int pin = 7;

void setup() {
  //sensoren declareren
  links= Sensormodule(0,1,2);
  Serial.begin(9600);
}

void loop() {
  // sensor waardes updaten en uitprinten
  links.update();
  links.print_waarden();
  Serial.println("digitaal: ");
  links.digitaliseerwaarden();
  links.print_waarden();
  Serial
  .println();
  delay(1000);
}
*/
