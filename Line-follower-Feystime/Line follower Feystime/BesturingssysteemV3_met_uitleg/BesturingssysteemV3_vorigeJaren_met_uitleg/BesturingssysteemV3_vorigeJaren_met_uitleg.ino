//Line follower programma
//Martijn Beele en Robin Sanders

//libraries toevoegen
#include <EEPROM.h>
#include "SerialCommand.h"
#include "EEPROMAnything.h"

#define SerialPort Serial1 //seriele communicatie instellen (Serial1 = via Tx en Rx voor bluetooth module)
SerialCommand sCmd(SerialPort);

//variabelen declareren
int channel[] = {A0, A1, A2, A3, A4, A5}; //inputs van de 6 sensoren
int value[6]; //array voor waarden sensoren
float average; //int voor interpolatie
float normalized[6]; //array voor genormaliseerde waarden

int pinAin1 = 13; //motorpinnen
int pinAin2 = 5;
int pinBin1 = 10;
int pinBin2 = 9;

int startknop = 2;
int stopknop = 3;

int witteller = 0; //automatisch stoppen bij het verliezen van de lijn
int stopteller = 0;

unsigned long lastTime; //variabelen voor PID regelaar
double Input, output, Setpoint;
double iTerm, lastInput;
float error;
double timeChange, dInput;
unsigned long now;
float outputP;
float outputI;
float outputD;

unsigned long time, prevTime, delta, calculationTime; //variabelen voor vaste cyclustijd

//variabelen die worden opgeslagen in het EEPROM
struct param_t
{
  bool start;
  int speed;
  float kp;
  float ki;
  float kd;
  unsigned long cycleTime;
  int white[6]; //array voor kalibratie wit
  int black[6]; //array voor kalibratie zwart
} params;

void setup()
{  
  attachInterrupt(0, onInterrupt, RISING);
    
  SerialPort.begin(9600); //baudrate bluetooth module
  
  //Commando's voor instellen waardes, starten, stoppen,... Verwijst naar de functies onStart, onStop,... verder in het programma
  sCmd.addCommand("start", onStart);
  sCmd.addCommand("stop", onStop);
  sCmd.addCommand("set", onSet);
  sCmd.addCommand("debug", onDebug);
  sCmd.addCommand("reset", onReset);
  sCmd.addCommand("calibrate", onCalibrate);
  sCmd.setDefaultHandler(onUnknownCommand);

  EEPROM_readAnything(0, params); //parameters in EEPROM uitlezen
  params.start = false;

  attachInterrupt(digitalPinToInterrupt(startknop), onStart, FALLING); //interrupt voor start- en stopknop
  attachInterrupt(digitalPinToInterrupt(stopknop), onStop, FALLING);
  
  time = micros();
  prevTime = time;
  
  SerialPort.println("ready");
}

void loop()
{  
  sCmd.readSerial();     //Seriele poort uitlezen

  //Software voor vaste cyclustijd te bekomen
  time = micros();
  
  if (time > prevTime) delta = time - prevTime;
  else delta = 4294967295 - prevTime + time + 1;
    
  if (delta > params.cycleTime)
  {
    prevTime = time;

    while (params.start == true)
    {
      sCmd.readSerial();

    //sensoren uitlezen en normaliseren
    for (int i = 0; i < 6; i++)
    {
      value[i] = analogRead(channel[i]);
      if (value[i] < 200)
      {
        witteller = witteller + 1;
      }
      
      normalized[i] = value[i] - params.white[i]; //volgens de formule x = ((waarde - laagste waarde) / (hoogste waarde - laagste waarde)) * 100
      normalized[i] /= (params.black[i] - params.white[i]);
      normalized[i] *= 100;
    }
    //teller die bijhoudt hoeveel keer elke sensor een witte ondergrond heet gedetecteerd na elkaar en na 50 keer de auto doet stoppen
    if (witteller == 6)
    {
      stopteller = stopteller + 1;
      witteller = 0;
    }
    if (stopteller == 100);
    {
      onStop;
    }

    // interpoleren
    average = ((250 * normalized[5]) + (150 * normalized[4]) + (50 * normalized [3]) + (-50 *   normalized[2]) + (-150 * normalized[1]) + (-250 * normalized[0]));
    average /= (normalized[5] + normalized[4] + normalized[3] + normalized[2] + normalized[1] + normalized[0]);

    #define setpoint 0

    error = setpoint - average;
    iTerm += (params.ki * error);
    dInput = (average - lastInput);

    //PID Output berekenen:
    outputP = params.kp * error;
    //Delen door 10000, anders moet Ki veel te klein gemaakt worden
    outputI = iTerm/10000;
    //Vermenigvuldigen met 10, anders moet Kd veel te groot gemaakt worden
    outputD = (params.kd * dInput)*10;
    output = outputP + outputI - outputD;

    //Variabelen onthouden voor volgende keer:
    lastTime = now;
    lastInput = average;

    int leftSpeed;
    int rightSpeed;

    rightSpeed = params.speed - output; //PWM waarde toekennen aan linkse en rechts motor
    leftSpeed = params.speed + output;

    //motor links (indien PWM kleiner is dan 0 zal de motor omgekeerd draaien met de absolute waarde van de PWM waarde)
    if (leftSpeed > 0)
    {
    analogWrite(pinAin1, leftSpeed);
    analogWrite(pinAin2, 0);
    }
    else if (leftSpeed < 0)
    {
    analogWrite(pinAin1, 0);
    analogWrite(pinAin2, (leftSpeed * (-1)));
    }
    //motor rechts (indien PWM kleiner is dan 0 zal de motor omgekeerd draaien met de absolute waarde van de PWM waarde)
    if (rightSpeed > 0)
    {
    analogWrite(pinBin1, rightSpeed);
    analogWrite(pinBin2, 0);
    }
    else if (rightSpeed < 0)
    {
    analogWrite(pinBin1, 0);
    analogWrite(pinBin2, (rightSpeed * (-1)));
    }
  }
  }
  unsigned long difference = micros() - time;
  if (difference > calculationTime) calculationTime = difference; 

}

