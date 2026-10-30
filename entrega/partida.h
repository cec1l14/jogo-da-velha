#ifndef PARTIDA_H
#define PARTIDA_H
#include "tabuleiro.h"
#include "jogadorTeclado.h"
#include "jogadorIA.h"

#define MODO_HUMANO_VS_HUMANO 1
#define MODO_HUMANO_VS_IA 2
#define MODO_REMOTO 3

void configuraJogadores(int *modo, JogadorTeclado *humano1, JogadorTeclado *humano2, JogadorIA *ia);
void inicia(Tabuleiro *tab, int modo, JogadorTeclado *humano1, JogadorTeclado *humano2, JogadorIA *ia);

#endif