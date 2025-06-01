#include <stdio.h>
#include <string.h>

int main(){

    char nome[100];
    char letra;
    int i, repete = 0;

    printf("Escreva a palavra:\n");
    fgets(nome, sizeof(nome), stdin);

    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite qual letra voce quer ver quantas vezes se repete:\n");
    scanf(" %c", &letra);

    for(i = 0; nome[i] != '\0'; i++){
        if(nome[i] == letra){
            repete++;
        }
    }
         printf("A letra '%c' se repete %d vezes na palavra \"%s\".\n", letra, repete, nome);

         return 0;
    }

    


