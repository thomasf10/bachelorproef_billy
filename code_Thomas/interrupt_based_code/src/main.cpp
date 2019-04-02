#include <Arduino.h>
//  Two IO EXPANDERS I2C addresses
#define I2C_ADDRESS_DIR_MOTORS    0x38
#define I2C_ADDRESS_ADD_PINS      0x39

//  Command Bytes -- Send to control register in the TCA9554
#define CMD_REG_INPUT   0x00
#define CMD_REG_OUTPUT  0x01
#define CMD_REG_POL_INV 0x02
#define CMD_REG_CONFIG  0x03

// constants
#define updatetijd 100
#define motorsnelheid 255 // 200
#define minimumsnelheid 20
#define draaisnelheid 150
#define maxcounter 5

// Declare objects:
bool completeupdate;
Sensormodule module;
int pidvalue;
Motorcontrol motors;
bool forward;

void setup() {
  //initialize objects:
  completeupdate=0;
  //Motorcontrol
  motors=Motorcontrol();

  //i2c
  Wire.begin();

  // Setup Configuration IO expander (Motor Directions)
  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_CONFIG, 0x00);

  // Setup Configuration IO expander (Additional Pins)
  motors.i2C_write_reg(I2C_ADDRESS_ADD_PINS, CMD_REG_CONFIG, 0x00);

  // Set motordirection forward
  motors.i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10101010);
  forward=true;

  //sensormodules
  module=Sensormodule(0,1,2,3,6,7);

  // start Serial monitor:

    Serial.begin(9600);

  // Set up timer interrupt:

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

void loop() {
  // put your main code here, to run repeatedly:
}

//ISR if adc conversion is finnished:

ISR(ADC_vect){

  // Must read low first
  int analogVal = ADCL | (ADCH << 8);

  switch (ADMUX) {
    case 0x40:
    //pin A0
      module.updatesumL1(analogVal);
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

// ISR for timer:

ISR(TIMER1_COMPA_vect){
  counter=1;
}
