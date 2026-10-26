#include <stdio.h>
#include <stdlib.h>
#include "partida.h"

int main(){
    Tabuleiro tab;
    JogadorTeclado humano;
    JogadorIA ia;

    configuraJogadores(&humano, &ia);
    inicia(&tab, &humano, &ia);

    return 0;
}