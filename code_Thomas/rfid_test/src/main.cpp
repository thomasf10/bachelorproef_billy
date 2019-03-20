#include <SPI.h>
#include <MFRC522.h>
/*aansluiting:
	SDA:D10
	SCK:D13
	MOSI:D11
	MISO:D12
	IRQ:unconnected
	GND:GND
	3.3V=3.3V
	RST=D8
*/
#define SS_PIN 10
#define RST_PIN 8

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
bool on=false;
void setup(){
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
	pinMode(7,OUTPUT);
}
void loop()
{
	Serial.println("looking for tag");

  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }



	Serial.println("na returns");
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "83 37 ED A4") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("checkpoint 1");
		/*to do
		  schrijf naar lcd
		*/
    Serial.println();
		if(on==false){
  	digitalWrite(7,HIGH);
		on=true;
		delay(1000);
	}
	/*to do:
	if(content.substring(1)=="......."){
	Serial.println("checkpoint 2");
	schrijf tijd naar lcd
}
	*/
	else{
		digitalWrite(7,LOW);
		on=false;
		delay(1000);
	}
  }

 else   {
    Serial.println(" Access denied");
    delay(1000);
  }
}
