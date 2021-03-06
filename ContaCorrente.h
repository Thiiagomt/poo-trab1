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

    // Construtores com a passsaegm de parâmetros voltadas para o cenário, de forma a inicializar os atributos do objeto
    // Dia, Mes, Ano, Saldo inicial, Numero da conta, o cliente, Limite de cheque especial
    ContaCorrente(int, int, int, float, int, PessoaFisica, float);
    ContaCorrente(int, int, int, float, int, PessoaJuridica, float);

    // Destrutor
    ~ContaCorrente();

    // toString
    virtual string toString() const;

    // Setters
    void setNumConta(int num);
    void setCPF(PessoaFisica);
    void setCNPJ(PessoaJuridica);
    void setLimiteCheque();
    void setLimiteCheque(float x);

    // Getters
    int getNumConta() const;
    string getCPFouCNPJ() const;
    float getLimiteCheque() const;

private:
    int numConta;
    string cpf;
    string cnpj;
    float limitecheque;
};

#endif //TRAB2_CONTACORRENTE_H
