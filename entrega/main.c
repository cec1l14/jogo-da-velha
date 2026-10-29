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
    inicia(&tab, modo, &humano1, &humano2, &ia);

    return 0;
}