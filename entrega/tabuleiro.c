/****
 * Implementação do módulo: tabuleiro
 * Autores: Cecília Candeia e Matheus Fernandes
 * Data de Criação: 19/10/2026
 * Última alteração: 26/10/2026
 * Descrição Geral: representa o tabuleiro do jogo da velha como uma matriz 3x3
 *   de inteiros (0 = casa vazia, 1 = O, 4 = X). Oferece funções para zerar o
 *   tabuleiro, converter um valor no caractere exibido, desenhar o estado atual
 *   na tela, registrar uma jogada e verificar o resultado da partida: soma 3 de
 *   uma linha indica vitória de O, soma 12 indica vitória de X, e o tabuleiro
 *   cheio sem vencedor e empate.
 ****/

#include <stdio.h>
#include "tabuleiro.h"

void inicializaTabuleiro(Tabuleiro *tab){    
    int i, j;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            tab->M[i][j] = VAZIO;
        }
    }
}

char conversao(int valor){
    if(valor == X){
        return 'X';
    }
    if(valor == O){
        return 'O';
    }
    else{
        return ' ';
    }
} 

void desenha(Tabuleiro *tab){
    int i,j;

    printf("\033[2J\033[H"); // limpeza da tela e reposicionamento do cursor no canto superior esquerdo 

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf(" %c ", conversao(tab->M[i][j]));
            if(j<2){
                printf("|");
            }
        }
        printf("\n");
        if(i<2){
            printf("-----------\n");
        }
    }

}

int temVencedor(Tabuleiro *tab){
    int i, j;
    int soma = 0;

    for(i=0; i<3; i++){
        soma = 0;
        for(j=0; j<3; j++){
            soma += tab->M[i][j];
        }
        if(soma==3){
            return O;
        }
        if(soma==12){
            return X;
        }
    }

    for(i=0; i<3; i++){
        soma = 0;
        for(j=0; j<3; j++){
            soma += tab->M[j][i];
        }
        if(soma==3){
            return O;
        }
        if(soma==12){
            return X;
        }
    }
    soma = (tab->M[0][0] + tab->M[1][1] + tab->M[2][2]);
    if(soma==3){
        return O;
    }
    if(soma==12){
        return X;
    }
    soma = (tab->M[0][2] + tab->M[1][1] + tab->M[2][0]);
    if(soma==3){
        return O;
    }
    if(soma==12){
        return X;
    }

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(tab->M[i][j] == VAZIO){
                return 0;
            }
        }
    }
    return EMPATE;
}

void marcaJogada(Tabuleiro *tab, int x, int y, int tipo){
    tab->M[x][y] = tipo;
}