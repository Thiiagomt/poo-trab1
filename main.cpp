/*
Trabalho 1 de Programação Orientada a Objetos - Sistema de Gerenciamento de Banco
Felipe Tavoni                       RA:758707
Guilherme Lorençato G Lamonato      RA:758665
Nathaelly Boni                      RA:758963
Thiago de Moraes Teixeira           RA:760667
Clara Gruber                        RA:
*/
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
// N° de contas nunca será superior ao de clientes
#define N_CLIENTES_CONTAS 20

#include "PessoaFisica.h"
#include "PessoaJuridica.h"
#include "ContaPoupanca.h"
#include "ContaCorrente.h"
#include "Lancamento.h"
#include "Data.h"

using namespace std;
// A variável "quebra" pode ser encontrada em multiplas funções. Ela é similar ao comportamento
// do "break", pois irá interromper o while quando tal objetivo for cumprido.

//Função para transformar float em string com 2 casas decimais
std::string to_string_with_precision(const float valor, const int num_casas){
    std::ostringstream out;
    out.precision(num_casas);
    out << std::fixed << valor;
    return out.str();
}

// Funções
void menuPrincipal();
void menuCliente();
void menuClienteJuridico();
void menuClienteFisico();
void menuConta();
void menuContaPoupanca();
void menuContaCorrente();
void menuBanco();
void menuLancamento();
int lancamento(int numConta, int operacao, float valor, float * saldoAnterior, float * saldoAtualizado);
int getQuantidadeDeContas();
int getQuantidadeDeClientes();
float getMontanteTotal();

int numContasPoupanca = 0;
int numContasCorrente = 0;
int numClientesFisicos = 0;
int numClientesJuridicos = 0;
int numLancamentosEfetuados = 0;

// Esse contador sempre sera incrementado, determinando o numero da conta (nunca será repetido)
int numProxConta = 1;

PessoaFisica * id_ClienteFisico[N_CLIENTES_CONTAS];
PessoaJuridica * id_ClienteJuridico[N_CLIENTES_CONTAS];
ContaPoupanca * id_ContaPoupanca[N_CLIENTES_CONTAS];
ContaCorrente * id_ContaCorrente[N_CLIENTES_CONTAS];
Lancamento * id_Lancamentos[N_CLIENTES_CONTAS];

int main() {

    menuPrincipal();

    return 0;
}

void menuPrincipal(){

    int option = -1;

    while (option != 0) {

        cout << endl << "--- BEM VINDO AO SISTEMA DO BANCO ---" << endl
             << "ESCOLHA O MENU QUE DESEJAR" << endl
             << "0 - SAIR" << endl
             << "1 - MENU CLIENTES" << endl
             << "2 - MENU CONTAS" << endl
             << "3 - GERENCIAMENTO DO BANCO" << endl;

        cin >> option;
        if(option<0 || option>3)
            while(option<1 || option>3){
                cout << "Selecione uma opção válida" << endl;
                cin >> option;
            }

        switch(option){
            case 0:{
                exit(1);
            }
            case 1: {
                menuCliente();
                break;
            }
            case 2: {
                menuConta();
                break;
            }
            case 3: {
                menuBanco();
                break;
            }
            default:
                break;
        }

    }
}

void menuCliente(){
    int option;
    cout << endl << "--- MENU CLIENTES ---" << endl
    << "0 - Menu anterior" << endl
    << "1 - Menu Pessoa Jurídica" << endl
    << "2 - Menu Pessoa Física" << endl
    << "3 - Sair" << endl;

    cin >> option;
    while(option<0 || option>3){
        cout << "Selecione uma opção válida" << endl;
        cin >> option;
    }

    switch(option){
        case 0:{
            menuPrincipal();
            break;
        }
        case 1:{
            menuClienteJuridico();
            break;
        }
        case 2:{
            menuClienteFisico();
            break;
        }
        case 3:{
            exit(1);
        }
        default:
            break;
    }
}

