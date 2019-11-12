#include  <iostream>
#include <string>

using namespace std;

#include "PessoaFisica.h"

PessoaFisica::PessoaFisica(){
    this->setCPF();
}
// Nome, Telefone, Email, Rua, Bairro, Cidade, Uf, Cep, Numero, Cpf
PessoaFisica::PessoaFisica(string a, string b, string c, string d, string e, string f, string g, string h, string i, string j){
    Pessoa(a, b, c, d, e, f, g, h, i);
    this->setCPF(j);
}

// Destrutor
PessoaFisica::~PessoaFisica() = default;

// Imprime info do PessoaFisica
string PessoaFisica::toString() {
    string saida;

    saida = "\nCliente: " + this->getNome() +
                "\nPortador do CPF: " + this->getCPF() +
                    "\nRua " + this->getEndereco()->getRua() + ", " + this->getEndereco()->getNumero() +
                        "\nBairro " + this->getEndereco()->getBairro() + " - " + "CEP: " + this->getEndereco()->getCep() +
                            "\nReside em: " + this->getEndereco()->getCidade() + "- " + this->getEndereco()->getUf() +
                                "\nTelefone: " + this->getTelefone() +
                                    "\nE-mail: " + this->getEmail() +
                                        "\n\n";

    return saida;
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
string PessoaFisica::getCPF(){
    return this->cpf;
}

int PessoaFisica::getContaPoupancaAtiva(){
    return this->conta_poupanca_ativa;
}
