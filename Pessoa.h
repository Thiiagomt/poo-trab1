#ifndef TRAB2_PESSOA_H
#define TRAB2_PESSOA_H

#include <string>
#include <sstream>

#include "Endereco.h"

class Pessoa {
public:

    // Construtor
    Pessoa();

    // Destrutor
    ~Pessoa();

    // Imprime info Pessoa
    string printPessoa();

    // Setters
    void setNome();
    void setEndereco();
    void setTelefone();
    void setEmail();
    void setContaAtiva(int);
    void setTipoConta();

    // Getters
    string getNome();
    Endereco* getEndereco();
    string getTelefone();
    string getEmail();
    int getContaAtiva();
    int getTipoConta();

private:
    string nome;
    Endereco *endereco;
    string telefone;
    string email;
    int conta_ativa;
    int tipo_conta;         // 1 - Fisica & 2 - Juridica
};

#endif //TRAB2_PESSOA_H
