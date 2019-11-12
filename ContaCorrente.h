#ifndef TRAB2_CONTACORRENTE_H
#define TRAB2_CONTACORRENTE_H

#include <string>
#include <sstream>
using namespace std;

#include "PessoaJuridica.h"
#include "PessoaFisica.h"
#include "Conta.h"

class ContaCorrente : public Conta {
public:
    
    // Construtor
    // Sobrecarga de metódos nessa classe
    // A passagem do parametro pela main irá determinar qual será o cadastro utilizado
    ContaCorrente(int, PessoaFisica);
    ContaCorrente(int, PessoaJuridica);

    // Destrutor
    ~ContaCorrente();

    // Imprime info conta
    string toString();

    // Setters
    void setNumConta(int num);
    void setCPF(PessoaFisica);
    void setCNPJ(PessoaJuridica);
    void setLimiteCheque(float lim);

    // Getters
    int getNumConta();
    string getCPFouCNPJ();
    float getLimiteCheque();

private:
    int numConta;
    string cpf;
    string cnpj;
    float limitecheque;
};

#endif //TRAB2_CONTACORRENTE_H
