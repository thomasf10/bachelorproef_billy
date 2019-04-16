//  Arduino, HM-10, App Inventor 2
// gevonden in volgende link: http://www.martyncurrey.com/arduino-hm-10-and-app-inventor-2/#part1
// gebruikte app om te testen: Serial Bluetooth Terminal
// om data te sturen type tussen [ en ]
// [start] --> starten met rijden
// [stop] --> stoppen met rijden
// [P] --> verander P waarde --> geef waarde erna in tussen vierkante haken
// idem voor I en D

//  BT VCC --> Arduino 5V out.
//  BT GND --> GND
//  Arduino D8 (ASS RX) - BT TX no need voltage divider
//  Arduino D9 (ASS TX) - BT RX through a voltage divider
//  Arduino D2 - Resistor + LED

#include <SoftwareSerial.h>
SoftwareSerial Bluetooth;

// Variables gebruikt voor binnenkomende data
const byte maxDataLength = 20;
char receivedChars[21] ;
boolean newCommand = false;
 
// general variables
bool rijden=true;
int getal;
int P=100;
int I=100;
int D=100;

void setup()  
{
    Serial.begin(9600);
    Serial.println(" ");
 
    Bluetooth.begin(9600); 
    Serial.println("AltSoftSerial started at 9600"); 
    Serial.println(" "); 
}
 
 
void loop()  
{
       recvWithStartEndMarkers();                //checken of er nieuwe commando's worden ontvangen
       if (newCommand)  {   processCommand();  }    //als er een nieuw commando is doe iets
}
 
void processCommand()
{
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

    else if(receivedChars){
      getal = receivedChars;
      Serial.print("Getal = ");
      Serial.println(getal);
      Bluetooth.print("Getal = ");
      Bluetooth.println(getal);
    }

    else if (strcmp("P",receivedChars) == 0)
    {
        P=getal;
        Serial.print("P = ");
        Serial.println(P);
        Bluetooth.print("P = ");
        Bluetooth.println(P);
        
    }
 
 
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
