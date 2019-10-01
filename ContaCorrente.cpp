//
// Created by thiago on 20/09/2019.
//

#include <iostream>

#include "ContaCorrente.h"
using namespace std;

void ContaCorrente::setConta(int numConta, Data dataAbertura, string cpfCliente, float saldoAtual) {
    setNumConta(numConta);
    setDataAbertura(dataAbertura);
    setCPFCliente(cpfCliente);
    setSaldoAtual(saldoAtual);
}

// Construtor
ContaCorrente::ContaCorrente(int numConta, Data dataAbertura, string cpfCliente, float saldoAtual) {
    setConta(numConta, dataAbertura, cpfCliente, saldoAtual);
}

// Construtor default
ContaCorrente::ContaCorrente() = default;

// Destrutor
ContaCorrente::~ContaCorrente() = default;

// Imprime info da conta
string ContaCorrente::printConta() {
    string saida;

    saida = "O CPF do dono desta conta é: " + getCPFCliente() +
        "\nO número da conta é: " + to_string(getNumConta()) +
            "\nA data de abertura da conta é: " + to_string(getDataAbertura().dia) + "/" + to_string(getDataAbertura().mes) + "/" + to_string(getDataAbertura().ano) +
                "\nO saldo atual da conta é: R$" + to_string_with_precision(getSaldoAtual(), 2);

    return saida;
}

// Setters
void ContaCorrente::setNumConta(int numConta){
    this->numConta = numConta;
}
void ContaCorrente::setDataAbertura(Data dataAbertura){
    if(dataAbertura.ano != 2019)
        while(dataAbertura.ano != 2019) {
            cout << "Ano inválido, insira novamente" << endl;
            cin >> dataAbertura.ano;
        }

    if(dataAbertura.mes<1 || dataAbertura.mes>12)
        while(dataAbertura.mes<1 || dataAbertura.mes>12){
            cout << "Mes inválido, insira novamente" << endl;
            cin >> dataAbertura.mes;
        }

    if(dataAbertura.mes == 2)
        if(dataAbertura.dia<1 || dataAbertura.dia>28)
            while(dataAbertura.dia<1 || dataAbertura.dia>28){
                cout << "O mes Fevereiro não pode ultrapassar o dia 28" << endl;
                cout << "Insira um novo dia válido" << endl;
                cin >> dataAbertura.dia;
            }

    if(dataAbertura.dia<1 || dataAbertura.dia>31)
        while(dataAbertura.dia<1 || dataAbertura.dia>31){
            cout << "Dia inválido, insira novamente" << endl;
            cin >> dataAbertura.dia;
        }

    this->dataAbertura = dataAbertura;
}
void ContaCorrente::setCPFCliente(string cpfCliente){
    this->cpfCliente = cpfCliente;
}
void ContaCorrente::setSaldoAtual(float saldoAtual){
    this->saldoAtual = saldoAtual;
}

// Getters
int ContaCorrente::getNumConta(){
    return this->numConta;
}
Data ContaCorrente::getDataAbertura(){
    return this->dataAbertura;
}
string ContaCorrente::getCPFCliente() {
    return this->cpfCliente;
}
float ContaCorrente::getSaldoAtual(){
    return this->saldoAtual;
}
