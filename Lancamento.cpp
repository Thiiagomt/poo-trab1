#include  <iostream>

#include "Data.h"
#include "Lancamento.h"

using namespace std;

void Lancamento::setLancamento(int numConta, int operacao, float valorLancamento, float saldoAnterior, float saldoAtualizado){
    setNumConta(numConta);
    setOperacao(operacao);
    setValorLancamento(valorLancamento);
    setSaldoAnterior(saldoAnterior);
    setSaldoAtualizado(saldoAtualizado);
    setDataLancamento();
}

//Construtor para cenários
Lancamento::Lancamento(int a, int b, float c, float d, float e, int f, int g, int h){
    setNumConta(a);
    setOperacao(b);
    setValorLancamento(c);
    setSaldoAnterior(d);
    setSaldoAtualizado(e);
    setDataLancamento(f, g, h);
}


// Construtor
Lancamento::Lancamento(int numConta, int operacao, float valorLancamento, float saldoAnterior, float saldoAtualizado) {
    setLancamento(numConta, operacao, valorLancamento, saldoAnterior, saldoAtualizado);
}

// Construtor default
Lancamento::Lancamento() = default;

// Destrutor
Lancamento::~Lancamento() = default;

// Imprime info do cliente
string Lancamento::toString() {
    string operation;
    string saida;

    if(getOperacao() == 1)
        operation = "Debito";
    else
        operation = "Credito";

    saida = "\nOperacao de: " + operation +
                "\nCom o valor de: R$" + to_string_with_precision(getValorLancamento(), 2) +
                    "\nA data do lancamento na conta foi: " + to_string(this->dataLancamento->getDia()) + "/" + to_string(this->dataLancamento->getMes()) + "/" + to_string(this->dataLancamento->getAno()) +
                        "\nO saldo anterior era de: " + to_string_with_precision(getSaldoAnterior(), 2) + 
                            "\nO saldo após o lancamento é: " + to_string_with_precision(getSaldoAtualizado(), 2) +
                                "\n";

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
void Lancamento::setDataLancamento(){
    this->dataLancamento = new Data;
}
void Lancamento::setDataLancamento(int x, int y, int z){
    this->dataLancamento = new Data(x, y, z);
}
void Lancamento::setSaldoAnterior(float saldoAnterior){
    this->saldoAnterior = saldoAnterior;
}
void Lancamento::setSaldoAtualizado(float saldoAtualizado){
    this->saldoAtualizado = saldoAtualizado;
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
    return *dataLancamento;
}
float Lancamento::getSaldoAnterior(){
    return this->saldoAnterior;
}
float Lancamento::getSaldoAtualizado(){
    return this->saldoAtualizado;
}
