#include "LED.h"

Led::Led(uint8_t pin) : // Os dois pontos mostram em qual classe o "Led" está (Led está na classe Led)
    pino(pin),
    estado(LOW),
    apagarNoTempo(false),
    apagarNoMomento(false),
    estadoPiscar(false),
    tempoEspera(0),
    tempoAnteriorPiscar(0),
    repeticoes(0)
{
    pinMode(pino, OUTPUT);
}
void Led::acender()
{
    estado = HIGH;
    apagarNoTempo = false;
    estadoPiscar = false;
}

void Led::acender(uint32_t tempoLigado)
{
    estado = HIGH;
    apagarNoMomento = millis() + tempoLigado;
    apagarNoTempo = true;
    estadoPiscar = false;
}

void Led::apagar()
{
    estado = LOW;
    apagarNoTempo = false;
    estadoPiscar = false;
}

void Led::alternar()
{
    estado = !estado;
    apagarNoTempo = false;
    estadoPiscar = false;
}
void Led::setEstado(bool estado)
{
    this->estado = estado;
    apagarNoTempo = false;
    estadoPiscar = false;
}

uint8_t Led::getPino()
{
    return pino;
}

void Led::update()
{
    if (apagarNoTempo)
    {
        funcaoApagarNoTempo();
    }

    if (estadoPiscar)
    {
        funcaoPiscar();
    }

    digitalWrite(pino, estado);
}

void Led::piscar()
{
    estadoPiscar = true;
    tempoEspera = 500;
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    apagarNoTempo = false;
    repeticoes = -1;
}

void Led::piscar(float freq)
{
    if(freq == 0)
    {
        return; //Isso serve para caso o ledA.piscar(0), o programa não dê erro e apenas saia da função com o return;
    }

    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * freq)); //fórmula da frequência //O (.0f) serve para usar valores float
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    apagarNoTempo = false;
    repeticoes = -1;
}
void Led::piscar(float freq, uint16_t repeticoes)
{
    if(freq == 0) //Isso serve para caso o ledA.piscar(0), o programa não dê erro e apenas saia da função com o return;
    {
        return;
    }

    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * freq));
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    this->repeticoes = repeticoes * 2; //(Só é * 2 porque a repetição também está contando na "piscada desligada" do LED)
    apagarNoTempo = false;
}

void Led::funcaoApagarNoTempo()
{
    if (millis() >= apagarNoMomento)
    {
        estado = LOW;
        apagarNoTempo = false;
    }
}

void Led::funcaoPiscar()
{
    if (millis() - tempoAnteriorPiscar >= tempoEspera)
    {
        estado = !estado;
        tempoAnteriorPiscar = millis();

        if (repeticoes > 0)
        {
            repeticoes--;
            if (repeticoes == 0)
            {
                estadoPiscar = false;
                estado = LOW;
            }
        }
    }
}
