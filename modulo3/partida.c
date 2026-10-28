/****
 * Implementação do módulo: partida
 * Autores: Cecília Candeia e Matheus Fernandes
 * Data de Criação: 19/10/2026
 * Última alteração: 26/10/2026
 * Descrição Geral: controla o jogo. configuraJogadores() pergunta o modo
 *   (humano contra humano ou humano contra IA) e o símbolo do jogador 1; o
 *   segundo jogador recebe o símbolo oposto. inicia() zera o tabuleiro e repete
 *   o laço de jogadas, alternando os jogadores, até haver vencedor ou empate.
 ****/

#include <stdio.h>
#include "partida.h"

void configuraJogadores(int *modo, JogadorTeclado *humano1, JogadorTeclado *humano2, JogadorIA *ia){
    int tipo1, tipo2;

    printf("1 - Humano vs Humano\n");
    printf("2 - Humano vs IA\n");
    printf("3 - Jogador remoto\n");
    printf("Escolha o modo de jogo:\n");
    scanf("%d", modo);

    while(*modo != MODO_HUMANO_VS_HUMANO && *modo != MODO_HUMANO_VS_IA){
        printf("Escolha invalida (selecione 1 para Humano vs Humano e 2 para Humano vs IA): ");
        scanf("%d", modo);
    }

    if(*modo == MODO_HUMANO_VS_HUMANO){
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

        humano1->tipo = tipo1;
        humano2->tipo = tipo2;

        printf("Jogador Humano 1 configurado como %c e Jogador Humano 2 configurado como %c\n", conversao(tipo1), conversao(tipo2));

    } else if(*modo == MODO_HUMANO_VS_IA){
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

    humano1->tipo = tipo1;
    ia->tipo = tipo2;

    printf("Jogador Humano configurado como %c e Jogador IA configurado como %c\n", conversao(tipo1), conversao(tipo2));
}
}
void inicia(Tabuleiro *tab, int modo, JogadorTeclado *humano1, JogadorTeclado *humano2, JogadorIA *ia){
    inicializaTabuleiro(tab);
    desenha(tab);

    int vencedor = 0;
    int vez = 0;

    while(vencedor == 0){
        if(vez % 2 == 0){
            joga(humano1, tab);
        } else if(modo == MODO_HUMANO_VS_HUMANO){
            joga(humano2, tab);
        } else {
            printf("\n Turno do Jogador %c. \n", conversao(ia->tipo));
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