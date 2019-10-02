#include <iostream>
#include <sstream>

#include "Cliente.h"
#include "ContaCorrente.h"
#include "Lancamento.h"

using namespace std;

// Funções
void menuPrincipal(ContaCorrente * cadastroContas, Cliente * cadastroClientes, Lancamento * historicoLancamentos);
void menuCliente(ContaCorrente * cadastroContas, Cliente * cadastroClientes, Lancamento * historicoLancamentos);
void menuConta(ContaCorrente * cadastroContas, Cliente * cadastroClientes, Lancamento * historicoLancamentos);
void menuBanco(ContaCorrente * cadastroContas, Cliente * cadastroClientes, Lancamento * historicoLancamentos);
void menuLancamento(ContaCorrente * cadastroContas, Cliente * cadastroClientes, Lancamento * historicoLancamentos);
int lancamento(int numConta, int operacao, float valor, Data dataLancamento, ContaCorrente * cadastroContas);
int cadastrarCliente();
int excluirCliente();
int criarConta();
int excluirConta();
int getQuantidadeDeContas();
int getQuantidadeDeClientes();
float getMontanteTotal(ContaCorrente * cadastroContas);

int numContasCadastradas = 0;
int numClientesCadastrados = 0;
int numLancamentosEfetuados = 0;

int main() {
    ContaCorrente * cadastroContas;
    cadastroContas = (ContaCorrente*) malloc(10 * sizeof(ContaCorrente));

    Cliente * cadastroClientes;
    cadastroClientes = (Cliente*) malloc(10 * sizeof(Cliente));

    Lancamento * historicoLancamentos;
    historicoLancamentos = (Lancamento*) malloc(10 * sizeof(Lancamento));


    Data data;
    data.dia = 12;
    data.mes = 7;
    data.ano = 2019;


    ContaCorrente conta1;
    conta1.setConta(147, data, "44175184830", 147.02);
    cadastroContas[0] = conta1;
    numContasCadastradas += 1;

    menuPrincipal(cadastroContas, cadastroClientes, historicoLancamentos);

    return 0;
}

void menuPrincipal(ContaCorrente * cadastroContas, Cliente * cadastroClientes, Lancamento * historicoLancamentos){

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
            menuCliente(cadastroContas, cadastroClientes, historicoLancamentos);
            break;
        }
        case 2: {
            menuConta(cadastroContas, cadastroClientes, historicoLancamentos);
            break;
        }
        case 3: {
            menuBanco(cadastroContas, cadastroClientes, historicoLancamentos);
            break;
        }
        case 4: {
            exit(1);
        }
        default:
            break;
    }
}

