/****
 * Implementação do módulo: jogadorRemoto
 * Autores: Cecília Candeia e Matheus Fernandes
 * Data de Criação: 27/10/2026
 * Última alteração: 01/11/2026
 * Descrição Geral: jogador que joga em outro processo, na mesma máquina ou em
 *   outro computador da rede, comunicando-se por sockets TCP (modelo
 *   cliente-servidor, usando a biblioteca Winsock do Windows). A estrutura
 *   JogadorRemoto guarda o símbolo do adversário (tipo) e o socket da conexão
 *   (sock). aceita() é usada pelo servidor: abre a porta PORTA e espera o
 *   cliente chegar. conecta() é usada pelo cliente: conecta ao IP informado.
 *   enviaJogada() manda a jogada (linha e coluna) ao outro processo, e
 *   jogaRemoto() fica bloqueada esperando a jogada do adversário chegar e a
 *   marca no tabuleiro. Se a conexão cair, o programa avisa e é encerrado.
 ****/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogadorRemoto.h"

void jogaRemoto(Tabuleiro *tab, JogadorRemoto *remoto){
    char buffer[TAM_BUFFER];

    memset(buffer, 0, TAM_BUFFER);
    int bytes = recv(remoto->sock, buffer, TAM_BUFFER - 1, 0);   

    if (bytes <= 0) {                                       
        printf("Adversario desconectou.\n");
        exit(EXIT_FAILURE);                                 
    }

    marcaJogada(tab, buffer[0] - '0', buffer[1] - '0', remoto->tipo); 
}

//  tenta conectar o cliente ao servidor

void conecta(JogadorRemoto *remoto, const char *ip) {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    remoto->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (remoto->sock == INVALID_SOCKET) {
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in servidor;
    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(PORTA);

    servidor.sin_addr.s_addr = inet_addr(ip);
    if (servidor.sin_addr.s_addr == INADDR_NONE) {
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
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    
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

    buffer[0] = linha + '0'; // única linha que não está presente no código fornecido. ela converte as linhas e colunas para a tabela ascii 
    buffer[1] = coluna + '0';
    buffer[2] = '\0';

    send(remoto->sock, buffer, strlen(buffer) + 1, 0);
}