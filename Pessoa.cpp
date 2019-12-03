#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "Pessoa.h"

// Construtor com parametros (uso para cenários)
// Nome, Telefone, Email, Rua, Bairro, Cidade, Uf, Cep, Numero
Pessoa::Pessoa(string a, string b, string c, string d, string e, string f, string g, string h, string i) {
    setNome(a);
    setTelefone(b);
    setEmail(c);
    setEndereco(d, e, f, g, h, i);
    setContaCorrenteAtiva(0);
}

// Construtor sem parametro (uso prático do código)
Pessoa::Pessoa() {
    setNome();
    setEndereco();
    setTelefone();
    setEmail();
    setContaCorrenteAtiva(0);
}

// Destrutor
Pessoa::~Pessoa() = default;

// toString
string Pessoa::toString() const {
    ostringstream sPessoa;
    sPessoa << "\nCliente/Empresa: " << this->getNome() <<
                    "\nRua " << this->getEndereco()->getRua() << ", " << this->getEndereco()->getNumero() <<
                        "\nBairro " << this->getEndereco()->getBairro() << " - " << "CEP: " << this->getEndereco()->getCep() <<
                            "\nReside em: " << this->getEndereco()->getCidade() << "- " << this->getEndereco()->getUf() <<
                                "\nTelefone: " << this->getTelefone() <<
                                    "\nE-mail: " << this->getEmail() <<
                                        "\n";
    return sPessoa.str();
}

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
void Pessoa::setContaCorrenteAtiva(int x) {
    this->conta_corrente_ativa = x;
}
void Pessoa::setTipoPessoa(int x){
    this->tipo_pessoa = x;
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
string Pessoa::getNome() const {
    return this->nome;
}
Endereco* Pessoa::getEndereco() const {
    return endereco;
}
string Pessoa::getTelefone() const {
    return this->telefone;
}
string Pessoa::getEmail() const {
    return this->email;
}

int Pessoa::getContaCorrenteAtiva() const {
    return this->conta_corrente_ativa;
}

int Pessoa::getTipoPessoa() const {
    return this->tipo_pessoa;
}
