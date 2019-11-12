#ifndef TRAB2_PESSOAJURIDICA_H
#define TRAB2_PESSOAJURIDICA_H

#include <string>
#include <sstream>

#include "Pessoa.h"
#include "Data.h"

using namespace std;

class PessoaJuridica : public Pessoa {
public:

    // Construtor sem parâmetros
    PessoaJuridica();

    // Construtor com parâmetros
    PessoaJuridica(string, string, string, string, string, string, string, string, string, string, string, string, int, int, int, int, int, int);

    // Destrutor
    ~PessoaJuridica();

    // Imprime info PessoaFisica
    string printPessoaJuridica();

    // Setters
    void setCNPJ();
    void setCNPJ(string);
    void setCPFProprietarioMajor();
    void setCPFProprietarioMajor(string);
    void setRamoAtuacao();
    void setRamoAtuacao(string);
    void setDataFundacao();
    void setDataFundacao(int, int, int);
    void setDataUltimaAtt();
    void setDataUltimaAtt(int, int, int);

    // Getters
    string getCNPJ();
    string getCPFProprietarioMajor();
    string getRamoAtuacao();
    Data* getDataFundacao();
    Data* getDataUltimaAtt();

private:
    string cnpj;
    string cpf_proprietario_major;
    string ramo_atuacao;
    Data *data_fundacao;
    Data *data_ultima_att;
};

#endif //TRAB2_PessoaJuridica_H
