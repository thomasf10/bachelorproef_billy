#include "motor.h"
#include "PID.h"
#include "SensorModule.h"
#include "RFID.h"
#include <SPI.h>
//######################## RFID ##############

//Rijden en sturen ctes
Motor motor;
SensorModule leftsens;
SensorModule rightsens;
PID steeringPID;
RFID rfid;
unsigned long tijdelijk=0;
int interval=0;
double PIDvalue;

unsigned long currentMillis;
unsigned long previousMillis=0;
boolean searchStartPos;
boolean leftright; //Left= true, Right= false

void setup() {
 //################################### Rijden en sturen setup ###################################
  Serial.begin(115200);
  steeringPID = PID(15,0,12);
  motor = Motor();
  motor.start(60);
  leftsens = SensorModule(4, 5, A2, A3);
  rightsens = SensorModule(8,9,A4,A5);
  //rfid = RFID();
  //rfid.RFIDSetup();
}

void loop() {  
  
 //tijdelijk=tijdelijk +1;
 currentMillis=millis();
if (currentMillis - previousMillis >= interval){
    previousMillis=currentMillis;
    //########################### Rijden en sturen ########################
    
    leftsens.RefreshValues(leftsens);
    rightsens.RefreshValues(rightsens);
    
    leftright=leftsens.LinksRechts(leftsens,rightsens);
    Serial.println("left=0/right=1");

    if (leftright){
      PIDvalue=leftsens.calculatePIDSituatie(steeringPID);
      Serial.println("Links");
    }else {
      PIDvalue=rightsens.calculatePIDSituatie(steeringPID);
      Serial.println("Rechts");
    }
    motor.rotate(PIDvalue,leftright);

    //########################### RFID loop ###########################
    
    //rfid.RFIDTag();
    
    tijdelijk=0;
 }

  
}



