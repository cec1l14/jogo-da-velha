/****
 * Implementação do módulo: mainServidor
 * Autores: Cecília Candeia e Matheus Fernandes
 * Data de Criação: 31/10/2026
 * Última alteração: 01/11/2026
 * Descrição Geral: programa do jogador servidor na partida remota. Espera a
 *   conexão do cliente com aceita(), joga com o símbolo X e faz a primeira
 *   jogada. Os turnos se alternam: na sua vez, joga() lê a linha e a coluna
 *   do teclado e envia a jogada ao cliente; na vez do adversário, jogaRemoto()
 *   fica esperando a jogada chegar. O laço termina quando alguém vence ou o
 *   tabuleiro enche, e o resultado é exibido.
 ****/

#include <stdio.h>
#include "jogadorRemoto.h"
#include "jogadorTeclado.h"
#include "tabuleiro.h"

int main(){
    Tabuleiro tab;
    JogadorTeclado humano;
    JogadorRemoto remoto;
    int vencedor = 0;
    int vez = 0;

    humano.tipo = X;             
    remoto.tipo = O;

    aceita(&remoto); 

    inicializaTabuleiro(&tab);
    desenha(&tab);

    while(vencedor == 0){
        if(vez % 2 == 0){
            joga(&humano, &tab, &remoto);
        } else {
            printf("Aguardando resposta do jogador O\n");
            jogaRemoto(&tab, &remoto);
        }
        desenha(&tab);
        vencedor = temVencedor(&tab);
        vez++;
    }

    if(vencedor == O){
        printf("Jogador O venceu!\n");
    } else if(vencedor == X){
        printf("Jogador X venceu!\n");
    } else {
        printf("Empate!\n");
    }

    closesocket(remoto.sock);
    WSACleanup();
    return 0;
}