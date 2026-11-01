/****
 * Implementação do módulo: jogadorIA
 * Autores: Cecília Candeia e Matheus Fernandes
 * Data de Criação: 23/10/2026
 * Última alteração: 31/10/2026
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

// R1. Se você ou seu oponente tiver duas marcações em sequência, marque o quadrado restante.

int r1(Tabuleiro *tab, JogadorIA *ia, int jogadorHumano){
    int i;

    for (i = 0; i < 3; i++) {

        if (tab->M[i][0] == ia->tipo && tab->M[i][1] == ia->tipo && tab->M[i][2] == VAZIO) {
            marcaJogada(tab, i, 2, ia->tipo);
            return 1;
        }
        if (tab->M[i][1] == ia->tipo && tab->M[i][2] == ia->tipo && tab->M[i][0] == VAZIO) {
            marcaJogada(tab, i, 0, ia->tipo);
            return 1;
        }
        if (tab->M[i][0] == ia->tipo && tab->M[i][2] == ia->tipo && tab->M[i][1] == VAZIO) {
            marcaJogada(tab, i, 1, ia->tipo);
            return 1;
        }

        if (tab->M[0][i] == ia->tipo && tab->M[1][i] == ia->tipo && tab->M[2][i] == VAZIO) {
            marcaJogada(tab, 2, i, ia->tipo);
            return 1;
        }
        if (tab->M[1][i] == ia->tipo && tab->M[2][i] == ia->tipo && tab->M[0][i] == VAZIO) {
            marcaJogada(tab, 0, i, ia->tipo);
            return 1;
        }
        if (tab->M[0][i] == ia->tipo && tab->M[2][i] == ia->tipo && tab->M[1][i] == VAZIO) {
            marcaJogada(tab, 1, i, ia->tipo);
            return 1;
        }
    }

    if (tab->M[0][0] == ia->tipo && tab->M[1][1] == ia->tipo && tab->M[2][2] == VAZIO) {
        marcaJogada(tab, 2, 2, ia->tipo);
        return 1;
    }
    if (tab->M[1][1] == ia->tipo && tab->M[2][2] == ia->tipo && tab->M[0][0] == VAZIO) {
        marcaJogada(tab, 0, 0, ia->tipo);
        return 1;
    }
    if (tab->M[0][0] == ia->tipo && tab->M[2][2] == ia->tipo && tab->M[1][1] == VAZIO) {
        marcaJogada(tab, 1, 1, ia->tipo);
        return 1;
    }

    if (tab->M[0][2] == ia->tipo && tab->M[1][1] == ia->tipo && tab->M[2][0] == VAZIO) {
        marcaJogada(tab, 2, 0, ia->tipo);
        return 1;
    }
    if (tab->M[1][1] == ia->tipo && tab->M[2][0] == ia->tipo && tab->M[0][2] == VAZIO) {
        marcaJogada(tab, 0, 2, ia->tipo);
        return 1;
    }
    if (tab->M[0][2] == ia->tipo && tab->M[2][0] == ia->tipo && tab->M[1][1] == VAZIO) {
        marcaJogada(tab, 1, 1, ia->tipo);
        return 1;
    }

    for (i = 0; i < 3; i++) {

        if (tab->M[i][0] == jogadorHumano && tab->M[i][1] == jogadorHumano && tab->M[i][2] == VAZIO) {
            marcaJogada(tab, i, 2, ia->tipo);
            return 1;
        }
        if (tab->M[i][1] == jogadorHumano && tab->M[i][2] == jogadorHumano && tab->M[i][0] == VAZIO) {
            marcaJogada(tab, i, 0, ia->tipo);
            return 1;
        }
        if (tab->M[i][0] == jogadorHumano && tab->M[i][2] == jogadorHumano && tab->M[i][1] == VAZIO) {
            marcaJogada(tab, i, 1, ia->tipo);
            return 1;
        }

        if (tab->M[0][i] == jogadorHumano && tab->M[1][i] == jogadorHumano && tab->M[2][i] == VAZIO) {
            marcaJogada(tab, 2, i, ia->tipo);
            return 1;
        }
        if (tab->M[1][i] == jogadorHumano && tab->M[2][i] == jogadorHumano && tab->M[0][i] == VAZIO) {
            marcaJogada(tab, 0, i, ia->tipo);
            return 1;
        }
        if (tab->M[0][i] == jogadorHumano && tab->M[2][i] == jogadorHumano && tab->M[1][i] == VAZIO) {
            marcaJogada(tab, 1, i, ia->tipo);
            return 1;
        }
    }

    if (tab->M[0][0] == jogadorHumano && tab->M[1][1] == jogadorHumano && tab->M[2][2] == VAZIO) {
        marcaJogada(tab, 2, 2, ia->tipo);
        return 1;
    }
    if (tab->M[1][1] == jogadorHumano && tab->M[2][2] == jogadorHumano && tab->M[0][0] == VAZIO) {
        marcaJogada(tab, 0, 0, ia->tipo);
        return 1;
    }
    if (tab->M[0][0] == jogadorHumano && tab->M[2][2] == jogadorHumano && tab->M[1][1] == VAZIO) {
        marcaJogada(tab, 1, 1, ia->tipo);
        return 1;
    }

    if (tab->M[0][2] == jogadorHumano && tab->M[1][1] == jogadorHumano && tab->M[2][0] == VAZIO) {
        marcaJogada(tab, 2, 0, ia->tipo);
        return 1;
    }
    if (tab->M[1][1] == jogadorHumano && tab->M[2][0] == jogadorHumano && tab->M[0][2] == VAZIO) {
        marcaJogada(tab, 0, 2, ia->tipo);
        return 1;
    }
    if (tab->M[0][2] == jogadorHumano && tab->M[2][0] == jogadorHumano && tab->M[1][1] == VAZIO) {
        marcaJogada(tab, 1, 1, ia->tipo);
        return 1;
    }
    return 0;
}

// R2. Se houver uma jogada que crie duas sequências de duas marcações, use-a. 

int r2(Tabuleiro *tab, JogadorIA *ia){
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
                    return 1;
                }
            }
        }
    }
    return 0;
} 

// R3. Se o quadrado central estiver livre, marque-o.

int r3(Tabuleiro *tab, JogadorIA *ia){
    if(tab->M[1][1] == VAZIO){
        marcaJogada(tab, 1, 1, ia->tipo);
        return 1;
    }
    return 0;
}

// R4: Se seu oponente tiver marcado um dos cantos, marque o canto oposto

int r4(Tabuleiro *tab, JogadorIA *ia, int jogadorHumano){
    
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
            return 1; 
        }
    }
    return 0;
}

// R5: Se houver um canto vazio, marque-o.

int r5(Tabuleiro *tab, JogadorIA *ia){
    int cantos[4][2] = {{0, 0}, {0, 2}, {2, 2}, {2, 0}};

    for (int i = 0; i < 4; i++) {
        int cantos_linha = cantos[i][0];
        int cantos_coluna = cantos[i][1];
        if (tab->M[cantos_linha][cantos_coluna] == VAZIO) {
            marcaJogada(tab, cantos_linha, cantos_coluna, ia->tipo);
            return 1;
        }
    }
    return 0;
}

// R6:  Marque arbitrariamente um quadrado vazio

int r6(Tabuleiro *tab, JogadorIA *ia){
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            if (tab->M[linha][coluna] == VAZIO) {
                marcaJogada(tab, linha, coluna, ia->tipo);
                return 1;
            }
        }
    }
    return 0;
}

// R7 - implementação extra: se houver uma jogada que crie duas sequências de duas marcações para o adversário, bloqueie-a

int regraExtra(Tabuleiro *tab, int ia, int adversario){
    
    int possiveisJogadas[8][2];
    int duplasIA, duplasHumano;
    int possiveisForks = 0;
    int casasVazias [8][2];

    for (int l = 0; l < 8; l++){
        possiveisJogadas[l][0] = -100;
        possiveisJogadas[l][1] = -100;
    }

    for (int i = 0; i<3; i++){

        for (int j = 0; j<3; j++){

            if (tab->M[i][j] == VAZIO){

                duplasHumano = 0;

                if((tab->M[i][0] + tab->M[i][1] + tab->M[i][2]) == adversario){
                    duplasHumano++;
                }

                if((tab->M[0][j] + tab->M[1][j] + tab->M[2][j]) == adversario){
                    duplasHumano++;
                }

                if(i == j && (tab->M[0][0] + tab->M[1][1] + tab->M[2][2]) == adversario){
                    duplasHumano++;
                }

                if(i + j == 2 && (tab->M[0][2] + tab->M[1][1] + tab->M[2][0]) == adversario){
                    duplasHumano++;
                }

                if(duplasHumano > 1){
                    possiveisJogadas[possiveisForks][0] = i;
                    possiveisJogadas[possiveisForks][1] = j;
                    possiveisForks++;
                }
            }
        }
    }
    if (possiveisForks == 1){
        marcaJogada(tab,possiveisJogadas[0][0],possiveisJogadas[0][1],ia);
        return 1;

    } else if (possiveisForks > 1){

        for (int i = 0; i<3; i++){

            for (int j = 0; j<3; j++){

                if (tab->M[i][j] == VAZIO){

                    for (int l = 0; l < 8; l++){
                        casasVazias[l][0] = -100;
                        casasVazias[l][1] = -100;
                    }

                    marcaJogada(tab,i,j,ia);
                    duplasIA = 0;

                    if((tab->M[i][0] + tab->M[i][1] + tab->M[i][2]) == (ia*2)){
                        duplasIA++;

                        if (tab->M[i][0] == VAZIO){
                            casasVazias[i][0] = i;
                            casasVazias[i][1] = 0;
                        }
                        if (tab->M[i][1] == VAZIO){
                            casasVazias[i][0] = i;
                            casasVazias[i][1] = 1;
                        }
                        if (tab->M[i][2] == VAZIO){
                            casasVazias[i][0] = i;
                            casasVazias[i][1] = 2;
                        }
                    }

                    if((tab->M[0][j] + tab->M[1][j] + tab->M[2][j]) == (ia*2)){
                        duplasIA++;

                        if (tab->M[0][j] == VAZIO){
                            casasVazias[j+3][0] = 0;
                            casasVazias[j+3][1] = j;      
                        }
                        if (tab->M[1][j] == VAZIO){
                            casasVazias[j+3][0] = 1;
                            casasVazias[j+3][1] = j;
                        }
                        if (tab->M[2][j] == VAZIO){
                            casasVazias[j+3][0] = 2;
                            casasVazias[j+3][1] = j;
                        }
                    }

                    if((tab->M[0][0] + tab->M[1][1] + tab->M[2][2]) == (ia*2)){
                        duplasIA++;
                        if (tab->M[0][0] == VAZIO){
                            casasVazias[6][0] = 0;
                            casasVazias[6][1] = 0;
                        }
                        if (tab->M[1][1] == VAZIO){
                            casasVazias[6][0] = 1;
                            casasVazias[6][1] = 1;
                        }
                        if (tab->M[2][2] == VAZIO){
                            casasVazias[6][0] = 2;
                            casasVazias[6][1] = 2;
                        }
                    }

                    if((tab->M[0][2] + tab->M[1][1] + tab->M[2][0]) == (ia*2)){
                        duplasIA++;

                        if (tab->M[0][2] == VAZIO){
                            casasVazias[7][0] = 0;
                            casasVazias[7][1] = 2;
                        }
                        if (tab->M[1][1] == VAZIO){
                            casasVazias[7][0] = 1;
                            casasVazias[7][1] = 1;
                        }
                        if (tab->M[2][0] == VAZIO){
                            casasVazias[7][0] = 2;
                            casasVazias[7][1] = 0;
                        }
                    }

                    marcaJogada(tab,i,j,VAZIO);   

                    if(duplasIA == 0){
                        continue;
                    } else {
                        int taConflitano = 0;
                        for (int n = 0; n < 8; n++){
                            if (casasVazias[n][0] == -100 && casasVazias[n][1] == -100){
                                continue;
                            }
                            for (int l = 0; l < possiveisForks; l++){
                                if (possiveisJogadas[l][0] == casasVazias[n][0] && possiveisJogadas[l][1] == casasVazias[n][1]){
                                    taConflitano = 1;
                                }
                            }
                        }
                        if (!taConflitano){
                            marcaJogada(tab,i,j,ia);
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void jogaIA(Tabuleiro *tab, JogadorIA *ia){

    int jogadorHumano;

    if (ia->tipo == O)
    {
        jogadorHumano = X;
    } else {
        jogadorHumano = O;
    }
    if(r1(tab, ia, jogadorHumano)) return;
    if(r2(tab, ia))                return;
    if(r3(tab, ia))                return;
    if(r4(tab, ia, jogadorHumano)) return;
    if(r5(tab, ia))                return;
    if(r6(tab, ia))                return;
    if(regraExtra(tab, ia->tipo, jogadorHumano)) return;
}