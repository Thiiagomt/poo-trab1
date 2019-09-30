#include <iostream>
 a 
#include "Cliente.h"
#include "ContaCorrente.h"

using namespace std;

// Funções
void menuPrincipal(ContaCorrente * cadastroContas, Cliente * cadastroClientes);
void menuCliente(ContaCorrente * cadastroContas, Cliente * cadastroClientes);
void menuConta(ContaCorrente * cadastroContas, Cliente * cadastroClientes);
void menuBanco(ContaCorrente * cadastroContas, Cliente * cadastroClientes);
void menuLancamento(ContaCorrente * cadastroContas, Cliente * cadastroClientes);
int lancamento(int numConta, int operacao, float valor, Data dataLancamento, ContaCorrente * cadastroContas);
int cadastrarCliente();
int excluirCliente();
int criarConta();
int excluirConta();
int getQuantidadeDeContas();
int getQuantidadeDeClientes(); 
float getMontanteTotal();

int numContasCadastradas = 0;
int numClientesCadastrados = 0;

int main() {
    ContaCorrente * cadastroContas;
    cadastroContas = (ContaCorrente*) malloc(10 * sizeof(ContaCorrente));

    Cliente * cadastroClientes;
    cadastroClientes = (Cliente*) malloc(10 * sizeof(Cliente));


    Data data;
    data.dia = 12;
    data.mes = 7;
    data.ano = 2019;

    ContaCorrente conta1;
    conta1.setConta(147, data, "44175184830", 147.02);
    cadastroContas[0] = conta1;


    menuPrincipal(cadastroContas, cadastroClientes);

    return 0;
}

void menuPrincipal(ContaCorrente * cadastroContas, Cliente * cadastroClientes){

    int option;
    cout << endl << "--- BEM VINDO AO SISTEMA DO BANCO ---" << endl
         << "ESCOLHA O MENU QUE DESEJAR" << endl
         << "1 - MENU CLIENTES" << endl
         << "2 - MENU CONTAS" << endl
         << "3 - GERENCIAMENTO DO BANCO" << endl
         << "4 - SAIR" << endl;

    cin >> option;
    if(option<1 || option>4)
        while(option<1 || option>3){
            cout << "Selecione uma opção válida" << endl;
            cin >> option;
        }

    switch(option){
        case 1: {
            menuCliente(cadastroContas, cadastroClientes);
            break;
        }
        case 2: {
            menuConta(cadastroContas, cadastroClientes);
            break;
        }
        case 3: {
            menuBanco(cadastroContas, cadastroClientes);
            break;
        }
        case 4: {
            exit(1);
        }
        default:
            break;
    }
}

void menuCliente(ContaCorrente * cadastroContas, Cliente * cadastroClientes){
    int option;
    cout << endl << "--- MENU CLIENTES ---" << endl
    << "0 - Menu anterior" << endl
    << "1 - Efetuar um novo cadastro" << endl
    << "2 - Alterar um cadastro existente" << endl
    << "3 - Excluir um cadastro" << endl
    << "4 - Sair" << endl;

    cin >> option;
    while(option<0 || option>4){
        cout << "Selecione uma opção válida" << endl;
        cin >> option;
    }

    switch(option){
        case 0:{
            menuPrincipal(cadastroContas, cadastroClientes);
            break;
        }
        case 1:{
            //
            break;
        }
        case 2:{
            //
            break;
        }
        case 3:{
            //
            break;
        }
        case 4:{
            exit(1);
        }
        default:
            break;
    }
}

void menuConta(ContaCorrente * cadastroContas, Cliente * cadastroClientes){
    int option;
    cout << endl << "--- MENU CONTAS ---" << endl
    << "0 - Menu anterior" << endl
    << "1 - Abrir uma nova conta" << endl
    << "2 - Alterar dados de uma conta" << endl
    << "3 - Excluir uma conta" << endl
    << "4 - Extrato de uma conta" << endl
    << "5 - Sair" << endl;

    cin >> option;
    while(option<0 || option>5){
        cout << "Selecione uma opção válida" << endl;
        cin >> option;
    }

    switch(option){
        case 0:{
            menuPrincipal(cadastroContas, cadastroClientes);
            break;
        }
        case 1:{
            //
            break;
        }
        case 2:{
            //
            break;
        }
        case 3:{
            //
            break;
        }
        case 4:{
            //
            break;
        }
        case 5:{
            exit(1);
        }
        default:
            break;
    }
}

