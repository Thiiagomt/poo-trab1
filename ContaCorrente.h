//
// Created by thiago on 20/09/2019.
//

#ifndef TRAB1_CONTACORRENTE_H
#define TRAB1_CONTACORRENTE_H

#include <string>
using namespace std;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;


class ContaCorrente {
public:
    // Construtor
    ContaCorrente(int numConta, Data dataAbertura, string cpfCliente, float saldoAtual);

    // Construtor default
    ContaCorrente();

    // Destrutor
    ~ContaCorrente();

    //Define Cliente
    void setConta(int numConta, Data dataAbertura, string cpfCliente, float saldoAtual);

    //Imprime info conta
    void printConta();

    //Setters
    void setNumConta(int);
    void setDataAbertura(Data);
    void setCPFCliente(string);
    void setSaldoAtual(float);

    //Getters
    int getNumConta();
    Data getDataAbertura();
    string getCPFCliente();
    float getSaldoAtual();

private:
    int numConta;
    Data dataAbertura;
    string cpfCliente;
    float saldoAtual;
};

#endif //TRAB1_CONTACORRENTE_H
