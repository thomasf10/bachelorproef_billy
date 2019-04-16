#include <Arduino.h>
#include "Led.h"
#include "Sensormodule.h"
#include <Wire.h>
#include "Motorcontrol.h"
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
/*aansluiting RFID:
	SDA:D10
	SCK:D13
	MOSI:D11
	MISO:D12
	IRQ:unconnected
	GND:GND
	3.3V=3.3V
	RST=D8
*/
// pins RFID
#define SS_PIN 10
#define RST_PIN 8

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
#define motorsnelheid 200 // 200
#define D 20


//objecten declareren

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
LiquidCrystal_I2C lcd(0x27,16,2);   // initialize lcd
Sensormodule module;
int pidvalue;
int Vi;
Motorcontrol motors;
unsigned long lastmillis;
unsigned long currentmillis;
bool rechtdoor;
int Rg;
unsigned long beginloop;

void setup(){
    Rg=0;
    // set up lcd
    lcd.init();
    lcd.backlight();

  // RFID pin's (misschien niet nodig testen!)
    pinMode(11,OUTPUT); //MOSI
    pinMode(12,OUTPUT); //MISO
    pinMode(13,OUTPUT); //SCK
    pinMode(8,OUTPUT); //rst

  // Initiate  SPI bus
    SPI.begin();

  // Initiate MFRC522
      mfrc522.PCD_Init();

  // motorsturing
  motors=Motorcontrol();

  // i2c
  Wire.begin();

 // Setup Configuration IO expander (Motor Directions)
 motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_CONFIG, 0x00);

 // Setup Configuration IO expander (debug led's)
 motors.i2C_write_reg(I2C_ADDRESS_ADD_PINS, CMD_REG_CONFIG, 0x00);

 // set motor direction: forward
   motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
   rechtdoor=true;

 // sensormodules
  module=Sensormodule(0,1,2,3,6,7);

  // seriele monitor
  Serial.begin(9600);

  //begintijd loop
  beginloop=millis();

}


void loop(){

  // timing:
  currentmillis=millis();
  if(currentmillis>(lastmillis+updatetijd)){
    lastmillis=currentmillis;

  // update
    module.update();

  // LED's:
  motors.i2C_write_reg(I2C_ADDRESS_ADD_PINS, CMD_REG_OUTPUT, module.getwaarden());

  // sturing:
  Serial.println("sensorwaarden: ");
  module.print_waarden();
  pidvalue=module.calculatepid();
  Serial.println("pid: ");
  Serial.println(pidvalue);
  /*
Vi=Vo * (R-(d/2))/(R+(d/2))
Vi= snelheid wiel aan binnekant bocht
Vo= snelheid wiel buitenkant bocht = motorsnelheid
R= gewenste draaistraal; hoe kleiner R hoe scherper de bocht
D= afstand tussen de twee wielen
  */
  if(pidvalue<0){
    //stuur naar rechts
    Rg=-motorsnelheid/pidvalue; // bereken draaistraal
    Vi=motorsnelheid*(Rg-(D/2))/(Rg+(D/2)); // Bereken snelheid binnenste wielen
    Serial.print("vi: ");
    Serial.println(Vi);
    //misschien nog moeten casten naar een byte want komma getallen zijn mogelijk.
    if(Vi>=0){
      // wielen draaien in gelijke richting
      if(rechtdoor==false){
        motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
        rechtdoor=true;
      }
      motors.set_motor_speed(Vi,Vi,motorsnelheid,motorsnelheid);
    }
    else{
      //Vi<0 => wielen draaien in tegengestelde richting
      motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B01011010);
      rechtdoor=false;
      motors.set_motor_speed(-Vi,-Vi,motorsnelheid, motorsnelheid);
    }
  }
  else if(pidvalue>0){
    // stuur naar links
    Rg=motorsnelheid/pidvalue; // bereken draaistraal
    Vi=motorsnelheid*(Rg-(D/2))/(Rg+(D/2)); // Bereken snelheid binnesnste wielen
    if(Vi>=0){
      // wielen draaien in gelijke richting
      if(rechtdoor==false){
        motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS,CMD_REG_OUTPUT,B10101010);
        rechtdoor=true;
      }
      motors.set_motor_speed(motorsnelheid, motorsnelheid, Vi, Vi);
    }
    else{
      //Vi<0 => wielen draaien in tegengestelde richting
      motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS,CMD_REG_OUTPUT,B10100101);
      rechtdoor=false;
      motors.set_motor_speed(motorsnelheid,motorsnelheid,-Vi,-Vi);
    }
  }
  else{
    // PIDvalue=0 => rij rechtdoor
    if(rechtdoor==false){
      motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
      rechtdoor=true;
    }
    motors.set_motor_speed(motorsnelheid, motorsnelheid, motorsnelheid, motorsnelheid);
  }
}
// RFID loop:
Serial.println("looking for tag");

// Look for new cards
if ( ! mfrc522.PICC_IsNewCardPresent())
{
  return;
}
// Select one of the cards
if ( ! mfrc522.PICC_ReadCardSerial())
{
  return;
}
// naar seriele monitor
Serial.println("rfid gevonden");

// naar lcd
unsigned long allesec=(millis()-beginloop)/1000;
int min= allesec/60;
int overigesec=allesec%60;
lcd.clear();// duurt 2 ms
lcd.setCursor(0,0);
lcd.print("tijd:");
lcd.setCursor(0,1);
lcd.print(min);
lcd.setCursor(2,1);
lcd.print("min");
lcd.setCursor(6,1);
lcd.print(overigesec);
lcd.setCursor(9,1);
lcd.print("sec");


}
/*to do:
if(content.substring(1)=="......."){
Serial.println("checkpoint 2");
schrijf tijd naar lcd
}
*/





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
