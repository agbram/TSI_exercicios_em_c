#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "conta.h"

#ifdef _WIN32
    #define LIMPAR_TELA "cls"
#else
    #define LIMPAR_TELA "clear"
#endif

#define MAX_TENTATIVAS 3

// Função que pede e verifica a senha
int verificarSenha(char senha[], char confirma[]) {
    printf("Digite sua senha:\n");
    fgets(senha, 20, stdin);
    senha[strcspn(senha, "\n")] = '\0';

    printf("Confirme sua senha:\n");
    fgets(confirma, 20, stdin);
    confirma[strcspn(confirma, "\n")] = '\0';

    return strcmp(senha, confirma) == 0;
}

// Função do sistema bancário principal
void menuConta(const char* nomeCliente) {
    int opcao;
    double valor;
    double totalDepositos = 0.0;
    double totalSaques = 0.0;

    Conta* conta = criarConta(0.0);

    do {
        system(LIMPAR_TELA);
        printf("=== Conta Bancária de %s ===\n", nomeCliente);
        printf("1. Ver saldo\n");
        printf("2. Depositar\n");
        printf("3. Sacar\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        system(LIMPAR_TELA);

        switch(opcao) {
            case 1:
                printf("Saldo atual: R$ %.2f\n", consultarSaldo(conta));
                break;

            case 2:
                printf("Informe o valor para depositar: ");
                scanf("%lf", &valor);
                if (valor > 0) {
                    depositar(conta, valor);
                    totalDepositos += valor;
                    printf("Depósito de R$ %.2f realizado com sucesso.\n", valor);
                } else {
                    printf("Valor inválido! Depósito deve ser maior que 0.\n");
                }
                break;

            case 3:
                printf("Informe o valor para sacar: ");
                scanf("%lf", &valor);
                if (valor > 0) {
                    if (valor <= consultarSaldo(conta)) {
                        sacar(conta, valor);
                        totalSaques += valor;
                        printf("Saque de R$ %.2f realizado com sucesso.\n", valor);
                    } else {
                        printf("Erro: saldo insuficiente!\n");
                    }
                } else {
                    printf("Valor inválido! Saque deve ser maior que 0.\n");
                }
                break;

            case 4:
                printf("Encerrando a conta de %s...\n", nomeCliente);
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

        if (opcao != 4) {
            printf("\nPressione ENTER para continuar...");
            getchar(); getchar(); // Espera ENTER
        }

    } while (opcao != 4);

    // Relatório final
    system(LIMPAR_TELA);
    printf("=== Relatório Final da Conta de %s ===\n", nomeCliente);
    printf("Total depositado: R$ %.2f\n", totalDepositos);
    printf("Total sacado:     R$ %.2f\n", totalSaques);
    printf("Saldo final:      R$ %.2f\n", consultarSaldo(conta));

    destruirConta(conta);
}

int main() {
    char senha[20];
    char confirma[20];
    char user[100];
    int repetir;

    do {
        system(LIMPAR_TELA);
        printf("Digite seu nome de usuário:\n");
        fgets(user, sizeof(user), stdin);
        user[strcspn(user, "\n")] = '\0';

        int tentativas = 0;
        int acesso = 0;

        while (tentativas < MAX_TENTATIVAS) {
            if (verificarSenha(senha, confirma)) {
                printf("\nUsuário %s: acesso autorizado.\n", user);
                acesso = 1;
                printf("Pressione ENTER para acessar sua conta...");
                getchar(); getchar();
                break;
            } else {
                tentativas++;
                printf("Usuário %s: senha incorreta. Tentativa %d de %d.\n\n", user, tentativas, MAX_TENTATIVAS);
            }
        }

        if (acesso) {
            menuConta(user);
        } else {
            printf("Usuário %s: número máximo de tentativas atingido. Acesso bloqueado.\n", user);
        }

        printf("\nDeseja tentar com outro usuário?\n(0) Encerrar programa\n(1) Novo usuário\n");
        if (scanf("%d", &repetir) != 1) {
            printf("Entrada inválida. Encerrando o programa.\n");
            break;
        }
        while (getchar() != '\n'); // Limpa o buffer

    } while (repetir == 1);

    return 0;
}

