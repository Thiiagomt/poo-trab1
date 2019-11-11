#ifndef TRAB2_DATA_H
#define TRAB2_DATA_H

#include <string>
#include <sstream>

using namespace std;

class Data {
public:
    // Construtor com parâmetros
    Data(int, int, int);

    // Construtor sem parâmetros
    Data();

    // Destrutor
    ~Data();

    // Imprime info Data
    void printData() const;

    // Valida Data e método toString
    int validaData();
    string toString() const;

    // Setters
    void setDia();
    void setDia(int);
    void setMes();
    void setMes(int);
    void setAno();
    void setAno(int);

    // Getters
    int getDia() const;
    int getMes() const;
    int getAno() const;

private:
    int dia;
    int mes;
    int ano;
};

#endif //TRAB2_DATA_H
