#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <MFRC522.h>
#include "Motorcontrol.h"
#include "Sensormodule.h"
//  Two IO EXPANDERS I2C addresses
#define I2C_ADDRESS_DIR_MOTORS    0x38
#define I2C_ADDRESS_ADD_PINS      0x39

//  Command Bytes -- Send to control register in the TCA9554
#define CMD_REG_INPUT   0x00
#define CMD_REG_OUTPUT  0x01
#define CMD_REG_POL_INV 0x02
#define CMD_REG_CONFIG  0x03

// constants
#define updatetijd 100
#define motorspeed 200// 200
#define minspeed 20
#define turnspeed 150
#define maxcounter 200 //=> ongeveer om de 90 milliseconden wordt het gemiddelde berekend

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

// Declare objects:
Sensormodule module;
int pidvalue;
Motorcontrol motors;
bool forward,calculateaverage,completeupdate;
int counter;
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

void setup() {
//  SPI.begin();      // Initiate  SPI bus
//  mfrc522.PCD_Init();   // Initiate MFRC522

  //control leds

  //leds kunnen niet teglijk werken met rfid
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(1,OUTPUT);

  //initialize objects:
  completeupdate=0;
  counter=0;
  calculateaverage=0;

  //Motorcontrol
  motors=Motorcontrol();

  //i2c
  Wire.begin();

  // Setup Configuration IO expander (Motor Directions)
  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_CONFIG, 0x00);

  // Setup Configuration IO expander (Additional Pins)
  motors.i2C_write_reg(I2C_ADDRESS_ADD_PINS, CMD_REG_CONFIG, 0x00);

  // Set motordirection forward
  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
  forward=true;

  //sensormodules
  module=Sensormodule(0,1,2,3,6,7);

  // start Serial monitor:

    Serial.begin(9600);

  // Set up timer interrupt:
/*
    // disable interrupts
    cli();
    //set timer1 interrupt at 66.67 Hz => T=15ms
    TCCR1A = 0; // set entire TCCR1A register to 0
    TCCR1B = 0; // same for TCCR1B
    TCNT1  = 0; //initialize counter value to 0
    // OCR1A = (fclk / (finterrupt * prescaler)) - 1 (must be <65536)
    OCR1A=30000;
    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    // set CS11 bit for /8 prescaler
    TCCR1B |= (1 << CS11);
    // enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);
*/
  // Set up ADC:

    // clear ADLAR in ADMUX (0x7C) to right-adjust the result
    // ADCL will contain lower 8 bits, ADCH upper 2 (in last two bits)
    ADMUX &= B11011111;
    // Set REFS1..0 in ADMUX (0x7C) to change reference voltage to the
    // proper source (01)
    ADMUX |=1<<REFS0;
    // Clear MUX3..0 in ADMUX (0x7C) in preparation for setting the analog
    // input
    ADMUX &= B11110000;
    // Set MUX3..0 in ADMUX (0x7C) to read from AD0
    ADMUX |= 0;
    // Set ADEN in ADCSRA to enable the ADC.
    ADCSRA |= 1<<ADEN;
    // Set the Prescaler to 128 (16000KHz/128 = 125KHz)
    ADCSRA |= B00000111;
    // Set ADIE in ADCSRA (0x7A) to enable the ADC interrupt.
    ADCSRA |= 1<<ADIE;
    // Enable global interrupts
    sei();
    // Set ADSC in ADCSRA (0x7A) to start the ADC conversion
    ADCSRA |=1<<ADSC;
}

