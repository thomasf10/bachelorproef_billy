
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);//wit sensor: links
  pinMode(A1, INPUT);//zwart senor: rechts
  pinMode(A2, INPUT);//wit sensor: links
  pinMode(A3, INPUT);//zwart senor: rechts
  pinMode(A4, INPUT);//wit sensor: links
  pinMode(A5, INPUT);//zwart senor: rechts
  pinMode(8, INPUT);//wit sensor: links
  pinMode(9, INPUT);//zwart senor: rechts
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(int(analogRead(8)));
  Serial.print("    -    ");
  Serial.print(int(analogRead(9)));
  Serial.print("    -    ");
  Serial.print(int(analogRead(A4)));
  Serial.print("    -    ");
  Serial.println(int(analogRead(A5)));
}
