#ifndef TRAB2_PESSOAFISICA_H
#define TRAB2_PESSOAFISICA_H

#include <string>
#include <sstream>

#include "Pessoa.h"

class PessoaFisica : public Pessoa {

public:
    // Construtor
    PessoaFisica();

    // Destrutoe
    ~PessoaFisica();

    // Imprime info PessoaFisica
    string printPessoaFisica();

    // Setters
    void setCPF();

    // Getters
    string getCPF();

private:
    string cpf;

};

#endif //TRAB2_PESSOAFISICA_H
