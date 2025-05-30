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

const float limiteAlerta(float media, float codigoAlerta)
{

    codigoAlerta = 100;

    if (media > codigoAlerta)
        return 1;
    return 0;
}

float mostraresultado(float media, float maior, float menor, float codigoAlerta)
{
    printf("\nO resultado do trio foi:\n");
    printf("\nA média é:\n", media);
    printf("\nO maior número é:\n", maior);
    printf("\nO menor número é:\n", menor);
    printf("\nO Código Alerta é:\n", codigoAlerta);
}

int main()
{

    float numero1, numero2, numero3, media, maior, menor;
    int input, qtdTrios, codigoAlerta;

    printf("Quantidade de trios a serem analisados?");
    scanf("%d", &qtdTrios);
    for (int i = 1; i <= qtdTrios; i++)
    {

        printf("\nTrio %d\n", i);
        printf("\nDigite os números:\n");

        printf("\nInsira o primeiro número:");
        scanf("%f", &numero1);

        printf("\nInsira o segundo número:");
        scanf("%f", &numero2);

        printf("\nInsira o terceiro número:");
        scanf("%f", &numero3);

        media = calcularmedia(numero1, numero2, numero3);
        maior = maiorNumero(numero1, numero2, numero3);
        menor = menorNumero(numero1, numero2, numero3);
        codigoAlerta = limiteAlerta(media, codigoAlerta);

        printf("\nO resultado geral é:\n");
        printf("Média: %.2f\n", media);
        printf("Maior: %.2f\n", maior);
        printf("Menor: %.2f \n", menor);
        printf("Código Alerta: %d\n", codigoAlerta);

        printf("Finalizando o processo de todos os trios...\n");
    }

    return 0;
}

// \#include \<stdio.h>

// float calcularmedia (float numero1, float numero2, float numero3){

// ```
// return (numero1 + numero2 + numero3)/3.0;
// ```

// }

// float maiorNumero(float numero1, float numero2, float numero3){

// ```
// if(numero1 > numero2 && numero1 > numero3) return numero1;
// if(numero2 > numero1 && numero2 > numero3) return numero2;
// return numero3;
// ```

// }

// float menorNumero(float numero1, float numero2, float numero3){

// ```
// if(numero1 < numero2 && numero1 < numero3) return numero1;
// if(numero2 < numero1 && numero2 < numero3) return numero2;
// return numero3;
// ```

// }

// const float limiteAlerta(float media, float codigoAlerta){

// ```
// codigoAlerta = 100;

// if (media > codigoAlerta) return 1;
// return 0;
// ```

// }

// float mostraresultado(float media, float maior, float menor, float codigoAlerta){
// printf("\nO resultado do trio foi:\n");
// printf("\nA média é:\n", media);
// printf("\nO maior número é:\n", maior);
// printf("\nO menor número é:\n", menor);
// printf("\nO Código Alerta é:\n", codigoAlerta);
// }

// int main (){

// ```
// float numero1, numero2, numero3, media, maior, menor;
// int input, qtdTrios, codigoAlerta;

// printf("---MENU INTERATIVO---");
// printf("\n1 - Informacoes gerais dos trios(NOTAS)\n");
// printf("2 - Sair do programa\n");
// scanf("%d", &input);
// ```

// switch(input){ /\* MENU INTERATIVO PARA MELHOR ACESSIBLIDADE DO USUÁRIO\*/

// ```
// case 1:
// printf("Quantidade de trios a serem analisados?");
// scanf("%d", &qtdTrios);
// for(int i = 1; i <= qtdTrios; i++){

// printf("\nTrio %d\n", i);
// printf("\nDigite as notas:\n");

//     printf("\nInsira a primeira nota:");
//     scanf("%f", &numero1);

//     printf("\nInsira a segunda nota:");
//     scanf("%f", &numero2);

//     printf("\nInsira a terceira nota:");
//     scanf("%f", &numero3);

//     media = calcularmedia(numero1, numero2, numero3);
//     maior = maiorNumero(numero1, numero2, numero3);
//     menor = menorNumero(numero1, numero2, numero3);
//     codigoAlerta = limiteAlerta(media, codigoAlerta);

//     printf("\nO resultado geral eh:\n");
//     printf("Media: %.2f\n", media);
//     printf("Maior: %.2f\n", maior);
//     printf("Menor: %.2f \n", menor);
//     printf("Codigo Alerta: %d\n", codigoAlerta);

// }

// printf("Finalizando o processo de todos os trios...\n");
// break;

// case 2:
//     printf("\nEncerrando programa...\n");
//     break;

// default:
// printf("\nInput Inválido. Insira novamente\n");
//    }

// return 0;
// ```

// }
