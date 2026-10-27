## Jogo da Velha

Projeto, implementado na linguagem de programação C, para a disciplina `Programação Estruturada`, no curso `Ciência de Dados e Inteligência Artificial` (Universidade Federal da Paraíba). 

Em suma, o projeto está dividido em três implementações básicas: 
1. Módulo Jogo de Tabuleiro: Humano vs. Humano, na mesma máquina;
2. Módulo IA: Humanos vs. "IA", na mesma máquina;
3. Módulo Jogador Remoto: Humano vs. Humano, na mesma máquina ou de forma remota.

### Módulo Jogo de Tabuleiro

Jogo da velha para **dois jogadores humanos**, jogando pelo teclado na mesma máquina. O jogo termina quando um dos jogadores alinha três símbolos (em linha, coluna ou diagonal) ou quando o tabuleiro enche sem vencedor, resultando em empate.

**Representação do tabuleiro:** cada casa guarda um inteiro: `0` (vazia), `1` (`O`) ou `4` (`X`). Somando as casas de uma linha, coluna ou diagonal, o resultado `3` indica vitória de `O` e `12` indica vitória de `X`.

### Módulo IA

Partida entre um **jogador humano** (teclado) e um **jogador IA**, na mesma máquina. O humano joga primeiro, e a partida segue até haver vencedor ou empate.

| Regra | O que a IA faz |
|---|---|
| R1 | Se você ou seu oponente tiver duas marcações em sequência, marque o quadrado restante. |
| R2 | Se houver uma jogada que crie duas sequências de duas marcações, use-a. |
| R3 | Se o quadrado central estiver livre, marque-o. |
| R4 | Se seu oponente tiver marcado um dos cantos, marque o canto oposto. |
| R5 | Se houver um canto vazio, marque-o. |
| R6 | Marque arbitrariamente um quadrado vazio. |

### Módulo Jogador Remoto

Partida entre um **jogador humano local** e um **jogador remoto**, que roda em outro processo, na mesma máquina ou em outro computador da rede. A comunicação usa **sockets TCP**, no modelo cliente-servidor

**Como clonar**

```bash
git clone https://github.com/cec1l14/jogo-da-velha.git
```

**Como compilar**

```bash
cd jogo-da-vea/entrega
```

```bash
gcc *.c -o jogo.exe
```

## Integrantes

| | Nome | GitHub |
|---|---|---|
| <img src="https://github.com/cec1l14.png" width="40"> | Cecília Candeia | [@cec1l14](https://github.com/cec1l14) |
| <img src="https://github.com/techteus.png" width="40"> | Matheus Fernandes | [@techteus](https://github.com/techteus) |