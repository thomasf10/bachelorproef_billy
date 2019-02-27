int SensorPin=0;
int SensorValue=LOW;

void setup()
{
pinMode(0,INPUT);
Serial.begin(9600);
}

void loop()
{
  SensorValue=analogRead(SensorPin);
  Serial.println(SensorValue);
}
