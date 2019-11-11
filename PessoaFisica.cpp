#include  <iostream>
#include <string>

using namespace std;

#include "PessoaFisica.h"

PessoaFisica::PessoaFisica(){
    this->setCPF();
}

// Destrutor
PessoaFisica::~PessoaFisica() = default;

// Imprime info do PessoaFisica
string PessoaFisica::printPessoaFisica() {
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

// Getters
string PessoaFisica::getCPF(){
    return this->cpf;
}