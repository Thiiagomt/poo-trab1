//
// Created by thiago on 20/09/2019.
//

#include  <iostream>
#include <sstream>

#include "Lancamento.h"
using namespace std;

std::string to_string_with_precision(const float valor, const int num_casas){
    std::ostringstream out;
    out.precision(num_casas);
    out << std::fixed << valor;
    return out.str();
}

void Lancamento::setLancamento(int numConta, int operacao, float valorLancamento, Data dataLancamento){
    setNumConta(numConta);
    setOperacao(operacao);
    setValorLancamento(valorLancamento);
    setDataLancamento(dataLancamento);
}

// Construtor
Lancamento::Lancamento(int numConta, int operacao, float valorLancamento, Data dataLancamento) {
    setLancamento(numConta, operacao, valorLancamento, dataLancamento);
}

// Construtor default
Lancamento::Lancamento() = default;

// Destrutor
Lancamento::~Lancamento() = default;

// Imprime info do cliente
string Lancamento::printLancamento() {
    string operation;
    string saida;

    if(getOperacao() == 1)
        operation = "Debito";
    else
        operation = "Credito";

    saida = "O número da conta onde o lançamento foi feito é: " + to_string(getNumConta()) +
        "\nOperacao de: " + operation +
            "\nCom o valor de: R$" + to_string_with_precision(getValorLancamento(), 2) +
                "\nA data do lancamento na conta foi: " + to_string(getDataLancamento().dia) + "/" + to_string(getDataLancamento().mes) + "/" + to_string(getDataLancamento().ano);

    return saida;
}


// Setters
void Lancamento::setNumConta(int numConta) {
    this->numConta = numConta;
}
void Lancamento::setOperacao(int operacao){
    this->operacao = operacao;
}
void Lancamento::setValorLancamento(float valorLancamento){
    this->valorLancamento = valorLancamento;
}
void Lancamento::setDataLancamento(Data dataLancamento){
    this->dataLancamento = dataLancamento;
}


// Getters
int Lancamento::getNumConta(){
    return this->numConta;
}
int Lancamento::getOperacao(){
    return this->operacao;
}
float Lancamento::getValorLancamento(){
    return this->valorLancamento;
}
Data Lancamento::getDataLancamento(){
    return this->dataLancamento;
}
