#include <stdio.h>

#define QUANTIDADE 20  // Define o tamanho do vetor como uma constante

int main() {
    int i; 
    int a[QUANTIDADE];   // Vetor para armazenar QUANTIDADE de inteiros
    int somaTotal = 0;   // Acumulador da soma dos elementos
    float media;         // Armazenará a média calculada

    // Solicita ao usuário que digite QUANTIDADE de números
    printf("Digite %d números inteiros:\n", QUANTIDADE);

    // Laço de leitura e soma dos valores
    for (i = 0; i < QUANTIDADE; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &a[i]);     // Lê o valor e armazena em a[i]
        somaTotal += a[i];      // Acrescenta o valor lido à soma total
    }

    // Calcula a média (converte somaTotal para float para evitar divisão inteira)
    media = (float)somaTotal / QUANTIDADE;

    // Exibe a média com duas casas decimais
    printf("\nMédia é %.2f\n", media);

    // Exibe os números que estão acima da média
    printf("\nNúmeros acima da média são:\n");
    for (i = 0; i < QUANTIDADE; i++) {
        if (a[i] > media) {           // Verifica se o elemento é maior que a média
            printf("%d ", a[i]);      // Imprime o valor acima da média
        }
    }

    return 0;  // Finaliza o programa indicando sucesso
}
