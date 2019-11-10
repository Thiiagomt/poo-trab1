#include <iostream>

#include "Conta.h"

using namespace std;

// Construtor
ContaPoupanca::ContaPoupanca(int x) {
    setNumConta(x);
    setDataAbertura();
    setSaldoAtual(0);  
}

// Destrutor
ContaPoupanca::~ContaPoupanca() = default;

// Setters
void ContaPoupanca::setNumConta(int x){
    this->numConta = x;
}

void ContaPoupanca::setDataAbertura(){
    this->dataAbertura = new Data;
}
void ContaPoupanca::setSaldoAtual(float x){
    this->saldoAtual = x;
}

// Getters
int ContaPoupanca::getNumConta(){
    return this->numConta;
}
Data ContaPoupanca::getDataAbertura(){
    return *dataAbertura;
}
float ContaPoupanca::getSaldoAtual(){
    return this->saldoAtual;
}
