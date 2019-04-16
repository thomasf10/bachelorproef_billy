//  Arduino, HM-10, App Inventor 2
// gevonden in volgende link: http://www.martyncurrey.com/arduino-hm-10-and-app-inventor-2/#part1
// gebruikte app om te testen: Serial Bluetooth Terminal
// om data te sturen type tussen [ en ]
// [start] --> starten met rijden
// [stop] --> stoppen met rijden
// [P200] --> verander P waarde naar 200 of welk getal er achter komt
// idem voor I en D
// P I en D worden weggeschrevn in EEPROM

//  BT VCC --> Arduino 5V out.
//  BT GND --> GND
//  Arduino D8 (ASS RX) - BT TX no need voltage divider
//  Arduino D9 (ASS TX) - BT RX through a voltage divider
//  Arduino D2 - Resistor + LED

#include <AltSoftSerial.h>
#include <EEPROM.h>
#include "writeAnything.h"

AltSoftSerial Bluetooth;

// Variables gebruikt voor binnenkomende data
const byte maxDataLength = 7;
char receivedChars[7] ;
boolean newCommand = false;
 
// general variables
bool rijden=true;

struct param_t
{
  int P;
  int I;
  int D;
} params;

void setup()  
{
    Serial.begin(9600);
    Serial.println(" ");
 
    Bluetooth.begin(9600); 
    Serial.println("AltSoftSerial started at 9600"); 
    Serial.println("Connectie gemaakt via Bluetooth");
    Serial.println(" ");

    EEPROM_readAnything(0,params); //parameters in EEPROM uitlezen
    Serial.print("P = ");
    Serial.println(params.P);
    Serial.print("I = ");
    Serial.println(params.I);
    Serial.print("D = ");
    Serial.println(params.D);
    Bluetooth.println("\n");
    Bluetooth.println(params.P);
    Bluetooth.println(params.I);
    Bluetooth.println(params.D);
}
 
 
void loop()  
{
       recvWithStartEndMarkers();                //checken of er nieuwe commando's worden ontvangen
       if (newCommand)  {   processCommand();  }    //als er een nieuw commando is doe iets
}
 
void processCommand()
{
  Serial.print("Ingave via App: ");
  Serial.println(receivedChars);
    if (strcmp ("stop",receivedChars) == 0) 
    {
        rijden = false;
        Serial.println("Gestopt met rijden: ");
        Serial.println(rijden); 
    }
 
    else if (strcmp ("start",receivedChars) == 0)
    {
        rijden = true;
        Serial.println("Start rijden: ");
        Serial.println(rijden);
    }

    else if (strcmp("P",atoi(&receivedChars[0])) == 0)
    {
        params.P= atoi(&receivedChars[1]); //char array omzetten na P123415.. naar integer
        Serial.print("P = ");
        Serial.println(params.P);
        Bluetooth.print("P = ");
        Bluetooth.println(params.P);
        
    }
   
   else if (strcmp("I",atoi(&receivedChars[0])) == 0)
    {
        params.I= atoi(&receivedChars[1]); //char array omzetten na D123415.. naar integer
        Serial.print("I = ");
        Serial.println(params.I);
        Bluetooth.print("I = ");
        Bluetooth.println(params.I);
        
    }
    
   else if (strcmp("D",atoi(&receivedChars[0])) == 0)
    {
        params.D= atoi(&receivedChars[1]); //char array omzetten na D123415.. naar integer
        Serial.print("D = ");
        Serial.println(params.D);
        Bluetooth.print("D = ");
        Bluetooth.println(params.D);
        
    }
    EEPROM_writeAnything(0, params); //waardes opslaan in EEPROM
    receivedChars[0] = '\0';
    newCommand = false;
 
}
 
 
// functie recvWithStartEndMarkers
// zie http://forum.arduino.cc/index.php?topic=288234.0

void recvWithStartEndMarkers()
{
     static boolean recvInProgress = false;
     static byte ndx = 0;
     char startMarker = '[';
     char endMarker = ']';
     char rc;
 
     if (Bluetooth.available() > 0) 
     {
          rc = Bluetooth.read();
          if (recvInProgress == true) 
          {
               if (rc != endMarker) 
               {
                    receivedChars[ndx] = rc;
                    ndx++;
                    if (ndx > maxDataLength) { ndx = maxDataLength; }
               }
               else 
               {
                     receivedChars[ndx] = '\0'; // terminate the string
                     recvInProgress = false;
                     ndx = 0;
                     newCommand = true;
               }
          }
          else if (rc == startMarker) { recvInProgress = true; }
     }
}
