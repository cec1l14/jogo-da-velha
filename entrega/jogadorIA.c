/****
 * Implementação do módulo: jogadorIA
 * Autores: Cecília Candeia e Matheus Fernandes
 * Data de Criação: 23/10/2026
 * Última alteração: 28/10/2026
 * Descrição Geral: jogador controlado pelo computador. A função jogaIA()
 *   aplica seis regras, testadas na ordem, e encerra o turno na primeira que
 *   resultar em jogada: R1 (completa a própria sequência de duas peças ou
 *   bloqueia a do oponente), R2 (cria duas sequências de duas peças), R3
 *   (centro livre), R4 (canto oposto ao do oponente), R5 (canto vazio) e
 *   R6 (qualquer casa vazia). O nome jogaIA evita conflito com a função joga()
 *   do jogadorTeclado.
 ****/

#include <stdio.h>
#include "jogadorIA.h"

void jogaIA(Tabuleiro *tab, JogadorIA *ia){

    int jogadorHumano;

    if (ia->tipo == 1)
    {
        jogadorHumano = 4;
    } else {
        jogadorHumano = 1;
    }

    int i;

    for (i = 0; i < 3; i++) {

        if (tab->M[i][0] == ia->tipo && tab->M[i][1] == ia->tipo && tab->M[i][2] == VAZIO) {
            marcaJogada(tab, i, 2, ia->tipo);
            return;
        }
        if (tab->M[i][1] == ia->tipo && tab->M[i][2] == ia->tipo && tab->M[i][0] == VAZIO) {
            marcaJogada(tab, i, 0, ia->tipo);
            return;
        }
        if (tab->M[i][0] == ia->tipo && tab->M[i][2] == ia->tipo && tab->M[i][1] == VAZIO) {
            marcaJogada(tab, i, 1, ia->tipo);
            return;
        }

        if (tab->M[0][i] == ia->tipo && tab->M[1][i] == ia->tipo && tab->M[2][i] == VAZIO) {
            marcaJogada(tab, 2, i, ia->tipo);
            return;
        }
        if (tab->M[1][i] == ia->tipo && tab->M[2][i] == ia->tipo && tab->M[0][i] == VAZIO) {
            marcaJogada(tab, 0, i, ia->tipo);
            return;
        }
        if (tab->M[0][i] == ia->tipo && tab->M[2][i] == ia->tipo && tab->M[1][i] == VAZIO) {
            marcaJogada(tab, 1, i, ia->tipo);
            return;
        }
    }

    if (tab->M[0][0] == ia->tipo && tab->M[1][1] == ia->tipo && tab->M[2][2] == VAZIO) {
        marcaJogada(tab, 2, 2, ia->tipo);
        return;
    }
    if (tab->M[1][1] == ia->tipo && tab->M[2][2] == ia->tipo && tab->M[0][0] == VAZIO) {
        marcaJogada(tab, 0, 0, ia->tipo);
        return;
    }
    if (tab->M[0][0] == ia->tipo && tab->M[2][2] == ia->tipo && tab->M[1][1] == VAZIO) {
        marcaJogada(tab, 1, 1, ia->tipo);
        return;
    }

    if (tab->M[0][2] == ia->tipo && tab->M[1][1] == ia->tipo && tab->M[2][0] == VAZIO) {
        marcaJogada(tab, 2, 0, ia->tipo);
        return;
    }
    if (tab->M[1][1] == ia->tipo && tab->M[2][0] == ia->tipo && tab->M[0][2] == VAZIO) {
        marcaJogada(tab, 0, 2, ia->tipo);
        return;
    }
    if (tab->M[0][2] == ia->tipo && tab->M[2][0] == ia->tipo && tab->M[1][1] == VAZIO) {
        marcaJogada(tab, 1, 1, ia->tipo);
        return;
    }

    for (i = 0; i < 3; i++) {

        if (tab->M[i][0] == jogadorHumano && tab->M[i][1] == jogadorHumano && tab->M[i][2] == VAZIO) {
            marcaJogada(tab, i, 2, ia->tipo);
            return;
        }
        if (tab->M[i][1] == jogadorHumano && tab->M[i][2] == jogadorHumano && tab->M[i][0] == VAZIO) {
            marcaJogada(tab, i, 0, ia->tipo);
            return;
        }
        if (tab->M[i][0] == jogadorHumano && tab->M[i][2] == jogadorHumano && tab->M[i][1] == VAZIO) {
            marcaJogada(tab, i, 1, ia->tipo);
            return;
        }

        if (tab->M[0][i] == jogadorHumano && tab->M[1][i] == jogadorHumano && tab->M[2][i] == VAZIO) {
            marcaJogada(tab, 2, i, ia->tipo);
            return;
        }
        if (tab->M[1][i] == jogadorHumano && tab->M[2][i] == jogadorHumano && tab->M[0][i] == VAZIO) {
            marcaJogada(tab, 0, i, ia->tipo);
            return;
        }
        if (tab->M[0][i] == jogadorHumano && tab->M[2][i] == jogadorHumano && tab->M[1][i] == VAZIO) {
            marcaJogada(tab, 1, i, ia->tipo);
            return;
        }
    }

    if (tab->M[0][0] == jogadorHumano && tab->M[1][1] == jogadorHumano && tab->M[2][2] == VAZIO) {
        marcaJogada(tab, 2, 2, ia->tipo);
        return;
    }
    if (tab->M[1][1] == jogadorHumano && tab->M[2][2] == jogadorHumano && tab->M[0][0] == VAZIO) {
        marcaJogada(tab, 0, 0, ia->tipo);
        return;
    }
    if (tab->M[0][0] == jogadorHumano && tab->M[2][2] == jogadorHumano && tab->M[1][1] == VAZIO) {
        marcaJogada(tab, 1, 1, ia->tipo);
        return;
    }

    if (tab->M[0][2] == jogadorHumano && tab->M[1][1] == jogadorHumano && tab->M[2][0] == VAZIO) {
        marcaJogada(tab, 2, 0, ia->tipo);
        return;
    }
    if (tab->M[1][1] == jogadorHumano && tab->M[2][0] == jogadorHumano && tab->M[0][2] == VAZIO) {
        marcaJogada(tab, 0, 2, ia->tipo);
        return;
    }
    if (tab->M[0][2] == jogadorHumano && tab->M[2][0] == jogadorHumano && tab->M[1][1] == VAZIO) {
        marcaJogada(tab, 1, 1, ia->tipo);
        return;
    }

    int duplasIA;
    for (int i = 0; i<3; i++){
    
        for (int j = 0; j<3; j++){
    
            if (tab->M[i][j] == VAZIO){
    
                duplasIA = 0;
    
                if((tab->M[i][0] + tab->M[i][1] + tab->M[i][2]) == ia->tipo){
                    duplasIA++;
                }

                if((tab->M[0][j] + tab->M[1][j] + tab->M[2][j]) == ia->tipo){
                    duplasIA++;
                }

                if(i == j && (tab->M[0][0] + tab->M[1][1] + tab->M[2][2]) == ia->tipo){
                    duplasIA++;
                }

                if(i + j == 2 && (tab->M[0][2] + tab->M[1][1] + tab->M[2][0]) == ia->tipo){
                    duplasIA++;
                }

                if(duplasIA >= 2){
                    marcaJogada(tab,i,j,ia->tipo);
                    return;
                }
            }
        }
    }


    if(tab->M[1][1] == VAZIO){
        marcaJogada(tab, 1, 1, ia->tipo);
        return;
    }
    
    
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
            marcaJogada(tab, opostos_linha, opostos_coluna, ia->tipo);
            return; 
        }
    }

    
    for (int i = 0; i < 4; i++) {
        int cantos_linha = cantos[i][0];
        int cantos_coluna = cantos[i][1];
        if (tab->M[cantos_linha][cantos_coluna] == VAZIO) {
            marcaJogada(tab, cantos_linha, cantos_coluna, ia->tipo);
            return;
        }
    }

    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            if (tab->M[linha][coluna] == VAZIO) {
                marcaJogada(tab, linha, coluna, ia->tipo);
                return;
            }
        }
    }
}
