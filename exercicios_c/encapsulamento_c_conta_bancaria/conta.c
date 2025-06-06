#include <stdlib.h>
#include "conta.h"

struct Conta{
    double saldo;
};

Conta* criarConta(double saldo_inicial){
    Conta* c = (Conta*) malloc(sizeof(Conta));
    if(c) c->saldo = saldo_inicial;
    return c;
}

void depositar(Conta* conta, double valor){
    if(valor > 0) {
        conta->saldo += valor;
    }
}

void sacar(Conta* conta, double valor){
    if(valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
    }
}

double consultarSaldo(Conta* conta){
    return conta->saldo;
}

void destruirConta(Conta* conta){
    free(conta);
}