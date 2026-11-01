/****
 * Implementação do módulo: jogadorRemoto
 * Autores: Cecília Candeia e Matheus Fernandes
 * Data de Criação: 27/10/2026
 * Última alteração: xx/10/2026
 * Descrição Geral: xxxxxx
 ****/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogadorRemoto.h"

//  tenta conectar o cliente ao servidor
void jogaRemoto(Tabuleiro *tab, JogadorRemoto *remoto){

}
void conecta(JogadorRemoto *remoto, const char *ip) {

    remoto->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (remoto->sock == INVALID_SOCKET) {
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in servidor;
    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(PORTA);

    if (inet_pton(AF_INET, ip, &servidor.sin_addr) <= 0) {
        perror("Endereco invalido");
        closesocket(remoto->sock);
        exit(EXIT_FAILURE);
    }

    if (connect(remoto->sock, (struct sockaddr *)&servidor, sizeof(servidor)) == SOCKET_ERROR) {
        perror("Erro ao conectar");
        closesocket(remoto->sock);
        exit(EXIT_FAILURE);
    }

    printf("Conectado ao servidor!\n");
}

// servidor espera o cliente chegar p aceitar 
void aceita(JogadorRemoto *remoto) {
    
    struct sockaddr_in endereco;
    int endereco_len = sizeof(endereco);
    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_port = htons(PORTA);

    SOCKET servidorSock = socket(AF_INET, SOCK_STREAM, 0);
    if (servidorSock == INVALID_SOCKET) {
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    if (bind(servidorSock, (struct sockaddr *)&endereco, sizeof(endereco)) == SOCKET_ERROR) {
        perror("Erro no bind");
        closesocket(servidorSock);
        exit(EXIT_FAILURE);
    }

    if (listen(servidorSock, 1) == SOCKET_ERROR) {
        perror("Erro no listen");
        closesocket(servidorSock);
        exit(EXIT_FAILURE);
    }

    printf("Servidor aguardando conexao na porta %d...\n", PORTA);

    remoto->sock = accept(servidorSock, (struct sockaddr *)&endereco, &endereco_len);
    if (remoto->sock == INVALID_SOCKET) {
        perror("Erro no accept");
        closesocket(servidorSock);
        exit(EXIT_FAILURE);
    }

    closesocket(servidorSock);
    printf("Cliente conectado!\n");
}
void enviaJogada(JogadorRemoto *remoto, int linha, int coluna){
    char buffer[TAM_BUFFER];

    buffer[0] = linha + '0';
    buffer[1] = coluna + '0';
    buffer[2] = '\0';

    send(remoto->sock, buffer, strlen(buffer) + 1, 0);
}
