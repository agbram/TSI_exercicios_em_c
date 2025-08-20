#include <stdio.h>
#define N 10

int main() {
    int vet[N];
    int num, i, posicao = -1;
    
    // (a) leitura do vetor
    printf("Digite %d números inteiros para o vetor:\n", N);
    for (i = 0; i < N; i++) {
        printf("vet[%d] = ", i);
        scanf("%d", &vet[i]);
    }

    // (b) leitura de NUM
    printf("Digite o valor a buscar (NUM): ");
    scanf("%d", &num);

    // (c) busca de NUM em vet[]
    for (i = 0; i < N; i++) {
        if (vet[i] == num) {
            posicao = i;
            break;      // interrompe na primeira ocorrência
        }
    }

    // saída: índice ou -1
    if (posicao >= 0)
        printf("O valor %d foi encontrado na posição %d.\n", num, posicao);
    else
        printf("Valor não encontrado. Retornando %d.\n", posicao);

    return 0;
}
