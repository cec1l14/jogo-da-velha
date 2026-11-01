/****
 * Implementação do módulo: main
 * Autores: Cecília Candeia e Matheus Fernandes
 * Data de Criação: 19/10/2026
 * Última alteração: 26/10/2026
 * Descrição Geral: ponto de entrada do programa. Declara o tabuleiro e os
 *   jogadores, configura a partida e a inicia.
 ****/

#include <stdio.h>
#include "partida.h"

int main(){
    Tabuleiro tab;
    JogadorTeclado humano1, humano2;
    JogadorIA ia;
    int modo; 

    configuraJogadores(&modo, &humano1, &humano2, &ia);
    if (modo == MODO_REMOTO) {
        return 0; // para não entrar na função inicia quando o modo for remoto
    }
    inicia(&tab, modo, &humano1, &humano2, &ia);

    return 0;
}