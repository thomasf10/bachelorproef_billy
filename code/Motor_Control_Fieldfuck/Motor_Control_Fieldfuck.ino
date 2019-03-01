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

//  Define PWN PINS
#define PWM_PIN_1 (3)
#define PWM_PIN_2 (5)
#define PWM_PIN_3 (6)
#define PWM_PIN_4 (9)

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

  // Setup Configuration IO expander (Motor Directions)
  i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_CONFIG, 0x00);

  // Setup Configuration IO expander (Additional Pins)
  i2C_write_reg(I2C_ADDRESS_ADD_PINS, CMD_REG_CONFIG, 0x00);
  
  // PinMode PWM pinnen speed Motors
  pinMode(PWM_PIN_1, OUTPUT);
  pinMode(PWM_PIN_2, OUTPUT);
  pinMode(PWM_PIN_3, OUTPUT);
  pinMode(PWM_PIN_4, OUTPUT);

  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), turnRight, RISING);
  attachInterrupt(digitalPinToInterrupt(2), reverse, FALLING);
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
  //MC en MD zijn de voorkant van de auto(met de sticker)
  //wielen aan linkerkant eerst gegeven
  //aan linkerkant achterwiel eerst, aan rechterkant voorwiel eerst
  //Met 2 voorwielen draaien scherper dan met 1 voor- en 1 achterwiel
  //10 voorwaarts en 01 achterwaarts
  //hoe langer delay, hoe langer draaien
  i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, DIR);
}

void reverse() {
i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B01010101);
}

void turnRight(){
  i2C_write_reg(I2C_ADDRESS_DIR_MOTORS, CMD_REG_OUTPUT, B10100101);
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
