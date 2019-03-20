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

//  Define PWN PINS
#define PWM_PIN_1 (3)
#define PWM_PIN_2 (5)
#define PWM_PIN_3 (6)
#define PWM_PIN_4 (9)

#define motorsnelheid 100
#define updatetijd 150
Motorcontrol motors;
Sensormodule links,rechts;
int pidvalue;
unsigned long lastmillis;
unsigned long currentmillis;
// set motorspeed

void setup(){

motors=Motorcontrol();
Wire.begin();

 // Setup Configuration IO expander (Motor Directions)
 motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_CONFIG, 0x00);

 // Setup Configuration IO expander (Additional Pins)
 motors.i2C_write_reg(I2C_ADDRESS_ADD_PINS, CMD_REG_CONFIG, 0x00);

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
  currentmillis=millis();
if(currentmillis>(lastmillis+updatetijd)){
lastmillis=currentmillis;
    //update en digitaliseer
    links.update();
    links.digitaliseerwaarden();
    rechts.update();
    rechts.digitaliseerwaarden();
// leds
if(links.getlinkerwaarde()==1 && links.getactief()==true){
    digitalWrite(2,HIGH);

  } else {
    digitalWrite(2,LOW);

  }

if(links.getmiddenwaarde()==1 && links.getactief()==true){
    digitalWrite(7,HIGH);

  }
  else {
    digitalWrite(7,LOW);

  }
if(links.getrechterwaarde()==1 && links.getactief()==true){
    digitalWrite(8,HIGH);

  }
  else {
    digitalWrite(8,LOW);

  }
if(rechts.getlinkerwaarde()==1 && rechts.getactief()==true){
    digitalWrite(11,HIGH);

  }
  else {
    digitalWrite(11,LOW);

  }
  if(rechts.getmiddenwaarde()==1 && rechts.getactief()==true){
    digitalWrite(12,HIGH);

  }
  else {
    digitalWrite(12,LOW);

  }
if(rechts.getrechterwaarde()==1 && rechts.getactief()==true){
    digitalWrite(13,HIGH);

  }
  else {
    digitalWrite(13,LOW);

  }
    //kies linker of rechter sensormodule om te sturen
    //links.kieslijn(rechts);

//sturing
  links.setactief(true);
  rechts.setactief(false);
    if(links.getactief()==true){
      //sturing op basis van linkser sensor
      pidvalue=links.calculatepid();
      Serial.println("links pid: ");
      Serial.println(pidvalue);
      if(pidvalue<0){
        //stuur naar rechts
        if(motorsnelheid+pidvalue<0){
          /*indien stuursignaal onder nul
          wielen in tegengestelde richting laten draaien
          voor scherpere bocht
          */
          motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B01011010);
          motors.set_motor_speed(motorsnelheid, motorsnelheid, motorsnelheid, motorsnelheid);
        }
        else{
      motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
      motors.set_motor_speed(motorsnelheid+pidvalue, motorsnelheid+pidvalue, motorsnelheid, motorsnelheid);

          }
        }
        else{

      if(pidvalue>0){
        //stuur naar links
        if(motorsnelheid-pidvalue<0){
          /*indien stuursignaal onder nul
          wielen in tegengestelde richting laten draaien
          voor scherpere bocht
          */
        /*tijdelijk weg
        motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10100101);
          motors.set_motor_speed(motorsnelheid, motorsnelheid, motorsnelheid, motorsnelheid);
          */
          //snelheid linker wielen ook opdrijven
          motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
          motors.set_motor_speed(motorsnelheid+(pidvalue/2), motorsnelheid+(pidvalue/2), motorsnelheid-(pidvalue/2), motorsnelheid-(pidvalue/2));
              }

        else{
      motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
      motors.set_motor_speed(motorsnelheid, motorsnelheid, motorsnelheid-pidvalue, motorsnelheid-pidvalue);
          }
        }
      else{
        //rij rechtdoor
        motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
        motors.set_motor_speed(motorsnelheid, motorsnelheid, motorsnelheid, motorsnelheid);
      }
    }
  }



    else{
      //sturing op basis van rechter sensor
      pidvalue=rechts.calculatepid();
      Serial.println("pid recht: ");
    Serial.println(pidvalue);
    if(pidvalue<0){
      //stuur naar rechts
      if(motorsnelheid+pidvalue<0){
        /*indien stuursignaal onder nul
        wielen in tegengestelde richting laten draaien
        voor scherpere bocht
        */
        /*
        wielen achteruit tijdelijk weg
        motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B01011010);
        motors.set_motor_speed(motorsnelheid, motorsnelheid, motorsnelheid, motorsnelheid);
        */
        //snelheid rechter wielen ook opdrijven
        motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
        motors.set_motor_speed(motorsnelheid+(pidvalue/2), motorsnelheid+(pidvalue/2), motorsnelheid-(pidvalue/2), motorsnelheid-(pidvalue/2));
      }
      else{
    motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
    motors.set_motor_speed(motorsnelheid+pidvalue, motorsnelheid+pidvalue, motorsnelheid, motorsnelheid);
        }
      }
      else{

    if(pidvalue>0){
      //stuur naar links
      if(motorsnelheid-pidvalue<0){
        /*indien stuursignaal onder nul
        wielen in tegengestelde richting laten draaien
        voor scherpere bocht
        */
        /*
        motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10100101);
        motors.set_motor_speed(motorsnelheid, motorsnelheid, motorsnelheid, motorsnelheid);
        */
        //snelheid linker wielen ook opdrijven
        motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
        motors.set_motor_speed(motorsnelheid+(pidvalue/2), motorsnelheid+(pidvalue/2), motorsnelheid-(pidvalue/2), motorsnelheid-(pidvalue/2));
      }else{
    motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
    motors.set_motor_speed(motorsnelheid, motorsnelheid, motorsnelheid-pidvalue, motorsnelheid-pidvalue);
        }
}
    else{
      //rij rechtdoor
      motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
      motors.set_motor_speed(motorsnelheid, motorsnelheid, motorsnelheid, motorsnelheid);
    }





      }
  }
}
}

  /*
code voor motoren:

void loop(){
  //set motor speed
  motors.motors.set_motor_speed(200, 200, 200, 200);
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
  motors.motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B01011010); //  Turn right
   delay(800);
  motors.motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B00000000); //  Wait
   delay(500);
  motors.motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010); //  Move forward
   delay(300);
  motors.motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B00000000); //  Wait
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
