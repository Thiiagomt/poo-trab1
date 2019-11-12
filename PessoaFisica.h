#ifndef TRAB2_PESSOAFISICA_H
#define TRAB2_PESSOAFISICA_H

#include <string>
#include <sstream>

#include "Pessoa.h"

class PessoaFisica : public Pessoa {

public:
    // Construtor sem parâmetros
    PessoaFisica();

    // Construtor com parâmetros
    PessoaFisica(string, string, string, string, string, string, string, string, string, string);

    // Destrutoe
    ~PessoaFisica();

    // Imprime info PessoaFisica
    string toString();

    // Setters
    void setCPF();
    void setCPF(string);
    void setContaPoupancaAtiva(int);

    // Getters
    string getCPF();
    int getContaPoupancaAtiva();

private:
    string cpf;
    int conta_poupanca_ativa;

};

#endif //TRAB2_PESSOAFISICA_H
