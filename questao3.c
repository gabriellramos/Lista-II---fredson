//descrição
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[50];
	int idade;
	char endereco[100];
}Pessoa;

int main(){
	Pessoa pessoa;
	
	printf ("Nome: ");
	fflush(stdin);
	fgets(pessoa.nome,50,stdin);
	printf ("Idade: ");
	scanf ("%d", &pessoa.idade);
	printf ("Endereco: ");
	fflush(stdin);
	fgets(pessoa.endereco,100,stdin);
	
	return 0;
}

