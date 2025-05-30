#include <stdio.h>
#include <string.h>

int main(){

    char nome[50];
    char copia[50];

    printf("Qual seu nome?\n");
    fgets(nome, sizeof(nome), stdin);

    nome[strcspn(nome, "\n")] = '\0'; 


    strcpy(copia, nome);

    printf("\nOlá %s,tudo bem?\n", copia);


    return 0;
}