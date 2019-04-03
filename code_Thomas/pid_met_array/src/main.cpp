#include <Arduino.h>
#include "Led.h"
#include "Sensormodule.h"
#include <Wire.h>
#include "Motorcontrol.h"
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>

//gebruikte pinnen voor lcd
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE); //0x27 werkt niet per se, ander adres proberen in dat geval (0x3F)

//  Two IO EXPANDERS I2C addresses
#define I2C_ADDRESS_DIR_MOTORS    0x38
#define I2C_ADDRESS_ADD_PINS      0x39

//  Command Bytes -- Send to control register in the TCA9554
#define CMD_REG_INPUT   0x00
#define CMD_REG_OUTPUT  0x01
#define CMD_REG_POL_INV 0x02
#define CMD_REG_CONFIG  0x03

//aantal tijd tussen update sensoren in milliseconden
#define updatetijd 1000
#define motorsnelheid 100

//objecten declareren
Sensormodule module;
int pidvalue;
Motorcontrol motors;
unsigned long lastmillis;
unsigned long currentmillis;
unsigned long currentmillisclock;
unsigned long elapsedtime;
unsigned long lastmillisclock;
int seconds = 0;
int minutes = 0;

void setup(){

  lcd.begin(16,2);
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home();


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

void setClock(){
  currentmillisclock = millis();
  elapsedtime += elapsedtime - lastmillisclock;

  if(elapsedtime>999){
    seconds++;
    elapsedtime = elapsedtime - 1000;
  }

  if(seconds == 60){
    minutes++;
    seconds = 0;
  }

  lastmillisclock = currentmillisclock;
}

void loop(){

  setClock();

  lcd.setCursor(0,1);
  lcd.print("min sec");
  lcd.setCursor(0,0);
  lcd.print(" ");
  lcd.print(minutes);
  lcd.print(":");
  lcd.print(seconds);
  lcd.print(" ");

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
          motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10100101);
          motors.set_motor_speed(motorsnelheid, motorsnelheid, motorsnelheid, motorsnelheid);
        }
      motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
      motors.set_motor_speed(motorsnelheid, motorsnelheid, motorsnelheid-pidvalue, motorsnelheid-pidvalue);
          }

      else{
        //rij rechtdoor
        motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
        motors.set_motor_speed(motorsnelheid, motorsnelheid, motorsnelheid, motorsnelheid);
      }
    }
    }
      //RFID loop


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
