#include <Arduino.h>

// Initialization
bool readFlag;
//int analogVal [3];
int a1,a2,a3,a4,a5,a6;
int counter;
int index;
bool completeupdate;


void setup(){
  completeupdate=0;

  Serial.begin(9600);
// Set up ADC:

  // clear ADLAR in ADMUX (0x7C) to right-adjust the result
  // ADCL will contain lower 8 bits, ADCH upper 2 (in last two bits)
  ADMUX &= B11011111;
  // Set REFS1..0 in ADMUX (0x7C) to change reference voltage to the
  // proper source (01)
  ADMUX |=1<<REFS0;
  // Clear MUX3..0 in ADMUX (0x7C) in preparation for setting the analog
  // input
  ADMUX &= B11110000;
  // Set MUX3..0 in ADMUX (0x7C) to read from AD0
  ADMUX |= 0;
  // Set ADEN in ADCSRA to enable the ADC.
  ADCSRA |= 1<<ADEN;
  // Set the Prescaler to 128 (16000KHz/128 = 125KHz)
  ADCSRA |= B00000111;
  // Set ADIE in ADCSRA (0x7A) to enable the ADC interrupt.
  ADCSRA |= 1<<ADIE;
  // Enable global interrupts
  sei();
  // Set ADSC in ADCSRA (0x7A) to start the ADC conversion
  ADCSRA |=1<<ADSC;
}


// Processor loop
void loop(){

  // Check to see if the value has been updated
  if (completeupdate == 1){

    // module.update();

    Serial.println(micros());
    completeupdate = 0;
  }

  // Whatever else you would normally have running in loop().

}


// Interrupt service routine for the ADC completion
ISR(ADC_vect){

  // Must read low first
  int analogVal = ADCL | (ADCH << 8);

  switch (ADMUX) {
    case 0x40:
      a1=analogVal;
      ADMUX=0x41;
      break;
    case 0x41:
      a2=analogVal;
      ADMUX=0x42;
      break;
    case 0x42:
      a3=analogVal;
      ADMUX=0x43;
      break;
    case 0x43:
      a4=analogVal;
      ADMUX=0x46;
      break;
    case 0x46:
      a5=analogVal;
      ADMUX=0x47;
      break;
    case 0x47:
      a6=analogVal;
      ADMUX=0x40;
      completeupdate=1;
      break;
    default:
      break;
  }

  //start conversion
  ADCSRA |=1<<ADSC;

}
