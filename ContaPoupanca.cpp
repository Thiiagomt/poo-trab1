#include <iostream>

#include "ContaPoupanca.h"
#include "Data.h"
using namespace std;

void ContaPoupanca::setContaPoupanca(int y, PessoaFisica x) {
    setNumConta(y);
    setDataAbertura();
    setCPFPessoaFisica(x);
    setSaldoAtual(0);
}

// Construtor
ContaPoupanca::ContaPoupanca(int y, PessoaFisica x) {
    setContaPoupanca(y, x);
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
void ContaPoupanca::setNumConta(int y){
    this->numConta = y;
}

void ContaPoupanca::setDataAbertura(){
    this->dataAbertura = new Data;
}
void ContaPoupanca::setCPFPessoaFisica(PessoaFisica x){
    this->cpfPessoaFisica = x.getCPF();
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
string ContaPoupanca::getCPFPessoaFisica() {
    return this->cpfPessoaFisica;
}
float ContaPoupanca::getSaldoAtual(){
    return this->saldoAtual;
}
