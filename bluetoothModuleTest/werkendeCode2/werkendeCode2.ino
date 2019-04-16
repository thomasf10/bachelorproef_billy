
//  Arduino, HM-10, App Inventor 2
// gevonden in volgende link: http://www.martyncurrey.com/arduino-hm-10-and-app-inventor-2/#part1
// gebruikte app om te testen: Serial Bluetooth Terminal
// Zend 0 voor led uit , 1 voor led aan
//
//  BT VCC --> Arduino 5V out.
//  BT GND --> GND
//  Arduino D8 (ASS RX) - BT TX no need voltage divider
//  Arduino D9 (ASS TX) - BT RX through a voltage divider
//  Arduino D2 - Resistor + LED

#include <AltSoftSerial.h>
AltSoftSerial Bluetooth;

byte LEDPin = 2;
char c=' ';
int P=100;
int I=100;
int D=100;

void setup()
{
    Serial.begin(9600);
    Bluetooth.begin(9600);
    Serial.println("Connectie gemaakt");
    Bluetooth.println("Connectie gemaakt");
    Serial.println(" ");
    Serial.println("Zend 0 voor LED uit, 1 voor LED aan");
    Bluetooth.println("Zend 0 voor LED uit, 1 voor LED aan");
    pinMode(LEDPin, OUTPUT);

}
// werkt nog niet , nog mee bezig , probleem met inlezen van p enzo
void loop()
{
     // Leest bluetooth module en zet led aan of uit
    if (Bluetooth.available())
    {
        c = Bluetooth.read();
        switch(c){
          case '0': 
            digitalWrite(LEDPin, LOW);
            break;
          case '1':
            digitalWrite(LEDPin, HIGH);
            break;
          case '2':
            Bluetooth.println("Geef een nieuwe waarde in voor P: ");
            P=Bluetooth.read();
            Serial.print("Nieuwe waarde voor P: ");
            Serial.println(P);
            break;
          //default:
            //Bluetooth.println("Ongeldige invoer");
        }
        //nog iets toevoegen als iets anders wordt ingegeven
    }
}
