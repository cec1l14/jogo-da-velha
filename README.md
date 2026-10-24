## Jogo da Velha

Projeto, implementado na linguagem de programação C, para a disciplina `Programação Estruturada`, no curso `Ciência de Dados e Inteligência Artificial` (Universidade Federal da Paraíba). 

Em suma, o projeto está dividido em três implementações básicas: 
1. Módulo Jogo de Tabuleiro: Humano vs. Humano, na mesma máquina;
2. Módulo IA: Humanos vs. "IA", na mesma máquina;
3. Módulo Jogador Remoto: Humano vs. Humano, na mesma máquina ou de forma remota.

### Módulo Jogo de Tabuleiro

Jogo da velha para **dois jogadores humanos**, jogando pelo teclado na mesma máquina. O jogo termina quando um dos jogadores alinha três símbolos (em linha, coluna ou diagonal) ou quando o tabuleiro enche sem vencedor, resultando em empate.

**Representação do tabuleiro:** cada casa guarda um inteiro: `0` (vazia), `1` (`O`) ou `4` (`X`). Somando as casas de uma linha, coluna ou diagonal, o resultado `3` indica vitória de `O` e `12` indica vitória de `X`.

**Como compilar**

```bash
gcc *.c -o jogo.exe
```

## Integrantes

| | Nome | GitHub |
|---|---|---|
| <img src="https://github.com/cec1l14.png" width="40"> | Cecília Candeia | [@cec1l14](https://github.com/cec1l14) |
| <img src="https://github.com/techteus.png" width="40"> | Matheus Fernandes | [@techteus](https://github.com/techteus) |