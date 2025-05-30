#include <stdio.h>  // Biblioteca padrão para entrada e saída

int main() {
    int i;        // Índice para percorrer o vetor
    int b[10];    // Vetor de 10 inteiros

    // Preenche o vetor b com valores decrescentes de 10 a 1
    for (i = 0; i < 10; i++) {
        b[i] = 10 - i;  // Na iteração i: armazena 10, 9, 8, ..., até 1
    }

    printf("Vetor gerado:\n");

    // Imprime todos os elementos do vetor b
    for (i = 0; i < 10; i++) {
        printf("%d ", b[i]);  // Exibe o elemento b[i] seguido de espaço
    }

    printf("\n");  // Quebra de linha ao final da impressão
    return 0;      // Retorna 0 indicando que o programa terminou com sucesso
}
