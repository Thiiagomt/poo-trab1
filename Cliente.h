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
    string cep;
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
    Cliente();

    // Destrutoe
    ~Cliente();

    // Define Cliente
    void setCliente();

    // Imprime info cliente
    string printCliente();

    // Setters
    void setNome();
    void setCPF();
    void setEndereco();
    void setTelefone();
    void setEmail();

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
