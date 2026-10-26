#ifndef JOGADORIA_H
#define JOGADORIA_H
#include "tabuleiro.h"

typedef struct{
    int tipo;
} JogadorIA;

void jogaIA(Tabuleiro *tab, JogadorIA *jogadoria);

#endif