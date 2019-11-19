#include <iostream>

#include "ContaCorrente.h"
#include "Data.h"
using namespace std;

// Construtor
// A variável z define se será usado cpf ou cnpj
// Caso queira usar na conta o cpf
ContaCorrente::ContaCorrente(int n, PessoaFisica x) {
    setNumConta(n);
    setCPF(x);
    setLimiteCheque();
}

// Caso queira usar na conta o cnpj
ContaCorrente::ContaCorrente(int n, PessoaJuridica x) {
    setNumConta(n);
    setCNPJ(x);
    setLimiteCheque(); 
}

// Construtores com a passsaegm de parâmetros voltadas para o cenário, de forma a inicializar os atributos do objeto
ContaCorrente::ContaCorrente(int a, int b, int c, float d, int n, PessoaFisica x, float e) : Conta(a, b, c, d) {
    setNumConta(n);
    setCPF(x);
    setLimiteCheque(e);
}

// Caso queira usar na conta o cnpj
ContaCorrente::ContaCorrente(int a, int b, int c, float d, int n, PessoaJuridica x, float e) : Conta(a, b, c, d) {
    Conta(a, b, c, d);
    setNumConta(n);
    setCNPJ(x);
    setLimiteCheque(e);
}

// Destrutor
ContaCorrente::~ContaCorrente() = default;

// toString
string ContaCorrente::toString() const {
    ostringstream sContaCorrente;
    sContaCorrente << "\n\nO CPF/CNPJ do dono desta conta é: " << this->getCPFouCNPJ() <<
                        "\nO número da conta é: 000" << to_string(this->getNumConta()) <<
                            Conta::toString() <<
                                "\nO limite de cheque especial é: R$" << to_string_with_precision(this->getLimiteCheque(), 2) << 
                                    "\n";
    return sContaCorrente.str();
}

// Setters
void ContaCorrente::setNumConta(int num){
    this->numConta = num;
}

void ContaCorrente::setCPF(PessoaFisica x){
    this->cpf = x.getCPF();
}

void ContaCorrente::setCNPJ(PessoaJuridica x){
    this->cnpj = x.getCNPJ();
}

void ContaCorrente::setLimiteCheque(){
    cout << "Digite o valor para seu limite de cheque: ";
    cin >> this->limitecheque;
}

void ContaCorrente::setLimiteCheque(float x){
    this->limitecheque = x;
}

// Getters
int ContaCorrente::getNumConta() const {
    return this->numConta;
}

string ContaCorrente::getCPFouCNPJ() const {
    // Para o cpf ser maior que o cnpj, cnpj não pode estar sendo ocupado aqui
    if (this->cpf > this->cnpj)
        return this->cpf;
    else
        return this->cnpj;
}
float ContaCorrente::getLimiteCheque() const {
    return this->limitecheque;
}
