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

    saida = "\n\nO dono(a) desta conta é: " + this->getNome() +
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

void PessoaFisica::setEndereco() {
    this->endereco = new Endereco();
}

void PessoaFisica::setTelefone(){
    cout << "Digite seu telefone: ";
    cin.ignore();
    getline(cin, this->telefone);   // Pega a string do telefone
}

void PessoaFisica::setEmail() {
    cout << "Digite seu email: ";
    getline(cin, this->email);      // Pega a string do email
}

void PessoaFisica::setContaAtiva(int x) {
    this->conta_ativa = x;
}

void PessoaFisica::setTipoConta() {
    this->tipo_conta = 1;
}

// Getters
string PessoaFisica::getCPF(){
    return this->cpf;
}