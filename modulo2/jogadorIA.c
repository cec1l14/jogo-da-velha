#include <stdio.h>
#include "jogadorIA.h"

void jogaIA(Tabuleiro *tab, JogadorIA *jogadorIA){ 

    int jogadorHumano;

    if (jogadorIA->tipo == 1)
    {
        jogadorHumano = 4;
    } else {
        jogadorHumano = 1;
    }

    // R1. Se você ou seu oponente tiver duas marcações em sequência, marque o quadrado restante.

    int i;

    for (i = 0; i < 3; i++) {

        // parte IA
        // verificação das linhas 

        if (tab->M[i][0] == jogadorIA->tipo && tab->M[i][1] == jogadorIA->tipo && tab->M[i][2] == VAZIO) {
            marcaJogada(tab, i, 2, jogadorIA->tipo);
            return;
        }
        if (tab->M[i][1] == jogadorIA->tipo && tab->M[i][2] == jogadorIA->tipo && tab->M[i][0] == VAZIO) {
            marcaJogada(tab, i, 0, jogadorIA->tipo);
            return;
        }
        if (tab->M[i][0] == jogadorIA->tipo && tab->M[i][2] == jogadorIA->tipo && tab->M[i][1] == VAZIO) {
            marcaJogada(tab, i, 1, jogadorIA->tipo);
            return;
        }

        // verificação das colunas

        if (tab->M[0][i] == jogadorIA->tipo && tab->M[1][i] == jogadorIA->tipo && tab->M[2][i] == VAZIO) {
            marcaJogada(tab, 2, i, jogadorIA->tipo);
            return;
        }
        if (tab->M[1][i] == jogadorIA->tipo && tab->M[2][i] == jogadorIA->tipo && tab->M[0][i] == VAZIO) {
            marcaJogada(tab, 0, i, jogadorIA->tipo);
            return;
        }
        if (tab->M[0][i] == jogadorIA->tipo && tab->M[2][i] == jogadorIA->tipo && tab->M[1][i] == VAZIO) {
            marcaJogada(tab, 1, i, jogadorIA->tipo);
            return;
        }
    }

    // verificação da diagonal principal

    if (tab->M[0][0] == jogadorIA->tipo && tab->M[1][1] == jogadorIA->tipo && tab->M[2][2] == VAZIO) {
        marcaJogada(tab, 2, 2, jogadorIA->tipo);
        return;
    }
    if (tab->M[1][1] == jogadorIA->tipo && tab->M[2][2] == jogadorIA->tipo && tab->M[0][0] == VAZIO) {
        marcaJogada(tab, 0, 0, jogadorIA->tipo);
        return;
    }
    if (tab->M[0][0] == jogadorIA->tipo && tab->M[2][2] == jogadorIA->tipo && tab->M[1][1] == VAZIO) {
        marcaJogada(tab, 1, 1, jogadorIA->tipo);
        return;
    }

    // verificação da diagonal secundária

    if (tab->M[0][2] == jogadorIA->tipo && tab->M[1][1] == jogadorIA->tipo && tab->M[2][0] == VAZIO) {
        marcaJogada(tab, 2, 0, jogadorIA->tipo);
        return;
    }
    if (tab->M[1][1] == jogadorIA->tipo && tab->M[2][0] == jogadorIA->tipo && tab->M[0][2] == VAZIO) {
        marcaJogada(tab, 0, 2, jogadorIA->tipo);
        return;
    }
    if (tab->M[0][2] == jogadorIA->tipo && tab->M[2][0] == jogadorIA->tipo && tab->M[1][1] == VAZIO) {
        marcaJogada(tab, 1, 1, jogadorIA->tipo);
        return;
    }

    for (i = 0; i < 3; i++) {

        // parte humano
        // verificação das linhas

        if (tab->M[i][0] == jogadorHumano && tab->M[i][1] == jogadorHumano && tab->M[i][2] == VAZIO) {
            marcaJogada(tab, i, 2, jogadorIA->tipo);
            return;
        }
        if (tab->M[i][1] == jogadorHumano && tab->M[i][2] == jogadorHumano && tab->M[i][0] == VAZIO) {
            marcaJogada(tab, i, 0, jogadorIA->tipo);
            return;
        }
        if (tab->M[i][0] == jogadorHumano && tab->M[i][2] == jogadorHumano && tab->M[i][1] == VAZIO) {
            marcaJogada(tab, i, 1, jogadorIA->tipo);
            return;
        }

        // verificação das colunas

        if (tab->M[0][i] == jogadorHumano && tab->M[1][i] == jogadorHumano && tab->M[2][i] == VAZIO) {
            marcaJogada(tab, 2, i, jogadorIA->tipo);
            return;
        }
        if (tab->M[1][i] == jogadorHumano && tab->M[2][i] == jogadorHumano && tab->M[0][i] == VAZIO) {
            marcaJogada(tab, 0, i, jogadorIA->tipo);
            return;
        }
        if (tab->M[0][i] == jogadorHumano && tab->M[2][i] == jogadorHumano && tab->M[1][i] == VAZIO) {
            marcaJogada(tab, 1, i, jogadorIA->tipo);
            return;
        }
    }

    // verificação da diagonal principal

    if (tab->M[0][0] == jogadorHumano && tab->M[1][1] == jogadorHumano && tab->M[2][2] == VAZIO) {
        marcaJogada(tab, 2, 2, jogadorIA->tipo);
        return;
    }
    if (tab->M[1][1] == jogadorHumano && tab->M[2][2] == jogadorHumano && tab->M[0][0] == VAZIO) {
        marcaJogada(tab, 0, 0, jogadorIA->tipo);
        return;
    }
    if (tab->M[0][0] == jogadorHumano && tab->M[2][2] == jogadorHumano && tab->M[1][1] == VAZIO) {
        marcaJogada(tab, 1, 1, jogadorIA->tipo);
        return;
    }

    // verificação da diagonal secundária

    if (tab->M[0][2] == jogadorHumano && tab->M[1][1] == jogadorHumano && tab->M[2][0] == VAZIO) {
        marcaJogada(tab, 2, 0, jogadorIA->tipo);
        return;
    }
    if (tab->M[1][1] == jogadorHumano && tab->M[2][0] == jogadorHumano && tab->M[0][2] == VAZIO) {
        marcaJogada(tab, 0, 2, jogadorIA->tipo);
        return;
    }
    if (tab->M[0][2] == jogadorHumano && tab->M[2][0] == jogadorHumano && tab->M[1][1] == VAZIO) {
        marcaJogada(tab, 1, 1, jogadorIA->tipo);
        return;
    }

    // R2. Se houver uma jogada que crie duas sequências de duas marcações, use-a. 
    
    int arredores_i, arredores_j, soma_arredores;
    
    for (int i = 0; i < 3; i++){
        
        for(int j = 0; j < 3; j++){
            
            soma_arredores = 0;
            
            for(int k = -1; k <=1; k++){
                
                for(int l = -1; l <= 1; l++){

                    if(k == 0 && l == 0){
                        continue;
                    }
                    
                    arredores_i = i + k;
                    arredores_j = j + l;
                    
                    if(arredores_i >= 0 && arredores_i < 3 && arredores_j >= 0 && arredores_j < 3){
                        if(tab->M[arredores_i][arredores_j] == jogadorIA->tipo){
                            soma_arredores += 1;
                        }
                    }
                }
            }
            
            if (soma_arredores >= 2 && tab->M[i][j] == VAZIO){
                marcaJogada(tab, i, j, jogadorIA->tipo);
                return;
            }
            
        }
    }

    // R3. Se o quadrado central estiver livre, marque-o.

    if(tab->M[1][1] == VAZIO){
        marcaJogada(tab, 1, 1, jogadorIA->tipo);
        return;
    }
    
    // R4: Se seu oponente tiver marcado um dos cantos, marque o canto oposto
    
    int cantos_linha, cantos_coluna, opostos_linha, opostos_coluna;
    
    int cantos[4][2] = {{0, 0}, {0, 2}, {2, 2}, {2, 0}};

    for (int i = 0; i < 4; i++) {
        cantos_linha = cantos[i][0];
        cantos_coluna = cantos[i][1];

        if (cantos_linha == 0) {
            opostos_linha = 2;
        } else {
            opostos_linha = 0;
        }

        if (cantos_coluna == 0) {
            opostos_coluna = 2;
        } else {
            opostos_coluna = 0;
        }

        if (tab->M[cantos_linha][cantos_coluna] == jogadorHumano && tab->M[opostos_linha][opostos_coluna] == VAZIO) {
            marcaJogada(tab, opostos_linha, opostos_coluna, jogadorIA->tipo);
            return; 
        }
    }

    // R5: Se houver um canto vazio, marque-o.
    
    for (int i = 0; i < 4; i++) {
        int cantos_linha = cantos[i][0];
        int cantos_coluna = cantos[i][1];
        if (tab->M[cantos_linha][cantos_coluna] == VAZIO) {
            marcaJogada(tab, cantos_linha, cantos_coluna, jogadorIA->tipo);
            return;
        }
    }

    // R6:  Marque arbitrariamente um quadrado vazio

    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            if (tab->M[linha][coluna] == VAZIO) {
                marcaJogada(tab, linha, coluna, jogadorIA->tipo);
                return;
            }
        }
    }
}