void menuClienteJuridico(){
    int option;
    cout << endl << "--- MENU PESSOA JURÍDICA ---" << endl
    << "0 - Menu anterior" << endl
    << "1 - Efetuar um novo cadastro" << endl
    << "2 - Alterar um cadastro existente" << endl
    << "3 - Excluir um cadastro" << endl
    << "4 - Ver Clientes Pessoa Jurídica" << endl
    << "5 - Sair" << endl;

    cin >> option;
    while(option<0 || option>5){
        cout << "Selecione uma opção válida" << endl;
        cin >> option;
    }

    switch(option){
        case 0:{
            menuCliente();
            break;
        }
        case 1:{
            if(numClientesFisicos == 0){
                cout << "Não há pessoas físicas cadastradas, para ser o proprietario majoritario" << endl
                << "Por favor, faça o cadastro de uma pessoa física primeiro" << endl;
                break;
            }
            int quebra=0, i=0, quebra2=0, j=0;
            // Cadastra-se um cliente em ordem
            id_ClienteJuridico[numClientesJuridicos] = new PessoaJuridica;
            numClientesJuridicos++;
            // Cria o cliente e verifica se tal já existe por meio do CNPJ.
            // Se já existir (CNPJ já usado), então é deletado o objeto criado
            while ((i<(numClientesJuridicos - 1)) && !quebra ) {
                if (id_ClienteJuridico[numClientesJuridicos-1]->getCNPJ() == id_ClienteJuridico[i]->getCNPJ()) {
                    quebra = 1;
                    cout << "\nCliente com CNPJ já existente!\n";
                    delete id_ClienteJuridico[numClientesJuridicos-1];
                    numClientesJuridicos--;
                }
                i++;
            }
            //Se o proprietário majoritário não estiver cadastrado em pessoa física, então é deletado o objeto criado
            if(numClientesFisicos == 1){
                if(id_ClienteJuridico[numClientesJuridicos-1]->getCPFProprietarioMajor() == id_ClienteFisico[0]->getCPF())
                    quebra2 = 1;
            }
            else{
                while(j<(numClientesFisicos-1 && !quebra2)){
                    //if se achar o CPF do proprietario majoritario cadastrado em pessoas fisicas
                    if(id_ClienteJuridico[numClientesJuridicos-1]->getCPFProprietarioMajor() == id_ClienteFisico[0]->getCPF())
                        quebra2 = 1;
                    j++;
                }
            }
            //verifica se o while anterior não achar o cpf do proprietario majoritario cadastrado em pessoas fisicas e deleta o objeto criado
            if(quebra2 == 0){
                cout << "\nO proprietario majoritario não está cadastrado em pessoas físicas\n";
                delete id_ClienteJuridico[numClientesJuridicos-1];
                numClientesJuridicos--;
            }

            cout << "\n\nPessoa Jurídica cadastrado com sucesso!\n" << endl;
            break;
        }
        case 2:{
            string aux;
            int i=0, quebra=0;
            int altera_opcao;
            // Busca de cliente por CNPJ
            // Após a inserção do CNPJ, o laço for verifica os multiplos perfis, localizando o do cliente e modificando o dado apontado
            cout << "Digite seu CNPJ: ";
            cin.ignore();
            getline(cin, aux);
            do {
                if (aux == (id_ClienteJuridico[i]->getCNPJ())) {
                    cout << "Qual alteração deseja realizar?\n1 - Razão Social\n2 - CNPJ\n3 - CPF do Proprietário Majoritário\n4 - Endereço\n5 - Telefone\n6 - Email\n7 - Ramo Atuação\n8- Data da última atualização do contrato social\nOpcao: ";
                    cin >> altera_opcao;
                    if (altera_opcao == 1) {
                        cin.ignore();
                        id_ClienteJuridico[i]->setNome();
                        cout << "Cadastro alterado com sucesso!\n";
                    } else if (altera_opcao == 2) {
                        if(id_ClienteJuridico[i]->getContaAtiva() == 0){
                            cin.ignore();
                            id_ClienteJuridico[i]->setCNPJ();
                            cout << "Cadastro alterado com sucesso!\n";
                        }
                        else{
                            cout << "Falha na alteração!\nExiste uma conta vinculada a este CNPJ no momento!\n";
                        }
                    } else if (altera_opcao == 3) {
                        cin.ignore();
                        id_ClienteJuridico[i]->setCPFProprietarioMajor();
                        cout << "Cadastro alterado com sucesso!\n";
                    } else if (altera_opcao == 4) {
                        cin.ignore();
                        id_ClienteJuridico[i]->setEndereco();
                        cout << "Cadastro alterado com sucesso!\n";
                    } else if (altera_opcao == 5) {
                        cin.ignore();
                        id_ClienteJuridico[i]->setTelefone();
                        cout << "Cadastro alterado com sucesso!\n";
                    } else if (altera_opcao == 6) {
                        cin.ignore();
                        id_ClienteJuridico[i]->setEmail();
                    } else if (altera_opcao == 7) {
                        cin.ignore();
                        id_ClienteJuridico[i]->setRamoAtuacao();
                    } else if (altera_opcao == 8) {
                        cin.ignore();
                        id_ClienteJuridico[i]->setDataUltimaAtt();
                    }
                    quebra = 1;
                }
                i++;
            } while ((i < numClientesJuridicos) && !quebra);

            if (quebra == 0)
                cout << "Nenhum cliente encontrado!";

            break;
        }
        case 3:{
            int i=0, quebra=0;
            string aux;
            cout << "Digite seu CNPJ: ";
            cin.ignore();
            getline(cin, aux);
            do {
                // Busca de cliente por meio do CNPJ
                // Se o cliente possuir uma conta ativa no momento, seu cadastro não poderá ser excluído
                if (aux == (id_ClienteJuridico[i]->getCNPJ())) {
                    if (id_ClienteJuridico[i]->getContaAtiva() == 1) {
                        cout << "Nao foi possivel deletar sua conta!\nVoce possui uma conta ativa no momento!\n";
                    } else {
                        delete id_ClienteJuridico[i];
                        numClientesJuridicos--;
                        for (int j=i; j<numClientesJuridicos; j++) {
                            id_ClienteJuridico[j] = id_ClienteJuridico[j+1];
                        }
                        quebra = 1;
                    }
                }
                i++;
            } while ((i < numClientesJuridicos) && !quebra);

            if (quebra == 0) {
                cout << "Cliente não encontrado!";
            }
            break;
        }
        case 4:{
            //Cadastro de todos os clientes
            for (int i=0; i<numClientesJuridicos; i++)
                cout << id_ClienteJuridico[i]->printPessoaJuridica();
            break;
        }
        case 5:{
            exit(1);
        }
        default:
            break;
    }
}

