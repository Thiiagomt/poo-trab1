#ifndef TRAB1_ContaPoupanca_H
#define TRAB1_ContaPoupanca_H

#include <string>
#include <sstream>
using namespace std;

#include "Conta.h"
#include "PessoaFisica.h"

class ContaPoupanca : public Conta {
public:

    // Construtor
    ContaPoupanca(int, PessoaFisica);

    // Destrutor
    ~ContaPoupanca();

    // Imprime info conta
    string printConta();

    // Setters
    void setCPFPessoaFisica(PessoaFisica);

    // Getters
    string getCPFPessoaFisica();

private:
    string cpfPessoaFisica;
};

#endif //TRAB1_ContaPoupanca_H
