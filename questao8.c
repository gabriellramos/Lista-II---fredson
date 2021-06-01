//questão 8
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char logradouro[100];
	int numero;
	char bairro[20];
	long int cep;
}Endereco;

typedef struct {
	int matricula;
	char nome[50];
	Endereco endereco;
}Cliente;

Cliente salva();
void imprime(Cliente cliente);
void mudaUltimoCaractereDaString(char *str, int tam);

int main(){
	Cliente cliente;
	cliente = salva();
	printf ("\n\n");
	imprime(cliente);
	return 0;
}

Cliente salva(){
	Cliente c;
	printf ("Matricula: ");
	scanf ("%d", &c.matricula);
	printf ("Nome: ", c.matricula);
	fflush (stdin);
	fgets(c.nome, 50,stdin);
	mudaUltimoCaractereDaString(c.nome, strlen(c.nome));
	printf ("****** Endereco ******\n");
	printf ("Logradouro: ");
	fflush (stdin);
	fgets(c.endereco.logradouro,100,stdin);
	mudaUltimoCaractereDaString(c.endereco.logradouro, strlen(c.endereco.logradouro));
	printf ("Numero: ");
	scanf ("%d", &c.endereco.numero);
	printf ("Bairro: ");
	fflush (stdin);
	fgets (c.endereco.bairro, 20, stdin);
	mudaUltimoCaractereDaString(c.endereco.bairro, strlen(c.endereco.bairro));
	printf ("CEP: ");
	scanf ("%ld", &c.endereco.cep);
	return c;
}

void imprime(Cliente c){
	printf ("Nome: %s\n", c.nome);
	printf ("Matricula: %d\n", c.matricula);
	printf ("Endereco:\n");
	printf ("\tLogradouro: %s\n", c.endereco.logradouro);
	printf ("\tNumero: %d\n", c.endereco.numero);
	printf ("\tBairro: %s\n", c.endereco.bairro);
	printf ("\tCEP: %ld\n", c.endereco.cep); 
}

void mudaUltimoCaractereDaString(char *str, int tam){
	str[tam-1] = '\0';	
}
