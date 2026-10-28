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

void jogaIA(Tabuleiro *tab, JogadorIA *jogadorIA){ // colocando jogaIA, pois jogadorTeclado já possui a função joga

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
    
int possiveisJogadas[8][2];       
int duplasIA, duplasHumano;
int possiveisForks = 0;
int casasVazias [8][2];                   

for (int i = 0; i<3; i++){
    
    for (int j = 0; j<3; j++){
        
        if (tab->M[i][j] == 0){
            
            marcaJogada(tab,i,j,jogadorIA->tipo);
            duplasIA = 0;

            // olhando linhas
            if((tab->M[0][0]==jogadorIA->tipo && tab->M[0][1]==jogadorIA->tipo && tab->M[0][2]==0) ||
               (tab->M[0][0]==jogadorIA->tipo && tab->M[0][2]==jogadorIA->tipo && tab->M[0][1]==0) ||
               (tab->M[0][1]==jogadorIA->tipo && tab->M[0][2]==jogadorIA->tipo && tab->M[0][0]==0)){
                duplasIA++;
            }
            if((tab->M[1][0]==jogadorIA->tipo && tab->M[1][1]==jogadorIA->tipo && tab->M[1][2]==0) ||
               (tab->M[1][0]==jogadorIA->tipo && tab->M[1][2]==jogadorIA->tipo && tab->M[1][1]==0) ||
               (tab->M[1][1]==jogadorIA->tipo && tab->M[1][2]==jogadorIA->tipo && tab->M[1][0]==0)){
                duplasIA++;
            }
            if((tab->M[2][0]==jogadorIA->tipo && tab->M[2][1]==jogadorIA->tipo && tab->M[2][2]==0) ||
               (tab->M[2][0]==jogadorIA->tipo && tab->M[2][2]==jogadorIA->tipo && tab->M[2][1]==0) ||
               (tab->M[2][1]==jogadorIA->tipo && tab->M[2][2]==jogadorIA->tipo && tab->M[2][0]==0)){
                duplasIA++;
            }

            // olhando colunas
            if((tab->M[0][0]==jogadorIA->tipo && tab->M[1][0]==jogadorIA->tipo && tab->M[2][0]==0) ||
               (tab->M[0][0]==jogadorIA->tipo && tab->M[2][0]==jogadorIA->tipo && tab->M[1][0]==0) ||
               (tab->M[1][0]==jogadorIA->tipo && tab->M[2][0]==jogadorIA->tipo && tab->M[0][0]==0)){
                duplasIA++;
            }
            if((tab->M[0][1]==jogadorIA->tipo && tab->M[1][1]==jogadorIA->tipo && tab->M[2][1]==0) ||
               (tab->M[0][1]==jogadorIA->tipo && tab->M[2][1]==jogadorIA->tipo && tab->M[1][1]==0) ||
               (tab->M[1][1]==jogadorIA->tipo && tab->M[2][1]==jogadorIA->tipo && tab->M[0][1]==0)){
                duplasIA++;
            }
            if((tab->M[0][2]==jogadorIA->tipo && tab->M[1][2]==jogadorIA->tipo && tab->M[2][2]==0) ||
               (tab->M[0][2]==jogadorIA->tipo && tab->M[2][2]==jogadorIA->tipo && tab->M[1][2]==0) ||
               (tab->M[1][2]==jogadorIA->tipo && tab->M[2][2]==jogadorIA->tipo && tab->M[0][2]==0)){
                duplasIA++;
            }

            // olhando diagonais
            if((tab->M[0][0]==jogadorIA->tipo && tab->M[1][1]==jogadorIA->tipo && tab->M[2][2]==0) ||
               (tab->M[0][0]==jogadorIA->tipo && tab->M[2][2]==jogadorIA->tipo && tab->M[1][1]==0) ||
               (tab->M[1][1]==jogadorIA->tipo && tab->M[2][2]==jogadorIA->tipo && tab->M[0][0]==0)){
                duplasIA++;
            }
            if((tab->M[0][2]==jogadorIA->tipo && tab->M[1][1]==jogadorIA->tipo && tab->M[2][0]==0) ||
               (tab->M[0][2]==jogadorIA->tipo && tab->M[2][0]==jogadorIA->tipo && tab->M[1][1]==0) ||
               (tab->M[1][1]==jogadorIA->tipo && tab->M[2][0]==jogadorIA->tipo && tab->M[0][2]==0)){
                duplasIA++;
            }

            if(duplasIA >= 2){
                return;
            }
            else {
                marcaJogada(tab,i,j,0);
            }
        }
    }
}

// EXTRA! Adiciona invencibilidade. (Olhei as regras lá de Newell e Simon), essa seria tecnicamente a R4.
// Se o oponente tiver apenas uma possibilidade de criar duas sequências de duas marcações, bloqueie-a.
// Se ele tiver várias maneiras, a melhor estratégia é atacá-lo criando duas peças em linha para forçá-lo a se defender, desde que essa defesa não resulte na criação de duas sequências de duas marcações para ele. (foi DIFÍCIL!)

for (int l = 0; l < 8; l++){
    possiveisJogadas[l][0] = -100;
    possiveisJogadas[l][1] = -100;
}

for (int i = 0; i<3; i++){
    
    for (int j = 0; j<3; j++){
        
        if (tab->M[i][j] == 0){
            
            marcaJogada(tab,i,j,jogadorHumano);
            duplasHumano = 0;

            // olhando linhas
            if((tab->M[0][0]==jogadorHumano && tab->M[0][1]==jogadorHumano && tab->M[0][2]==0) ||
               (tab->M[0][0]==jogadorHumano && tab->M[0][2]==jogadorHumano && tab->M[0][1]==0) ||
               (tab->M[0][1]==jogadorHumano && tab->M[0][2]==jogadorHumano && tab->M[0][0]==0)){
                duplasHumano++;
            }
            if((tab->M[1][0]==jogadorHumano && tab->M[1][1]==jogadorHumano && tab->M[1][2]==0) ||
               (tab->M[1][0]==jogadorHumano && tab->M[1][2]==jogadorHumano && tab->M[1][1]==0) ||
               (tab->M[1][1]==jogadorHumano && tab->M[1][2]==jogadorHumano && tab->M[1][0]==0)){
                duplasHumano++;
            }
            if((tab->M[2][0]==jogadorHumano && tab->M[2][1]==jogadorHumano && tab->M[2][2]==0) ||
               (tab->M[2][0]==jogadorHumano && tab->M[2][2]==jogadorHumano && tab->M[2][1]==0) ||
               (tab->M[2][1]==jogadorHumano && tab->M[2][2]==jogadorHumano && tab->M[2][0]==0)){
                duplasHumano++;
            }

            // olhando colunas
            if((tab->M[0][0]==jogadorHumano && tab->M[1][0]==jogadorHumano && tab->M[2][0]==0) ||
               (tab->M[0][0]==jogadorHumano && tab->M[2][0]==jogadorHumano && tab->M[1][0]==0) ||
               (tab->M[1][0]==jogadorHumano && tab->M[2][0]==jogadorHumano && tab->M[0][0]==0)){
                duplasHumano++;
            }
            if((tab->M[0][1]==jogadorHumano && tab->M[1][1]==jogadorHumano && tab->M[2][1]==0) ||
               (tab->M[0][1]==jogadorHumano && tab->M[2][1]==jogadorHumano && tab->M[1][1]==0) ||
               (tab->M[1][1]==jogadorHumano && tab->M[2][1]==jogadorHumano && tab->M[0][1]==0)){
                duplasHumano++;
            }
            if((tab->M[0][2]==jogadorHumano && tab->M[1][2]==jogadorHumano && tab->M[2][2]==0) ||
               (tab->M[0][2]==jogadorHumano && tab->M[2][2]==jogadorHumano && tab->M[1][2]==0) ||
               (tab->M[1][2]==jogadorHumano && tab->M[2][2]==jogadorHumano && tab->M[0][2]==0)){
                duplasHumano++;
            }

            // olhando diagonais
            if((tab->M[0][0]==jogadorHumano && tab->M[1][1]==jogadorHumano && tab->M[2][2]==0) ||
               (tab->M[0][0]==jogadorHumano && tab->M[2][2]==jogadorHumano && tab->M[1][1]==0) ||
               (tab->M[1][1]==jogadorHumano && tab->M[2][2]==jogadorHumano && tab->M[0][0]==0)){
                duplasHumano++;
            }
            if((tab->M[0][2]==jogadorHumano && tab->M[1][1]==jogadorHumano && tab->M[2][0]==0) ||
               (tab->M[0][2]==jogadorHumano && tab->M[2][0]==jogadorHumano && tab->M[1][1]==0) ||
               (tab->M[1][1]==jogadorHumano && tab->M[2][0]==jogadorHumano && tab->M[0][2]==0)){
                duplasHumano++;
            }

            if(duplasHumano > 1){
                possiveisJogadas[possiveisForks][0] = i;   
                possiveisJogadas[possiveisForks][1] = j;   
                possiveisForks++;
                marcaJogada(tab,i,j,0);

            } else {
                marcaJogada(tab,i,j,0);
            }
        }
    }
}
if (possiveisForks == 1){
    marcaJogada(tab,possiveisJogadas[0][0],possiveisJogadas[0][1],jogadorIA->tipo);
    return;

} else if (possiveisForks > 1){

   for (int i = 0; i<3; i++){
       
    for (int j = 0; j<3; j++){
        
        if (tab->M[i][j] == 0){
            
            for (int l = 0; l < 8; l++){
                casasVazias[l][0] = -100;
                casasVazias[l][1] = -100;
            }
            
            marcaJogada(tab,i,j,jogadorIA->tipo);
            duplasIA = 0;

            // olhando linhas
            if((tab->M[0][0]==jogadorIA->tipo && tab->M[0][1]==jogadorIA->tipo && tab->M[0][2]==0) ||
               (tab->M[0][0]==jogadorIA->tipo && tab->M[0][2]==jogadorIA->tipo && tab->M[0][1]==0) ||
               (tab->M[0][1]==jogadorIA->tipo && tab->M[0][2]==jogadorIA->tipo && tab->M[0][0]==0)){
                   
                duplasIA++;
                
                if (tab->M[0][0] == 0){ 
                    casasVazias[0][0] = 0; 
                    casasVazias[0][1] = 0; 
                }   
                if (tab->M[0][1] == 0){ 
                    casasVazias[0][0] = 0; 
                    casasVazias[0][1] = 1; 
                }
                if (tab->M[0][2] == 0){ 
                    casasVazias[0][0] = 0; 
                    casasVazias[0][1] = 2; 
                }
            }
            if((tab->M[1][0]==jogadorIA->tipo && tab->M[1][1]==jogadorIA->tipo && tab->M[1][2]==0) ||
               (tab->M[1][0]==jogadorIA->tipo && tab->M[1][2]==jogadorIA->tipo && tab->M[1][1]==0) ||
               (tab->M[1][1]==jogadorIA->tipo && tab->M[1][2]==jogadorIA->tipo && tab->M[1][0]==0)){
                   
                duplasIA++;
                
                if (tab->M[1][0] == 0){ 
                    casasVazias[1][0] = 1; 
                    casasVazias[1][1] = 0; 
                }
                if (tab->M[1][1] == 0){ 
                    casasVazias[1][0] = 1; 
                    casasVazias[1][1] = 1; 
                }
                if (tab->M[1][2] == 0){ 
                    casasVazias[1][0] = 1; 
                    casasVazias[1][1] = 2; 
                }
            }
            if((tab->M[2][0]==jogadorIA->tipo && tab->M[2][1]==jogadorIA->tipo && tab->M[2][2]==0) ||
               (tab->M[2][0]==jogadorIA->tipo && tab->M[2][2]==jogadorIA->tipo && tab->M[2][1]==0) ||
               (tab->M[2][1]==jogadorIA->tipo && tab->M[2][2]==jogadorIA->tipo && tab->M[2][0]==0)){
                   
                duplasIA++;
                
                if (tab->M[2][0] == 0){ 
                    casasVazias[2][0] = 2; 
                    casasVazias[2][1] = 0; 
                }
                if (tab->M[2][1] == 0){ 
                    casasVazias[2][0] = 2; 
                    casasVazias[2][1] = 1; 
                }
                if (tab->M[2][2] == 0){ 
                    casasVazias[2][0] = 2; 
                    casasVazias[2][1] = 2; 
                }
                    
            }

            // olhando colunas
            if((tab->M[0][0]==jogadorIA->tipo && tab->M[1][0]==jogadorIA->tipo && tab->M[2][0]==0) ||
               (tab->M[0][0]==jogadorIA->tipo && tab->M[2][0]==jogadorIA->tipo && tab->M[1][0]==0) ||
               (tab->M[1][0]==jogadorIA->tipo && tab->M[2][0]==jogadorIA->tipo && tab->M[0][0]==0)){
                   
                duplasIA++;
                
                if (tab->M[0][0] == 0){ 
                    casasVazias[3][0] = 0; 
                    casasVazias[3][1] = 0; 
                }
                if (tab->M[1][0] == 0){ 
                    casasVazias[3][0] = 1; 
                    casasVazias[3][1] = 0; 
                }
                if (tab->M[2][0] == 0){ 
                    casasVazias[3][0] = 2; 
                    casasVazias[3][1] = 0; 
                }
            }
            if((tab->M[0][1]==jogadorIA->tipo && tab->M[1][1]==jogadorIA->tipo && tab->M[2][1]==0) ||
               (tab->M[0][1]==jogadorIA->tipo && tab->M[2][1]==jogadorIA->tipo && tab->M[1][1]==0) ||
               (tab->M[1][1]==jogadorIA->tipo && tab->M[2][1]==jogadorIA->tipo && tab->M[0][1]==0)){
                   
                duplasIA++;
                
                if (tab->M[0][1] == 0){ 
                    casasVazias[4][0] = 0; 
                    casasVazias[4][1] = 1; 
                }
                if (tab->M[1][1] == 0){ 
                    casasVazias[4][0] = 1; 
                    casasVazias[4][1] = 1; 
                }
                if (tab->M[2][1] == 0){ 
                    casasVazias[4][0] = 2; 
                    casasVazias[4][1] = 1; 
                }
            }
            if((tab->M[0][2]==jogadorIA->tipo && tab->M[1][2]==jogadorIA->tipo && tab->M[2][2]==0) ||
               (tab->M[0][2]==jogadorIA->tipo && tab->M[2][2]==jogadorIA->tipo && tab->M[1][2]==0) ||
               (tab->M[1][2]==jogadorIA->tipo && tab->M[2][2]==jogadorIA->tipo && tab->M[0][2]==0)){
                   
                duplasIA++;
                
                if (tab->M[0][2] == 0){ 
                    casasVazias[5][0] = 0; 
                    casasVazias[5][1] = 2; 
                }
                if (tab->M[1][2] == 0){ 
                    casasVazias[5][0] = 1; 
                    casasVazias[5][1] = 2; 
                }
                if (tab->M[2][2] == 0){ 
                    casasVazias[5][0] = 2; 
                    casasVazias[5][1] = 2; 
                }
            }

            // olhando diagonais
            if((tab->M[0][0]==jogadorIA->tipo && tab->M[1][1]==jogadorIA->tipo && tab->M[2][2]==0) ||
               (tab->M[0][0]==jogadorIA->tipo && tab->M[2][2]==jogadorIA->tipo && tab->M[1][1]==0) ||
               (tab->M[1][1]==jogadorIA->tipo && tab->M[2][2]==jogadorIA->tipo && tab->M[0][0]==0)){
                duplasIA++;
                if (tab->M[0][0] == 0){ 
                    casasVazias[6][0] = 0; 
                    casasVazias[6][1] = 0; 
                }
                if (tab->M[1][1] == 0){ 
                    casasVazias[6][0] = 1; 
                    casasVazias[6][1] = 1; 
                }
                if (tab->M[2][2] == 0){ 
                    casasVazias[6][0] = 2; 
                    casasVazias[6][1] = 2; 
                }
            }
            if((tab->M[0][2]==jogadorIA->tipo && tab->M[1][1]==jogadorIA->tipo && tab->M[2][0]==0) ||
               (tab->M[0][2]==jogadorIA->tipo && tab->M[2][0]==jogadorIA->tipo && tab->M[1][1]==0) ||
               (tab->M[1][1]==jogadorIA->tipo && tab->M[2][0]==jogadorIA->tipo && tab->M[0][2]==0)){
                duplasIA++;
                if (tab->M[0][2] == 0){ 
                    casasVazias[7][0] = 0; 
                    casasVazias[7][1] = 2; 
                }
                if (tab->M[1][1] == 0){ 
                    casasVazias[7][0] = 1; 
                    casasVazias[7][1] = 1; 
                }
                if (tab->M[2][0] == 0){ 
                    casasVazias[7][0] = 2; 
                    casasVazias[7][1] = 0; 
                }
            }

            marcaJogada(tab,i,j,0);

            if(duplasIA == 0){
                continue;   
            } else {
                // odeio o fato de que a biblioteca normal n tem booleano
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
                    marcaJogada(tab,i,j,jogadorIA->tipo); 
                    return;
                }
            }
        }
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