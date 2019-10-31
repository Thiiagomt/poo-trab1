//
// Created by thiago on 20/09/2019.
//

#ifndef TRAB1_ContaPoupanca_H
#define TRAB1_ContaPoupanca_H

#include <string>
#include <sstream>
using namespace std;

#include "PessoaFisica.h"
#include "Data.h"

class ContaPoupanca {
public:

    //Função para transformar float em int
    std::string to_string_with_precision(const float valor, const int num_casas){
        std::ostringstream out;
        out.precision(num_casas);
        out << std::fixed << valor;
        return out.str();
    }

    // Construtor
    ContaPoupanca(PessoaFisica);

    // Destrutor
    ~ContaPoupanca();

    // Define PessoaFisica
    void setContaPoupanca(PessoaFisica);

    // Imprime info conta
    string printConta();

    // Setters
    void setNumConta();
    void setDataAbertura();
    void setCPFPessoaFisica(PessoaFisica);
    void setSaldoAtual(float value);

    // Getters
    int getNumConta();
    Data getDataAbertura();
    string getCPFPessoaFisica();
    float getSaldoAtual();

private:
    int numConta;
    Data *dataAbertura;
    string cpfPessoaFisica;
    float saldoAtual;
};

#endif //TRAB1_ContaPoupanca_H
