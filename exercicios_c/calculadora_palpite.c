#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int minimo, maximo, numeroAleatorio, palpite, tentativas;
    float diferencaPercentual;
    char jogarNovamente;

    do {
        // Zera as tentativas a cada novo jogo
        tentativas = 0;

        printf("Digite o valor mínimo do intervalo: ");
        scanf("%d", &minimo);

        printf("Digite o valor máximo do intervalo: ");
        scanf("%d", &maximo);

        srand(time(NULL));
        numeroAleatorio = (rand() % (maximo - minimo + 1)) + minimo;
        printf("Número gerado! Tente adivinhar.\n");

        do {
            printf("Tentativa %d: Digite seu palpite: ", tentativas + 1);
            scanf("%d", &palpite);
            tentativas++;

            if (palpite == numeroAleatorio) {
                printf("Parabéns! Você acertou!\n");
                break;
            } else {
                diferencaPercentual = (float)fabs(palpite - numeroAleatorio) / numeroAleatorio * 100;
                if (diferencaPercentual <= 10) {
                    printf("Muito quente!\n");
                } else if (diferencaPercentual <= 30) {
                    printf("Quente!\n");
                } else if (diferencaPercentual <= 60) {
                    printf("Frio!\n");
                } else {
                    printf("Muito frio!\n");
                }
            }

        } while (tentativas < 3);

        if (tentativas == 3 && palpite != numeroAleatorio) {
            printf("Você não acertou em 3 tentativas. O número era: %d\n", numeroAleatorio);
        }

        // Pergunta se o usuário quer jogar de novo
        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente); // espaço antes do %c para ignorar o Enter anterior

    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    printf("Obrigado por jogar!\n");
    return 0;
}
