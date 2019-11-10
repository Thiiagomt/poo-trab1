#ifndef TRAB2_PESSOAJURIDICA_H
#define TRAB2_PESSOAJURIDICA_H

#include <string>
#include <sstream>

#include "Pessoa.h"
#include "Data.h"

using namespace std;

class PessoaJuridica : public Pessoa {
public:

    // Construtor
    PessoaJuridica();

    // Destrutor
    ~PessoaJuridica();

    // Imprime info PessoaFisica
    string printPessoaJuridica();

    // Setters
    void setCNPJ();
    void setCPFProprietarioMajor();
    void setRamoAtuacao();
    void setDataFundacao();
    void setDataUltimaAtt();

    // Getters
    string getCNPJ();
    string getCPFProprietarioMajor();
    string getRamoAtuacao();
    Data getDataFundacao();
    Data getDataUltimaAtt();

private:
    string cnpj;
    string cpf_proprietario_major;
    string ramo_atuacao;
    Data *data_fundacao;
    Data *data_ultima_att;
};

#endif //TRAB2_PessoaJuridica_H
