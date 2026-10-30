#ifndef JOGADORIA_H
#define JOGADORIA_H
#include "tabuleiro.h"

typedef struct{
    int tipo;
} JogadorIA;

int r1(Tabuleiro *tab, JogadorIA *ia, int jogadorHumano);
int r2(Tabuleiro *tab, JogadorIA *ia);
int r3(Tabuleiro *tab, JogadorIA *ia);
int r4(Tabuleiro *tab, JogadorIA *ia, int jogadorHumano);
int r5(Tabuleiro *tab, JogadorIA *ia);
int r6(Tabuleiro *tab, JogadorIA *ia);
void jogaIA(Tabuleiro *tab, JogadorIA *ia);

#endif