#ifndef TRAB1_PESSOAJURIDICA_H
#define TRAB1_PESSOAJURIDICA_H

#include <string>
#include <sstream>

#include "Endereco.h"
#include "Data.h"

using namespace std;

class PessoaJuridica {
public:

    //Função para transformar float em string com 2 casas decimais
    std::string to_string_with_precision(const float valor, const int num_casas){
        std::ostringstream out;
        out.precision(num_casas);
        out << std::fixed << valor;
        return out.str();
    }

    // Construtor
    PessoaJuridica();

    // Destrutoe
    ~PessoaJuridica();

    // Define PessoaFisica
    void setPessoaJuridica();

    // Imprime info PessoaFisica
    string printPessoaJuridica();

    // Editar Dados
    void EditaPessoaJuridica(int option);

    // Setters
    void setRazaoSocial();
    void setCNPJ();
    void setCPFProprietarioMajor();
    void setEndereco();
    void setTelefone();
    void setEmail();
    void setRamoAtuacao();
    void setDataFundacao();
    void setDataUltimaAtt();
    void setContaAtiva(int);
    void setTipoConta();

    // Getters
    string getRazaoSocial();
    string getCNPJ();
    string getCPFProprietarioMajor();
    Endereco getEndereco();
    string getTelefone();
    string getEmail();
    string getRamoAtuacao();
    Data getDataFundacao();
    Data getDataUltimaAtt();
    int getContaAtiva();
    int getTipoConta();

private:
    string razao_social;
    string cnpj;
    string cpf_proprietario_major;
    Endereco *endereco;
    string telefone;
    string email;
    string ramo_atuacao;
    Data *data_fundacao;
    Data *data_ultima_att;
    int conta_ativa;
    int tipo_conta;         // 1 - Fisica & 2 - Juridica
};

#endif //TRAB1_PessoaJuridica_H
