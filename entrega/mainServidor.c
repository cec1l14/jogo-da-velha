/****
 * Implementação do módulo: mainServidor
 * Autores: Cecília Candeia e Matheus Fernandes
 * Data de Criação: 31/10/2026
 * Última alteração: xx/10/2026
 * Descrição Geral:
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
            joga(&humano, &tab);
            enviaJogada(&remoto, humano.ultimaLinha, humano.ultimaColuna);
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