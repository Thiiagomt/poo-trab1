#include <iostream>

#include "ContaPoupanca.h"

using namespace std;

// Construtor
ContaPoupanca::ContaPoupanca(PessoaFisica &x, int y) {
    this->setNumConta(y);
    this->setCPFPessoaFisica(x);
    x.setContaPoupancaAtiva(1);
}

// Construtor voltado para os cenários
// Cliente Fisico, Numero da conta, Dia, Mes, Ano, Saldo inicial
ContaPoupanca::ContaPoupanca(PessoaFisica &x, int y, int a, int b, int c, float d) : Conta(a, b, c, d) {
    this->setNumConta(y);
    this->setCPFPessoaFisica(x);
    x.setContaPoupancaAtiva(1);
}

// Destrutor
ContaPoupanca::~ContaPoupanca() = default;

// toString
// toString
string ContaPoupanca::toString() const {
    ostringstream sContaCorrente;
    sContaCorrente << "\n\nO CPF do dono desta conta é: " << getCPFPessoaFisica() <<
                        "\nO número da conta é: 000" << to_string(getNumConta()) <<
                            Conta::toString() << "\n";

    return sContaCorrente.str();
}

// Setters
void ContaPoupanca::setNumConta(int y){
    this->numConta = y;
}
void ContaPoupanca::setCPFPessoaFisica(PessoaFisica x){
    this->cpf = x.getCPF();
}

// Getters
int ContaPoupanca::getNumConta() const {
    return this->numConta;
}
string ContaPoupanca::getCPFPessoaFisica() const {
    return this->cpf;
}
