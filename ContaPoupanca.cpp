#include <iostream>

#include "ContaPoupanca.h"

using namespace std;

// Construtor
ContaPoupanca::ContaPoupanca(int y, PessoaFisica x) {
    this->setNumConta(y);
    this->setDataAbertura();
    this->setCPFPessoaFisica(x);
    this->setSaldoAtual(0);
}

// Destrutor
ContaPoupanca::~ContaPoupanca() = default;

// Imprime info da conta
string ContaPoupanca::printConta() {
    string saida;

    saida = "O CPF do dono desta conta é: " + getCPFPessoaFisica() +
        "\nO número da conta é: 000" + to_string(getNumConta()) +
            "\nA data de abertura da conta é: " + to_string(this->dataAbertura->getDia()) + "/" + to_string(this->dataAbertura->getMes()) + "/" + to_string(this->dataAbertura->getAno()) +
                "\nO saldo atual da conta é: R$" + to_string_with_precision(getSaldoAtual(), 2)
                    + "\n";

    return saida;
}

// Setters
void ContaPoupanca::setCPFPessoaFisica(PessoaFisica x){
    this->cpfPessoaFisica = x.getCPF();
}

// Getters
string ContaPoupanca::getCPFPessoaFisica() {
    return this->cpfPessoaFisica;
}
