//
// Created by thiago on 20/09/2019.
//

#ifndef TRAB1_CONTACORRENTE_H
#define TRAB1_CONTACORRENTE_H

#include <string>
#include <sstream>
using namespace std;



typedef struct {
    int dia;
    int mes;
    int ano;
} Data;


class ContaCorrente {
public:

    //Função para transformar float em int
    std::string to_string_with_precision(const float valor, const int num_casas){
        std::ostringstream out;
        out.precision(num_casas);
        out << std::fixed << valor;
        return out.str();
    }

    // Construtor
    ContaCorrente(int numConta, Data dataAbertura, string cpfCliente, float saldoAtual);

    // Construtor default
    ContaCorrente();

    // Destrutor
    ~ContaCorrente();

    // Define Cliente
    void setConta(int numConta, Data dataAbertura, string cpfCliente, float saldoAtual);

    // Imprime info conta
    string printConta();

    // Setters
    void setNumConta(int);
    void setDataAbertura(Data);
    void setCPFCliente(string);
    void setSaldoAtual(float);

    // Getters
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
