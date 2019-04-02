#include <Arduino.h>
int counter;
void setup() {
  counter=0;
// start serial monitor
  Serial.begin(9600);
// disable interrupts
  cli();
//set timer1 interrupt at 66.67 Hz => T=15ms
TCCR1A = 0; // set entire TCCR1A register to 0
TCCR1B = 0; // same for TCCR1B
TCNT1  = 0; //initialize counter value to 0

// OCR1A = (fclk / (finterrupt * prescaler)) - 1 (must be <65536)
OCR1A=30000;

// turn on CTC mode
TCCR1B |= (1 << WGM12);
// set CS11 bit for /8 prescaler
TCCR1B |= (1 << CS11);
// enable timer compare interrupt
TIMSK1 |= (1 << OCIE1A);
// enable interrupts
sei();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(counter==1){
    Serial.println(micros());
    counter=0;
  }
}

ISR(TIMER1_COMPA_vect){
  counter=1;
}
