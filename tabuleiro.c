#include <stdio.h>
#include "tabuleiro.h"

void inicializaTabuleiro(Tabuleiro *tab){

    int M[3][3];
    int i, j;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            (*tab).M[i][j] = VAZIO;
        }
    }
}

void desenha(Tabuleiro *tab){

}

int temVencedor(Tabuleiro *tab){
    int i, j;
    int soma = 0;

    for(i=0; i<3; i++){
        soma = 0;
        for(j=0; j<3; j++){
            soma += (*tab).M[i][j];
        }
        if((soma==3) || (soma==12)){
            return 1;
        }
    }

    for(i=0; i<3; i++){
        soma = 0;
        for(j=0; j<3; j++){
            soma += (*tab).M[j][i];
        }
        if((soma==3) || (soma==12)){
            return 1;
        }
    }
    soma = ((*tab).M[0][0] + (*tab).M[1][1] + (*tab).M[2][2]);
    if((soma==3) || (soma==12)){
        return 1;
    }
    soma = ((*tab).M[0][2] + (*tab).M[1][1] + (*tab).M[2][0]);
    if((soma==3) || (soma==12)){
        return 1;
    }

    return 0;
    
}
void marcaJogada(Tabuleiro *tab, int x, int y, int tipo){
    (*tab).M[x][y] = tipo;
}