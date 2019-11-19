#include <iostream>

#include "Conta.h"

using namespace std;

// Construtor
Conta::Conta() {
    setDataAbertura();
    setSaldoAtual();
}

// Construtor com parâmetros
// Dia, Mes, Ano, Saldo inicial
Conta::Conta(int a, int b, int c, float d) {
    setDataAbertura(a, b, c);
    setSaldoAtual(d);
}

// Destrutor
Conta::~Conta() = default;

// toString
string Conta::toString() const {
    ostringstream sConta;
    sConta << "\nA data de abertura da conta é: " << this->getDataAbertura()->getDia() << "/" << this->getDataAbertura()->getMes() << "/" << this->getDataAbertura()->getAno() <<
                        "\nO saldo atual da conta é: R$" << to_string_with_precision(this->getSaldoAtual(), 2);
    return sConta.str();
}

// Setters sem parâmetros
void Conta::setDataAbertura(){
	cout << "\nInsira a data de abertura da conta: " << endl;
    this->dataAbertura = new Data;
}
void Conta::setSaldoAtual(){
    cout << "Digite o valor do saldo inicial: ";
    cin >> this->saldoAtual;
}
void Conta::setSaldoAtual(float x){
    this->saldoAtual = x;
}

// Setters com parâmetros
void Conta::setDataAbertura(int x, int y, int z){
    this->dataAbertura = new Data(x, y, z);
}

// Getters
Data* Conta::getDataAbertura() const {
    return dataAbertura;
}
float Conta::getSaldoAtual() const {
    return this->saldoAtual;
}
