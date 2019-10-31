//
// Created by thiago on 20/09/2019.
//

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "ContaPoupanca.h"
#include "Data.h"
using namespace std;

void ContaPoupanca::setContaPoupanca(PessoaFisica x) {
    setNumConta();
    setDataAbertura();
    setCPFPessoaFisica(x);
    setSaldoAtual(0);
}

// Construtor
ContaPoupanca::ContaPoupanca(PessoaFisica x) {
    setContaPoupanca(x);
}

// Destrutor
ContaPoupanca::~ContaPoupanca() = default;

// Imprime info da conta
string ContaPoupanca::printConta() {
    string saida;

    saida = "O CPF do dono desta conta é: " + getCPFPessoaFisica() +
        "\nO número da conta é: " + to_string(getNumConta()) +
            "\nA data de abertura da conta é: " + to_string(this->dataAbertura->getDia()) + "/" + to_string(this->dataAbertura->getMes()) + "/" + to_string(this->dataAbertura->getAno()) +
                "\nO saldo atual da conta é: R$" + to_string_with_precision(getSaldoAtual(), 2)
                    + "\n";

    return saida;
}

// Setters
void ContaPoupanca::setNumConta(){
    /* Gera um numero 1000000 e 10000000: */  
    this->numConta = rand() % (10000000 + 1 - 1000000) + 1000000;
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
