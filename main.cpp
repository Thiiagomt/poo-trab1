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
#include "ContaPoupanca.h"
#include "Lancamento.h"

using namespace std;
// A variável "quebra" pode ser encontrada em multiplas funções. Ela é similar ao comportamento
// do "break", pois irá interromper o while quando tal objetivo for cumprido.

// Funções
void menuPrincipal();
void menuCliente();
void menuConta();
void menuBanco();
void menuLancamento();
int lancamento(int numConta, int operacao, float valor);
int getQuantidadeDeContas();
int getQuantidadeDeClientes();
float getMontanteTotal();

//Função para transformar float em string com 2 casas decimais
std::string to_string_with_precision(const float valor, const int num_casas){
    std::ostringstream out;
    out.precision(num_casas);
    out << std::fixed << valor;
    return out.str();
}

int numContasCadastradas = 0;
int numClientesCadastrados = 0;
int numLancamentosEfetuados = 0;

// Esse contador sempre sera incrementado, determinando o numero da conta (nunca será repetido)
int numProxConta = 1;

PessoaFisica * id_Cliente[N_CLIENTES_CONTAS];
ContaPoupanca * id_ContaPoupanca[N_CLIENTES_CONTAS];
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
    << "1 - Efetuar um novo cadastro" << endl
    << "2 - Alterar um cadastro existente" << endl
    << "3 - Excluir um cadastro" << endl
    << "4 - Ver Clientes" << endl
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
            int quebra=0, i=0;
            // Cadastra-se um cliente em ordem
            id_Cliente[numClientesCadastrados] = new PessoaFisica;
            numClientesCadastrados++;
            // Cria o cliente e verifica se tal já existe por meio  do cpf. 
            // Se já existir (cpf já usado), então é deletado o objeto criado
            while ( (i<(numClientesCadastrados - 1)) && !quebra ) {
                if (id_Cliente[numClientesCadastrados-1]->getCPF() == id_Cliente[i]->getCPF()) {
                    quebra = 1;
                    cout << "\nCliente com CPF já existente!\n";
                    delete id_Cliente[numClientesCadastrados-1];
                    numClientesCadastrados--;
                }
                i++;
            }
            cout << "\n\nPessoaFisica cadastrado com sucesso!" << endl;
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
                    cout << "Qual alteração deseja realizar?\n1 - Nome\n2 - CPF\n3 - Endereco\n4 - Telefone\n5 - Email\nOpcao: ";
                    cin >> altera_opcao;
                    if (altera_opcao == 1) {
                        cin.ignore();
                        id_Cliente[i]->setNome();
                        cout << "Cadastro alterado com sucesso!\n";
                    } else if (altera_opcao == 2) {
                        if(id_Cliente[i]->getContaAtiva() == 0){
                            cin.ignore();
                            id_Cliente[i]->setCPF();
                            cout << "Cadastro alterado com sucesso!\n";
                        }
                        else{
                            cout << "Falha na alteração!\nExiste uma conta vinculada a este CPF no momento!\n";
                        }
                    } else if (altera_opcao == 3) {
                        cin.ignore();
                        id_Cliente[i]->setEndereco();
                        cout << "Cadastro alterado com sucesso!\n";
                    } else if (altera_opcao == 4) {
                        cin.ignore();
                        id_Cliente[i]->setTelefone();
                        cout << "Cadastro alterado com sucesso!\n";
                    } else if (altera_opcao == 5) {
                        cin.ignore();
                        id_Cliente[i]->setEmail();
                        cout << "Cadastro alterado com sucesso!\n";
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
            string aux;
            cout << "Digite seu cpf: ";
            cin.ignore();
            getline(cin, aux);
            do {
                // Busca de cliente por meio do cpf
                // Se o cliente possuir uma conta ativa no momento, seu cadastro não poderá ser excluído
                if (aux == (id_Cliente[i]->getCPF())) {
                    if (id_Cliente[i]->getContaAtiva() == 1) {
                        cout << "Nao foi possivel deletar sua conta!\nVoce possui uma conta ativa no momento!\n";
                    } else {
                        delete id_Cliente[i];
                        numClientesCadastrados--;
                        for (int j=i; j<numClientesCadastrados; j++) {
                            id_Cliente[j] = id_Cliente[j+1];
                        }
                        quebra = 1;
                    }
                }
                i++;
            } while ((i < numClientesCadastrados) && !quebra);

            if (quebra == 0) {
                cout << "Cliente não encontrado!";
            }
            break;
        }
        case 4:{
            //Cadastro de todos os clientes
            for (int i=0; i<numClientesCadastrados; i++)
                cout << id_Cliente[i]->printPessoaFisica();
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
    << "1 - Abrir uma nova conta" << endl
    << "2 - Alterar dados de uma conta" << endl
    << "3 - Excluir uma conta" << endl
    << "4 - Realizar lancamento em conta" << endl
    << "5 - Ver Contas Criadas" << endl
    << "6 - Sair" << endl;

    cin >> option;
    while(option<0 || option>6){
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
            if (numClientesCadastrados != 0) {
                // Busca o cliente pelo seu cpf, para verificar se já há um cadastro
                // assim, cria a contaa ou avisa se o cliente não foi encontrado
                int quebra=0, i=0, k=0;
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
                            // Pessoa Juridica
                            if (id_Cliente[i]->getTipoConta() == 2) {
                                
                            }
                            // Pessoa Fisica
                            else {
                                // Verificar se o numero da conta a ser criada pode ser usado
                                while (k < numContasCadastradas) {
                                    if (id_ContaPoupanca[k]->getNumConta() == numProxConta) {
                                        numProxConta++;     // Incrementa para ser diferente
                                        k = -1;              // Reseta a verificação
                                    }
                                    k++;
                                }
                                id_ContaPoupanca[numContasCadastradas] = new ContaPoupanca(numProxConta, *id_Cliente[i]);
                                cout << id_ContaPoupanca[numContasCadastradas]->printConta();
                                numContasCadastradas++;
                                id_Cliente[i]->setContaAtiva(1);
                                cout << "\nConta Criada Com Sucesso!\n";
                                quebra = 1;
                            }
                        }
                    }
                    i++;
                } while ((i < numClientesCadastrados) && !quebra);

                if (quebra == 0)
                    cout << "Nenhum cliente encontrado!\nFavor cadastrar-se\n";

            } else {
                cout << "\nNão ha clientes para criação de contas\n";
            }

            break;
        }
        case 2:{
            // Procura a conta pelo seu número. Quando achava, solicita ao usuário a mudança a ser feito
            int i=0, quebra=0, aux, novo_num=0, alterado=0, conta_tipo;
            int altera_opcao;
            cout << "Digite o numero da conta: ";
            cin >> aux;
            cout << "Tipo da conta: 1 - Fisica & 2 - Juridica\n";
            cin >> conta_tipo;
            do {
                if (conta_tipo == 1) {
                    if (aux == (id_ContaPoupanca[i]->getNumConta())) {
                        cout << "Qual alteração deseja realizar?\n1 - Alterar numero da conta\n2 - Data de Abertura\nOpcao: ";
                        cin >> altera_opcao;
                        if (altera_opcao == 1) {
                            do {
                                cout << "Digite o numero da conta: ";
                                cin >> novo_num;
                                int k=0;
                                // Verifica se o numero ja pertence a outra conta
                                do {
                                    if (id_ContaPoupanca[k]->getNumConta() == novo_num)
                                        cout << "Digite novamente!\n";
                                    else {
                                        id_ContaPoupanca[k]->setNumConta(novo_num);
                                        k = numContasCadastradas;      // Condicao de parada
                                    }
                                    k++;
                                } while (k < numContasCadastradas);
                                alterado = 1;
                            } while (!alterado);
                            cout << "\nConta alterada com sucesso!\n";
                        } else if (altera_opcao == 2) {
                            id_ContaPoupanca[i]->setDataAbertura();
                            cout << "\nConta alterada com sucesso!\n";
                        }
                        quebra = 1;
                    }
                }
                else {
                // Alteração aqui para as contas de cunho juridicas
                }
                i++;
            } while ((i < numContasCadastradas) && !quebra);

            if (quebra == 0)
                cout << "Nenhum cliente encontrado!";
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
                    numContasCadastradas--;
                    for (int j=i; j<numClientesCadastrados; j++) {
                        id_ContaPoupanca[j] = id_ContaPoupanca[j+1];
                    }
                    for (int j=0; j<numClientesCadastrados; j++) {
                        if (cpf_aux == id_Cliente[j]->getCPF())
                            id_Cliente[j]->setContaAtiva(0);
                    }
                    quebra = 1;
                    cout << "Conta excluida com sucesso!\n";
                }
                i++;
            } while ((i < numContasCadastradas) && !quebra);

            if (quebra == 0) {
                cout << "Cliente não encontrado!";
            }
            break;
        }
        case 4:{
            menuLancamento();
            break;
        }
        case 5:{
            // Imprime todas as contas cadastradas
            for (int i=0; i<numContasCadastradas; i++)
                cout << id_ContaPoupanca[i]->printConta();
            break;
        }
        case 6:{
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
            cout << "Você será redirecionado para o menu de gerenciamento do banco" << endl;
            menuBanco();
            break;
        }
        case 2:{
            cout << "Total de cliente cadastrados no banco: " + to_string(getQuantidadeDeClientes()) << endl;
            cout << "Você será redirecionado para o menu de gerenciamento do banco" << endl;
            menuBanco();
            break;
        }
        case 3:{
            cout << "Montante total presente no banco: R$" + to_string_with_precision(getMontanteTotal(), 2) << endl;
            cout << "Você será redirecionado para o menu de gerenciamento do banco" << endl;
            menuBanco();
            break;
        }
        case 4:{
            int numConta, lancamentosExibidos;
            lancamentosExibidos=0;

            if (numContasCadastradas != 0){
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
    float valorLancamento;
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
            menuBanco();
            break;
        }
        case 1: {
            if (numContasCadastradas != 0) {
                operacao = 1;

                cout << "Insira o numero da conta: ";
                cin >> numConta;

                cout << "Insira o valor a ser debitado: ";
                cin >> valorLancamento;

                comando = lancamento(numConta, operacao, valorLancamento);
            } else {
                cout << "\nSem contas cadastradas!\n";
            }
            switch(comando){
                case 0: {
                    Lancamento *lancamento = (Lancamento*) malloc(sizeof(Lancamento));
                    lancamento->setLancamento(numConta, operacao, valorLancamento);
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
            if (numContasCadastradas != 0) {
                operacao = 2;

                cout << "Insira o numero da conta: ";
                cin >> numConta;

                cout << "Insira o valor a ser depositado: ";
                cin >> valorLancamento;

                comando = lancamento(numConta, operacao, valorLancamento);
            } else {
                cout << "\nSem contas cadastradas!\n";
            }

            switch(comando){
                case 0: {
                    Lancamento *lancamento = (Lancamento*) malloc(sizeof(Lancamento));
                    lancamento->setLancamento(numConta, operacao, valorLancamento);
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

int lancamento(int numConta, int operacao, float valor){
    int i=0;
    int cont=0;
    float novoValor=0;

    do{
        if(numConta == id_ContaPoupanca[i]->getNumConta())
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
        if((id_ContaPoupanca[i]->getSaldoAtual() - valor) < 0)
            return 2;
        else {
            novoValor = id_ContaPoupanca[i]->getSaldoAtual() - valor;
            id_ContaPoupanca[i]->setSaldoAtual(novoValor);
            return 0;
        }
    }
    else{
        novoValor = id_ContaPoupanca[i]->getSaldoAtual() + valor;
        id_ContaPoupanca[i]->setSaldoAtual(novoValor);
        return 0;
    }
}

int getQuantidadeDeContas(){
    return numContasCadastradas;
}

int getQuantidadeDeClientes(){
    return numClientesCadastrados;
}

float getMontanteTotal(){
    int i;
    float montanteTotal=0;

    if(numContasCadastradas == 0)
        montanteTotal=0;
    else
        for(i=0; i<numContasCadastradas; i++)
            montanteTotal = id_ContaPoupanca[i]->getSaldoAtual() + montanteTotal;

    return montanteTotal;
}