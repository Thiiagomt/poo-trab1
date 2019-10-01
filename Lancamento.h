//
// Created by thiago on 30/09/2019.
//

#ifndef TRAB1_LANCAMENTO_H
#define TRAB1_LANCAMENTO_H

using namespace std;
#include <string>
#include <sstream>
#include "ContaCorrente.h"

class Lancamento {
public:

    //Função para transformar float em int
    std::string to_string_with_precision(const float valor, const int num_casas){
        std::ostringstream out;
        out.precision(num_casas);
        out << std::fixed << valor;
        return out.str();
    }

    // Construtor
    Lancamento(int numConta, int operacao, float valorLancamento, Data dataLancamento);

    // Construtor default
    Lancamento();

    // Destrutor
    ~Lancamento();

    // Define Cliente
    void setLancamento(int numConta, int operacao, float valorLancamento, Data dataLancamento);

    // Imprime info conta
    string printLancamento();

    // Setters
    void setNumConta(int);
    void setOperacao(int);
    void setValorLancamento(float);
    void setDataLancamento(Data);

    // Getters
    int getNumConta();
    int getOperacao();
    float getValorLancamento();
    Data getDataLancamento();

private:
    int numConta;
    int operacao;
    float valorLancamento;
    Data dataLancamento;
};


#endif //TRAB1_LANCAMENTO_H
