#include <Arduino.h>
#include "Led.h"
#include "Sensormodule.h"
#include "Motorcontrol.h"
#include <Wire.h>

//  Two IO EXPANDERS I2C addresses
#define I2C_ADDRESS_DIR_MOTORS    0x38
#define I2C_ADDRESS_ADD_PINS      0x39

//  Command Bytes -- Send to control register in the TCA9554
#define CMD_REG_INPUT   0x00
#define CMD_REG_OUTPUT  0x01
#define CMD_REG_POL_INV 0x02
#define CMD_REG_CONFIG  0x03
int pidvalue;
Motorcontrol motors;
Sensormodule links,rechts;

void setup(){
  Wire.begin();
  motors=Motorcontrol();
// Setup Configuration IO expander (Motor Directions)
  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_CONFIG, 0x00);
 // Setup Configuration IO expander (Additional Pins)
  motors.i2C_write_reg(I2C_ADDRESS_ADD_PINS, CMD_REG_CONFIG, 0x00);
  Serial.begin(9600);
  links= Sensormodule(0,1,2);
  rechts= Sensormodule(3,6,7);
}

void loop(){
  /*
  to do: main schrijven die motoren stuurt adhv
  de sensormodules
  1) update
  2) digitaliseerwaarden
  3) kieslijn
  4)stuur adhv de waarden
  */
Serial.println("in loop");
  links.update();
  links.digitaliseerwaarden();
  rechts.update();
  rechts.digitaliseerwaarden();
  Serial.println("na update sensoren");
  rechts.kieslijn(links);
 Serial.println("links actief: ");
 Serial.println(links.getactief());
Serial.println("rechts actief: ");
Serial.println(rechts.getactief());
  if(links.getactief()==true){
    //sturing op basis van linkser sensor
    pidvalue=links.calculatepid();
    if(pidvalue<0){
      //stuur naar rechts
    motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B01011010);
    motors.set_motor_speed(200+pidvalue, 200+pidvalue, 200, 200);
      }
    else{

    motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10100101);
    motors.set_motor_speed(200, 200, 200-pidvalue, 200-pidvalue);
        }
    }



  else{
    //sturing op basis van rechter sensor
    pidvalue=rechts.calculatepid();
    if(pidvalue<0){
      //stuur naar rechts
    motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B01011010);
    motors.set_motor_speed(200+pidvalue, 200+pidvalue, 200, 200);
      }
    else{

    motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10100101);
    motors.set_motor_speed(200, 200, 200-pidvalue, 200-pidvalue);
        }
    }
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
