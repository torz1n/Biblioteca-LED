#include <Arduino.h>
#include <LED.h>

Led ledA(45);
bool jaExecutou = false;

void setup() {

}

void loop() {
 
  if(!jaExecutou)
  {
    ledA.acender(5000);
    jaExecutou = true;
  }
  ledA.update();//Este método deve ser chamado sempre no loop()
}

