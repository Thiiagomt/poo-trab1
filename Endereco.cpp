#include  <iostream>
#include "Endereco.h"
using namespace std;

// Construtor sem parametro (uso prático do código)
Endereco::Endereco() {
    setRua();
    setBairro();
    setCidade();
    setUf();
    setCep();
    setNumero();
}

// Construtor com parametros (uso para cenários)
// Rua, Bairro, Cidade, Uf, Cep, Numero
Endereco::Endereco(string a, string b, string c, string d, string e, string f) {
    setRua(a);
    setBairro(b);
    setCidade(c);
    setUf(d);
    setCep(e);
    setNumero(f);
}

// Destrutor
Endereco::~Endereco() = default;

// Imprime info da Endereco
void Endereco::printEndereco() const {
    cout << "Endereco:\n" << "Rua: " << getRua() << ", " << getBairro() << ", " << ", " << getNumero() <<
    "\nCEP: " + getCep() + ", " + getCidade() << ", " << getUf();
}

// Metodo toString
string Endereco::toString() const {
    string retorno;
    ostringstream sEndereco;
    sEndereco << this->rua << "/" << this->bairro << "/" << this->cidade << "/" << this->numero << "/" << this->cep <<
    "/" << this->uf;
    retorno = sEndereco.str();
    return retorno;
}

// Setters sem parametros.  Usados no construtor sem parametros. As entradas vem do teclado
void Endereco::setRua() {
    cout << "Rua: ";
    getline(cin, this->rua);
}
void Endereco::setBairro() {
    cout << "Bairro: ";
    getline(cin, this->bairro);
}
void Endereco::setCidade() {
    cout << "Cidade: ";
    getline(cin, this->cidade);
}
void Endereco::setUf() {
    cout << "Uf: ";
    getline(cin, this->uf);
}
void Endereco::setCep() {
    cout << "CEP: ";
    getline(cin, this->cep);
}
void Endereco::setNumero() {
    cout << "Numero: ";
    cin >> this->numero;
}

// Setters com parametros.  Usados no construtor com parametros. As entradas sao passadas pos parametros
void Endereco::setRua(string x) {
    this->rua = x;
}
void Endereco::setBairro(string x) {
    this->bairro = x;
}
void Endereco::setCidade(string x) {
    this->cidade = x;
}
void Endereco::setUf(string x) {
    this->uf = x;
}
void Endereco::setCep(string x) {
    this->cep = x;
}
void Endereco::setNumero(string x) {
    this->numero = x;
}

// Getters
string Endereco::getRua() const {
    return this->rua;
}

string Endereco::getBairro() const {
    return this->bairro;
}

string Endereco::getCidade() const {
    return this->cidade;
}

string Endereco::getUf() const {
    return this->uf;
}

string Endereco::getCep() const {
    return this->cep;
}

string Endereco::getNumero() const {
    return this->numero;
}
