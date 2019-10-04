//
// Created by thiago on 20/09/2019.
//

#include  <iostream>

#include "Cliente.h"
using namespace std;

void Cliente::setCliente(){
    setNome();
    setCPF();
    setEndereco();
    setTelefone();
    setEmail();
} 

// Construtor
Cliente::Cliente() {
    setCliente();
}

// Destrutor
Cliente::~Cliente() = default;

// Imprime info do cliente
string Cliente::printCliente() {
    string saida;

    saida = "O dono(a) desta conta é: " + getNome() +
        "\nPortador do CPF: " + getCPF() +
            "\nEndereço: Rua " + getEndereco().rua + "," + to_string(getEndereco().numero) + " Bairro " + getEndereco().bairro + "," + " CEP: " + getEndereco().cep +
                "\nReside em: " + getEndereco().cidade + "," + getEndereco().uf +
                    "\nTelefone: " + getTelefone() +
                        "\nEmail: " + getEmail() + "\n";

    return saida;
}


// Setters
void Cliente::setNome() {
    cout << "Digite seu nome: ";
    cin.ignore();                   // Retira do buffer o '\n' vindo do switch
    getline(cin, this->nome);       // Pega a string do nome
}
void Cliente::setCPF() {
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
void Cliente::setEndereco() {

    Adress endereco;
    
    // Tavoni: Tentei fazer o mesmo laço para o CPF, mas não estava retornando o tamanho da string (não sei o porque...)
    cout << "CEP: ";
    getline(cin, this->endereco.cep);

    cout << "Rua: ";
    getline(cin, this->endereco.rua);
    
    cout << "Numero: ";
    cin >> this->endereco.numero;

    cout << "Bairro: ";
    cin.ignore();
    getline(cin, this->endereco.bairro);

    cout << "Cidade: ";
    getline(cin, this->endereco.cidade);

    cout << "Uf: ";
    getline(cin, this->endereco.uf);
}

void Cliente::setTelefone(){
    cout << "Digite seu telefone: ";
    getline(cin, this->telefone);   // Pega a string do telefone
}

void Cliente::setEmail() {
    cout << "Digite seu email: ";
    getline(cin, this->email);      // Pega a string do email
}

void Cliente::EditaCliente(int option){
    if (option == 1) {
        setTelefone();
    } else if (option == 2) {
        setEndereco();
    } else if (option == 3) {
        setEmail();
    } else if (option == 4) {
        setNome();
    } else if (option == 5) {
        setCPF();
    }
}

// Getters
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