void menuClienteFisico(){
    int option;
    cout << endl << "--- MENU PESSOA FÍSICA ---" << endl
    << "0 - Menu anterior" << endl
    << "1 - Efetuar um novo cadastro" << endl
    << "2 - Alterar um cadastro existente" << endl
    << "3 - Excluir um cadastro" << endl
    << "4 - Ver Clientes Pessoa Física" << endl
    << "5 - Sair" << endl;

    cin >> option;
    while(option<0 || option>5){
        cout << "Selecione uma opção válida" << endl;
        cin >> option;
    }

    switch(option){
        case 0:{
            menuCliente();
            break;
        }
        case 1:{
            int quebra=0, i=0;
            // Cadastra-se um cliente em ordem
            id_ClienteFisico[numClientesFisicos] = new PessoaFisica;
            numClientesFisicos++;
            // Cria o cliente e verifica se tal já existe por meio  do CPF.
            // Se já existir (CPF já usado), então é deletado o objeto criado
            while ( (i<(numClientesFisicos - 1)) && !quebra ) {
                if (id_ClienteFisico[numClientesFisicos-1]->getCPF() == id_ClienteFisico[i]->getCPF()) {
                    quebra = 1;
                    cout << "\nCliente com CPF já existente!\n";
                    delete id_ClienteFisico[numClientesFisicos-1];
                    numClientesFisicos--;
                }
                i++;
            }
            cout << "\n\nPessoa Fisica cadastrado com sucesso!" << endl;
            break;
        }
        case 2:{
            string aux;
            int i=0, quebra=0;
            int altera_opcao;
            // Busca de cliente por CPF
            // Após a inserção do CPF, o laço for verifica os multiplos perfis, localizando o do cliente e modificando o dado apontado
            cout << "Digite seu CPF: ";
            cin.ignore();
            getline(cin, aux);
            do {
                if (aux == (id_ClienteFisico[i]->getCPF())) {
                    cout << "Qual alteração deseja realizar?\n1 - Nome\n2 - CPF\n3 - Endereco\n4 - Telefone\n5 - Email\nOpcao: ";
                    cin >> altera_opcao;
                    if (altera_opcao == 1) {
                        cin.ignore();
                        id_ClienteFisico[i]->setNome();
                        cout << "Cadastro alterado com sucesso!\n";
                    } else if (altera_opcao == 2) {
                        if(id_ClienteFisico[i]->getContaAtiva() == 0){
                            cin.ignore();
                            id_ClienteFisico[i]->setCPF();
                            cout << "Cadastro alterado com sucesso!\n";
                        }
                        else{
                            cout << "Falha na alteração!\nExiste uma conta vinculada a este CPF no momento!\n";
                        }
                    } else if (altera_opcao == 3) {
                        cin.ignore();
                        id_ClienteFisico[i]->setEndereco();
                        cout << "Cadastro alterado com sucesso!\n";
                    } else if (altera_opcao == 4) {
                        cin.ignore();
                        id_ClienteFisico[i]->setTelefone();
                        cout << "Cadastro alterado com sucesso!\n";
                    } else if (altera_opcao == 5) {
                        cin.ignore();
                        id_ClienteFisico[i]->setEmail();
                        cout << "Cadastro alterado com sucesso!\n";
                    }
                    quebra = 1;
                }
                i++;
            } while ((i < numClientesFisicos) && !quebra);

            if (quebra == 0)
                cout << "Nenhum cliente encontrado!";

            break;
        }
        case 3:{
            int i=0, quebra=0;
            string aux;
            cout << "Digite seu CPF: ";
            cin.ignore();
            getline(cin, aux);
            do {
                // Busca de cliente por meio do CPF
                // Se o cliente possuir uma conta ativa no momento, seu cadastro não poderá ser excluído
                if (aux == (id_ClienteFisico[i]->getCPF())) {
                    if (id_ClienteFisico[i]->getContaAtiva() == 1) {
                        cout << "Nao foi possivel deletar sua conta!\nVoce possui uma conta ativa no momento!\n";
                    } else {
                        delete id_ClienteFisico[i];
                        numClientesFisicos--;
                        for (int j=i; j<numClientesFisicos; j++) {
                            id_ClienteFisico[j] = id_ClienteFisico[j+1];
                        }
                        quebra = 1;
                    }
                }
                i++;
            } while ((i < numClientesFisicos) && !quebra);

            if (quebra == 0) {
                cout << "Cliente não encontrado!";
            }
            break;
        }
        case 4:{
            //Cadastro de todos os clientes
            for (int i=0; i<numClientesFisicos; i++)
                cout << id_ClienteFisico[i]->printPessoaFisica();
            break;
        }
        case 5:{
            exit(1);
        }
        default:
            break;
    }
}

