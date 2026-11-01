#ifndef JOGADORTECLADO_H
#define JOGADORTECLADO_H
#include "tabuleiro.h"

typedef struct{
    int tipo;
    int ultimaLinha;
    int ultimaColuna;
} JogadorTeclado;

void joga(JogadorTeclado *jogador, Tabuleiro *tab);

#endif