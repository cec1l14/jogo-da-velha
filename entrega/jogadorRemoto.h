#ifndef  JOGADORREMOTO_H
#define JOGADORREMOTO_H
#include <winsock2.h>
#include <ws2tcpip.h>
#include "tabuleiro.h"

#define PORTA 1313
#define TAM_BUFFER 1024

typedef struct {
    int tipo;
    SOCKET sock;  
} JogadorRemoto;

void conecta(JogadorRemoto *remoto, const char *ip, int porta);
void aceita(JogadorRemoto *remoto, int porta);
void jogaRemoto(Tabuleiro *tab, JogadorRemoto *remoto);
void enviaJogada(JogadorRemoto *remoto, int linha, int coluna);

#endif