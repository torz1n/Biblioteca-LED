#ifndef LED_h
#define LED_h

#include <Arduino.h>

/**
 * @class Led
 * @brief Classe para controle não bloqueante de um LED.
 * 
 * Permite ligar, desligar, ligar por um tempo,
 * piscar continuamente e piscar por quantidade definida.
 * 
 * @note O método update() deve ser chamado continuamente dentro do loop().
 */
class Led 
{
    private:
    uint8_t pino;
    bool estado;
    bool apagarNoTempo;
    uint32_t apagarNoMomento;
    bool estadoPiscar;
    uint32_t tempoEspera;
    uint32_t tempoAnteriorPiscar;
    uint16_t repeticoes;
    /**
     * @brief Processa o desligamento temporizado
     */
    void funcaoApagarNoTempo();
    /**
     * @brief Processa a lógica da piscada do LED.
     */
    void funcaoPiscar();


    public:
    /**
     * Constrói um objeto Led.
     * @param pin Número do pino digital onde o LED está conectado.
     */
    Led(uint8_t pin);
    /**
     *@brief Liga o LED continuamente.
     */
    void acender();
    /**
     *@brief Liga o LED por um tempo determinado.
     *@param tempoLigado Tempo em milissegundos que o LED ficará ligado.
     */
    void acender(uint32_t tempoLigado);
    /**
     *@brief Desliga o LED e cancela modos automáticos.
     */
    void apagar();
    /**
     * @brief Acende e Apaga o LED continuamente.
     */
    void piscar();
    /**
     * @brief Acende e Apaga o LED em uma frequência determinada.
     * @param freq frequência a ser definida em que o Led irá piscar.
     */
    void piscar(float freq);
    /**
     * @brief Acende e apaga o LED em uma frequência e número de repetições determinado pelo usuário.
     * @param freq frequência a ser definida em que o Led irá piscar.
     * @param repeticoes Número de vezes que o Led deve piscar.
     */
    void piscar(float freq, uint16_t repeticoes);
    /**
     * @brief Alterna o Estado do Led (Ligado/Desligado).
     */
    void alternar();
    /**
     * @brief Altera o Estado do Pino do LED.
     * 
     * @param estado Estado em que o LED está (Ligado/Desligado)
     */
    void setEstado(bool estado);
    /**
     * @brief Retorna o número do pino para o usuário.
     */
    uint8_t getPino();
    /**
     * @brief Atualiza a lógica interna da classe e escreve no pino.
     * 
     * @note Deve ser chamado repetidamente dentro a função loop().
     */
    void update();

};


#endif;