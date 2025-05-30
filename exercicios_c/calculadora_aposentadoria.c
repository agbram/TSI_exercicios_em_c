#include <stdio.h>

int main () {
    int idade;
    int trabalho;
    
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite seu tempo de trabalho (em anos): ");
    scanf("%d", &trabalho);


    if(idade >= 65 || trabalho >= 35 || (idade >= 60 && trabalho >= 30)){
        printf("Você pode se aposentar! \n");
    } 

    else{
        printf("Você não atingiu os requisitos para se aposentar \n");
    }

    return 0;
}