//bij ongekend commando foutmelding geven
void onUnknownCommand(char *command)
{
  SerialPort.print("unknown command: \"");
  SerialPort.print(command);
  SerialPort.println("\"");
}

//instellen van alle parameters (bv: "set speed 50", "set kp 1.5") 
void onSet()
{
  char* parameter = sCmd.next();
  char* value = sCmd.next();
  
  if (strcmp(parameter, "speed") == 0) params.speed = atoi(value);
  else if (strcmp(parameter, "kp") == 0) params.kp = atof(value);
  else if (strcmp(parameter, "ki") == 0) params.ki = atof(value);
  else if (strcmp(parameter, "kd") == 0) params.kd = atof(value);
  else if (strcmp(parameter, "cycle") == 0) params.cycleTime = atol(value);
  
  EEPROM_writeAnything(0, params); //waardes opslaan in EEPROM
}

//auto starten
void onStart()
{
  params.start = true;
}
 //auto stoppen
void onStop()
{
  params.start = false;
  analogWrite(pinAin1, 0);
  analogWrite(pinAin2, 0);
  analogWrite(pinBin1, 0);
  analogWrite(pinBin2, 0);
  stopteller = 0;
}

//alle waarden en parameters worden uitgelezen en via de seriele poort doorgestuurd
void onDebug()
{
  //sensoren uitlezen
  SerialPort.print("Sensoren: ");
  for (int i = 0; i < 6; i++)
  {
    SerialPort.print(analogRead(channel[i]));
    SerialPort.print(" ");
  }
  SerialPort.println("");

  //kalibratie wit
  SerialPort.print("kalibratie wit: ");
  for (int i = 0; i < 6; i++)
  {
    SerialPort.print(params.white[i]);
    SerialPort.print(" ");
  }
  SerialPort.println("");
  
  //kalibratie zwart
  SerialPort.print("kalibratie zwart: ");
  for (int i = 0; i < 6; i++)
  {
    SerialPort.print(params.black[i]);
    SerialPort.print(" ");
  }
  SerialPort.println("");  
  
  //parameters
  SerialPort.print("speed: ");
  SerialPort.println(params.speed);
  SerialPort.print("kp: ");
  SerialPort.println(params.kp); 
  SerialPort.print("ki: ");
  SerialPort.println(params.ki); 
  SerialPort.print("kd: ");
  SerialPort.println(params.kd); 
  //SerialPort.println();
  
  //cycle times
  SerialPort.print("cycle time: ");
  SerialPort.println(params.cycleTime);
  SerialPort.print("calculation time: ");
  SerialPort.println(calculationTime);
  //SerialPort.println();
  calculationTime = 0;  //reset calculation time
  
  //running
  SerialPort.print("running: ");
  SerialPort.println(params.start); 
}

void onReset()
{
  SerialPort.print("resetting parameters... ");
  EEPROM_resetAnything(0, params);
  EEPROM_readAnything(0, params);  
  SerialPort.println("done");
}

void onInterrupt()
{
  params.start = not params.start;
}

//sensoren kalibreren op wit en zwart
void onCalibrate()
{
  char *arg = sCmd.next();
  if (strcmp (arg, "white") == 0) //voert dit uit als commando "calibrate white" is
  {
    for (int i = 0; i < 6; i++) //de array wordt volledig op 1023 gezet, anders wordt er zo meteen niet overschreven
    {
      params.white[i] = 1023;
    }
    
    SerialPort.print("Calibrating white... ");
    for (int i = 0; i < 50; i++) //de sensorwaarde wordt 50 keer uitgelezen voor elke sensor
    {
      for (int j = 0; j < 6; j++)
      {
        int value_white = analogRead(channel[j]); //indien de uitgelezen waarde lager ligt dan de reeds gekalibreerde witte waarde wordt die overschreven
        if (value_white < params.white[j])
        {
          params.white[j] = value_white;
        }
      }
    }
    SerialPort.println(""); //resulataten worden getoond
    for (int i = 0; i < 6; i++)
    {
      SerialPort.print(params.white[i]);
      SerialPort.print(" ");
    }
    SerialPort.println("");
}

  if (strcmp (arg, "black") == 0) //zelfde werking als wit
  {
    SerialPort.print("Calibrating black... ");
    for (int i = 0; i < 6 ; i++)
    {
      for (int j = 0; j < 6; j++)
      {
        int value_black = analogRead(channel[j]);
        if (value_black > params.black[j])
        {
          params.black[j] = value_black;
        }
      }
    }
    SerialPort.println("");
    for (int i = 0; i < 6; i++)
    {
      SerialPort.print(params.black[i]);
      SerialPort.print(" ");
    }
    SerialPort.println("");
  }
  EEPROM_writeAnything(0,params);
}
