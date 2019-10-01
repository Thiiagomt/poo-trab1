//
// Created by thiago on 20/09/2019.
//

#ifndef TRAB1_CLIENTE_H
#define TRAB1_CLIENTE_H

#include <string>
#include <sstream>

using namespace std;

typedef struct{
    string rua;
    string bairro;
    string cidade;
    string uf;
    int cep;
    int numero;
} Adress;

class Cliente {
public:

    //Função para transformar float em int
    std::string to_string_with_precision(const float valor, const int num_casas){
        std::ostringstream out;
        out.precision(num_casas);
        out << std::fixed << valor;
        return out.str();
    }

    // Construtor
    Cliente(string nome, string cpf, Adress endereco, string telefone, string email);

    // Construtor default
    Cliente();

    // Destrutoe
    ~Cliente();

    // Define Cliente
    void setCliente(string nome, string cpf, Adress endereco, string telefone, string email);

    // Imprime info cliente
    string printCliente();

    // Setters
    void setNome(string);
    void setCPF(string);
    void setEndereco(Adress);
    void setTelefone(string);
    void setEmail(string);

    // Getters
    string getNome();
    string getCPF();
    Adress getEndereco();
    string getTelefone();
    string getEmail();

private:
    string nome;
    string cpf;
    Adress endereco;
    string telefone;
    string email;
};

#endif //TRAB1_CLIENTE_H
