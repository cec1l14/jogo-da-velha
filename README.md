## Jogo da Velha

Projeto, implementado na linguagem de programação C, para a disciplina `Programação Estruturada`, no curso `Ciência de Dados e Inteligência Artificial` (Universidade Federal da Paraíba). 

Em suma, o projeto está dividido em três implementações básicas: 
1. Módulo Jogo de Tabuleiro: Humano vs. Humano, na mesma máquina;
2. Módulo IA: Humanos vs. "IA", na mesma máquina;
3. Módulo Jogador Remoto: Humano vs. Humano, na mesma máquina ou de forma remota.

### Estrutura do projeto

```
jogo-da-velha/
├── README.md
├── LICENSE
├── .gitignore 
├── entrega/              
│   ├── main.c / mainCliente.c / mainServidor.c
│   ├── partida.c / partida.h
│   ├── tabuleiro.c / tabuleiro.h
│   ├── jogadorTeclado.c / jogadorTeclado.h
│   └── jogadorIA.c / jogadorIA.h
│   └── jogadorRemoto.c / jogadorRemoto.h

```

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

Partida entre um **jogador humano local** e um **jogador remoto**, que roda em outro processo, na mesma máquina ou em outro computador da rede. A comunicação usa **sockets TCP**, no modelo cliente-servidor.

**Como clonar**

```bash
git clone https://github.com/cec1l14/jogo-da-velha.git
```

**Como compilar (Módulos 1 2)**

```bash
cd jogo-da-velha/entrega
```

```bash
gcc *.c -o jogo.exe
```

```bash
.\jogo.exe
```

**Como compilar (Módulo 3)**

1. Em cada terminal devem ser rodados:

```bash
gcc mainServidor.c jogadorRemoto.c jogadorTeclado.c tabuleiro.c -o servidor.exe -lws2_32
```

```bash
gcc mainCliente.c jogadorRemoto.c jogadorTeclado.c tabuleiro.c -o cliente.exe -lws2_32
```

2. No terminal referente ao servidor, deve ser posto: 

```bash
.\servidor.exe
```

`Aparecerá uma mensagem do tipo 'Servidor aguardando conexao'.`

3. No terminal referente ao cliente, coloca-se:

```bash
\.cliente.exe
```
`Aparecerá uma mensagem do tipo 'IP do cliente'.`

#### Exemplo de partida remota

Cada jogada aparece **nos dois computadores**, e os dois tabuleiros ficam sempre iguais. Na partida abaixo, o servidor (`X`) joga primeiro, e o cliente (`O`) vence pela diagonal.

**Resultado final, como cada janela mostra:**

<table>
<tr>
<th>Servidor (X)</th>
<th>Cliente (O)</th>
</tr>
<tr>
<td>

```text
  0   1   2
0 O | X | X 
 -----------
1 X | O |   
 -----------
2   |   | O 
Jogador O venceu!
```

</td>
<td>

```text
  0   1   2
0 O | X | X 
 -----------
1 X | O |   
 -----------
2   |   | O 
Jogador O venceu!
```

</td>
</tr>
</table>

<details>
<summary>Ver a partida passo a passo</summary>

**Conexão.** O servidor abre a porta e espera. O cliente informa o IP e conecta.

<table>
<tr>
<th>Servidor (X)</th>
<th>Cliente (O)</th>
</tr>
<tr>
<td>

```text
$ servidor.exe
Servidor aguardando conexao na porta 1313...
Cliente conectado!
```

</td>
<td>

```text
$ cliente.exe
IP do servidor: 127.0.0.1
Conectado ao servidor!
```

</td>
</tr>
</table>

**Jogada 1.** O servidor joga `X` na linha 0, coluna 1 e envia a jogada. O cliente a recebe e marca no seu tabuleiro.

<table>
<tr>
<th>Servidor (X): digitou 0 e 1</th>
<th>Cliente (O): recebeu 0 e 1</th>
</tr>
<tr>
<td>

```text
  0   1   2
0   | X |   
 -----------
1   |   |   
 -----------
2   |   |   
```

</td>
<td>

```text
  0   1   2
0   | X |   
 -----------
1   |   |   
 -----------
2   |   |   
```

</td>
</tr>
</table>

**Jogada 2.** Agora é a vez do cliente: `O` na linha 0, coluna 0.

<table>
<tr>
<th>Servidor (X): recebeu 0 e 0</th>
<th>Cliente (O): digitou 0 e 0</th>
</tr>
<tr>
<td>

```text
  0   1   2
0 O | X |   
 -----------
1   |   |   
 -----------
2   |   |   
```

</td>
<td>

```text
  0   1   2
0 O | X |   
 -----------
1   |   |   
 -----------
2   |   |   
```

</td>
</tr>
</table>

**Jogada 3.** Servidor: `X` na linha 0, coluna 2.

<table>
<tr>
<th>Servidor (X): digitou 0 e 2</th>
<th>Cliente (O): recebeu 0 e 2</th>
</tr>
<tr>
<td>

```text
  0   1   2
0 O | X | X 
 -----------
1   |   |   
 -----------
2   |   |   
```

</td>
<td>

```text
  0   1   2
0 O | X | X 
 -----------
1   |   |   
 -----------
2   |   |   
```

</td>
</tr>
</table>

**Jogada 4.** Cliente: `O` no centro (linha 1, coluna 1).

<table>
<tr>
<th>Servidor (X): recebeu 1 e 1</th>
<th>Cliente (O): digitou 1 e 1</th>
</tr>
<tr>
<td>

```text
  0   1   2
0 O | X | X 
 -----------
1   | O |   
 -----------
2   |   |   
```

</td>
<td>

```text
  0   1   2
0 O | X | X 
 -----------
1   | O |   
 -----------
2   |   |   
```

</td>
</tr>
</table>

**Jogada 5.** Servidor: `X` na linha 1, coluna 0.

<table>
<tr>
<th>Servidor (X): digitou 1 e 0</th>
<th>Cliente (O): recebeu 1 e 0</th>
</tr>
<tr>
<td>

```text
  0   1   2
0 O | X | X 
 -----------
1 X | O |   
 -----------
2   |   |   
```

</td>
<td>

```text
  0   1   2
0 O | X | X 
 -----------
1 X | O |   
 -----------
2   |   |   
```

</td>
</tr>
</table>

**Jogada 6.** Cliente: `O` na linha 2, coluna 2. Completa a diagonal, e os dois lados anunciam a vitória.

<table>
<tr>
<th>Servidor (X): recebeu 2 e 2</th>
<th>Cliente (O): digitou 2 e 2</th>
</tr>
<tr>
<td>

```text
  0   1   2
0 O | X | X 
 -----------
1 X | O |   
 -----------
2   |   | O 
Jogador O venceu!
```

</td>
<td>

```text
  0   1   2
0 O | X | X 
 -----------
1 X | O |   
 -----------
2   |   | O 
Jogador O venceu!
```

</td>
</tr>
</table>

</details>


## Integrantes

| | Nome | GitHub |
|---|---|---|
| <img src="https://github.com/cec1l14.png" width="40"> | Cecília Candeia | [@cec1l14](https://github.com/cec1l14) |
| <img src="https://github.com/techteus.png" width="40"> | Matheus Fernandes | [@techteus](https://github.com/techteus) |
