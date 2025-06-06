
#ifndef CONTA_H
#define CONTA_H 

typedef struct Conta Conta;
    Conta* criarConta(double saldo_inicial);
    void depositar(Conta* conta, double valor);
    void sacar(Conta* conta, double valor);
    double consultarSaldo(Conta* conta);
    void destruirConta(Conta* conta);

#endif