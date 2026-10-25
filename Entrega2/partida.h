#ifndef PARTIDA_H
#define PARTIDA_H
#include "tabuleiro.h"
#include "jogadorTeclado.h"
#include "jogadorIA.h"

void configuraJogadores(JogadorTeclado *humano, JogadorIA *ia);
void inicia(Tabuleiro *tab, JogadorTeclado *humano, JogadorIA *ia);

#endif