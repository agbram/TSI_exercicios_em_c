#include <stdio.h>
#define M 5

int main() {
    int A[M], B[M];
    int i;
    
    // leitura de A
    printf("Digite %d inteiros para o vetor A:\n", M);
    for (i = 0; i < M; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }

    // geração de B em ordem inversa
    for (i = 0; i < M; i++) {
        B[i] = A[M - 1 - i];
    }

    // exibição dos dois vetores
    printf("\nVetor A: ");
    for (i = 0; i < M; i++) printf("%d ", A[i]);
    
    printf("\nVetor B (inverso): ");
    for (i = 0; i < M; i++) printf("%d ", B[i]);
    
    printf("\n");
    return 0;
}
