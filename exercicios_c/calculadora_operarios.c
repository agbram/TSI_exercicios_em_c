#include <stdio.h>

int main() {

    int salariominimo;
    int quantidadepeças;
    int salariobruto;

    printf("Dê o salário minimo\n");
    scanf("%d", &salariominimo);

    printf("Quantas peças foram montadas?\n");
    scanf("%d", &quantidadepeças);

    if(quantidadepeças <= 30) {
        salariobruto = salariominimo;
        printf("A Classe do Operário é 1 e o Salário é %d \n", salariobruto);

            
    } else {
        if(quantidadepeças <=50) {
            salariobruto = salariominimo + (quantidadepeças-30) * (salariominimo*0.03);
            printf("A Classe do Operário é 2 e o Salário é %d \n", salariobruto);

        } else {
            salariobruto = salariominimo + (quantidadepeças-50) * (salariominimo*0.05);
            printf("A Classe do Operário é 3 e o Salário é %d \n", salariobruto);

        }
    }


   
    
 return 0;
}
