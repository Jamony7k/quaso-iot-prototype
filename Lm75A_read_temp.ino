#include <inttypes.h>
#include <Wire.h>
#include <lm75.h>

TempI2C_LM75 termo = TempI2C_LM75(0x48, TempI2C_LM75::nine_bits); //0x48 คือ Address ของ LM75 

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Temperature in Celsius   : ");
  Serial.print(termo.getTemp() - 4);
  Serial.println(" *C");


  if (termo.getTemp() >= 37) {
    Serial.print("Temperature Status       : Hot");
    Serial.println();
  }

  if (termo.getTemp() <= 28) {
    Serial.print("Temperature Status       : Cold");
    Serial.println();
  }

  if (termo.getTemp() < 37 && termo.getTemp() > 28) {
    Serial.print("Temperature Status       : Warm");
    Serial.println();
  }
  delay(5000);
  Serial.println();

}
