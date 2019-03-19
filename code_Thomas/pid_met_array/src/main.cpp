#include <Arduino.h>
#include "Led.h"
#include "Sensormodule.h"
#include <Wire.h>
#include "Motorcontrol.h"

//  Two IO EXPANDERS I2C addresses
#define I2C_ADDRESS_DIR_MOTORS    0x38
#define I2C_ADDRESS_ADD_PINS      0x39

//  Command Bytes -- Send to control register in the TCA9554
#define CMD_REG_INPUT   0x00
#define CMD_REG_OUTPUT  0x01
#define CMD_REG_POL_INV 0x02
#define CMD_REG_CONFIG  0x03



//objecten declareren
Sensormodule module;
int pidvalue;
Motorcontrol motors;

void setup(){

  motors=Motorcontrol();
  Wire.begin();

 // Setup Configuration IO expander (Motor Directions)
 motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_CONFIG, 0x00);

 // Setup Configuration IO expander (Additional Pins)
 motors.i2C_write_reg(I2C_ADDRESS_ADD_PINS, CMD_REG_CONFIG, 0x00);

 //sensormodules
  module=Sensormodule(0,1,2,3,6,7);

  Serial.begin(9600);
}

void loop(){
  //update
    module.update();
  //sturing

      pidvalue=module.calculatepid();
      Serial.println("pid: ");
      Serial.println(pidvalue);
      if(pidvalue<0){
        //stuur naar rechts
        if(200+pidvalue<0){
          /*indien stuursignaal onder nul
          wielen in tegengestelde richting laten draaien
          voor scherpere bocht
          */
          motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B01011010);
          motors.set_motor_speed(200, 200, 200, 200);
        }
        else{
      motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
      motors.set_motor_speed(200+pidvalue, 200+pidvalue, 200, 200);
          }
        }

      if(pidvalue>0){
        //stuur naar links
        if(200-pidvalue<0){
          /*indien stuursignaal onder nul
          wielen in tegengestelde richting laten draaien
          voor scherpere bocht
          */
          motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10100101);
          motors.set_motor_speed(200, 200, 200, 200);
        }
      motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
      motors.set_motor_speed(200, 200, 200-pidvalue, 200-pidvalue);
          }

      else{
        //rij rechtdoor
        motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
        motors.set_motor_speed(100, 100, 100, 100);
      }

      //RFID loop

    }




  /*
code voor motoren:

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
 /*
  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B01011010); //  Turn right
   delay(800);
  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B00000000); //  Wait
   delay(500);
  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010); //  Move forward
   delay(300);
  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B00000000); //  Wait
   delay(500);
}

*/
