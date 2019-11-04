#ifndef TRAB1_PESSOAFISICA_H
#define TRAB1_PESSOAFISICA_H

#include <string>
#include <sstream>

#include "Endereco.h"

using namespace std;

class PessoaFisica {
public:

    //Função para transformar float em int
    std::string to_string_with_precision(const float valor, const int num_casas){
        std::ostringstream out;
        out.precision(num_casas);
        out << std::fixed << valor;
        return out.str();
    }

    // Construtor
    PessoaFisica();

    // Destrutoe
    ~PessoaFisica();

    // Define PessoaFisica
    void setPessoaFisica();

    // Imprime info PessoaFisica
    string printPessoaFisica();

    // Editar Dados
    void EditaPessoaFisica(int option);

    // Setters
    void setNome();
    void setCPF();
    void setEndereco();
    void setTelefone();
    void setEmail();
    void setContaAtiva(int);
    void setTipoConta();

    // Getters
    string getNome();
    string getCPF();
    Endereco getEndereco();
    string getTelefone();
    string getEmail();
    int getContaAtiva();
    int getTipoConta();

private:
    string nome;
    string cpf;
    Endereco *endereco;
    string telefone;
    string email;
    int conta_ativa;
    int tipo_conta;         // 1 - Fisica & 2 - Juridica
};

#endif //TRAB1_PessoaFisica_H
