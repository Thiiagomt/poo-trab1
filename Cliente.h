//
// Created by thiago on 20/09/2019.
//

#ifndef TRAB1_CLIENTE_H
#define TRAB1_CLIENTE_H

#include <string>
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
    // Construtor
    Cliente(string nome, string cpf, Adress endereco, string telefone, string email);

    // Construtor default
    Cliente();

    // Destrutoe
    ~Cliente();

    // Define Cliente
    void setCliente(string nome, string cpf, Adress endereco, string telefone, string email);

    // Imprime info cliente
    void printCliente();

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