void menuConta(){
    int option;
    cout << endl << "--- MENU CONTAS ---" << endl
    << "0 - Menu anterior" << endl
    << "1 - Menu Conta Poupanca" << endl
    << "2 - Menu Conta Corrente" << endl
    << "3 - Realizar lancamento em conta" << endl
    << "4 - Sair" << endl;

    cin >> option;
    while(option<0 || option>4){
        cout << "Selecione uma opção válida" << endl;
        cin >> option;
    }

    switch(option){
        case 0:{
            menuPrincipal();
            break;
        }
        case 1:{
            menuContaPoupanca();
            break;
        }
        case 2:{
            menuContaCorrente();
            break;
        }
        case 3:{
            menuLancamento();
        }
        case 4:{
            exit(1);
        }
        default:
            break;
    }
}

void menuContaPoupanca(){
    int option;
    cout << endl << "--- MENU CONTA POUPANCA ---" << endl
    << "0 - Menu anterior" << endl
    << "1 - Abrir uma nova conta poupanca" << endl
    << "2 - Alterar dados de uma conta poupanca" << endl
    << "3 - Excluir uma conta poupanca" << endl
    << "4 - Ver contas poupancas criadas" << endl
    << "5 - Sair" << endl;

    cin >> option;
    while(option<0 || option>5){
        cout << "Selecione uma opção válida" << endl;
        cin >> option;
    }

    switch(option){
        case 0:{
            menuPrincipal();
            break;
        }
        case 1:{
            // Verifica antes se há pelo menos 1 cliente para criação de conta
            if (numClientesFisicos != 0) {
                // Busca o cliente pelo seu cpf, para verificar se já há um cadastro
                // assim, cria a contaa ou avisa se o cliente não foi encontrado
                int quebra=0, i=0, k=0;
                string aux;
                cout << "Digite seu cpf: ";
                cin.ignore();
                getline(cin, aux);
                do {
                    // Dedica-se somente aos cliente fisicos (na especificação, apenas clientes fisicos podem possuir uma conta poupança)
                    if (aux == (id_ClienteFisico[i]->getCPF())) {
                        if (id_ClienteFisico[i]->getContaAtiva() == 1) {
                            cout << "Cliente já possui uma conta\n";
                            quebra = 1;
                        } else {
                            // Verificar se o numero da conta a ser criada pode ser usado
                            // Verificando nas contas poupacas
                            while (k < numContasPoupanca) {
                                if (id_ContaPoupanca[k]->getNumConta() == numProxConta) {
                                    numProxConta++;     // Incrementa para ser diferente
                                    k = -1;              // Reseta a verificação
                                }
                                k++;
                            }
                            k = 0;
                            // Verificando nas contas correntes
                            while (k < numContasCorrente) {
                                if (id_ContaCorrente[k]->getNumConta() == numProxConta) {
                                    numProxConta++;     // Incrementa para ser diferente
                                    k = -1;              // Reseta a verificação
                                }
                                k++;
                            }
                            id_ContaPoupanca[numContasPoupanca] = new ContaPoupanca(*id_ClienteFisico[i], numProxConta);
                            cout << id_ContaPoupanca[numContasPoupanca]->printConta();
                            numContasPoupanca++;
                            id_ClienteFisico[i]->setContaAtiva(1);
                            cout << "\nConta Criada Com Sucesso!\n";
                            quebra = 1;
                        }
                    }
                    i++;
                } while ((i < numClientesFisicos) && !quebra);

                if (quebra == 0){
                    cout << "Nenhum cliente encontrado!\nFavor cadastrar-se\n";
                }
            } else {
                cout << "\nNão ha clientes para criação de contas poupancas\n";
            }
            break;
        }
        case 2:{
            // Procura a conta pelo seu número. Quando achava, solicita ao usuário a mudança a ser feito
            int i=0, quebra=0, aux, novo_num=0, alterado=0, usado;
            int altera_opcao;
            cout << "Digite o numero da conta: ";
            cin >> aux;
            do {
                if (aux == (id_ContaPoupanca[i]->getNumConta())) {
                    cout << "Qual alteração deseja realizar em sua conta poupanca?\n1 - Alterar numero da conta\n2 - Data de Abertura\nOpcao: ";
                    cin >> altera_opcao;
                    if (altera_opcao == 1) {
                        do {
                            cout << "Digite o novo numero da conta: ";
                            cin >> novo_num;
                            int k=0;
                            // Verifica se o numero ja pertence a outra conta
                            usado = 0;
                            do {
                                if (id_ContaPoupanca[k]->getNumConta() == novo_num) {
                                    cout << "Digite novamente!\n";
                                    usado = 1;
                                }
                                k++;
                            } while (k < numContasPoupanca && !usado);
                            if (!usado) {
                                id_ContaPoupanca[i]->setNumConta(novo_num);
                                alterado = 1;
                            }
                        } while (!alterado);
                        cout << "\nConta alterada com sucesso!\n";
                        break;
                    } else if (altera_opcao == 2) {
                        id_ContaPoupanca[i]->setDataAbertura();
                        cout << "\nConta alterada com sucesso!\n";
                    }
                    quebra = 1;
                }
                i++;
            } while ((i < numContasPoupanca) && !quebra);

            if (quebra == 0){
                cout << "Nenhum cliente encontrado!";
            }
            break;
        }
        case 3: {
            // Deleta a conta segundo o número da conta
            int aux, i=0, quebra=0;
            string cpf_aux;
            cout << "Digite o numero da conta: ";
            cin >> aux;
            do {
                // Varre até obter a conta baseada no numero digitado
                if (aux == (id_ContaPoupanca[i]->getNumConta())) {
                    cpf_aux = id_ContaPoupanca[i]->getCPFPessoaFisica();
                    delete id_ContaPoupanca[i];
                    numContasPoupanca--;
                    for (int j=i; j<numClientesFisicos; j++) {
                        id_ContaPoupanca[j] = id_ContaPoupanca[j+1];
                    }
                    for (int j=0; j<numClientesFisicos; j++) {
                        if (cpf_aux == id_ClienteFisico[j]->getCPF())
                            id_ClienteFisico[j]->setContaAtiva(0);
                    }
                    quebra = 1;
                    cout << "Conta excluida com sucesso!\n";
                }
                i++;
            } while ((i < numContasPoupanca) && !quebra);

            if (quebra == 0) {
                cout << "Cliente não encontrado!";
            }
            break;
        }
        case 4:{
            // Imprime todas as contas cadastradas
            for (int i=0; i<numContasPoupanca; i++)
                cout << id_ContaPoupanca[i]->printConta();
            break;
        }
        case 5:{
            exit(1);
        }
        default:
            break;
    }
}