void loop() {
if(calculateaverage==1){
  //ADC read all inputs maxcounter times:
  Serial.print("tijd: ");
  Serial.println(micros());
  counter=0;
  calculateaverage=0;
  module.update(maxcounter);
  module.clearsum();

  //start next conversion
  ADCSRA |=1<<ADSC;

  module.print_values();
  module.updateleds();
  pidvalue=module.calculatepid();
  Serial.println(pidvalue);
 // control motor with calculated pid value:

  if(pidvalue<0){
            //turn right
            if(-pidvalue>255){
                  //if pidvalue>255 wheels spin in opposite directions
                motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10100101);
                forward=false;
                motors.set_motor_speed(turnspeed, turnspeed, turnspeed, turnspeed);
            }
            else if(motorspeed+pidvalue<minspeed){
              /*indien stuursignaal onder minspeed
                linker wielen ook versnellen, ipv enkel
                rechter wielen te vertragen
              */
              //motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
                if(forward==false){
                  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
                  forward=true;
                }
              motors.set_motor_speed(minspeed, minspeed, -pidvalue, -pidvalue);
            }
            else{
              //rechter wielen vertragen
          //motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
              if(forward==false){
                motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
                forward=true;
              }
          motors.set_motor_speed(motorspeed+pidvalue, motorspeed+pidvalue, motorspeed, motorspeed);
            }
  }
  else if(pidvalue>0){
            //stuur naar links
            if(pidvalue>255){
              //if pidvalue<255 wheels spin in opposite directions
                motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B01011010);
                forward=false;
                motors.set_motor_speed(turnspeed, turnspeed, turnspeed, turnspeed);
            }
            else if(motorspeed-pidvalue<minspeed){
              /*indien stuursignaal onder minspeed
              rechter wielen ook versnellen, ipv enkel
              linker wielen te vertragen
              */
            //  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
              if(forward==false){
                motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
                forward=true;
              }

              motors.set_motor_speed(pidvalue, pidvalue, minspeed , minspeed);
            }
            else{
          //motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
              if(forward==false){
                motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
                forward=true;
              }

          motors.set_motor_speed(motorspeed, motorspeed, motorspeed-pidvalue, motorspeed-pidvalue);
            }
    }
    else{
            //rij forward
          //  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
          if(forward==false){
            motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
            forward=true;
          }
            motors.set_motor_speed(motorspeed, motorspeed, motorspeed, motorspeed);
          }


}

    //ADC is still reading inputs:
    //RFID code
/*
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
if (content.substring(1) == "83 37 ED A4") //change here the UID of the card/cards that you want to give access
{
  Serial.println("checkpoint 1");
  //to do
  //schrijf naar lcd via io expander

  Serial.println();

}
//to do:
//if(content.substring(1)=="......."){
//Serial.println("checkpoint 2");
//schrijf tijd naar lcd
//}

else{
  Serial.println(" Access denied");

}
*/


}

//ISR if adc conversion is finnished:

ISR(ADC_vect){

  // Must read low first
  int analogVal = ADCL | (ADCH << 8);

  switch (ADMUX) {
    case 0x40:
    // pin A0
      module.updatesumL1(analogVal);
      // set next pin A1
      ADMUX=0x41;
      //start next conversion
      ADCSRA |=1<<ADSC;
      break;
    case 0x41:
    // pin A1
      module.updatesumL2(analogVal);
      // set next pin A2
      ADMUX=0x42;
      //start next conversion
      ADCSRA |=1<<ADSC;
      break;
    case 0x42:
    // pin A2
      module.updatesumL3(analogVal);
      // set next pin A3
      ADMUX=0x43;
      //start next conversion
      ADCSRA |=1<<ADSC;
      break;
    case 0x43:
    // pin A3
      module.updatesumR1(analogVal);
      // set next pin A6
      ADMUX=0x46;
      //start next conversion
      ADCSRA |=1<<ADSC;
      break;
    case 0x46:
    // pin A6
      module.updatesumR2(analogVal);
      // set next pin A7
      ADMUX=0x47;
      //start next conversion
      ADCSRA |=1<<ADSC;
      break;
    case 0x47:
    // pin A7
      module.updatesumR3(analogVal);
      // set next pin A0
      ADMUX=0x40;
      if(counter<maxcounter){
      //start next conversion
      ADCSRA |=1<<ADSC;
      counter++;
    }
    else{
      calculateaverage=1;
    }
      break;
    default:
      break;
  }



}

// ISR for timer:

/*ISR(TIMER1_COMPA_vect){
  if(completeupdate==1){
  if(counter<maxcounter){
    completeupdate=0;
    counter++;
    //start next conversion
    ADCSRA |=1<<ADSC;
    }
  else{
    calculateaverage=1;
    counter=0;
    completeupdate=0;
    }
  }
  else{
    Serial.println("timing error");
  }
}*/
