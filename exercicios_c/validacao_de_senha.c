#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
    #define LIMPA_TELA "cls"
#else
    #define LIMPA_TELA "clear"
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

int main() {
    char senha[20];
    char confirma[20];
    char user[20];
    int repetir;

    do {
        system(LIMPA_TELA);

        printf("Digite seu usuário:\n");
        fgets(user, sizeof(user), stdin);
        user[strcspn(user, "\n")] = '\0';  // Remove o '\n'

        int tentativas = 0;
        int acesso = 0;

        while (tentativas < MAX_TENTATIVAS) {
            if (verificarSenha(senha, confirma)) {
                printf("\nUsuário %s: acesso autorizado.\n", user);
                acesso = 1;
                break;
            } else {
                tentativas++;
                printf("Usuário %s: senha incorreta. Tentativa %d de %d.\n\n", user, tentativas, MAX_TENTATIVAS);
            }
        }

        if (!acesso) {
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
