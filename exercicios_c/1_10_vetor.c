#include <stdio.h> // Inclui a biblioteca padrão para entrada e saída

int main() {

    int a[10]; // Declara um vetor de inteiros com 10 posições
    int i;     // Variável de controle para os laços for

    // Preenche o vetor com valores de 1 a 10
    for(i = 0; i < 10; i++) {
        a[i] = i + 1; // A posição i recebe o valor i+1 (ou seja, de 1 até 10)
    }

    printf("Vetor preenchido:\n");

    // Imprime os valores armazenados no vetor
    for(i = 0; i < 10; i++) {
        printf("%d ", a[i]); // Imprime o valor da posição i do vetor
    }

    printf("\n"); // Quebra de linha após imprimir o vetor

    return 0; // Encerra o programa com sucesso
}