void menuContaCorrente(){
    int option;
    cout << endl << "--- MENU CONTA CORRENTE ---" << endl
    << "0 - Menu anterior" << endl
    << "1 - Abrir uma nova conta corrente" << endl
    << "2 - Alterar dados de uma conta corrente" << endl
    << "3 - Excluir uma conta corrente" << endl
    << "4 - Ver contas poupancas criadas" << endl
    << "5 - Sair" << endl;

    cin >> option;
    while(option<0 || option>5){
        cout << "Selecione uma opção válida" << endl;
        cin >> option;
    }

    switch(option){
        case 0:{
            menuPrincipal();
            break;
        }
        case 1:{
            // Verifica antes se há pelo menos 1 cliente para criação de conta
            if (numClientesJuridicos != 0 || numClientesFisicos != 0) {
                // Busca o cliente pelo seu cpf, para verificar se já há um cadastro
                // assim, cria a contaa ou avisa se o cliente não foi encontrado
                int quebra=0, i=0, k=0;
                string aux;
                cout << "Digite seu CPF/CNPJ: ";
                cin.ignore();
                getline(cin, aux);
                do {
                    // Busca e tratamento caso para CLIENTES FISICOS
                    if (aux == (id_ClienteFisico[i]->getCPF())) {
                        if (id_ClienteFisico[i]->getContaAtiva() == 1) {
                            cout << "Cliente já possui uma conta\n";
                            quebra = 1;
                        } else {
                            // Verificar se o numero da conta a ser criada pode ser usado
                            while (k < numContasPoupanca) {
                                if (id_ContaPoupanca[k]->getNumConta() == numProxConta) {
                                    numProxConta++;     // Incrementa para ser diferente
                                    k = -1;             // Reseta a verificação
                                }
                                k++;
                            }
                            k = 0;
                            // Verificando nas contas correntes
                            while (k < numContasCorrente) {
                                if (id_ContaCorrente[k]->getNumConta() == numProxConta) {
                                    numProxConta++;     // Incrementa para ser diferente
                                    k = -1;             // Reseta a verificação
                                }
                                k++;
                            }
                            id_ContaCorrente[numContasCorrente] = new ContaCorrente(numProxConta, *id_ClienteFisico[i]);
                            cout << id_ContaCorrente[numContasCorrente]->printConta();
                            numContasCorrente++;
                            id_ClienteFisico[i]->setContaAtiva(1);
                            cout << "\nConta Criada Com Sucesso!\n";
                            quebra = 1;
                        }
                    }
                    i++;
                } while ((i < numClientesFisicos) && !quebra);

                // Caso não tenha realizado nenhuma operação no laço acima, prepara para o próximo laço
                if (i == numClientesFisicos || id_ClienteFisico[i-1]->getContaAtiva() == 1)
                    quebra = 0;

                // Zerado o contador do laço.
                i = 0;

                // Busca e tratamento caso para CLIENTES JURIDICOS. Entra no laço se criado ou não localizado no caso do cliente fisico
                while ( (i < numClientesJuridicos) && !quebra ) {
                    if (aux == (id_ClienteJuridico[i]->getCNPJ())) {
                        if (id_ClienteJuridico[i]->getContaAtiva() == 1) {
                            cout << "Cliente já possui uma conta\n";
                            quebra = 1;
                        } else {
                            // Verificar se o numero da conta a ser criada pode ser usado
                            while (k < numContasPoupanca) {
                                if (id_ContaPoupanca[k]->getNumConta() == numProxConta) {
                                    numProxConta++;     // Incrementa para ser diferente
                                    k = -1;              // Reseta a verificação
                                }
                                k++;
                            }
                            k = 0;
                            // Verificando nas contas correntes
                            while (k < numContasCorrente) {
                                if (id_ContaCorrente[k]->getNumConta() == numProxConta) {
                                    numProxConta++;     // Incrementa para ser diferente
                                    k = -1;              // Reseta a verificação
                                }
                                k++;
                            }
                            id_ContaCorrente[numContasCorrente] = new ContaCorrente(numProxConta, *id_ClienteJuridico[i]);
                            cout << id_ContaCorrente[numContasCorrente]->printConta();
                            numContasCorrente++;
                            id_ClienteJuridico[i]->setContaAtiva(1);
                            cout << "\nConta Criada Com Sucesso!\n";
                            quebra = 1;
                        }
                    }
                    i++;
                }

                if (quebra == 0){
                    cout << "Nenhum cliente encontrado!\nFavor cadastrar-se\n";
                }

            } else {
                cout << "\nNão ha clientes para criação de contas correntes\n";
            }
            break;
        }
        case 2:{
            // Procura a conta pelo seu número. Quando achava, solicita ao usuário a mudança a ser feito
            int i=0, quebra=0, aux, novo_num=0, alterado=0;
            float novo_valor=0;
            int altera_opcao;
            cout << "Digite o numero da conta corrente: ";
            cin >> aux;
            do {
                if (aux == (id_ContaCorrente[i]->getNumConta())) {
                    cout << "Qual alteração deseja realizar em sua conta poupanca?\n1 - Alterar numero da conta\n2 - Data de Abertura\n3 - Aumentar limite de cheque especial\nOpcao: ";
                    cin >> altera_opcao;
                    if (altera_opcao == 1) {
                        do {
                            cout << "Digite o numero da conta: ";
                            cin >> novo_num;
                            int k=0;
                            // Verifica se o numero ja pertence a outra conta
                            do {
                                if (id_ContaCorrente[k]->getNumConta() == novo_num)
                                    cout << "Digite novamente!\n";
                                else {
                                    id_ContaCorrente[k]->setNumConta(novo_num);
                                    k = numContasCorrente;      // Condicao de parada
                                }
                                k++;
                            } while (k < numContasCorrente);
                            alterado = 1;
                        } while (!alterado);
                        cout << "\nConta alterada com sucesso!\n";
                    } else if (altera_opcao == 2) {
                        id_ContaCorrente[i]->setDataAbertura();
                        cout << "\nConta alterada com sucesso!\n";
                    } else if (altera_opcao == 3) {
                        cout << "Digite o novo valor para cheque especial: ";
                        cin >> novo_valor;
                        id_ContaCorrente[i]->setLimiteCheque(novo_valor);
                        cout << "\nConta alterada sucesso!\n";
                    }
                    quebra = 1;
                }
                i++;
            } while ((i < numContasPoupanca) && !quebra);

            if (quebra == 0){
                cout << "Nenhum cliente encontrado!";
            }
            break;
        }
        case 3: {
            // Deleta a conta segundo o número da conta
            int aux, i=0, quebra=0;
            string cpf_aux;
            cout << "Digite o numero da conta: ";
            cin >> aux;
            do {
                // Varre até obter a conta baseada no numero digitado
                if (aux == (id_ContaCorrente[i]->getNumConta())) {
                    cpf_aux = id_ContaCorrente[i]->getCPFouCNPJ();
                    delete id_ContaCorrente[i];
                    numContasCorrente--;
                    for (int j=i; j<numClientesFisicos; j++) {
                        id_ContaCorrente[j] = id_ContaCorrente[j+1];
                    }
                    for (int j=0; j<numClientesFisicos; j++) {
                        if (cpf_aux == id_ClienteFisico[j]->getCPF())
                            id_ClienteFisico[j]->setContaAtiva(0);
                    }
                    quebra = 1;
                    cout << "Conta excluida com sucesso!\n";
                }
                i++;
            } while ((i < numContasCorrente) && !quebra);

            if (quebra == 0) {
                cout << "Cliente não encontrado!";
            }
            break;
        }
        case 4:{
            // Imprime todas as contas cadastradas
            for (int i=0; i<numContasCorrente; i++)
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

void menuBanco(){
    int option;
    cout << endl << "--- GERENCIAMENTO DO BANCO ---" << endl
    << "0 - Menu anterior" << endl
    << "1 - Exibir número total de contas" << endl
    << "2 - Exibir número total de clientes cadastrados" << endl
    << "3 - Exibir montante total presente no banco" << endl
    << "4 - Exibir histórico de lançamentos de uma conta" << endl
    << "5 - Sair" << endl;

    cin >> option;
    while(option<0 || option>5){
        cout << "Selecione uma opção válida" << endl;
        cin >> option;
    }

    switch(option){
        case 0:{
            menuPrincipal();
            break;
        }
        case 1:{
            cout << "Total de contas cadastradas no banco: " + to_string(getQuantidadeDeContas()) << endl;
            if(getQuantidadeDeContas() > 0)
                cout << "Sendo " + to_string(numContasCorrente) + " do tipo Conta Corrente e " + to_string(numContasPoupanca) + " do tipo Conta Poupancan\n";
            cout << "Você será redirecionado para o menu de gerenciamento do banco" << endl;
            menuBanco();
            break;
        }
        case 2:{
            cout << "Total de cliente cadastrados no banco: " + to_string(getQuantidadeDeClientes()) << endl;
            if(getQuantidadeDeClientes() > 0)
                cout << "Sendo " + to_string(numClientesFisicos) + " do tipo Pessoa Física e " + to_string(numClientesJuridicos) + " do tipo Pessoa Juridica\n";
            cout << "Você será redirecionado para o menu de gerenciamento do banco" << endl;
            menuBanco();
            break;
        }
        case 3:{
            // Tinha um to_string_with_precision aqui...retirado pois estava dando erro
            cout << "Montante total presente no banco: R$" + to_string_with_precision(getMontanteTotal(), 2) << endl;
            cout << "Você será redirecionado para o menu de gerenciamento do banco" << endl;
            menuBanco();
            break;
        }
        case 4:{
            int option2;
            cout << "1 - Exibir extrato de todo o período da conta" << endl
            << "2 - Exibir extrato com período definido" << endl;
            cin >> option2;

            switch(option2){
                //case 1 - Exibe todos os lancamentos relacionados aquela conta
                case 1:{
                    int numConta, lancamentosExibidos;
                    lancamentosExibidos=0;

                    if (numContasPoupanca != 0 || numContasCorrente != 0){
                        cout << "Insira o número da conta desejada: ";
                        cin >> numConta;

                        for(int i=0; i<numLancamentosEfetuados; i++){
                            if(id_Lancamentos[i]->getNumConta() == numConta) {
                                cout << id_Lancamentos[i]->printLancamento() << endl;
                                lancamentosExibidos++;
                            }
                        }

                        if(lancamentosExibidos==0)
                            cout << "Não há lançamentos para essa conta ainda!";

                        cout << "\nVocê será redirecionado para o menu de gerenciamento do banco" << endl;
                        menuBanco();
                    } else{
                        cout << "\nSem contas cadastradas!\n";
                    }
                    break;
                }
                //case 2 - Exibe os lancamentos na conta para um periodo de tempo fechado
                case 2:{
                    int numConta, lancamentosExibidos;
                    lancamentosExibidos=0;

                    //periodo que definido
                    int diaInicio, mesInicio, anoInicio, diaFim, mesFim, anoFim;

                    if(numContasCorrente != 0 || numContasPoupanca != 0){
                        cout << "Insira o número da conta desejada: ";
                        cin >> numConta;

                        cout << "Insira a data de início do periodo desejado: \nDia: ";
                        cin >> diaInicio;
                        cout << "Mes: ";
                        cin >> mesInicio;
                        cout << "Ano: ";
                        cin >> anoInicio;

                        cout << "Insira a data de termino do período: \nDia: ";
                        cin >> diaFim;
                        cout << "Mes: ";
                        cin >> mesFim;
                        cout << "Ano: ";
                        cin >> anoFim;

                        //Varre o vetor de lancamentos buscando o numero da conta e após isso verifica se o lancamento foi feito nos dias dentro do periodo
                        for(int i=0; i<numLancamentosEfetuados; i++)
                            if(id_Lancamentos[i]->getNumConta() == numConta)
                                if(((id_Lancamentos[i]->getDataLancamento().getDia() >= diaInicio && id_Lancamentos[i]->getDataLancamento().getMes() >= mesInicio)) && id_Lancamentos[i]->getDataLancamento().getAno() >= anoInicio)
                                    if(((id_Lancamentos[i]->getDataLancamento().getDia() <= diaFim && id_Lancamentos[i]->getDataLancamento().getMes() <= mesFim)) && id_Lancamentos[i]->getDataLancamento().getAno() <= anoFim){
                                        cout << id_Lancamentos[i]->printLancamento() << endl;
                                        lancamentosExibidos++;
                                    }

                        if(lancamentosExibidos==0)
                            cout << "Não há lançamentos para esse período!";
                        cout << "\nVocê será redirecionado para o menu de gerenciamento do banco" << endl;
                        menuBanco();
                    }
                    else{
                        cout << "\nSem contas Cadastradas!\n";
                    }
                    break;
                }
            }
        }
        case 5:{
            exit(1);
        }
        default:
            break;
    }
}

void menuLancamento() {
    int comando;
    int numConta;
    int operacao = 0;
    float valorLancamento, saldoAnterior=0, saldoAtualizado=0;
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
            menuConta();
            break;
        }
        case 1: {
            if (numContasPoupanca != 0 || numContasCorrente != 0) {
                operacao = 1;

                cout << "Insira o numero da conta: ";
                cin >> numConta;

                cout << "Insira o valor a ser debitado: ";
                cin >> valorLancamento;

                comando = lancamento(numConta, operacao, valorLancamento, &saldoAnterior, &saldoAtualizado);
            } else {
                cout << "\nSem contas cadastradas!\n";
            }
            switch(comando){
                case 0: {
                    Lancamento *lancamento = (Lancamento*) malloc(sizeof(Lancamento));
                    lancamento->setLancamento(numConta, operacao, valorLancamento, saldoAnterior, saldoAtualizado);
                    id_Lancamentos[numLancamentosEfetuados] = lancamento;
                    numLancamentosEfetuados += 1;

                    cout << endl << "Lançamento realizado com sucesso!" << endl;
                    cout << "Você será redirecionado para o menu de lançamentos" << endl;
                    menuLancamento();
                    break;
                }
                case 1: {
                    cout << endl << "ERRO! Não há nenhuma conta correspondente com o número inserido" << endl;
                    cout << "Você será redirecionado para o menu de lançamentos" << endl;
                    menuLancamento();
                    break;
                }
                case 2: {
                    cout << endl << "ERRO! A conta não tem saldo suficiente para o débito" << endl;
                    cout << "Você será redirecionado para o menu de lançamentos" << endl;
                    menuLancamento();
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case 2: {
            if (numContasPoupanca != 0 || numContasCorrente != 0) {
                operacao = 2;

                cout << "Insira o numero da conta: ";
                cin >> numConta;

                cout << "Insira o valor a ser depositado: ";
                cin >> valorLancamento;

                comando = lancamento(numConta, operacao, valorLancamento, &saldoAnterior, &saldoAtualizado);
            } else {
                cout << "\nSem contas cadastradas!\n";
            }
            switch(comando){
                case 0: {
                    Lancamento *lancamento = (Lancamento*) malloc(sizeof(Lancamento));
                    lancamento->setLancamento(numConta, operacao, valorLancamento, saldoAnterior, saldoAtualizado);
                    id_Lancamentos[numLancamentosEfetuados] = lancamento;
                    numLancamentosEfetuados += 1;

                    cout << endl << "Lançamento realizado com sucesso!" << endl;
                    cout << "Você será redirecionado para o menu de lançamentos" << endl;
                    menuLancamento();
                    break;
                }
                case 1: {
                    cout << endl << "ERRO! Não há nenhuma conta correspondente com o número inserido" << endl;
                    cout << "Você será redirecionado para o menu de lançamentos" << endl;
                    menuLancamento();
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

int lancamento(int numConta, int operacao, float valor, float * saldoAnterior, float * saldoAtualizado){
    int i=0;
    float novoValor=0;
    int tipo_conta=0;

    //tipo_conta = 0 -> não existe esse numero de conta
    //tipo_conta = 1 -> Conta poupanca
    //tipo_conta = 2 -> Conta corrente
    do{
        if(i < numContasPoupanca)
            if(numConta == id_ContaPoupanca[i]->getNumConta())
                tipo_conta += 1;

        if(i < numContasCorrente)
            if(numConta == id_ContaCorrente[i]->getNumConta())
                tipo_conta += 2;

        i += 1;
    }while(i<getQuantidadeDeContas());

    //Subtrai 1 do i para voltar para a posição da conta desejada no vetor
    i -= 1;

    //Não existe esse numero de conta
    if(tipo_conta == 0)
        return 1;

    //Operação 1 = Débito
    //Operação 2 = Crédito
    if(tipo_conta == 1){
        if(operacao == 1){
            if((id_ContaPoupanca[i]->getSaldoAtual() - valor) < 0)
                return 2;
            else {
                *saldoAnterior = id_ContaPoupanca[i]->getSaldoAtual();
                novoValor = id_ContaPoupanca[i]->getSaldoAtual() - valor;
                *saldoAtualizado = novoValor;
                id_ContaPoupanca[i]->setSaldoAtual(novoValor);
                return 0;
            }
        }
        else{
            *saldoAnterior = id_ContaPoupanca[i]->getSaldoAtual();
            novoValor = id_ContaPoupanca[i]->getSaldoAtual() + valor;
            *saldoAtualizado = novoValor;
            id_ContaPoupanca[i]->setSaldoAtual(novoValor);
            return 0;
        }
    }
    else{
        if(operacao == 1){
            if(((id_ContaCorrente[i]->getSaldoAtual() + id_ContaCorrente[i]->getLimiteCheque()) - valor) < 0)
                return 2;
            else{
                *saldoAnterior = id_ContaCorrente[i]->getSaldoAtual();
                novoValor = id_ContaCorrente[i]->getSaldoAtual() - valor;
                *saldoAtualizado = novoValor;
                id_ContaCorrente[i]->setSaldoAtual(novoValor);
                return 0;
            }
        }
        else{
            *saldoAnterior = id_ContaCorrente[i]->getSaldoAtual();
            novoValor = id_ContaCorrente[i]->getSaldoAtual() + valor;
            *saldoAtualizado = novoValor;
            id_ContaCorrente[i]->setSaldoAtual(novoValor);
            return 0;
        }
    }
}

int getQuantidadeDeContas(){
    return numContasCorrente + numContasPoupanca;
}

int getQuantidadeDeClientes(){
    return numClientesFisicos + numClientesJuridicos;
}

float getMontanteTotal(){
    int i=0;
    float montanteTotal=0;

    if(numContasPoupanca == 0 && numContasCorrente == 0)
        return montanteTotal;
    else{
        do{
            if(i < numContasPoupanca)
                montanteTotal += id_ContaPoupanca[i]->getSaldoAtual();

            if(i < numContasCorrente)
                montanteTotal += id_ContaCorrente[i]->getSaldoAtual();

            i += 1;
        }while(i<getQuantidadeDeContas());

        return montanteTotal;
    }
}
