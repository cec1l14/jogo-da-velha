/****
 * Implementação do módulo: mainCliente
 * Autores: Cecília Candeia e Matheus Fernandes
 * Data de Criação: 31/10/2026
 * Última alteração: xx/10/2026
 * Descrição Geral: xxxx
 ****/

#include <stdio.h>
#include "jogadorRemoto.h"
#include "jogadorTeclado.h"
#include "tabuleiro.h"

int main(){
    Tabuleiro tab;
    JogadorTeclado humano;
    JogadorRemoto remoto;
    char ip[32];                                    

    humano.tipo = O;                                
    remoto.tipo = X;

    printf("IP do servidor: ");
    scanf("%31s", ip);
    conecta(&remoto, ip);

    inicializaTabuleiro(&tab);
    desenha(&tab);

    int vencedor = 0;
    int vez = 0;
    
    while(vencedor == 0){
        if(vez % 2 == 0){          
            printf("Agurdando resposta do jogador X\n");
            jogaRemoto(&tab, &remoto);
        } else {  
            joga(&humano, &tab);
            enviaJogada(&remoto, humano.ultimaLinha, humano.ultimaColuna);
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
