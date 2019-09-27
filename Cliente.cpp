//
// Created by thiago on 20/09/2019.
//

#include  <iostream>

#include "Cliente.h"
using namespace std;

void Cliente::setCliente(string nome, string cpf, Adress endereco, string telefone, string email){
    setNome(nome);
    setCPF(cpf);
    setEndereco(endereco);
    setTelefone(telefone);
    setEmail(email);
} 

//Construtor
Cliente::Cliente(string nome, string cpf, Adress endereco, string telefone, string email) {
    setCliente(nome, cpf, endereco, telefone, email);
}

//Construtor default
Cliente::Cliente() = default;

//Destrutor
Cliente::~Cliente() = default;

//Imprime info do cliente
void Cliente::printCliente() {
    cout << "O dono(a) desta conta é: " << getNome() << endl;
    cout << "Portador do CPF: " << getCPF() << endl;
    cout << "Endereço: Rua " << getEndereco().rua << "," << getEndereco().numero << " - Bairro " << getEndereco().bairro << " - CEP: " << getEndereco().cep << endl;
    cout << "Reside em: " << getEndereco().cidade << "," << getEndereco().uf << endl;
    cout << "Telefone: " << getTelefone() << endl;
    cout << "Email: " << getEmail() << endl;
}


//Setters
void Cliente::setNome(string nome) {
    this->nome = nome;
}
void Cliente::setCPF(string cpf) {
    this->cpf = cpf;
}
void Cliente::setEndereco(Adress endereco) {
    this->endereco = endereco;
}
void Cliente::setTelefone(string telefone){
    this->telefone = telefone;
}
void Cliente::setEmail(string email) {
    this->email = email;
}

//Getters
string Cliente::getNome(){
	return this->nome;
}
string Cliente::getCPF(){
	return this->cpf;
}
Adress Cliente::getEndereco(){
    return this->endereco;
}
string Cliente::getTelefone(){
    return this->telefone;
}
string Cliente::getEmail(){
    return this->email;
}