void menuBanco(ContaCorrente * cadastroContas, Cliente * cadastroClientes){
    int option;
    cout << endl << "--- GERENCIAMENTO DO BANCO ---" << endl
    << "0 - Menu anterior" << endl
    << "1 - Realizar lançamento em conta" << endl
    << "2 - Exibir número total de contas" << endl
    << "3 - Exibir número total de clientes cadastrados" << endl
    << "4 - Exibir montante total presente no banco" << endl
    << "5 - Sair" << endl;

    cin >> option;
    while(option<0 || option>6){
        cout << "Selecione uma opção válida" << endl;
        cin >> option;
    }

    switch(option){
        case 0:{
            menuPrincipal(cadastroContas, cadastroClientes);
            break;
        }
        case 1:{
            menuLancamento(cadastroContas, cadastroClientes);
            break;
        }
        case 2:{
            //
            break;
        }
        case 3:{
            //
            break;
        }
        case 4:{
            //
            break;
        }
        case 5:{
            exit(1);
        }
        default:
            break;
    }
}

void menuLancamento(ContaCorrente * cadastroContas, Cliente * cadastroClientes) {
    int comando;
    int numConta;
    int operacao = 0;
    float valorLancamento;
    Data dataLancamento;
    int option;
    cout << endl << "--- LANÇAMENTOS ---" << endl
         << "0 - Menu anterior" << endl
         << "1 - Efetuar débito em conta" << endl
         << "2 - Efetuar crédito em conta" << endl
         << "3 - SAIR" << endl;

    cin >> option;
    while (option<0 || option>6) {
        cout << "Selecione uma opção válida" << endl;
        cin >> option;
    }

    switch (option) {
        case 0: {
            menuBanco(cadastroContas, cadastroClientes);
            break;
        }
        case 1: {
            operacao = 1;

            cout << endl << "Insira o numero da conta: ";
            cin >> numConta;

            cout << "Insira o valor a ser debitado: ";
            cin >> valorLancamento;

            cout << "Para controle insira a data do lancamento na seguinte ordem";
            cout << endl << "Ano: ";
            cin >> dataLancamento.ano;
            while (dataLancamento.ano != 2019) {
                cout << "O ano digitado é invalido! Tente novamente" << endl;
                cout << "Ano: ";
                cin >> dataLancamento.ano;
            }
            cout << "Mes: ";
            cin >> dataLancamento.mes;
            while (dataLancamento.mes<1 || dataLancamento.mes>12) {
                cout << "O mes digitado é invalido! Tente novamente" << endl;
                cout << "Mes: ";
                cin >> dataLancamento.mes;
            }
            cout << "Dia: ";
            cin >> dataLancamento.dia;
            if (dataLancamento.mes == 2){
                if (dataLancamento.dia<1 || dataLancamento.dia>28)
                    while (dataLancamento.dia<1 || dataLancamento.dia>28) {
                        cout << "O dia digitado é invalido! Tente novamente" << endl;
                        cout << "Dia: ";
                        cin >> dataLancamento.dia;
                    }
            }
            else {
                if (dataLancamento.dia<1 || dataLancamento.dia>31)
                    while (dataLancamento.dia<1 || dataLancamento.dia>31) {
                        cout << "O dia digitado é invalido! Tente noamente" << endl;
                        cout << "Dia: ";
                        cin >> dataLancamento.dia;
                    }
            }

            comando = lancamento(numConta, operacao, valorLancamento, dataLancamento, cadastroContas);
            switch(comando){
                case 0:
                    break;
                case 1:
                    break;
                case 2:
                    break;
                default:
                    break;
            }


            break;
        }
        case 2: {
            //
            break;
        }
        case 3: {
            exit(1);
        }
        default:
            break;
    }
}

int lancamento(int numConta, int operacao, float valor, Data data, ContaCorrente * cadastroContas){
    int i;
    int cont=0;

    for(i=0; i<numContasCadastradas; i++)
        if(numConta == cadastroContas[i].getNumConta())
            cont += 1;

    //Não existe esse numero de conta
    if(cont == 0)
        return 1;

    //Operação 1 = Débito
    //Operação 2 = Crédito
    if(operacao == 1){

    }
    else if(operacao == 2){

    }
}
