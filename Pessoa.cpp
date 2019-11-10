#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "Pessoa.h"

// Construtor
Pessoa::Pessoa() {
    setNome();
    setEndereco();
    setTelefone();
    setEmail();
    setContaAtiva(0);
    setTipoConta();
}

// Destrutor
Pessoa::~Pessoa() = default;

// Setters
void Pessoa::setNome() {
    cout << "Digite seu nome: ";
    cin.ignore();                   // Retirar do buffer o '\n' proveniente da main
    getline(cin, this->nome);       // Pega a string do nome
}

void Pessoa::setEndereco() {
    this->endereco = new Endereco();
}

void Pessoa::setTelefone(){
    cout << "Digite seu telefone: ";
    cin.ignore();
    getline(cin, this->telefone);   // Pega a string do telefone
}

void Pessoa::setEmail() {
    cout << "Digite seu email: ";
    getline(cin, this->email);      // Pega a string do email
}

void Pessoa::setContaAtiva(int x) {
    this->conta_ativa = x;
}

void Pessoa::setTipoConta() {
    this->tipo_conta = 1;
}

// Getters
string Pessoa::getNome(){
    return this->nome;
}
Endereco* Pessoa::getEndereco(){
    return endereco;
}
string Pessoa::getTelefone(){
    return this->telefone;
}
string Pessoa::getEmail(){
    return this->email;
}

int Pessoa::getContaAtiva(){
    return this->conta_ativa;
}

int Pessoa::getTipoConta(){
    return this->tipo_conta;
}
