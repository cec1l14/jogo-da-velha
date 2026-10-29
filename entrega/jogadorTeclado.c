/****
 * Implementação do módulo: jogadorTeclado
 * Autores: Cecília Candeia e Matheus Fernandes
 * Data de Criação: 19/10/2026
 * Última alteração: 26/10/2026
 * Descrição Geral: jogador humano que joga pelo teclado. A função joga() pede
 *   a linha e a coluna (de 0 a 2) e repete a leitura enquanto a posição estiver
 *   fora do tabuleiro ou ocupada. Depois marca a casa com o símbolo (tipo) do
 *   jogador.
 ****/

#include <stdio.h>
#include "jogadorTeclado.h"

void joga(JogadorTeclado *jogador, Tabuleiro *tab){
    
    printf("\n Turno do Jogador %c. \n", conversao(jogador->tipo));
    
    int linha, coluna;
    int jogadaValida = 0; 
    
    while (!jogadaValida) {
        printf("Digite a linha da jogada (0, 1 ou 2): ");
        scanf("%d", &linha);

        printf("Digite a coluna da jogada (0, 1 ou 2): ");
        scanf("%d", &coluna);
        
        
        if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tab->M[linha][coluna] == VAZIO) {
            marcaJogada(tab, linha, coluna, jogador->tipo);
            jogadaValida = 1;
        } else if(linha < 0 || linha > 3 || coluna < 0 || coluna > 3){
            printf("Jogada invalida! A jogada desejada esta em uma posicao fora do tabuleiro.\n");
        } else if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tab->M[linha][coluna] != VAZIO){
            printf("Jogada invalida! A jogada desejada esta em uma posicao ocupada.\n");
    }
 }
}
