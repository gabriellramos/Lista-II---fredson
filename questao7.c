//descrição
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3

typedef struct {
	char titulo[30];
	char autor[15];
	int ano;
}Livro;

void salva(Livro *livros);
void buscaLivroPorTitulo(Livro *livros, char *titulo);
void mudaUltimoCaractereDaString(char *str, int tam);

int main(){
	Livro livros[N];
	char titulo[30];
	
	salva(livros);
	
	printf ("\n\nQual titulo deseja buscar?: ");
	fflush (stdin);
	fgets (titulo, 30, stdin);
	mudaUltimoCaractereDaString(titulo, strlen(titulo));
	
	buscaLivroPorTitulo(livros, titulo);
	return 0;
}

void salva(Livro *livros){
	int i;
	for (i = 0; i < N; i++){
		printf ("Livro %d\n", i+1);
		printf ("Titulo: ");
		fflush (stdin);
		fgets(livros[i].titulo, 30, stdin);
		mudaUltimoCaractereDaString(livros[i].titulo, strlen(livros[i].titulo));
		printf ("Autor: ");
		fflush (stdin);
		fgets (livros[i].autor, 15, stdin)
		printf ("Ano: ");
		scanf ("%d", &livros[i].ano);
		printf ("----------------------------------------\n");
	}
}

void buscaLivroPorTitulo(Livro *livros, char *titulo){
	int i, cont=0;
	char str[30], strTitulo[30];
	//copiando titulo para str
	strcpy(strTitulo,titulo);
	strupr(strTitulo); //convertendo para maiusculo
	printf ("Buscando livro %s\n", titulo);
	
	for (i = 0; i < N; i++){
		strcpy(str,livros[i].titulo);
		strupr(str);
		//compara se strings são iguais
		if (!strcmp(str, strTitulo)){
			printf ("Livro %d\tAno: %d\tAutor: %s\n", ++cont, livros[i].ano, livros[i].autor);
		}
	}
	
	if(cont==0)
		printf ("Nenhum livro encontrado!\n\n");
}

void mudaUltimoCaractereDaString(char *str, int tam){
	str[tam-1] = '\0';	
}
