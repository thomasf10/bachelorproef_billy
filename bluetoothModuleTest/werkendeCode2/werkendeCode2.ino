
//  Arduino, HM-10, App Inventor 2
// gevonden in volgende link: http://www.martyncurrey.com/arduino-hm-10-and-app-inventor-2/#part1
// gebruikte app om te testen: Serial Bluetooth Terminal
// om data te sturen type tussen [ en ]
// [start] --> starten met rijden
// [stop] --> stoppen met rijden
// [P] --> verander P waarde --> geef waarde erna in tussen vierkante haken
// idem voor I en D
// P I en D worden weggeschrevn in EPROM

//  BT VCC --> Arduino 5V out.
//  BT GND --> GND
//  Arduino D8 (ASS RX) - BT TX no need voltage divider
//  Arduino D9 (ASS TX) - BT RX through a voltage divider
//  Arduino D2 - Resistor + LED

#include <AltSoftSerial.h>
AltSoftSerial Bluetooth;

// Variables gebruikt voor binnenkomende data
const byte maxDataLength = 7;
char receivedChars[7] ;
boolean newCommand = false;
 
// general variables
bool rijden=true;
int P;
int I;
int D;

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

    else if (strcmp('P',receivedChars[0]) == 0)
    {
        P= atoi(&receivedChars[1]); //char array omzetten na P123415.. naar integer
        Serial.print("P = ");
        Serial.println(P);
        Bluetooth.print("P = ");
        Bluetooth.println(P);
        
    }
    
   else if (strcmp('I',receivedChars[0]) == 0)
    {
        I= atoi(&receivedChars[1]); //char array omzetten na I123415.. naar integer
        Serial.print("I = ");
        Serial.println(I);
        Bluetooth.print("I = ");
        Bluetooth.println(I);
        
    }
    
   else if (strcmp('D',receivedChars[0]) == 0)
    {
        D= atoi(&receivedChars[1]); //char array omzetten na D123415.. naar integer
        Serial.print("D = ");
        Serial.println(D);
        Bluetooth.print("D = ");
        Bluetooth.println(D);
        
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
