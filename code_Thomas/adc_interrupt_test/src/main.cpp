#include <Arduino.h>

// Initialization
bool readFlag;
int analogVal [3];
int counter;
int index;
bool completeupdate;


void setup(){
  completeupdate=0;
  counter=0;
  index=0;

  Serial.begin(9600);
  // clear ADLAR in ADMUX (0x7C) to right-adjust the result
  // ADCL will contain lower 8 bits, ADCH upper 2 (in last two bits)
  ADMUX &= B11011111;

  // Set REFS1..0 in ADMUX (0x7C) to change reference voltage to the
  // proper source (01)
  ADMUX |= B01000000;

  // Clear MUX3..0 in ADMUX (0x7C) in preparation for setting the analog
  // input
  ADMUX &= B11110000;

  // Set MUX3..0 in ADMUX (0x7C) to read from AD8 (Internal temp)
  // Do not set above 15! You will overrun other parts of ADMUX. A full
  // list of possible inputs is available in Table 24-4 of the ATMega328
  // datasheet
  ADMUX |= 0;
  // ADMUX |= B00001000; // Binary equivalent

  // Set ADEN in ADCSRA (0x7A) to enable the ADC.
  // Note, this instruction takes 12 ADC clocks to execute
  ADCSRA |= B10000000;

  // Set ADATE in ADCSRA (0x7A) to enable auto-triggering.
  ADCSRA |= B00100000;

  // Clear ADTS2..0 in ADCSRB (0x7B) to set trigger mode to free running.
  // This means that as soon as an ADC has finished, the next will be
  // immediately started.
  ADCSRB &= B11111000;

  // Set the Prescaler to 128 (16000KHz/128 = 125KHz)
  // Above 200KHz 10-bit results are not reliable.
  ADCSRA |= B00000111;

  // Set ADIE in ADCSRA (0x7A) to enable the ADC interrupt.
  // Without this, the internal interrupt will not trigger.
  ADCSRA |= B00001000;

  // Enable global interrupts
  // AVR macro included in <avr/interrupts.h>, which the Arduino IDE
  // supplies by default.
  sei();

  // Kick off the first ADC
  readFlag = 0;
  // Set ADSC in ADCSRA (0x7A) to start the ADC conversion
  ADCSRA |=B01000000;
}


// Processor loop
void loop(){

  // Check to see if the value has been updated
  if (completeupdate == 1){

    // module.update();
    for(int i=0;i<3;i++){
      Serial.print(analogVal[i]);
      Serial.print("   ");
    }
    Serial.println(" ");
    completeupdate = 0;
    ADCSRA |=B10000000;

  }

  // Whatever else you would normally have running in loop().

}


// Interrupt service routine for the ADC completion
ISR(ADC_vect){

  // Must read low first
  analogVal[counter] = ADCL | (ADCH << 8);

  if(counter==2){
    // want volgorde analoge pinnen: 0,1,2,3,6,7
    counter=0;
    completeupdate=1;
    ADCSRA &=B01111111;
  }
else{
  counter++;
}

  ADMUX |= counter;
}
