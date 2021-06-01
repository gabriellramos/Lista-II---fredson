//questão 9
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	long int cpf;
	char nome[100];
}Proprietario;

typedef struct {
	char modelo[30];
	int ano;
	char placa[10];
	Proprietario proprietario;
}Carro;

Carro salva();
void imprimeCarro(Carro c);

int main(){
	Carro carro;
	carro = salva();
	printf ("\n\n\n");
	imprimeCarro(carro);
	return 0;
}


Carro salva(){
	Carro c;
	printf ("Modelo: ");
	fflush (stdin);
	fgets (c.modelo, 30, stdin);
	printf ("Ano: ");
	scanf ("%d", &c.ano);
	printf ("Placa: ");
	fflush (stdin);
	fgets (c.placa, 10, stdin);
	printf ("Proprietario: \n");
	printf ("\tNome: ");
	fflush (stdin);
	fgets (c.proprietario.nome, 100, stdin);
	printf ("\tCPF: ");
	scanf ("%ld", &c.proprietario.cpf);

	return c;
}

void imprimeCarro(Carro c){
	printf ("Modelo: %s", c.modelo);
	printf ("Ano: %d\n", c.ano);
	printf ("Placa: %s", c.placa);
	printf ("Proprietario: \n");
	printf ("\tNome: %s", c.proprietario.nome);
	printf ("\tCPF: %ld\n", c.proprietario.cpf);
}
