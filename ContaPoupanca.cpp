#include <iostream>

#include "ContaPoupanca.h"

using namespace std;

// Construtor
ContaPoupanca::ContaPoupanca(PessoaFisica x, int y) {
    this->setNumConta(y);
    this->setCPFPessoaFisica(x);
}

// Destrutor
ContaPoupanca::~ContaPoupanca() = default;

// Imprime info da conta
string ContaPoupanca::printConta() {
    string saida;

    saida = "O CPF do dono desta conta é: " + getCPFPessoaFisica() +
        "\nO número da conta é: 000" + to_string(getNumConta()) +
            "\nA data de abertura da conta é: " + to_string(this->getDataAbertura()->getDia()) + "/" + to_string(this->getDataAbertura()->getMes()) + "/" + to_string(this->getDataAbertura()->getAno()) +
                "\nO saldo atual da conta é: R$" + to_string_with_precision(getSaldoAtual(), 2)
                    + "\n";

    return saida;
}

// Setters
void ContaPoupanca::setNumConta(int y){
    this->numConta = y;
}
void ContaPoupanca::setCPFPessoaFisica(PessoaFisica x){
    this->cpf = x.getCPF();
}

// Getters
int ContaPoupanca::getNumConta(){
    return this->numConta;
}
string ContaPoupanca::getCPFPessoaFisica() {
    return this->cpf;
}
