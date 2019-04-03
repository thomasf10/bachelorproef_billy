#include <Arduino.h>
#include "Led.h"
#include "Sensormodule.h"
#include <Wire.h>
#include "Motorcontrol.h"
#include <SPI.h>
#include <MFRC522.h>
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
#define minimumsnelheid 20
#define draaisnelheid 150


//objecten declareren

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

Sensormodule module;
int pidvalue;
Motorcontrol motors;
unsigned long lastmillis;
unsigned long currentmillis;
bool rechtdoor;
//bool ledon;

void setup(){
  //ledon=false;
  //controle leds
    pinMode(11,OUTPUT); //R1
    pinMode(12,OUTPUT); //R2
    pinMode(13,OUTPUT); //R3
    pinMode(8,OUTPUT); //L3
    pinMode(7,OUTPUT); //L2
    pinMode(2,OUTPUT); //L1
  // Initiate  SPI bus
    SPI.begin();
  // Initiate MFRC522
      mfrc522.PCD_Init();
  //motorsturing
  motors=Motorcontrol();

  //i2c
  Wire.begin();

 // Setup Configuration IO expander (Motor Directions)
 motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_CONFIG, 0x00);

 // Setup Configuration IO expander (Additional Pins)
 motors.i2C_write_reg(I2C_ADDRESS_ADD_PINS, CMD_REG_CONFIG, 0x00);

 //wielen vooruit laten rijden
   motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
   rechtdoor=true;

 //sensormodules
  module=Sensormodule(0,1,2,3,6,7);

// seriele monitor
  Serial.begin(9600);

}


void loop(){

  //timing:
  currentmillis=millis();
  if(currentmillis>(lastmillis+updatetijd)){
    lastmillis=currentmillis;

  //update
    module.update();

   //LED's:
  // module.updateleds();
  motors.i2C_write_reg(I2C_ADDRESS_ADD_PINS, CMD_REG_OUTPUT, module.getwaarden());
<<<<<<< HEAD

=======
>>>>>>> ce17075fb7230543a3786b0d33e678426b781b1b
  //sturing
  Serial.println("sensorwaarden: ");
  module.print_waarden();
      pidvalue=module.calculatepid();
      Serial.println("pid: ");
      Serial.println(pidvalue);
      if(pidvalue<0){
              //stuur naar rechts
              if(-pidvalue>255){
                    //TO DO: indien -pidavalue>255 dan max snelheid bereikt=>wielen in tegengestelde richting laten draaien
                  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B01011010);
                  rechtdoor=false;
                  motors.set_motor_speed(draaisnelheid, draaisnelheid, draaisnelheid, draaisnelheid);
              }
              else if(motorsnelheid+pidvalue<minimumsnelheid){
                /*indien stuursignaal onder minimumsnelheid
                  linker wielen ook versnellen, ipv enkel
                  rechter wielen te vertragen
                */
                //motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
                if(rechtdoor==false){
                  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
                  rechtdoor=true;
                }
                motors.set_motor_speed(minimumsnelheid, minimumsnelheid, -pidvalue, -pidvalue);
              }
              else{
                //rechter wielen vertragen
            //motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
            if(rechtdoor==false){
              motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
              rechtdoor=true;
            }
            motors.set_motor_speed(motorsnelheid+pidvalue, motorsnelheid+pidvalue, motorsnelheid, motorsnelheid);
                }
              }
        else if(pidvalue>0){
              //stuur naar links
              if(pidvalue>255){
                    //TO DO: indien -pidavalue>255 dan max snelheid bereikt=>wielen in tegengestelde richting laten draaien
                  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10100101);
                  rechtdoor=false;
                  motors.set_motor_speed(draaisnelheid, draaisnelheid, draaisnelheid, draaisnelheid);
              }
              else if(motorsnelheid-pidvalue<minimumsnelheid){
                /*indien stuursignaal onder minimumsnelheid
                rechter wielen ook versnellen, ipv enkel
                linker wielen te vertragen
                */
              //  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
              if(rechtdoor==false){
                motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
                rechtdoor=true;
              }

                motors.set_motor_speed(pidvalue, pidvalue, minimumsnelheid , minimumsnelheid);
              }
              else{
            //motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
            if(rechtdoor==false){
              motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
              rechtdoor=true;
            }

            motors.set_motor_speed(motorsnelheid, motorsnelheid, motorsnelheid-pidvalue, motorsnelheid-pidvalue);
                }
            }

        else{
              //rij rechtdoor
            //  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
            if(rechtdoor==false){
              motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
              rechtdoor=true;
            }
              motors.set_motor_speed(motorsnelheid, motorsnelheid, motorsnelheid, motorsnelheid);
            }

            //RFID loop
          }
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

//Show UID on serial monitor
Serial.print("UID tag :");
String content= "";
byte letter;
for (byte i = 0; i < mfrc522.uid.size; i++)
{
   Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
   Serial.print(mfrc522.uid.uidByte[i], HEX);
   content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
   content.concat(String(mfrc522.uid.uidByte[i], HEX));
}
Serial.println();
Serial.print("Message : ");
content.toUpperCase();
if (content.substring(1) == "E4 11 F9 1F") //change here the UID of the card/cards that you want to give access
{
  Serial.println("checkpoint 1");
  /*to do
    schrijf naar lcd
  */
Serial.println("rfid gevonden");


}
/*to do:
if(content.substring(1)=="......."){
Serial.println("checkpoint 2");
schrijf tijd naar lcd
}
*/



else {
  Serial.println(" Access denied");

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
