#include <stdio.h>  // Biblioteca padrão de entrada e saída

int main() {
    int i;               // Índice para os laços
    int a[8];            // Vetor de 8 inteiros
    int maior;           // Armazena o maior valor encontrado
    int posicaoMaior;    // Armazena o índice do maior valor

    // Solicita ao usuário que digite 8 números inteiros
    printf("Digite 8 números inteiros:\n");
    for (i = 0; i < 8; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &a[i]);  // Lê cada número e armazena em a[i]
    }

    // Inicializa a busca pelo maior valor
    // Assume, inicialmente, que o primeiro elemento é o maior
    maior = a[0];
    posicaoMaior = 0;

    // Percorre o vetor a partir do segundo elemento
    for (i = 1; i < 8; i++) {
        // Se o elemento atual for maior que o 'maior' conhecido
        if (a[i] > maior) {
            maior = a[i];         // Atualiza o maior valor
            posicaoMaior = i;     // Atualiza a posição do maior valor
        }
    }

    // Exibe o resultado
    printf("O maior elemento é: %d\n", maior);
    printf("Ele se encontra na posição (índice): %d\n", posicaoMaior);

    return 0;  // Encerra o programa retornando 0 (sucesso)
}
