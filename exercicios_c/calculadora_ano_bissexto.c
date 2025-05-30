#include <stdio.h>  // Inclui a biblioteca padrão de entrada/saída
                   // Necessária para usar printf e scanf

// Função que verifica se um ano é bissexto
int anobissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
    // Retorna 1 (true) se for bissexto, 0 (false) caso contrário
}

int main() {
    int ano;                     // Variável para armazenar o ano digitado
    char tentarNovamente = 's';  // Variável de controle para repetir ou encerrar o programa

    // Laço principal que continua enquanto o usuário digitar 's' ou 'S'
    while (tentarNovamente == 's' || tentarNovamente == 'S') {
        printf("Digite um ano:\n");
        scanf("%d", &ano);  // Lê o ano digitado pelo usuário

        // Verifica se o ano é negativo
        if (ano < 0) {
            printf("Ano inválido!\n");
            printf("Deseja tentar novamente? (s/n): \n");

            scanf(" %c", &tentarNovamente);  

            continue;  // Volta ao início do laço, sem executar o resto
        }

        // Verifica se o ano é bissexto e imprime o resultado
        if (anobissexto(ano)) {
            printf("%d é um ano bissexto!\n", ano);
        } else {
            printf("%d não é um ano bissexto.\n", ano);
        }

        // Pergunta se o usuário deseja verificar outro ano
        printf("Deseja verificar outro ano? (s/n): ");
        scanf(" %c", &tentarNovamente);  // O espaço ignora o ENTER pendente
    }

    // Mensagem final após sair do laço
    printf("Programa encerrado.\n");
    return 0;
}
