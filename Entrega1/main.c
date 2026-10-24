#include <stdio.h>
#include "partida.h"

int main(){
    Tabuleiro tab;
    JogadorTeclado jogador1, jogador2;

    configuraJogadores(&jogador1, &jogador2);
    inicia(&tab, &jogador1, &jogador2);
    
    return 0;
}