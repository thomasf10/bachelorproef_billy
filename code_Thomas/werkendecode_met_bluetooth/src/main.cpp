#include <Arduino.h>
#include "Sensormodule.h"
#include <Wire.h>
#include "Motorcontrol.h"
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>


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

// aantal gebruikte parameters
#define updatetijd 100 //130
#define defaultmotorsnelheid 255 // 200
#define minimumsnelheid 20 //20
//#define draaisnelheid 150

//bluetooth
// [start] --> starten met rijden
// [stop] --> stoppen met rijden
// [P200] --> verander P waarde naar 200 of welk getal er achter komt
// idem voor I en D en S voor snelheid
SoftwareSerial Bluetooth(2,4);

// Variables gebruikt voor binnenkomende data
const byte maxDataLength = 7;
char receivedChars[7] ;
boolean newCommand = false;


//objecten declareren
const byte interruptPin = 2; //interruptPin voor bluetooth
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
LiquidCrystal_I2C lcd(0x27,16,2);   // initialize lcd
Sensormodule module;
int pidvalue;
Motorcontrol motors;
unsigned long lastmillis;
unsigned long currentmillis;
bool rechtdoor;
unsigned long beginloop;
bool actief;
int motorsnelheid;

void processCommand()
{
  int Kp=0;
  int Ki=0;
  int Kd=0;
  Serial.println("Ingave via App: ");
  Serial.println(receivedChars);
    if (strcmp ("stop",receivedChars) == 0)
    {
        actief = false;
        Serial.println("Gestopt met rijden: ");
        motors.set_motor_speed(0, 0, 0, 0);
    }

    else if (strcmp ("start",receivedChars) == 0)
    {
        actief = true;
        Serial.println("Start rijden: ");
        module.resetlasterror();
        module.resetovertimeerror();
        beginloop=millis();
    }

    else if (strcmp("P",atoi(&receivedChars[0])) == 0)
    {
        Kp= atoi(&receivedChars[1]); //char array omzetten na P123415.. naar integer
        Serial.print("P = ");
        Serial.println(Kp);
        Bluetooth.print("P = ");
        Bluetooth.println(Kp);
    }

   else if (strcmp("I",atoi(&receivedChars[0])) == 0)
    {
        Ki= atoi(&receivedChars[1]); //char array omzetten na D123415.. naar integer
        Serial.print("I = ");
        Serial.println(Ki);
        Bluetooth.print("I = ");
        Bluetooth.println(Ki);
    }

   else if (strcmp("D",atoi(&receivedChars[0])) == 0)
    {
        Kd= atoi(&receivedChars[1]); //char array omzetten na D123415.. naar integer
        Serial.print("D = ");
        Serial.println(Kd);
        Bluetooth.print("D = ");
        Bluetooth.println(Kd);
    }
  else if(strcmp("S",atoi(&receivedChars[0]))==0){
    motorsnelheid=atoi(&receivedChars[1]);
    Serial.print("snelheid: ");
    Serial.println(motorsnelheid);
    Bluetooth.print("D = ");
    Bluetooth.print(motorsnelheid);
  }
    module.set_pid_waarden(Kp, Ki, Kd);

    //print waarden naar lcd
    lcd.setCursor(0,0);
    lcd.print("P");
    lcd.setCursor(2,0);
    lcd.print(module.getKp());
    lcd.setCursor(5,0);
    lcd.print("I");
    lcd.setCursor(7,0);
    lcd.print(module.getKi());
    lcd.setCursor(11,0);
    lcd.print("D");
    lcd.setCursor(13,0);
    lcd.print(module.getKd());

    receivedChars[0] = '\0';
    newCommand = false;

}


// functie recvWithStartEndMarkers
// zie http://forum.arduino.cc/index.php?topic=288234.0

