#include <stdio.h>

typedef struct{
    int tipo;
} JogadorIA;
// nao mexi nisso direito ainda

void joga(Tabuleiro *tab, JogadorIA *jogador); // acho q o nome dos ponteiros iguais gera confusao n sei

    int jogadorHumano;
    if (jogador->tipo == 1) {
        jogadorHumano = 4;
    } else {
        jogadorHumano = 1;
    }
    // R4: Se seu oponente tiver marcado um dos cantos, marque o canto oposto
    int cantos_linha, cantos_coluna, opostos_linha, opostos_coluna;

    // vetor fica facil, talvez struct seja mais agradavel dps vejo
    // pq vai pegando em ordem

    int cantos[4][2] = {{0, 0}, {0, 2}, {2, 2}, {2, 0}};

    for (int i = 0; i < 4; i++) {
        cantos_linha = cantos[i][0];
        cantos_coluna = cantos[i][1];

        if (cantos_linha == 0) {
            opostos_linha = 2;
        } else {
            opostos_linha = 0;
        }

        if (cantos_coluna == 0) {
            opostos_coluna = 2;
        } else {
            opostos_coluna = 0;
        }

        if (M[cantos_linha][cantos_coluna] == jogadorHumano && M[opostos_linha][opostos_coluna] == 0) {
            marcaJogada(tab, opostos_linha, opostos_coluna, jogador->tipo);
            return; // acho q precisa de return pra parar ne? pq se nao vai continuar
        }
    }

    // R5: Se houver um canto vazio, marque-o.
    // randomizavel tb esse, da p fazer um armazenamento em lista e dps sortear, dps agnt ve
    for (int i = 0; i < 4; i++) {
        int cantos_linha = cantos[i][0];
        int cantos_coluna = cantos[i][1];
        if (M[cantos_linha][cantos_coluna] == 0) {
            marcaJogada(tab, cantos_linha, cantos_coluna, jogador->tipo);
            return;
        }
    }

    // R6:  Marque arbitrariamente um quadrado vazio
    // logica simples sem usar rand

    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            if (M[linha][coluna] == 0) {
                marcaJogada(tab, linha, coluna, jogador->tipo);
                return;
            }
        }
    }
