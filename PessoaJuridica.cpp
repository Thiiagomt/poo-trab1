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
                                                        "\n\n";

    return saida;
}


// Setters,
void PessoaJuridica::setRazaoSocial() {
    cout << "Digite o nome da empresa: ";
    cin.ignore();                           // Retira do buffer o '\n' vindo do switch
    getline(cin, this->razao_social);       // Pega a string do nome
}

void PessoaJuridica::setCNPJ() {
    int verif = 0;
    do {
        cout << "Digite o cnpj: ";
        getline(cin, this->cnpj);        // Pega a string do cnpj
}

void PessoaJuridica::setCPFProprietarioMajor() {
    int verif = 0;
    do {
        cout << "Digite o CPF do proprietario majoritario: ";
        getline(cin, this->cpf);        // Pega a string do cpf
        if (cpf.size() == 11) {         // Verifica se há 11 digitos, senão retorna ao for
            verif = 1;
        } else {
            cout << "CPF inválido! Verifique os dígitos\n";
        }
    } while (!verif);
}

void PessoaJuridica::setEndereco() {
    this->endereco = new Endereco();
}

void PessoaJuridica::setTelefone() {
    cout << "Digite seu telefone: ";
    cin.ignore();
    getline(cin, this->telefone);   
}

void PessoaJuridica::setEmail() {
    cout << "Digite seu email: ";
    getline(cin, this->email);      
}

void PessoaJuridica::setContaAtiva(int x) {
    this->conta_ativa = x;
}

void PessoaJuridica::setTipoConta() {
    this->tipo_conta = 2;
}

void PessoaJuridica::EditaPessoaJuridica(int option){
    if (option == 1) {
        setRazaoSocial();
    } else if (option == 2) {
        setCNPJ();
    } else if (option == 3) {
        setCPFProprietarioMajor();
    } else if (option == 4) {
        setEndereco();
    } else if (option == 5) {
        setTelefone();
    } else if (option == 6){
        setEmail();
    }
}

// Getters
string PessoaJuridica::getRazaoSocial(){
	return this->razao_social;
}

string PessoaJuridica::getCNPJ(){
	return this->cnpj;
}

string PessoaJuridica::getCPFProprietarioMajor(){
    return this->cpf_proprietario_major;
}

Endereco PessoaJuridica::getEndereco(){
    return *endereco;
}

string PessoaJuridica::getTelefone(){
    return this->telefone;
}

string PessoaJuridica::getEmail(){
    return this->email;
}

string PessoaJuridica::getRamoAtuacao(){
    return this->ramo_atuacao;
}

Data PessoaJuridica::getDataFundacao(){
    return *data_fundacao;
}

Data PessoaJuridica::getDataUltimaAtt(){
    return *data_ultima_att;
}

int PessoaJuridica::getContaAtiva(){
    return this->conta_ativa;
}

int PessoaJuridica::getTipoConta(){
    return this->tipo_conta;
}

