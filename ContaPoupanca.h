#ifndef TRAB2_CONTAPOUPANCA_H
#define TRAB2_CONTAPOUPANCA_H

#include <string>
#include <sstream>
using namespace std;

#include "Conta.h"
#include "PessoaFisica.h"

class ContaPoupanca : public Conta {
public:

    // Construtor
    ContaPoupanca(PessoaFisica, int);

    // Destrutor
    ~ContaPoupanca();

    // Imprime info conta
    string printConta();

    // Setters
    void setNumConta(int);
    void setCPFPessoaFisica(PessoaFisica);

    // Getters
    int getNumConta();
    string getCPFPessoaFisica();

private:
    int numConta;
    string cpf;
};

#endif //TRAB2_CONTAPOUPANCA_H
