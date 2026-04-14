#include <Arduino.h>
#include <LED.h>

Led ledA(45);
uint8_t pinBotao = 0;
bool jaExecutou = false;
bool botaoAnterior = 1;

void setup()
{
  pinMode(pinBotao, INPUT_PULLUP);
}

void loop()
{
  bool botaoAtual = digitalRead(pinBotao);
  ledA.update();

  if (!jaExecutou)
  {
    if (!botaoAtual && botaoAnterior)
    {
      ledA.piscar(2, 10);
    }
  botaoAnterior = botaoAtual;
  }
}
