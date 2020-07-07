# Trabalhos práticos da disciplina de Programação Orientada a Objetos 2019/2

<br>

## Os 3 trabalhos práticos foram dividos dentro de cada branch.

### Branch master - Trabalho 1

### Branch Trab2 - Trabalho 2

### Branch Trab3 - Trabalho 3

<br>

## Overview

### Trabalho 1 - Elaborar um programa em C++ que gerencie contas correntes de clientes de um banco, oferecendo as seguintes funcionalidades:

* Gerenciamento de clientes: inclusao, alteracao e exclusao de clientes. Para cada cliente, os seguintes dados sao armazenados: nome, CPF, endereco, telefone, e-mail. O programa nao deve permitir CPFs repetidos para clientes.<br>
* Gerenciamento de contas: inclusao, alteracao e exclusao de contas. Para cada conta, os seguintes dados devem ser armazenados: numero da conta, data de abertura, CPF do cliente, e saldo atual. O programa nao deve permitir numeros repetidos de contas. O cliente da conta deve estar previamente cadastrado nosistema. Somente datas validas devem ser permitidas.<br>
* Lancamentos em conta corrente. Um lancamento deve especificar a data do lancamento, o numero da conta corrente, o tipo (debito ou credito), e o valor. Um lancamento de debito somente pode ocorrer se a conta tiver saldo suficiente para nao ficar negativa. Apos o lancamento ter sido realizado, o saldo atual da conta deve ser atualizado.
* Extrato de conta corrente. Para uma dada conta corrente, os respectivos lancamentos devem ser listados, apresentando-se o saldo final atualizado. O extrato deve considerar todo os lancamentos feitos para a conta em questao.


### Trabalho 2 - Evoluir o programa que gerencia contas correntes de clientes de um banco, elaborado para o Trabalho Pratico 1.
 
 A implementacao dever ser feita na linguagem C++ e deve evoluir e/ou adicionar as seguintes funcionalidades:

* Gerenciamento de clientes tipo Pessoa Fısica e Pessoa Jurıdica: <br>
inclusao,alteracao e exclusao de clientes. <br>
* Para cada cliente tipo Pessoa Fısica, os seguintes dados sao armazenados: nome, CPF, endereco, telefone, e e-mail.<br>
* Para cada cliente tipo Pessoa Jurıdica, os seguintes dados sao armazenados: nome (raz ̃ao  social), CNPJ, CPF do proprietario majoritario, endereco,telefone, e-mail, ramo de atuacao, data de fundacao, e data da ultimaatualizacao do contrato social.


### Trabalho 3 - Evoluir o programa que gerencia contas tipo corrente e poupanca, de clientes tipo pessoa fısica e pessoa jurıdica, elaborado para o Trabalho Pratico  2. 

A implementacao dever ser feita na linguagem C++ e deve evoluir e/ou adicionar as seguintes funcionalidades:

* Armazenamento em arquivos: Todos os dados inseridos no sistema (clientes,contas e lancamentos) devem ser armazenados de forma permanente, em arquivos de acesso aleatorio. Esses arquivos serao lidos quando o sistema for reinicializado, e deverao estar disponıveis para novas transacoes a serem realizadas no sistema.
* Reinicializacao dos arquivos: O sistema deve oferecer ao usuario a opcao de reinicializar os arquivos (ou seja, limpar o conteudo dos arquivos). Essa funcionalidade sera ́util para permitir que os cenarios de teste do sistema sejam executados adequadamente, em qualquer ordem.
* Interface: A interface deve possibilitar a escolha da funcionalidade desejada pelo usuario, de acordo com a especificacao do Trabalho Pratico 2. A interface pode ser simples, porem possibilitando interacao clara entre o usuario e o sistema, assim como com a capacidade de apresentar as informacoes manipuladas de forma clara e completa.
