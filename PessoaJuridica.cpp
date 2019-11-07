#include  <iostream>

#include "PessoaJuridica.h"
#include "Endereco.h"
#include "Data.h"

using namespace std;

void PessoaJuridica::setPessoaJuridica(){
    setRazaoSocial();
    setCNPJ();
    setCPFProprietarioMajor();
    setEndereco();
    setTelefone();
    setEmail();
    setRamoAtuacao();
    setDataFundacao();
    setDataUltimaAtt();
    setContaAtiva(0);
    setTipoConta();
} 

// Construtor
PessoaJuridica::PessoaJuridica() {
    setPessoaJuridica();
}

// Destrutor
PessoaJuridica::~PessoaJuridica() = default;

// Imprime info do PessoaJuridica
string PessoaJuridica::printPessoaJuridica() {
    string saida;

    saida = "\n\nA empresa dona desta conta é: " + getRazaoSocial() +
                "\nCom CNPJ: " + getCNPJ() +
                    "\nCPF do proprietario majoritario é" + getCPFProprietarioMajor() +
                        "\nTrabalha no ramo de atuacao de:" + getRamoAtuacao() +
                            "\nFundada em:" + this->data_fundacao->getDia() + "/" + this->data_fundacao->getMes() + "/" + this->data_fundacao->getAno() + 
                                "\nA ultima atualizacao do contrato social foi no dia:" + this->data_ultima_att->getDia() + "/" + this->data_ultima_att->getMes() + "/" + this->data_ultima_att->getAno() +
                                    "\nRua " + this->endereco->getRua() + ", " + this->endereco->getNumero() + 
                                        "\nBairro " + this->endereco->getBairro() + " - " + "CEP: " + this->endereco->getCep() +
                                            "\nLocalizada em: " + this->endereco->getCidade() + "- " + this->endereco->getUf() +
                                                "\nTelefone: " + getTelefone() +
                                                    "\nE-mail: " + getEmail() +
                                                        "\n";

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
    cout << "\n\n\nPessoaFisica cadastrado com sucesso!" << endl;
}

void PessoaFisica::setContaAtiva(int x) {
    this->conta_ativa = x;
}

void PessoaFisica::setTipoConta() {
    this->tipo_conta = 1;
}

void PessoaFisica::EditaPessoaFisica(int option){
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

