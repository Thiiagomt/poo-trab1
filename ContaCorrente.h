#ifndef TRAB1_ContaCorrente_H
#define TRAB1_ContaCorrente_H

#include <string>
#include <sstream>
using namespace std;

#include "PessoaJuridica.h"
#include "Data.h"

class ContaPoupanca : public Conta {
public:
    
    // Construtor
    ContaPoupanca(int, PessoaFisica);

    // Destrutor
    ~ContaPoupanca();

    // Define PessoaFisica
    void setContaPoupanca(int, PessoaFisica);

    // Imprime info conta
    string printConta();

    // Setters
    void setNumConta(int);
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
