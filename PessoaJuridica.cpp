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

    saida = "\n\nA empresa dona desta conta é: " + getRazaoSocial() +
                "\nCom CNPJ: " + getCNPJ() +
                    "\nCPF do proprietario majoritario é" + getCPFProprietarioMajor() +
                        "\nTrabalha no ramo de atuacao de:" + getRamoAtuacao() +
                            "\nFundada em:" + this->data_fundacao->getDia() + "/" + this->data_fundacao->getMes() + "/" + this->data_fundacao->getAno() + 
                                "\nA ultima atualizacao do contrato social foi no dia:" + this->data_ultima_att->getDia() + "/" + this->data_ultima_att->getMes() + "/" + this->data_ultima_att->getAno() +
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
        cout << "Digite seu cnpj: ";
        getline(cin, this->cnpj);        // Pega a string do cnpj
        if (cnpj.size() == 13) {         // Verifica se há 13 digitos, senão retorna ao for
            verif = 1;
        } else {
            cout << "CNPJ inválido! Verifique os dígitos\n";
        }
    } while (!verif);
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

Data PessoaJuridica::getDataFundacao(){
    return *data_fundacao;
}

Data PessoaJuridica::getDataUltimaAtt(){
    return *data_ultima_att;
}

