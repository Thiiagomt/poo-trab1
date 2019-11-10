#include <iostream>

#include "Conta.h"

using namespace std;

// Construtor
Conta::Conta() {
    setDataAbertura();
    setSaldoAtual(0);  
}

// Destrutor
Conta::~Conta() = default;

// Setters
void Conta::setDataAbertura(){
    this->dataAbertura = new Data;
}
void Conta::setSaldoAtual(float x){
    this->saldoAtual = x;
}

// Getters
Data* Conta::getDataAbertura(){
    return dataAbertura;
}
float Conta::getSaldoAtual(){
    return this->saldoAtual;
}
