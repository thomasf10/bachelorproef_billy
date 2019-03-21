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

//aantal tijd tussen update sensoren in milliseconden
#define updatetijd 150
#define motorsnelheid 100
#define minimumsnelheid 20

//objecten declareren
Sensormodule module;
int pidvalue;
Motorcontrol motors;
unsigned long lastmillis;
unsigned long currentmillis;

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
  currentmillis=millis();
  if(currentmillis>(lastmillis+updatetijd)){
    lastmillis=currentmillis;

  //update
    module.update();
  //sturing
  Serial.println("sensorwaarden: ");
  module.print_waarden();
      pidvalue=module.calculatepid();
      Serial.println("pid: ");
      Serial.println(pidvalue);
      if(pidvalue<0){
              //stuur naar rechts
              if(motorsnelheid+pidvalue<minimumsnelheid){
                //TO DO: indien -pidavalue>255 dan max snelheid bereikt=>met 255 rijden

                /*indien stuursignaal onder nul
                  linker wielen ook versnellen, ipv enkel
                  rechter wielen te vertragen
                */
                //motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
                motors.set_motor_speed(minimumsnelheid, minimumsnelheid, -pidvalue, -pidvalue);
              }
              else{
                //rechter wielen vertragen
            //motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
            motors.set_motor_speed(motorsnelheid+pidvalue, motorsnelheid+pidvalue, motorsnelheid, motorsnelheid);
                }
              }
              else if(pidvalue>0){
              //stuur naar links
              if(motorsnelheid-pidvalue<minimumsnelheid){
                /*indien stuursignaal onder nul
                rechter wielen ook versnellen, ipv enkel
                linker wielen te vertragen
                */
              //  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
                motors.set_motor_speed(pidvalue, pidvalue, minimumsnelheid , minimumsnelheid);
              }
              else{
            //motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
            motors.set_motor_speed(motorsnelheid, motorsnelheid, motorsnelheid-pidvalue, motorsnelheid-pidvalue);
                }
              }
            else{
              //rij rechtdoor
            //  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
              motors.set_motor_speed(motorsnelheid, motorsnelheid, motorsnelheid, motorsnelheid);
            }

            //RFID loop
          }
      }




  /*
code voor motoren:

void loop(){
  //set motor speed
  motors.set_motor_speed(motorsnelheid, motorsnelheid, motorsnelheid, motorsnelheid);
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
