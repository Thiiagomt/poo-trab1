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

    // Construtor sem parâmetros
    Pessoa();

    // Construtor com parâmetros
    Pessoa(string, string, string, string, string, string, string, string, string);

    // Destrutor
    ~Pessoa();

    // toString
    virtual string toString() const;

    // Setters
    void setNome();
    void setEndereco();
    void setTelefone();
    void setEmail();
    void setNome(string);
    void setEndereco(string, string, string, string, string, string);
    void setTelefone(string);
    void setEmail(string);
    void setContaCorrenteAtiva(int);

    // Getters
    string getNome() const;
    Endereco* getEndereco() const;
    string getTelefone() const;
    string getEmail() const;
    int getContaCorrenteAtiva() const;

private:
    string nome;
    Endereco *endereco;
    string telefone;
    string email;
    int conta_corrente_ativa;
};

#endif //TRAB2_PESSOA_H
