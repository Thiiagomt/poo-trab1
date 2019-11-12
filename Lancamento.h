#ifndef TRAB1_LANCAMENTO_H
#define TRAB1_LANCAMENTO_H

using namespace std;
#include <string>
#include <sstream>

#include "Data.h"
#include "ContaPoupanca.h"

class Lancamento {
public:

    //Função para transformar float em string com 2 casas decimais
    std::string to_string_with_precision(const float valor, const int num_casas){
        std::ostringstream out;
        out.precision(num_casas);
        out << std::fixed << valor;
        return out.str();
    }

    // Construtor
    Lancamento(int numConta, int operacao, float valorLancamento, float saldoAnterior, float saldoAtualizado);

    // Construtor default
    Lancamento();

    // Destrutor
    ~Lancamento();

    // Define Cliente
    void setLancamento(int numConta, int operacao, float valorLancamento, float saldoAnterior, float saldoAtualizado);

    // Imprime info conta
    string toString();

    // Setters
    void setNumConta(int);
    void setOperacao(int);
    void setValorLancamento(float);
    void setDataLancamento();
    void setSaldoAnterior(float);
    void setSaldoAtualizado(float);


    // Getters
    int getNumConta();
    int getOperacao();
    float getValorLancamento();
    Data getDataLancamento();
    float getSaldoAnterior();
    float getSaldoAtualizado();

private:
    int numConta;
    int operacao;
    float valorLancamento;
    Data *dataLancamento;
    float saldoAnterior;
    float saldoAtualizado;
};


#endif //TRAB1_LANCAMENTO_H
