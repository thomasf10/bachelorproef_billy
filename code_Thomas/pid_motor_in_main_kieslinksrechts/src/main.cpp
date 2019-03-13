#include <Arduino.h>
#include "Led.h"
#include "Sensormodule.h"
#include <Wire.h>

//  Two IO EXPANDERS I2C addresses
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

Sensormodule links,rechts;
int pidvalue;
// set motorspeed
void set_motor_speed(uint8_t speed_m1, uint8_t speed_m2, uint8_t speed_m3, uint8_t speed_m4){
  analogWrite(PWM_PIN_1, speed_m1);
  analogWrite(PWM_PIN_2, speed_m2);
  analogWrite(PWM_PIN_3, speed_m3);
  analogWrite(PWM_PIN_4, speed_m4);
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
void i2C_write_reg(uint8_t address, uint8_t reg, uint8_t instruction){
  Wire.beginTransmission(address);
  Wire.write(reg);
  Wire.write(instruction);
  Wire.endTransmission();
}



void setup(){
//  motors=Motorcontrol();
Wire.begin();

 // Setup Configuration IO expander (Motor Directions)
 i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_CONFIG, 0x00);

 // Setup Configuration IO expander (Additional Pins)
 i2C_write_reg(I2C_ADDRESS_ADD_PINS, CMD_REG_CONFIG, 0x00);

 // PinMode PWM pinnen speed Motors
 pinMode(PWM_PIN_1, OUTPUT);
 pinMode(PWM_PIN_2, OUTPUT);
 pinMode(PWM_PIN_3, OUTPUT);
 pinMode(PWM_PIN_4, OUTPUT);

 //sensormodules
  links= Sensormodule(0,1,2);
  rechts= Sensormodule(3,6,7);

  Serial.begin(9600);
}

void loop(){
    //update en digitaliseer
    links.update();
    links.digitaliseerwaarden();
    rechts.update();
    rechts.digitaliseerwaarden();

    //kies linker of rechter sensormodule om te sturen
    links.kieslijn(rechts);

//sturing
    if(links.getactief()==true){
      //sturing op basis van linkser sensor
      pidvalue=links.calculatepid();
      if(pidvalue<0){
        //stuur naar rechts
      i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B01011010);
      set_motor_speed(200+pidvalue, 200+pidvalue, 200, 200);
        }

      if(pidvalue>0){
        //stuur naar links
      i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10100101);
      set_motor_speed(200, 200, 200-pidvalue, 200-pidvalue);
          }

      else{
        //rij rechtdoor
        i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
        set_motor_speed(100, 100, 100, 100);
      }
    }

    else{
      //sturing op basis van rechter sensor
      pidvalue=rechts.calculatepid();
      if(pidvalue<0){
        //stuur naar rechts
      i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B01011010); // misschien enkel wielen sneller laten draaien en niet wielen in andere richting, nog testen!
      set_motor_speed(200+pidvalue, 200+pidvalue, 200, 200);
        }
      else{
        //stuur naar links
      i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10100101);
      set_motor_speed(200, 200, 200-pidvalue, 200-pidvalue);
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