void menuCliente(ContaCorrente * cadastroContas, Cliente * cadastroClientes, Lancamento * historicoLancamentos){
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
            menuPrincipal(cadastroContas, cadastroClientes, historicoLancamentos);
            break;
        }
        case 1:{
            Cliente people1;
            cout << "\n" << people1.printCliente();
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

void menuConta(ContaCorrente * cadastroContas, Cliente * cadastroClientes, Lancamento * historicoLancamentos){
    int option;
    cout << endl << "--- MENU CONTAS ---" << endl
    << "0 - Menu anterior" << endl
    << "1 - Abrir uma nova conta" << endl
    << "2 - Alterar dados de uma conta" << endl
    << "3 - Excluir uma conta" << endl
    << "4 - Sair" << endl;

    cin >> option;
    while(option<0 || option>4){
        cout << "Selecione uma opção válida" << endl;
        cin >> option;
    }

    switch(option){
        case 0:{
            menuPrincipal(cadastroContas, cadastroClientes, historicoLancamentos);
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

void menuBanco(ContaCorrente * cadastroContas, Cliente * cadastroClientes, Lancamento * historicoLancamentos){
    int option;
    cout << endl << "--- GERENCIAMENTO DO BANCO ---" << endl
    << "0 - Menu anterior" << endl
    << "1 - Realizar lançamento em conta" << endl
    << "2 - Exibir número total de contas" << endl
    << "3 - Exibir número total de clientes cadastrados" << endl
    << "4 - Exibir montante total presente no banco" << endl
    << "5 - Exibir extrato de uma conta" << endl
    << "6 - Sair" << endl;

    cin >> option;
    while(option<0 || option>6){
        cout << "Selecione uma opção válida" << endl;
        cin >> option;
    }

    switch(option){
        case 0:{
            menuPrincipal(cadastroContas, cadastroClientes, historicoLancamentos);
            break;
        }
        case 1:{
            menuLancamento(cadastroContas, cadastroClientes, historicoLancamentos);
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
            //
            break;
        }
        case 6:{
            exit(1);
        }
        default:
            break;
    }
}

void menuLancamento(ContaCorrente * cadastroContas, Cliente * cadastroClientes, Lancamento * historicoLancamentos) {
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
    while (option<0 || option>3) {
        cout << "Selecione uma opção válida" << endl;
        cin >> option;
    }

    switch (option) {
        case 0: {
            menuBanco(cadastroContas, cadastroClientes, historicoLancamentos);
            break;
        }
        case 1: {
            operacao = 1;

            cout << "Insira o numero da conta: ";
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
                case 0: {
                    Lancamento *lancamento = (Lancamento *) malloc(sizeof(Lancamento));
                    lancamento->setLancamento(numConta, operacao, valorLancamento, dataLancamento);
                    historicoLancamentos[numLancamentosEfetuados] = *lancamento;
                    numLancamentosEfetuados += 1;

                    cout << endl << "Lançamento realizado com sucesso!" << endl;
                    cout << "Você será redirecionado para o menu de lançamentos" << endl;
                    menuLancamento(cadastroContas, cadastroClientes, historicoLancamentos);
                    break;
                }
                case 1: {
                    cout << endl << "ERRO! Não há nenhuma conta correspondente com o número inserido" << endl;
                    cout << "Você será redirecionado para o menu de lançamentos" << endl;
                    menuLancamento(cadastroContas, cadastroClientes, historicoLancamentos);
                    break;
                }
                case 2: {
                    cout << endl << "ERRO! A conta não tem saldo suficiente para o débito" << endl;
                    cout << "Você será redirecionado para o menu de lançamentos" << endl;
                    menuLancamento(cadastroContas, cadastroClientes, historicoLancamentos);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case 2: {
            operacao = 2;

            cout << "Insira o numero da conta: ";
            cin >> numConta;

            cout << "Insira o valor a ser depositado: ";
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
                case 0: {
                    Lancamento *lancamento = (Lancamento *) malloc(sizeof(Lancamento));
                    lancamento->setLancamento(numConta, operacao, valorLancamento, dataLancamento);
                    historicoLancamentos[numLancamentosEfetuados] = *lancamento;
                    numLancamentosEfetuados += 1;

                    cout << endl << "Lançamento realizado com sucesso!" << endl;
                    cout << "Você será redirecionado para o menu de lançamentos" << endl;
                    menuLancamento(cadastroContas, cadastroClientes, historicoLancamentos);
                    break;
                }
                case 1: {
                    cout << endl << "ERRO! Não há nenhuma conta correspondente com o número inserido" << endl;
                    cout << "Você será redirecionado para o menu de lançamentos" << endl;
                    menuLancamento(cadastroContas, cadastroClientes, historicoLancamentos);
                    break;
                }
                default:
                    break;
            }
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
    int i=0;
    int cont=0;
    float novoValor=0;

    do{
        if(numConta == cadastroContas[i].getNumConta())
            cont += 1;

        i += 1;
    }while(i<numContasCadastradas);

    //Subtrai 1 do i para voltar para a posição da conta desejada no vetor
    i -= 1;

    //Não existe esse numero de conta
    if(cont == 0)
        return 1;

    //Operação 1 = Débito
    //Operação 2 = Crédito
    if(operacao == 1){
        if((cadastroContas[i].getSaldoAtual() - valor) < 0)
            return 2;
        else {
            novoValor = cadastroContas[i].getSaldoAtual() - valor;
            cadastroContas[i].setSaldoAtual(novoValor);
            return 0;
        }
    }
    else{
        novoValor = cadastroContas[i].getSaldoAtual() + valor;
        cadastroContas[i].setSaldoAtual(novoValor);
        return 0;
    }
}

int getQuantidadeDeContas(){
    return numContasCadastradas;
}

int getQuantidadeDeClientes(){
    return numClientesCadastrados;
}

float getMontanteTotal(ContaCorrente * cadastroContas){
    int i;
    float montanteTotal=0;

    for(i=0; i<numContasCadastradas; i++)
        montanteTotal = cadastroContas[i].getSaldoAtual() + montanteTotal;

    return montanteTotal;
}