#include  <iostream>
#include "Data.h"
using namespace std;

// Construtor sem parâmetros
Data::Data() {
    int valido = 0;
    while (!valido) {
        setDia();
        setMes();
        setAno();
        valido = validaData();
    }
}

// Construtor com parâmetros
// Dia, Mes, Ano
Data::Data(int a, int b, int c) {
    setDia(a);
    setMes(b);
    setAno(c);
    int nadaaver=0;
    nadaaver=validaData();
}

// Destrutor
Data::~Data() = default;

// Imprime info da data
void Data::printData() const {
    cout << "Data: " << dia << "/" << mes << "/" << ano << "\n";
}

// Metodo toString
string Data::toString() const {
    string retorno;
    ostringstream sData;
    sData << this->dia << "/" << this->mes << "/" << this->ano;
    retorno = sData.str();
    return retorno;
}

// Setters
void Data::setDia() {
    cout << "Dia: ";
    cin >> this->dia;
}
void Data::setMes() {
    cout << "Mes: ";
    cin >> this->mes;
}
void Data::setAno() {
    cout << "Ano: ";
    cin >> this->ano;
}

//Setters com parâmetros
void Data::setDia(int x) {
    this->dia = x;
}
void Data::setMes(int y) {
    this->mes = y;
}
void Data::setAno(int z) {
    this->ano = z;
}

// Getters
int Data::getDia() const {
    return dia;
}

int Data::getMes() const {
    return mes;
}

int Data::getAno() const {
    return ano;
}

int Data::validaData() {
    /*
     *  Ano Bissexto -> É divisível por 400 ou não é divisível por 100 e é divisível por 4
     */
    if ( ((dia >= 1) && (dia <= 31)) && ((mes == 1) || (mes==3) || (mes==5) || (mes==7) || (mes==8) || (mes==10) || (mes==12)) ) {
        return 1;
    }
    else if ( ((dia >= 1) && (dia <= 30)) && ((mes == 4) || (mes==6) || (mes==9) || (mes==11)) ) {
        return 1;
    }
    else if ( ((dia >= 1) && (dia <= 28)) && (mes == 2) ) {
        return 1;
    }
    else if ( (dia == 29) && (mes == 2) && ( (ano % 400 == 0) || ( (ano % 4 == 0) && (ano % 100 !=0) ) ) ) {
        return 1;
    }
    else {
        cout << "Data invalida! Digite novamente!\n";
        this->dia = 0;
        this->mes = 0;
        this->ano = 0;
        return 0;
    }
}
