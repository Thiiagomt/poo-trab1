#ifndef TRAB1_ContaCorrente_H
#define TRAB1_ContaCorrente_H

#include <string>
#include <sstream>
using namespace std;

#include "Data.h"

class Conta {
public:

    // Construtor
    ContaPoupanca(int);

    // Destrutor
    ~ContaPoupanca();

    // Setters
    void setNumConta(int);
    void setDataAbertura();
    void setSaldoAtual(float x);

    // Getters
    int getNumConta();
    Data getDataAbertura();
    float getSaldoAtual();

private:
    int numConta;
    Data *dataAbertura;
    float saldoAtual;
};

#endif //TRAB1_ContaPoupanca_H
