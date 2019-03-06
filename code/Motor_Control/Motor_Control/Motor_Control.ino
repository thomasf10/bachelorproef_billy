/*  ____  ____      _    __  __  ____ ___
 * |  _ \|  _ \    / \  |  \/  |/ ___/ _ \
 * | | | | |_) |  / _ \ | |\/| | |  | | | |
 * | |_| |  _ <  / ___ \| |  | | |__| |_| |
 * |____/|_| \_\/_/   \_\_|  |_|\____\___/
 *                           research group
 *                             dramco.be/
 *
 *  KU Leuven - Technology Campus Gent,
 *  Gebroeders De Smetstraat 1,
 *  B-9000 Gent, Belgium
 *
 *         File: Motor_Control_Example.ino
 *      Created: 2019_02_11
 *       Author: Jarne Van Mulders
 *      Version: 1.1
 *
 *  Description: Motor Control Example 
 *                TCA9554 as IO EXPANDER
 */

#include <Wire.h>
#include <Arduino.h>
#include <PinChangeInterrupt.h>

//  Define PWN PINS
#define PWM_PIN_1 (3)
#define PWM_PIN_2 (5)
#define PWM_PIN_3 (6)
#define PWM_PIN_4 (9)
#define ARDUINOPIN_1 A0
#define ARDUINOPIN_2 A1

int SensorPin = 0;
int SensorValue = 0;

//  Two IO EXPANDERS I2C addresses
#define I2C_ADDRESS_DIR_MOTORS    0x38
#define I2C_ADDRESS_ADD_PINS      0x39

//  Command Bytes -- Send to control register in the TCA9554
#define CMD_REG_INPUT   0x00
#define CMD_REG_OUTPUT  0x01
#define CMD_REG_POL_INV 0x02
#define CMD_REG_CONFIG  0x03
#define uint8_t Dir = B10101010





void setup()
{
  Wire.begin();
  Serial.begin(9600);

  // Setup Configuration IO expander (Motor Directions)
  i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_CONFIG, 0x00);

  // Setup Configuration IO expander (Additional Pins)
  i2C_write_reg(I2C_ADDRESS_ADD_PINS, CMD_REG_CONFIG, 0x00);
  
  // PinMode PWM pinnen speed Motors
  pinMode(PWM_PIN_1, OUTPUT);
  pinMode(PWM_PIN_2, OUTPUT);
  pinMode(PWM_PIN_3, OUTPUT);
  pinMode(PWM_PIN_4, OUTPUT);

  pinMode(ARDUINOPIN_1,INPUT_PULLUP);
  pinMode(ARDUINOPIN_2,INPUT_PULLUP);
  attachPinChangeInterrupt(ARDUINOPIN_1, turnRight, RISING);
  attachPinChangeInterrupt(ARDUINOPIN_1, reverse, FALLING);
}





void loop() {

  //  Set motor speed
  set_motor_speed(200, 200, 200, 200);

  /*
  *  Determining DC motor rotation direction
  *  Instruction Byte 
  *    2 bits for each motor
  *    00  or  11  Stop
  *    01          CCW or CW
  *    10          CCW or CW
  *    
  *    Byte: MD MC MB MA
  */    

  // Motor example
  i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, Dir);
  delay (300);//  Turn right
}

void reverse(){
  if(SensorValue<350) {
    Dir = B01010101;
  }
}

void turnRight(){
  if(SensorValue>350){
    Dir = B10100101;
  }
}




void set_motor_speed(uint8_t speed_m1, uint8_t speed_m2, uint8_t speed_m3, uint8_t speed_m4){
  analogWrite(PWM_PIN_1, speed_m1);
  analogWrite(PWM_PIN_2, speed_m2);
  analogWrite(PWM_PIN_3, speed_m3);
  analogWrite(PWM_PIN_4, speed_m4);
}

void i2C_write_reg(uint8_t address, uint8_t reg, uint8_t instruction){
  Wire.beginTransmission(address); 
  Wire.write(reg);
  Wire.write(instruction); 
  Wire.endTransmission(); 
}
