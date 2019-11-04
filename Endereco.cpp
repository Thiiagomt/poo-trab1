#include  <iostream>
#include "Endereco.h"
using namespace std;

// Construtor
Endereco::Endereco() {
    setRua();
    setBairro();
    setCidade();
    setUf();
    setCep();
    setNumero();
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

// Setters
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