#include <stdio.h>
#include <stdlib.h>

char tabuleiro[3][3];
char jogadorAtual;

void inicializarTabuleiro(void);
void exibirTabuleiro(void);
int  jogadaValida(int linha, int coluna);
int  verificarVencedor(void);
int  verificarEmpate(void);
void alternarJogador(void);
void limparBuffer(void);
void jogar(void);

int main(void) {
    char jogarNovamente;
    do {
        inicializarTabuleiro();
        jogadorAtual = 'X';
        jogar();
        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente);
        limparBuffer();
    } while (jogarNovamente == 's' || jogarNovamente == 'S');
    return 0;
}

void inicializarTabuleiro(void) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tabuleiro[i][j] = ' ';
}

void exibirTabuleiro(void) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n",
               tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int jogadaValida(int linha, int coluna) {
    return linha >= 0 && linha < 3 &&
           coluna >= 0 && coluna < 3 &&
           tabuleiro[linha][coluna] == ' ';
}

int verificarVencedor(void) {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogadorAtual &&
            tabuleiro[i][1] == jogadorAtual &&
            tabuleiro[i][2] == jogadorAtual)
            return 1;
        if (tabuleiro[0][i] == jogadorAtual &&
            tabuleiro[1][i] == jogadorAtual &&
            tabuleiro[2][i] == jogadorAtual)
            return 1;
    }
    if (tabuleiro[0][0] == jogadorAtual &&
        tabuleiro[1][1] == jogadorAtual &&
        tabuleiro[2][2] == jogadorAtual)
        return 1;
    if (tabuleiro[0][2] == jogadorAtual &&
        tabuleiro[1][1] == jogadorAtual &&
        tabuleiro[2][0] == jogadorAtual)
        return 1;
    return 0;
}

int verificarEmpate(void) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tabuleiro[i][j] == ' ')
                return 0;
    return 1;
}

void alternarJogador(void) {
    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
}

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void jogar(void) {
    int linha, coluna;
    while (1) {
        system("cls");               // limpa a tela
        exibirTabuleiro();

        printf("Jogador %c, escolha linha e coluna (0-2): ", jogadorAtual);
        // tenta ler 2 inteiros
        if (scanf("%d %d", &linha, &coluna) != 2) {
            printf("Entrada inválida! Digite dois números inteiros.\n");
            limparBuffer();
            system("pause");
            continue;
        }

        if (!jogadaValida(linha, coluna)) {
            printf("Jogada inválida! Tente novamente.\n");
            system("pause");
            continue;
        }

        tabuleiro[linha][coluna] = jogadorAtual;

        if (verificarVencedor()) {
            system("cls");
            exibirTabuleiro();
            printf("Jogador %c venceu!\n", jogadorAtual);
            break;
        }
        if (verificarEmpate()) {
            system("cls");
            exibirTabuleiro();
            printf("Empate!\n");
            break;
        }

        alternarJogador();
    }
}
