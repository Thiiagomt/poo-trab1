#include <iostream>
#include <sstream>
// N° de contas nunca será superior ao de clientes
#define N_CLIENTES_CONTAS 20

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
int getQuantidadeDeContas();
int getQuantidadeDeClientes();
float getMontanteTotal(ContaCorrente * cadastroContas);

int numContasCadastradas = 0;
int numClientesCadastrados = 0;
int numLancamentosEfetuados = 0;
Cliente *id_Cliente[N_CLIENTES_CONTAS];
ContaCorrente *id_ContaCorrente[N_CLIENTES_CONTAS];

int main() {
    ContaCorrente * cadastroContas;
    cadastroContas = (ContaCorrente*) malloc(10 * sizeof(ContaCorrente));

    Cliente * cadastroClientes;
    cadastroClientes = (Cliente*) malloc(10 * sizeof(Cliente));

    Lancamento * historicoLancamentos;
    historicoLancamentos = (Lancamento*) malloc(10 * sizeof(Lancamento));

    /*
    Data data;
    data.dia = 12;
    data.mes = 7;
    data.ano = 2019;


    ContaCorrente conta1;
    conta1.setConta(147, data, "44175184830", 147.02);
    cadastroContas[0] = conta1;
    numContasCadastradas += 1;
    */

    menuPrincipal(cadastroContas, cadastroClientes, historicoLancamentos);

    return 0;
}

void menuPrincipal(ContaCorrente * cadastroContas, Cliente * cadastroClientes, Lancamento * historicoLancamentos){

    int option = -1;

    while (option != 0) {

        cout << endl << "--- BEM VINDO AO SISTEMA DO BANCO ---" << endl
             << "ESCOLHA O MENU QUE DESEJAR" << endl
             << "0 - SAIR" << endl
             << "1 - MENU CLIENTES" << endl
             << "2 - MENU CONTAS" << endl
             << "3 - GERENCIAMENTO DO BANCO" << endl;

        cin >> option;
        if(option<0 || option>4)
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
            default:
                break;
        }

    }
}

