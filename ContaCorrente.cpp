#include <iostream>

#include "ContaCorrente.h"
#include "Data.h"
using namespace std;

// Construtor
ContaCorrente::ContaCorrente(int n, PessoaFisica x, PessoaJuridica y, int z) { // Z define se será usado cpf ou cnpj
    setNumConta(n);
    setTipoCadastro(z);
    setCPFouCNPJ(x, y);
    setLimiteCheque(100);   // Definido R$ 100 como padrão
}

// Destrutor
ContaCorrente::~ContaCorrente() = default;

// Imprime info da conta
string ContaCorrente::printConta() {
    string saida;

    saida = "O CPF/CNPJ do dono desta conta é: " + this->getCPFouCNPJ() +
                "\nO número da conta é: 000" + to_string(this->getNumConta()) +
                    "\nA data de abertura da conta é: " + to_string(this->getDataAbertura()->getDia()) + "/" + to_string(this->getDataAbertura()->getMes()) + "/" + to_string(this->getDataAbertura()->getAno()) +
                        "\nO saldo atual da conta é: R$" + to_string_with_precision(this->getSaldoAtual(), 2) +
                            "\nO limite de cheque especial é: R$" + to_string(this->getLimiteCheque())
                            + "\n";

    return saida;
}

// Setters
void ContaCorrente::setNumConta(int num){
    this->numConta = num;
}

void ContaCorrente::setTipoCadastro(int z){
    this->tipo_cadastro = z;
}

void ContaCorrente::setCPFouCNPJ(PessoaFisica x, PessoaJuridica y){
    if (tipo_cadastro == 1)
        this->cpf = x.getCPF();
    else
        this->cnpj = y.getCNPJ();
}
void ContaCorrente::setLimiteCheque(float lim){
    this->limitecheque = lim;
}

// Getters
int ContaCorrente::getNumConta(){
    return this->numConta;
}

int ContaCorrente::getTipoCadastro(){
    return this->tipo_cadastro;
}

string ContaCorrente::getCPFouCNPJ() {
    if (tipo_cadastro == 1)
        return this->cpf;
    else
        return this->cnpj;
}
float ContaCorrente::getLimiteCheque(){
    return this->limitecheque;
}
