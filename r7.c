// EXTRA! Adiciona invencibilidade. (Olhei as regras lá de Newell e Simon), essa seria tecnicamente a R4.
// Se o oponente tiver apenas uma possibilidade de criar duas sequências de duas marcações, bloqueie-a.
// Se ele tiver várias maneiras, a melhor estratégia é atacá-lo criando duas peças em linha para forçá-lo a se defender, desde que essa defesa não resulte na criação de duas sequências de duas marcações para ele. (foi DIFÍCIL!)

#include "r7.h"

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
        return;
 
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
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
