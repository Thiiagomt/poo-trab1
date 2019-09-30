#include <iostream>
 a 
#include "Cliente.h"
#include "ContaCorrente.h"

using namespace std;

// Funções
void menuPrincipal();
void menuCliente();
void menuConta();
void menuBanco();
int getQuantidadeDeContas();
int getQuantidadeDeClientes();
float getMontanteTotal();

int main() {

    Adress endereco;
    endereco.rua = "pedro pretti";
    endereco.numero = 153;
    endereco.bairro = "maria izabel";
    endereco.cep = 17516290;
    endereco.cidade = "marilia";
    endereco.uf = "sp";

    Cliente client1("Thiago", "44175184830", endereco, "981216643", "tmoraes505@gmail.com");

    Cliente * cadastro;
    cadastro = (Cliente*) malloc(10 * sizeof(Cliente));

    Cliente cliente2;

    cliente2.setNome("alcides");
    cliente2.setCPF("4123");
    cliente2.setEndereco(endereco);
    cliente2.setTelefone("4587");
    cliente2.setEmail("t@gmail.com");

    cadastro[0] = cliente2;
    cadastro[1] = client1;

    cadastro[0].printCliente();

    //menuPrincipal();

    return 0;
}

void menuPrincipal(){
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
        case 4: {
            exit(1);
        }
        default:
            break;
    }
}

void menuCliente(){
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
            menuPrincipal();
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

void menuConta(){
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
            menuPrincipal();
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

void menuBanco(){
    int option;
    cout << endl << "--- GERENCIAMENTO DO BANCO ---" << endl
    << "0 - Menu anterior" << endl
    << "1 - Efetuar débito em conta" << endl
    << "2 - Efetuar crédito em conta" << endl
    << "3 - Número total de contas" << endl
    << "4 - Número total de clientes cadastrados" << endl
    << "5 - Montante total presente no banco" << endl
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
