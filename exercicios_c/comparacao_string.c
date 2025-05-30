#include <stdio.h>
#include <string.h>

int main(){

    char senha[10];
    char senha2[10];
    int resultado;

    do{printf("Digite a senha:\n");
    scanf("%s", senha);

    printf("Confirme sua senha:\n");
    scanf("%s", senha2);

    resultado = strcmp(senha, senha2);
    if(resultado == 0){
        printf("As senhas coincidem! Acesso liberado\n");

    } else{
        printf("\nAs senhas são diferentes tente novamente\n");
    }


} while (resultado != 0);

return 0;

}