void menuCliente(ContaCorrente * cadastroContas, Cliente * cadastroClientes, Lancamento * historicoLancamentos){
    int option;
    cout << endl << "--- MENU CLIENTES ---" << endl
    << "0 - Menu anterior" << endl
    << "1 - Efetuar um novo cadastro" << endl
    << "2 - Alterar um cadastro existente" << endl
    << "3 - Excluir um cadastro" << endl
    << "4 - Ver Clientes" << endl
    << "5 - Sair" << endl;

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
            // Cadastra-se um cliente em ordem
            id_Cliente[numClientesCadastrados] = new Cliente;
            numClientesCadastrados++;
            break;
        }
        case 2:{
            string aux;
            int i=0, quebra=0;
            int altera_opcao;
            // Busca de cliente por CPF
            // Após a inserção do cpf, o laço for verifica os multiplos perfis, localizando o do cliente e modificando o dado apontado
            cout << "Digite seu cpf: ";
            cin.ignore();
            getline(cin, aux);
            do {
                if (aux == (id_Cliente[i]->getCPF())) {
                    cout << "Qual alteração deseja realizar?\n1 - Telefone\n2 - Endereco\n3 - Email\n4 - Nome\n5 - CPF\nOpcao: ";
                    cin >> altera_opcao;
                    if (altera_opcao == 1) {
                        cin.ignore();
                        id_Cliente[i]->setTelefone();
                    } else if (altera_opcao == 2) {
                        cin.ignore();
                        id_Cliente[i]->setEndereco();
                    } else if (altera_opcao == 3) {
                        cin.ignore();
                        id_Cliente[i]->setEmail();
                    } else if (altera_opcao == 4) {
                        id_Cliente[i]->setNome();
                    } else if (altera_opcao == 5) {
                        cin.ignore();
                        id_Cliente[i]->setCPF();
                        id_ContaCorrente[i]->setCPFCliente(*id_Cliente[i]);
                    }
                    quebra = 1;
                } 
                i++;
            } while ((i < numClientesCadastrados) && !quebra);

            if (quebra == 0)
                cout << "Nenhum cliente encontrado!";

            break;
        }
        case 3:{
            int i=0, quebra=0;
            string aux, cpf_conta;
            cout << "Digite seu cpf: ";
            cin.ignore();
            getline(cin, aux);
            do {
                // Busca de clientes por cpf, deletando-o quando achar junto com sua respectiva conta corrente (se houver)
                // É ajustado também a alocação
                if (aux == (id_Cliente[i]->getCPF())) {
                    if (id_Cliente[i]->getContaAtiva() == 1) {
                        cpf_conta = id_Cliente[i]->getCPF();
                        for (int f=0; f<numContasCadastradas; f++) {
                            if (cpf_conta == (id_ContaCorrente[f]->getCPFCliente())) {
                                delete id_ContaCorrente[f];
                                numContasCadastradas--;
                                for (int k=f; k<numClientesCadastrados; k++) {
                                    id_ContaCorrente[k] = id_ContaCorrente[k+1];
                                }
                            }
                        }
                    }
                    delete id_Cliente[i];
                    numClientesCadastrados--;
                    for (int j=i; j<numClientesCadastrados; j++) {
                        id_Cliente[j] = id_Cliente[j+1];
                    }
                    quebra = 1;
                }
                i++;
            } while ((i < numClientesCadastrados) && !quebra);

            if (quebra == 0) {
                cout << "Cliente não encontrado!";
            }
            break;
        }
        case 4:{
            /*Cadastro de todos os clientes*/
            for (int i=0; i<numClientesCadastrados; i++)
                cout << id_Cliente[i]->printCliente();
            break;
        }
        case 5:{
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
    << "4 - Ver Contas Criadas" << endl
    << "5 - Sair" << endl;

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
            // Busca o cliente peo seu cpf, para verificar se já há um cadastro
            // assim, cria a contaa ou avisa se o cliente não foi encontrado
            int quebra=0, i=0;
            string aux;
            cout << "Digite seu cpf: ";
            cin.ignore();
            getline(cin, aux);
            do {
                if (aux == (id_Cliente[i]->getCPF())) {
                    if (id_Cliente[i]->getContaAtiva() == 1) {
                        cout << "Cliente já possui uma conta\n";
                        quebra = 1;
                    } else {
                        id_ContaCorrente[numContasCadastradas] = new ContaCorrente(*id_Cliente[i]);
                        cout << id_ContaCorrente[numContasCadastradas]->printConta();
                        numContasCadastradas++;
                        id_Cliente[i]->setContaAtiva(1);
                        cout << "\nConta Criada Com Sucesso!\n";
                        quebra = 1;
                    }
                }
                i++;
            } while ((i < numClientesCadastrados) && !quebra);

            if (quebra == 0)
                cout << "Nenhum cliente encontrado!\nFavor cadastrar-se\n";

            break;
        }
        case 2:{
            int i=0, quebra=0, aux;
            int altera_opcao;
            cout << "Digite o numero da conta: ";
            cin >> aux;
            do {
                if (aux == (id_ContaCorrente[i]->getNumConta())) {
                    cout << "Qual alteração deseja realizar?\n1 - Alterar numero da conta(geracao aleatoria)\n2 - Data de Abertura\n3 - CPF\nOpcao: ";
                    cin >> altera_opcao;
                    if (altera_opcao == 1) {
                        id_ContaCorrente[i]->setNumConta();
                    } else if (altera_opcao == 2) {
                        id_ContaCorrente[i]->setDataAbertura();
                    } else if (altera_opcao == 3) {
                        id_Cliente[i]->setCPF();
                        id_ContaCorrente[i]->setCPFCliente(*id_Cliente[i]);
                    }
                    quebra = 1;
                } 
                i++;
            } while ((i < numContasCadastradas) && !quebra);

            if (quebra == 0)
                cout << "Nenhum cliente encontrado!";
            break;
        }
        case 3:{
            int aux, i=0, quebra=0;
            cout << "Digite o numero da conta: ";
            cin >> aux;
            do {
                if (aux == (id_ContaCorrente[i]->getNumConta())) {
                    delete id_ContaCorrente[i];
                    numClientesCadastrados--;
                    for (int j=i; j<numClientesCadastrados; j++) {
                        id_Cliente[j] = id_Cliente[j+1];
                    }
                    quebra = 1;
                }
                i++;
            } while ((i < numContasCadastradas) && !quebra);

            if (quebra == 0) {
                cout << "Cliente não encontrado!";
            }
            break;
        }
        case 4:{
            for (int i=0; i<numContasCadastradas; i++)
                cout << id_ContaCorrente[i]->printConta();
            break;
        }
        case 5:{
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
    << "5 - Exibir histórico de lançamentos de uma conta" << endl
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
            cout << "Total de contas cadastradas no banco: " + to_string(getQuantidadeDeContas()) << endl;
            cout << "Você será redirecionado para o menu de gerenciamento do banco" << endl;
            menuBanco(cadastroContas, cadastroClientes, historicoLancamentos);
            break;
        }
        case 3:{
            cout << "Total de cliente cadastrados no banco: " + to_string(getQuantidadeDeClientes()) << endl;
            cout << "Você será redirecionado para o menu de gerenciamento do banco" << endl;
            menuBanco(cadastroContas, cadastroClientes, historicoLancamentos);
            break;
        }
        case 4:{
            cout << "Montante total presente no bando: R$" + to_string(getMontanteTotal(cadastroContas)) << endl;
            cout << "Você será redirecionado para o menu de gerenciamento do banco" << endl;
            menuBanco(cadastroContas, cadastroClientes, historicoLancamentos);
            break;
        }
        case 5:{
            int numConta, lancamentosExibidos;
            lancamentosExibidos=0;

            cout << "Insira o número da conta desejada: ";
            cin >> numConta;

            for(int i=0; i<numLancamentosEfetuados; i++){
                if(historicoLancamentos[i].getNumConta() == numConta) {
                    historicoLancamentos[i].printLancamento();
                    lancamentosExibidos++;
                }
            }

            if(lancamentosExibidos==0)
                cout << "Não há lançamentos para essa conta ainda!";

            cout << "Você será redirecionado para o menu de gerenciamento do banco" << endl;
            menuBanco(cadastroContas, cadastroClientes, historicoLancamentos);
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
                    Lancamento *lancamento = (Lancamento*) malloc(sizeof(Lancamento));
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
                    Lancamento *lancamento = (Lancamento*) malloc(sizeof(Lancamento));
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