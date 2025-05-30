#include <stdio.h>

float calcularmedia(float numero1, float numero2, float numero3)
{
    return (numero1 + numero2 + numero3) / 3.0;
}   

float maiorNumero(float numero1, float numero2, float numero3)
{
    if (numero1 > numero2 && numero1 > numero3)
        return numero1;
    if (numero2 > numero1 && numero2 > numero3)
        return numero2;
    return numero3;
}

float menorNumero(float numero1, float numero2, float numero3)
{
    if (numero1 < numero2 && numero1 < numero3)
        return numero1;
    if (numero2 < numero1 && numero2 < numero3)
        return numero2;
    return numero3;
}

int limiteAlerta(float media)
{
    const float LIMITE = 100.0f;
    return media > LIMITE ? 1 : 0;
}

void mostraresultado(float media, float maior, float menor, int codigoAlerta)
{
    printf("\nO resultado do trio foi:\n");
    printf("Média: %.2f\n", media);
    printf("Maior número: %.2f\n", maior);
    printf("Menor número: %.2f\n", menor);
    printf("Código Alerta: %d\n", codigoAlerta);
}

int main()
{
    float numero1, numero2, numero3, media, maior, menor;
    int input, qtdTrios, codigoAlerta;

    do
    {
        printf("\n--- MENU INTERATIVO ---\n");
        printf("1 - Informações gerais dos trios (NOTAS)\n");
        printf("2 - Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            printf("Quantidade de trios a serem analisados: ");
            scanf("%d", &qtdTrios);

            for (int i = 1; i <= qtdTrios; i++)
            {
                printf("\n--- Trio %d ---\n", i);

                printf("Insira a primeira nota: ");
                scanf("%f", &numero1);

                printf("Insira a segunda nota: ");
                scanf("%f", &numero2);

                printf("Insira a terceira nota: ");
                scanf("%f", &numero3);

                media = calcularmedia(numero1, numero2, numero3);
                maior = maiorNumero(numero1, numero2, numero3);
                menor = menorNumero(numero1, numero2, numero3);
                codigoAlerta = limiteAlerta(media);

                mostraresultado(media, maior, menor, codigoAlerta);
            }

            printf("\nFinalizando o processo dos trios analisados...\n");
            break;

        case 2:
            printf("\nEncerrando o programa. Até mais!\n");
            break;

        default:
            printf("\nOpção inválida. Tente novamente.\n");
        }

    } while (input != 2); // Continua enquanto o usuário não escolher sair

    return 0;
}
