#include <iostream>

#include "Conta.h"

using namespace std;

// Construtor
Conta::Conta() {
    setDataAbertura();
    setSaldoAtual(0);
}

Conta::Conta(int a, int b, int c, float d) {
    setDataAbertura(a, b, c);
    setSaldoAtual(0);
}

// Destrutor
Conta::~Conta() = default;

// Setters sem parâmetros
void Conta::setDataAbertura(){
	cout << "\nInsira a data de abertura da conta: " << endl;
    this->dataAbertura = new Data;
}
void Conta::setSaldoAtual(float x){
    this->saldoAtual = x;
}

// Setters com parâmetros
void Conta::setDataAbertura(int x, int y, int z){
    this->dataAbertura = new Data(x, y, z);
}

// Getters
Data* Conta::getDataAbertura(){
    return dataAbertura;
}
float Conta::getSaldoAtual(){
    return this->saldoAtual;
}
