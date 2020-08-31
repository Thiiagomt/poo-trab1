# Trabalhos práticos da disciplina de Programação Orientada a Objetos 2019/2

<br>

## Os 3 trabalhos práticos foram dividos dentro de cada branch.

### Branch master - Trabalho 1

### Branch Trab2 - [Trabalho 2](https://github.com/thiagomtt/poo-trab1/tree/Trab2)

### Branch Trab3 - [Trabalho 3](https://github.com/thiagomtt/poo-trab1/tree/Trab3)

<br>

## Overview

### Trabalho 1 - Elaborar um programa em C++ que gerencie contas correntes de clientes de um banco, oferecendo as seguintes funcionalidades:

* Gerenciamento de clientes: inclusao, alteracao e exclusao de clientes. Para cada cliente, os seguintes dados sao armazenados: nome, CPF, endereco, telefone, e-mail. O programa nao deve permitir CPFs repetidos para clientes.<br>
* Gerenciamento de contas: inclusao, alteracao e exclusao de contas. Para cada conta, os seguintes dados devem ser armazenados: numero da conta, data de abertura, CPF do cliente, e saldo atual. O programa nao deve permitir numeros repetidos de contas. O cliente da conta deve estar previamente cadastrado nosistema. Somente datas validas devem ser permitidas.<br>
* Lancamentos em conta corrente. Um lancamento deve especificar a data do lancamento, o numero da conta corrente, o tipo (debito ou credito), e o valor. Um lancamento de debito somente pode ocorrer se a conta tiver saldo suficiente para nao ficar negativa. Apos o lancamento ter sido realizado, o saldo atual da conta deve ser atualizado.
* Extrato de conta corrente. Para uma dada conta corrente, os respectivos lancamentos devem ser listados, apresentando-se o saldo final atualizado. O extrato deve considerar todo os lancamentos feitos para a conta em questao.
