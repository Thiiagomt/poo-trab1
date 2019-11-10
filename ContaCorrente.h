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
    // A ideia de passar os dois e para a escolha para cfp ou cnpj a ser usado na conta conta
    ContaCorrente(int, PessoaFisica, PessoaJuridica, int);

    // Destrutor
    ~ContaCorrente();

    // Imprime info conta
    string printConta();

    // Setters
    void setNumConta(int num);
    void setTipoCadastro(int tipo);
    void setCPFouCNPJ(PessoaFisica, PessoaJuridica);
    void setLimiteCheque(float lim);

    // Getters
    int getNumConta();
    int getTipoCadastro();
    string getCPFouCNPJ();
    float getLimiteCheque();

private:
    int numConta;
    int tipo_cadastro;   // Determina se será usado cpf ou cnpj
    string cpf;
    string cnpj;
    float limitecheque;
};

#endif //TRAB2_CONTACORRENTE_H
