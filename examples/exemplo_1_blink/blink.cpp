#include <Arduino.h>
#include <LED.h>

Led ledA(45);
bool jaExecutou = false;
void setup() {

}

void loop() {
 if(!jaExecutou)
 {
    ledA.piscar();
    jaExecutou = true;
 }
}

