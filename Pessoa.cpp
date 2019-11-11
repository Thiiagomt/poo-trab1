#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "Pessoa.h"

// Construtor sem parametro (uso prático do código)
Pessoa::Pessoa() {
    setNome();
    setEndereco();
    setTelefone();
    setEmail();
    setContaAtiva(0);
    setTipoConta();
}

// Construtor com parametros (uso para cenários)
// Nome, Telefone, Email, Rua, Bairro, Cidade, Uf, Cep, Numero
Pessoa::Pessoa(string a, string b, string c, string d, string e, string f, string g, string h, string i) {
    setNome(a);
    setTelefone(b);
    setEmail(c);
    setEndereco(d, e, f, g, h, i);
    setContaAtiva(0);
    setTipoConta();
}

// Destrutor
Pessoa::~Pessoa() = default;

// Setters sem parametros.  Usados no construtor sem parametros. As entradas vem do teclado
void Pessoa::setNome() {
    cout << "Digite seu Nome/Nome da Empresa: ";
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

// Setters com parametros.  Usados no construtor com parametros. As entradas sao passadas pos parametros
void Pessoa::setNome(string x) {
    this->nome = x;
}
void Pessoa::setEndereco(string a, string b, string c, string d, string e, string f) {
    this->endereco = new Endereco(a, b, c, d, e, f);
}
void Pessoa::setTelefone(string x){
    this->telefone = x;
}
void Pessoa::setEmail(string x) {
    this->email = x;
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
