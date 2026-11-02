#ifndef JOGADORTECLADO_H
#define JOGADORTECLADO_H
#include "jogadorRemoto.h"
#include "tabuleiro.h"

typedef struct{
    int tipo;
} JogadorTeclado;

void joga(JogadorTeclado *jogador, Tabuleiro *tab, JogadorRemoto *remoto);

#endif