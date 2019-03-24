void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 int a1= analogRead(0);
 int a2= analogRead(1);
 int a3= analogRead(2);
 Serial.print(a1 );
 Serial.print(" ");
 Serial.print(a2);
 Serial.print(" ");
 Serial.print(a3);
 Serial.println();
 delay(500);
 
}
