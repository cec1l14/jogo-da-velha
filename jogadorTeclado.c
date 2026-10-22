#include <stdio.h>
#include "jogadorTeclado.h"

int tipo;


void joga(Tabuleiro *tab) {
    char letra;
    if (tipo == 4) {
        letra = 'X';
    } else {
        letra = 'O';
    }

    printf("\n Turno do Jogador %c. \n", letra);
    
    int linha, coluna;
    int jogadaValida = 0; 
    
    while (!jogadaValida) {
        printf("Digite a linha da jogada (0, 1 ou 2): ");
        scanf("%d", &linha);

        printf("Digite a coluna da jogada (0, 1 ou 2): ");
        scanf("%d", &coluna);
        
        
        if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tab->M[linha][coluna] == 0) {
            marcaJogada(tab, linha, coluna, tipo);
            jogadaValida = 1;
        } else {
            printf("Jogada inválida! A jogada desejada está em uma posição fora do tabuleiro ou ocupada.\n");
        }
    }
 }
