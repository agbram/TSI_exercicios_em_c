#include <stdio.h>

int main(){

    float altura, peso, imc;
    int repetir;

    do{
        printf("Informe seu peso:\n");
    scanf("%f", &peso);

    printf("Informe sua altura (m):\n");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("Seu IMC: %.2F\n", imc);

    if(imc < 18.5){
        printf("Você esta abaixo do peso.\n");
    } else if(imc >= 18.5 && imc <= 24.9){
        printf("Você está com o peso saudável.\n");
    } else if(imc >= 25 && imc <= 29.9){
        printf("Você está acima do peso.\n");
    } else if( imc >= 30 && imc <= 39.9){
        printf("Você esta com obesidade.\n");
    } else {
        printf("Você está com obseidade grave, procure um médico.\n");
    } 
    
    printf("Deseja fazer um novo cálculo?\n(0) Encerra programa\n(1) Novo Cálculo\n");
    scanf("%d", &repetir);
    
} while(repetir == 1);

return 0;
}