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

    // Construtor com parâmetros (voltada para os cenários)
    // Cliente Fisico, Numero da conta, Dia, Mes, Ano, Saldo inicial
    ContaPoupanca(PessoaFisica, int, int, int, int, int);

    // Destrutor
    ~ContaPoupanca();

    // Imprime info conta
    string toString();

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
