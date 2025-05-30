#include <stdio.h>
#include <string.h>

int main(){

    char nome [50];
    int tamanho;

    printf("Digite seu primeiro nome:\n");
    scanf("%s", &nome);

    tamanho = strlen(nome);

    printf("O seu primeiro nome têm %d letras\n", tamanho);

    return 0;


         
}