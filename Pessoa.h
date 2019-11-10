#ifndef TRAB2_PESSOA_H
#define TRAB2_PESSOA_H

#include <string>
#include <sstream>

#include "Endereco.h"

class Pessoa {
public:

    //Função para transformar float em string com 2 casas decimais
    std::string to_string_with_precision(const float valor, const int num_casas){
        std::ostringstream out;
        out.precision(num_casas);
        out << std::fixed << valor;
        return out.str();
    }

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
