#include  <iostream>

#include "PessoaJuridica.h"

using namespace std;

// Construtor
PessoaJuridica::PessoaJuridica() {
    this->setCNPJ();
    this->setCPFProprietarioMajor();
    this->setRamoAtuacao();
    this->setDataFundacao();
    this->setDataUltimaAtt();
}

// Destrutor
PessoaJuridica::~PessoaJuridica() = default;

// Imprime info do PessoaJuridica
string PessoaJuridica::printPessoaJuridica() {
    string saida;

    saida = "\n\nA empresa dona desta conta é: " + this->getNome() +
                "\nCom CNPJ: " + this->getCNPJ() +
                    "\nCPF do proprietario majoritario é" + this->getCPFProprietarioMajor() +
                        "\nTrabalha no ramo de atuacao de:" + this->getRamoAtuacao() +
                            "\nFundada em:" + to_string(this->getDataFundacao()->getDia()) + "/" + to_string(this->getDataFundacao()->getMes()) + "/" + to_string(this->getDataFundacao()->getAno()) + 
                                "\nA ultima atualizacao do contrato social foi no dia:" + to_string(this->getDataUltimaAtt()->getDia()) + "/" + to_string(this->getDataUltimaAtt()->getMes()) + "/" + to_string(this->getDataUltimaAtt()->getAno()) +
                                    "\nRua " + this->getEndereco()->getRua() + ", " + this->getEndereco()->getNumero() + 
                                        "\nBairro " + this->getEndereco()->getBairro() + " - " + "CEP: " + this->getEndereco()->getCep() +
                                            "\nLocalizada em: " + this->getEndereco()->getCidade() + "- " + this->getEndereco()->getUf() +
                                                "\nTelefone: " + getTelefone() +
                                                    "\nE-mail: " + getEmail() +
                                                        "\n\n";

    return saida;
}


// Setters
void PessoaJuridica::setCNPJ() {
    int verif = 0;
    do {
        cout << "Digite seu CNPJ: ";
        getline(cin, this->cnpj);        // Pega a string do cnpj
        if (cnpj.size() == 14) {         // Verifica se há 13 digitos, senão retorna ao for
            verif = 1;
        } else {
            cout << "CNPJ inválido! Verifique os dígitos\n";
        }
    } while (!verif);
}

void PessoaJuridica::setCPFProprietarioMajor() {
    string cpf_digitado;
    int verif = 0;
    do {
        cout << "Digite o CPF do proprietario majoritario: ";
        getline(cin, cpf_digitado);        // Pega a string do cpf_digitado
        if (cpf_digitado.size() == 11) {         // Verifica se há 11 digitos, senão retorna ao for
            verif = 1;
            this->cpf_proprietario_major = cpf_digitado;
        } else {
            cout << "CPF inválido! Verifique os dígitos\n";
        }
    } while (!verif);
}

void PessoaJuridica::setRamoAtuacao(){
    cout << "Digite o ramo de atuação da empresa: ";
    getline(cin, this->ramo_atuacao);
}

void PessoaJuridica::setDataFundacao(){
    cout << "Insira a data de fundação da empresa:\n";
    this->data_fundacao = new Data;
}

void PessoaJuridica::setDataUltimaAtt(){
    cout << "Insira a data da ultima atualizacao do contrato social\n";
    this->data_ultima_att = new Data;
}

// Getters
string PessoaJuridica::getCNPJ(){
    return this->cnpj;
}

string PessoaJuridica::getCPFProprietarioMajor(){
    return this->cpf_proprietario_major;
}

string PessoaJuridica::getRamoAtuacao(){
    return this->ramo_atuacao;
}

Data* PessoaJuridica::getDataFundacao(){
    return data_fundacao;
}

Data* PessoaJuridica::getDataUltimaAtt(){
    return data_ultima_att;
}