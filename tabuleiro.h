#ifndef TABULEIRO_H
#define TABULEIRO_H

#define VAZIO 0
#define O 1
#define X 4

typedef struct{
    int M[3][3];
} Tabuleiro;

void inicializaTabuleiro(Tabuleiro *tab);
void desenha(Tabuleiro *tab);
int temVencedor(Tabuleiro *tab);
void marcaJogada(Tabuleiro *tab, int x, int y, int tipo);

#endif