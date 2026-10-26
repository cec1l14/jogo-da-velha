#include <stdio.h>
#include <stdlib.h>
#include "partida.h"

int main(){
    Tabuleiro tab;
    JogadorTeclado humano1, humano2;
    JogadorIA ia;
    int modo; // é utilizado em 'partida.c', para determinar o tipo de jogo

    configuraJogadores(&modo, &humano1, &humano2, &ia);
    inicia(&tab, modo, &humano1, &humano2, &ia);

    return 0;
}