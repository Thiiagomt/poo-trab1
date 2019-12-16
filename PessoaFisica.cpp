#include  <iostream>
#include <string>

using namespace std;

#include "PessoaFisica.h"

PessoaFisica::PessoaFisica(){}
/*
PessoaFisica::PessoaFisica(){
    this->setCPF();
    this->setContaPoupancaAtiva(0);
}
*/
// Nome, Telefone, Email, Rua, Bairro, Cidade, Uf, Cep, Numero, Cpf
PessoaFisica::PessoaFisica(string a, string b, string c, string d, string e, string f, string g, string h, string i, string j) : Pessoa(a, b, c, d, e, f, g, h, i) {
    this->setCPF(j);
    this->setContaPoupancaAtiva(0);
}

// Destrutor
PessoaFisica::~PessoaFisica() = default;

// Imprime info do PessoaFisica
string PessoaFisica::toString() const {
    ostringstream sPessoaFisica;

    sPessoaFisica << "\nPortador do CPF: " << this->getCPF() << Pessoa::toString();

    return sPessoaFisica.str();
}

// Setters
void PessoaFisica::setCPF() {
    int verif = 0;
    do {
        cout << "Digite seu cpf: ";
        getline(cin, this->cpf);        // Pega a string do cpf
        if (cpf.size() == 11) {         // Verifica se há 11 digitos, senão retorna ao for
            verif = 1;
        } else {
            cout << "CPF inválido! Verifique os dígitos\n";
        }
    } while (!verif);
}

void PessoaFisica::setCPF(string x) {
    this->cpf = x;
}

void PessoaFisica::setContaPoupancaAtiva(int y){
    this->conta_poupanca_ativa= y;
}

// Getters
string PessoaFisica::getCPF() const {
    return this->cpf;
}

int PessoaFisica::getContaPoupancaAtiva() const {
    return this->conta_poupanca_ativa;
}
