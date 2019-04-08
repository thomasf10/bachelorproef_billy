//  Arduino, HM-10, App Inventor 2
// gevonden in volgende link: http://www.martyncurrey.com/arduino-hm-10-and-app-inventor-2/#part1
//  Example Project Part 1: Turn an LED on and off basic
// gebruikte app om te testen: Serial Bluetooth Terminal
// Zend 0 voor led uit , 1 voor led aan
//
//  BT VCC --> Arduino 5V out. 
//  BT GND --> GND
//  Arduino D8 (ASS RX) - BT TX no need voltage divider 
//  Arduino D9 (ASS TX) - BT RX through a voltage divider
//  Arduino D2 - Resistor + LED
 
#include <AltSoftSerial.h>
AltSoftSerial ASSserial; 
 
byte LEDPin = 2;
char c=' ';
 
 
void setup() 
{
    Serial.begin(9600); 
    ASSserial.begin(9600);  
    Serial.println("Connectie gemaakt");
    ASSserial.println("Connectie gemaakt");
    Serial.println(" ");
    Serial.println("Zend 0 voor LED uit, 1 voor LED aan");
    ASSserial.println("Zend 0 voor LED uit, 1 voor LED aan");
    pinMode(LEDPin, OUTPUT); 
 
}
 
void loop()
{
     // Leest bluetooth module en zet led aan of uit
    if (ASSserial.available())
    {
        c = ASSserial.read();
        Serial.println(c);
 
        // De ascii code voor 0 is dec 48
        // De ascii code voor 1 is dec 49
        if ( c== 48) { digitalWrite(LEDPin, LOW); }
        if ( c== 49) { digitalWrite(LEDPin, HIGH); }
    }
}