void recvWithStartEndMarkers()
{

     static boolean recvInProgress=false;
     static byte ndx=0;
     char startMarker='[';
     char endMarker=']';
     char rc;

     if(Bluetooth.available()>0){
          rc=Bluetooth.read();
          if(recvInProgress == true){
               if(rc!=endMarker){
                    receivedChars[ndx]=rc;
                    ndx++;
                    if(ndx>maxDataLength){ ndx=maxDataLength; }
               }
               else
               {
                     receivedChars[ndx]='\0'; // terminate the string
                     recvInProgress=false;
                     ndx=0;
                     newCommand=true;
               }
          }
          else if(rc == startMarker) { recvInProgress=true; }
     }
}

void setup(){
  // set snelheid
  motorsnelheid=defaultmotorsnelheid;

  //bluetooth
  Bluetooth.begin(9600);

  // actief
  actief=false;

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

  // begintijd loop
  beginloop=millis();

  //print waarden naar lcd
  lcd.setCursor(0,0);
  lcd.print("P");
  lcd.setCursor(2,0);
  lcd.print(module.getKp());
  lcd.setCursor(5,0);
  lcd.print("I");
  lcd.setCursor(7,0);
  lcd.print(module.getKi());
  lcd.setCursor(11,0);
  lcd.print("D");
  lcd.setCursor(13,0);
  lcd.print(module.getKd());

}


void loop(){
//Serial.println("toestand:  ");
//Serial.println(actief);

if(actief==false){
  // aan het comuniceren via bluetooth
  recvWithStartEndMarkers();  //checken of er nieuwe commando's worden ontvangen
  if(newCommand){processCommand();}   //als er een nieuw commando is doe iets
  Serial.println("in bluetooth loop");
}


else{
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
    if(pidvalue<0){
      //stuur naar rechts
      if(-pidvalue>255){
        //indien -pidavalue>255 dan max snelheid bereikt=>wielen in tegengestelde richting laten draaien
        if(-pidvalue>510){
          motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B01011010);
          rechtdoor=false;
          motors.set_motor_speed(255, 255, 255 ,  255);
        }
        else{
          motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B01011010);
          rechtdoor=false;
          motors.set_motor_speed(-pidvalue-255, -pidvalue-255, 255, 255);
        }

      }
      else if(motorsnelheid+pidvalue<minimumsnelheid){
        /*indien stuursignaal onder 0
        linker wielen ook versnellen, ipv enkel
        rechter wielen te vertragen
        */
          if(rechtdoor==false){
            motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
            rechtdoor=true;
          }
          motors.set_motor_speed(minimumsnelheid, minimumsnelheid, -pidvalue, -pidvalue);
      }
      else{
        //rechter wielen vertragen
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
          if(pidvalue>510){
            motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10100101);
            rechtdoor=false;
            motors.set_motor_speed(255, 255, 255, 255);
          }
          else{
            motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10100101);
            rechtdoor=false;
            motors.set_motor_speed(255, 255, pidvalue-255, pidvalue-255);
          }

        }
        else if(motorsnelheid-pidvalue<minimumsnelheid){
          /*indien stuursignaal onder minimumsnelheid
          rechter wielen ook versnellen, ipv enkel
          linker wielen te vertragen
          */
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
}
// RFID loop:
//Serial.println("looking for tag");
// stopknop checken
recvWithStartEndMarkers();
//Serial.println("looking for bluetoothhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh");  //checken of er nieuwe commando's worden ontvangen
if(newCommand){
  processCommand(); //als er een nieuw commando is doe iets
  return;
}
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

Serial.println("rfid gevonden");
unsigned long allesec=(millis()-beginloop)/1000;
int min= allesec/60;
int overigesec=allesec%60;

lcd.setCursor(0,1);
lcd.print("tijd:");
lcd.setCursor(5,1);
lcd.print(min);
lcd.setCursor(7,1);
lcd.print("min");
lcd.setCursor(11,1);
lcd.print(overigesec);
lcd.setCursor(13,1);
lcd.print("sec");


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
