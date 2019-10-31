//
// Created by felipe on 20/09/2019.
//

#include  <iostream>
#include "Data.h"
using namespace std;

// Construtor
Data::Data() {
    valido = 0;
    while (!valido) {
        setDia();
        setMes();
        setAno();
        validaData();
    }
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
    cin >> dia;
}

void Data::setMes() {
    cout << "Mes: ";
    cin >> mes;
}

void Data::setAno() {
    cout << "Ano: ";
    cin >> ano;
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

void Data::validaData() {
    /*
     *  Ano Bissexto -> É divisível por 400 ou não é divisível por 100 e é divisível por 4
     */

    while (!valido) {

        if ( dia >= 1) {
            if (dia <= 28) {
                if ( (mes==2) && ( (ano % 400 == 0) || ( (ano % 4 == 0) && (ano % 100 !=0) ) ) ) {
                    valido = 1;
                }
            }
            if (dia == 29) {
                if ( (mes ==2) && ( (ano % 400 == 0) || ( (ano % 4 == 0) && (ano % 100 !=0) ) ) ) {
                    valido = 1;
                } 
            }
            else if ( (mes == 2) && (dia <=28) ) {
                valido = 1;
            }
            if (dia <= 30) {
                if ( (mes == 4) || (mes==6) || (mes==9) || (mes==11) ) {
                    valido = 1;
                }
            }
            if (dia <= 31) {
                if ( (mes == 1) || (mes==3) || (mes==5) || (mes==7) || (mes==8) || (mes==10) || (mes==12) ) {
                    valido = 1;
                }
            }
        }

    }
}