#include <i2cmaster.h>

const int gasPin = A0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Setup...");

  i2c_init(); 
  PORTC = (1 << PORTC4) | (1 << PORTC5);//enable pullups
}

void loop()
{
  int dev = 0x5A<<1;
  int data_low = 0;
  int data_high = 0;
  int pec = 0;
  i2c_start_wait(dev+I2C_WRITE);
  i2c_write(0x07);
  i2c_rep_start(dev+I2C_READ);
  data_low = i2c_readAck(); 
  data_high = i2c_readAck(); 
  pec = i2c_readNak();
  i2c_stop();
  double tempFactor = 0.02; 
  double tempData = 0x0000; 
  int frac;
  tempData = (double)(((data_high & 0x007F) << 8) + data_low);
  tempData = (tempData * tempFactor)-0.01;

  float celcius = tempData - 273.15;

  Serial.print(celcius);
  Serial.print(',');
  Serial.println(analogRead(gasPin));
  delay(1000);
}




