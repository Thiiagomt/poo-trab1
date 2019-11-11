#ifndef TRAB2_END_H
#define TRAB2_END_H

#include <string>
#include <sstream>

using namespace std;

class Endereco {
public:
    // Construtor sem parâmetros
    Endereco();

    // Construtor com parâmetros
    Endereco(string, string, string, string, string, string);

    // Destrutor
    ~Endereco();

    // Imprime info Endereco
    void printEndereco() const;

    // Valida Endereco e método toString
    string toString() const;

    // Setters
    void setRua();
    void setRua(string);
    void setBairro();
    void setBairro(string);
    void setCidade();
    void setCidade(string);
    void setUf();
    void setUf(string);
    void setCep();
    void setCep(string);
    void setNumero();
    void setNumero(string);

    // Getters
    string getRua() const;
    string getBairro() const;
    string getCidade() const;
    string getUf() const;
    string getCep() const;
    string getNumero() const;

private:
    string rua;
    string bairro;
    string cidade;
    string uf;
    string cep;
    string numero;
};

#endif //TRAB2_END_H
