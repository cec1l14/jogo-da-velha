#include <stdio.h>
#include "partida.h"

void configuraJogadores(JogadorTeclado *jogador1, JogadorTeclado *jogador2){
    int tipo1, tipo2;

    printf("Escolha o tipo do jogador 1 (1 representa 0 e 4 representa X): ");
    scanf("%d", &tipo1);

    while(tipo1 != O && tipo1 != X){
        printf("Escolha invalida (selecione 1 para 0 e 4 para X): ");
        scanf("%d", &tipo1);
    }

    (*jogador1).tipo = tipo1;

    printf("Escolha o tipo do jogador 2 (1 representa O e 4 representa X): ");
    scanf("%d", &tipo2);

    while(tipo2 != O && tipo2 != X){
        printf("Escolha invalida (selecione 1 para 0 e 4 para X): ");
        scanf("%d", &tipo2);
    }

    (*jogador2).tipo = tipo2;
}

void inicia(Tabuleiro *tab, JogadorTeclado *jogador1, JogadorTeclado *jogador2){
    inicializaTabuleiro(tab);
    desenha(tab);

    int vencedor = 0;
    int vez = 0;

    while(vencedor == 0){
        if(vez % 2 == 0){
            joga(jogador1, tab);
        } else {
            joga(jogador2, tab);
        }
        desenha(tab);
        vencedor = temVencedor(tab);
        vez++;
    }

    if(vencedor == O){
        printf("Jogador O venceu!\n");
    } else if(vencedor == X){
        printf("Jogador X venceu!\n");
    } else {
        printf("Empate!\n");
    }
}