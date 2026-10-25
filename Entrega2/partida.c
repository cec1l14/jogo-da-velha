#include <stdio.h>
#include "partida.h"

void configuraJogadores(JogadorTeclado *humano, JogadorIA *ia){
    int tipo1, tipo2;

    printf("Escolha o tipo do jogador 1 (1 representa O e 4 representa X): ");
    scanf("%d", &tipo1);

    while(tipo1 != O && tipo1 != X){
        printf("Escolha invalida (selecione 1 para O e 4 para X): ");
        scanf("%d", &tipo1);
    }
    if(tipo1 == O){
        tipo2 = X;
    } else{
        tipo2= O;
    }

    (*humano).tipo = tipo1;
    (*ia).tipo = tipo2;

    printf("Jogador Humano configurado como %c e Jogador IA configurado como %c\n", conversao(tipo1), conversao(tipo2));
}

void inicia(Tabuleiro *tab, JogadorTeclado *humano, JogadorIA *ia){
    inicializaTabuleiro(tab);
    desenha(tab);

    int vencedor = 0;
    int vez = 0;

    while(vencedor == 0){
        if(vez % 2 == 0){
            joga(humano, tab);
        } else {
            jogaIA(tab, ia);
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