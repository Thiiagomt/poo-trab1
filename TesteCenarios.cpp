void menuCenario();
void Cenario1();
void Cenario2();
void Cenario3();
void Cenario4();

void menuCenario() {
    cout << "-- MENU CLIENTES --\n";
    cout << "1 - Cenario 1\n";
    cout << "2 - Cenario 1\n";
    cout << "3 - Cenario 1\n";
    cout << "4 - Cenario 1\n";
}

void Cenario1() {
    id_ClienteFisico[numClientesFisicos] = new PessoaFisica(Fabiano Lamborghini, 33002211, fabiano@dc.ufscar.com, Universidade, Federal, Sao, Carlos, 12345678, 1, 12345678910);
    numClientesFisicos++;
    // Criar um conta poupanca saldo inicial 200
    ContaPoupanca(id_ClienteFisico[numClientesFisicos-1], 1, 12, 12, 2012, 200.0);
    // Criar uma conta corrente saldo inicial 100
    ContaCorrente(12, 12, 2012, 100.0, 1, id_ClienteFisico[numClientesFisicos-1], 0.0);

    id_ClienteFisico[numClientesFisicos] = new PessoaFisica(Jardim Ferreira, 981011692, SouOtario@hotmail.com, Universidade, Federal, Sao, Carlos, 12345678, 1, 12345678901);
    numClientesFisicos++;
    // Criar um conta poupanca saldo inicial 50
    ContaCorrente(12, 12, 2012, 50.0, 1, id_ClienteFisico[numClientesFisicos-1], 0.0);
    // Criar uma conta corrente saldo inicial 0
    ContaPoupanca(id_ClienteFisico[numClientesFisicos-1], 1, 12, 12, 2012, 0.0);
}