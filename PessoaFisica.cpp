#include  <iostream>

#include "PessoaFisica.h"
#include "Endereco.h"

using namespace std;

void PessoaFisica::setPessoaFisica(){
    setNome();
    setCPF();
    setEndereco();
    setTelefone();
    setEmail();
    setContaAtiva(0);
    setTipoConta();
} 

// Construtor
PessoaFisica::PessoaFisica() {
    setPessoaFisica();
}

// Destrutor
PessoaFisica::~PessoaFisica() = default;

// Imprime info do PessoaFisica
string PessoaFisica::printPessoaFisica() {
    string saida;

    saida = "\n\nO dono(a) desta conta é: " + getNome() +
                "\nPortador do CPF: " + getCPF() +
                    "\nRua " + this->endereco->getRua() + ", " + this->endereco->getNumero() + 
                        "\nBairro " + this->endereco->getBairro() + " - " + "CEP: " + this->endereco->getCep() +
                            "\nReside em: " + this->endereco->getCidade() + "- " + this->endereco->getUf() +
                                "\nTelefone: " + getTelefone() +
                                    "\nE-mail: " + getEmail() +
                                        "\n\n";

    return saida;
}


// Setters
void PessoaFisica::setNome() {
    cout << "Digite seu nome: ";
    cin.ignore();                   // Retira do buffer o '\n' vindo do switch
    getline(cin, this->nome);       // Pega a string do nome
}

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

void PessoaFisica::EditaPessoaFisica(int option){
    if (option == 1) {
        setNome();
    } else if (option == 2) {
        setCPF();
    } else if (option == 3) {
        setEndereco();
    } else if (option == 4) {
        setTelefone();
    } else if (option == 5) {
        setEmail();
    }
}

// Getters
string PessoaFisica::getNome(){
	return this->nome;
}
string PessoaFisica::getCPF(){
	return this->cpf;
}
Endereco PessoaFisica::getEndereco(){
    return *endereco;
}
string PessoaFisica::getTelefone(){
    return this->telefone;
}
string PessoaFisica::getEmail(){
    return this->email;
}

int PessoaFisica::getContaAtiva(){
    return this->conta_ativa;
}

int PessoaFisica::getTipoConta(){
    return this->tipo_conta;
}

