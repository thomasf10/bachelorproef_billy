#include <SoftwareSerial.h>
#include "RFID.h"

#define RX 4
#define TX 5
int count = 0;
int previousValue;
int currentValue;
unsigned long startTime, currentTime;
const double pi = 3.1415;
RFID rfid;
uint8_t naamTag[]= { 0, 0, 0, 0, 0, 0, 0 };
SoftwareSerial myserial(RX, TX);

void setup()
{
  Serial.begin(115200);
  myserial.begin(9600);
  pinMode(2, INPUT);
  startTime = millis();
  rfid = RFID();
  rfid.RFIDSetup();
  myserial.print("Hallo begin van het einde van ons bachelor projectje");
}

void loop()
{
    rfid.RFIDTag();
    //naamTag=rfid.Tag();
    myserial.print("naam van de tag is ");
    for (uint8_t i = 0; i < uidLength; i++)
    {
      myserial.println(naamTag[i],HEX);      
    }
    Serial.println("het lukte");
  
  //myserial.println("Hello World");
  //snelheid bepalen
  currentValue = digitalRead(2);
  //Serial.println(currentValue);
  if (currentValue == 0 && previousValue == 1) {
    count += 1;
    //Serial.println(count);
  }
  

  if (count == 3) {
    unsigned long currentTime = millis();
    //Serial.println("StartTime" + String(startTime));
    //Serial.println("CurrentTime" + String(currentTime));
    unsigned long ElapsedTime = currentTime - startTime;
    myserial.println("De snelheid is: " + String(3 * 6.9 * pi / ElapsedTime, 4));
    //Serial.println("De snelheid is: " + String(3 * 6.9 * pi / ElapsedTime, 4));
    count = 0;
    startTime = currentTime;
  }
  previousValue = currentValue;

}

