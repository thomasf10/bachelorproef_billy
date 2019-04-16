// modulenaam: MLT-BT05
// wachtwoord om te verbinden: 123456789
// ik denk RX nog naar 3.3V brengen, 
// VCC --> 5V
// GND --> GND
// bRX --> 3
// bTX --> 2

#define softserial
const int LED  = 13;
const int LED_ext  = A0;

#ifdef softserial
  #include <SoftwareSerial.h>
  const int BTRX = 2;  // 2
  const int BTTX = 3;  // 3
  SoftwareSerial SerialBT(BTRX, BTTX);
#else 
  HardwareSerial SerialBT = Serial1;
#endif


// het bericht verzenden:
String msg;

void setup() {
  SerialBT.begin(9600);
  SerialBT.println("Bluetooth-Verbinding is beschikbaar");
  pinMode(LED, OUTPUT);
}

void loop() {
  if (SerialBT.available()){      // Gegevens zijn beschikbaar
     msg = SerialBT.readString(); // Bericht lezen
     if (msg == "aan") {
         digitalWrite(LED, HIGH);
         digitalWrite(LED_ext, HIGH);
         SerialBT.print("LED op Pin ");
         SerialBT.print(LED);
         SerialBT.println(" is aan");
      } 
      else
      if (msg == "uit") {
         digitalWrite(LED, LOW);
         digitalWrite(LED_ext, LOW);
         SerialBT.print("LED op Pin ");
         SerialBT.print(LED);
         SerialBT.println(" is aan");
      }
      else {
         SerialBT.print("Commando <");
         SerialBT.print(msg);
         SerialBT.println("> niet gekend");
      }
    }
}                                          
