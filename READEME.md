# Biblioteca LED

Biblioteca que permite controlar as funções de um LED, no framework Arduino utilizando ESP32.

A classe 'Led' permite:
- ligar continuamente o LED
- ligar por tempo determinado
- alternar os estados do LED
- apagar o LED
- piscar o LED continuamente
- piscar o LED em determinada frequência e determiado número de vezes

O funcionamento do LED é não bloqueante, usando "millis()".
Por isso, o método "update()" deve ser chamado repetidamente dentro do "loop()".

---

# Estrutura da bilbioteca

``` text
LED/ 
- library.json
- README.md
- LICENSE
- src/
    -LED.h
    -LED.cpp
- examples/