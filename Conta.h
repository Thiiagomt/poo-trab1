#ifndef TRAB2_CONTA_H
#define TRAB2_CONTA_H

#include <string>
#include <sstream>
using namespace std;

#include "Data.h"

class Conta {
public:

    //Função para transformar float em string com 2 casas decimais
    std::string to_string_with_precision(const float valor, const int num_casas) const {
        std::ostringstream out;
        out.precision(num_casas);
        out << std::fixed << valor;
        return out.str();
    }

    // Construtor sem parâmetros
    Conta();

    // Construtor com parâmetros
    Conta(int, int, int, float);

    // Destrutor
    ~Conta();

    // toString
    virtual string toString() const;

    // Setters
    void setDataAbertura();
    void setDataAbertura(int a, int b, int c);
    void setSaldoAtual();
    void setSaldoAtual(float x);
    void setTipoConta(int x);

    // Getters
    Data* getDataAbertura() const;
    float getSaldoAtual() const;
    int getTipoConta() const;

private:
    Data *dataAbertura;
    float saldoAtual;
    int tipo_conta; //1 = conta poupança ; 2 = conta corrente; 
};

#endif //TRAB2_CONTA_H
