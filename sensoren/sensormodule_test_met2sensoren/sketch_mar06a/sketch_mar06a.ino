

int links = 0;     // potentiometer wiper (middle terminal) connected to analog pin 3
int rechts = 1;
                       // outside leads to ground and +5V

int vallinks = 0;
int valrechts=0;        // variable to store the value read



void setup()

{

  Serial.begin(9600);          //  setup serial

}



void loop()

{

  vallinks = analogRead(links);    // read the input pin
  Serial.print("links: ");
  Serial.println(vallinks);
  delay(500);
  
  valrechts=analogRead(rechts);
  Serial.println("rechts: ");
  Serial.println(valrechts);
  delay(500);

               // debug value

}
