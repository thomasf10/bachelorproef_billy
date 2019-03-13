#include <Arduino.h>
#include "Led.h"
#include "Sensormodule.h"
#include "Motorcontrol.h"

//  Two IO EXPANDERS I2C addresses
#define I2C_ADDRESS_DIR_MOTORS    0x38
#define I2C_ADDRESS_ADD_PINS      0x39

//  Command Bytes -- Send to control register in the TCA9554
#define CMD_REG_INPUT   0x00
#define CMD_REG_OUTPUT  0x01
#define CMD_REG_POL_INV 0x02
#define CMD_REG_CONFIG  0x03
//Motorcontrol motors;
Sensormodule links,rechts;

void setup(){
//  motors=Motorcontrol();
  links= Sensormodule(0,1,2);
  rechts= Sensormodule(3,6,7);
  Serial.begin(9600);
}

void loop(){
  links.update();
  rechts.update();
  links.digitaliseerwaarden();
  rechts.digitaliseerwaarden();
  Serial.print("module links: ");
  links.print_waarden();
  delay(1000);
  Serial.print("module rechts: ");
  rechts.print_waarden();
  delay(1000);
  /*
  to do: main schrijven die motoren stuurt adhv
  de sensormodules
  1) update
  2) digitaliseerwaarden
  3) kieslijn
  4)stuur adhv de waarden
  */
/*
  links.update();
  links.digitaliseerwaarden();
  rechts.update();
  rechts.digitaliseerwaarden();
  rechts.kieslijn(links);
  if(links.getactief()==true){
    //sturing op basis van linkser sensor
    if(links.getlinkerwaarde()==0 && links.getmiddenwaarde()==1 && links.getrechterwaarde()==0){
      //rij rechtdoor
      motors.set_motor_speed(200,200,200,200);
      motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
    }
    else{
      if(links.getlinkerwaarde()==1 && links.getmiddenwaarde()==0 && links.getrechterwaarde()==0){
        // draai links

      }
      if(links.getlinkerwaarde()==0 && links.getmiddenwaarde()==0 && links.getrechterwaarde()==1){
        // draar rechts

      }
    }

  }
  else{
    //sturing op basis van rechter sensor
    if(rechts.getlinkerwaarde()==0 && rechts.getmiddenwaarde()==1 && rechts.getrechterwaarde()==0){
      //rij rechtdoor
      motors.set_motor_speed(200,200,200,200);
      motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
    }
    else{
      if(rechts.getlinkerwaarde()==1 && rechts.getmiddenwaarde()==0 && rechts.getrechterwaarde()==0){
        // draai links

      }
      if(rechts.getlinkerwaarde()==0 && rechts.getmiddenwaarde()==0 && rechts.getrechterwaarde()==1){
        // draar links

      }
    }
  }
*/
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



/*code voor sensoren:

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
  Serial.println();
  delay(1000);
}
*/
