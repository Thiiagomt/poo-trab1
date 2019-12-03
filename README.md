# poo-trab1

# ARQUIVO 

#include <fstream>	
using namespace std;

class Pessoa {
public:
	Pessoa(void){}
	int id;
	int idade;
	double altura;
	char nome[20];
};

void writePessoa(ofstream &arq, Pessoa &p){
	// para gravar todos os atributos da classe
	arq.write(reinterpret_cast<const char*>(&p),sizeof(p));
}

void readPessoa(ifstream &arq, Pessoa &p){
	// para ler todos os atributos da classe
	arq.read(reinterpret_cast<char*>(&p),sizeof(p));
}

void imprime(Pessoa &p){
	cout << "Nome  : " << p.nome << endl;
	cout << "Id    : " << p.id << endl;
	cout << "Idade : " << p.idade << endl;
	cout << "Altura: " << p.altura << endl;
}

int main(){
	
	srand( (unsigned)time( NULL ) );
	cout << "Exemplo de acesso aleatório em arquivos" << endl;

	ofstream arq("hitman.bin", ios::binary); 


	Pessoa p1;
	p1.id=0;
	p1.altura=1.75;
	p1.idade=23;
	strcpy(p1.nome, "Fulano\0");
	writePessoa(arq, p1);
	
	p1.id=1;
	p1.altura=1.79;
	p1.idade=34;
	strcpy(p1.nome, "Beltrano\0");
	writePessoa(arq, p1);

	p1.id=2;
	p1.altura=1.67;
	p1.idade=15;
	strcpy(p1.nome, "Delgrano\0");
	writePessoa(arq, p1);
	
	arq.close();

	ifstream arq2("hitman.bin", ios::binary); 
	Pessoa p2;

	int id=0;
	while(id >= 0){
		cout << "O que você deseja fazer? (1-buscar por id; 2-gerar aleatorio; -1-sair): ";
		int op;
		cin >> op;
		if(op < 0) 
			break;
		op %= 2;
		if(op == 1){
			cout << "Digite o id do registro a ser lido (-1 para sair): ";
			cin >> id;
			if(id < 0) break;
		} else {
			id = rand();
		}
		
		// para garantir que o id esteja [0,2]
		id %= 3; 
		
		// retorna o tamanho de uma estrutura em bytes
		arq2.seekg(id * sizeof(Pessoa));

		// efetua leitura dos dados para a estrutura Pessoa
		readPessoa(arq2, p2);

		// imprime os dados
		imprime(p2);

		cout << endl;
	}
	// sempre
	arq2.close();

	return 0;
}

