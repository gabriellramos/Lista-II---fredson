//questao 10
#include <stdio.h>
#include <stdlib.h>


typedef struct{
	long int cpf;
	char nome[50];
}Professor;

typedef struct {
	int codigo;
	char nome[50];
	Professor professor;
}Disciplina;

typedef struct {
	int matricula;
	char nome[50];
	Disciplina disciplina;
}Aluno;

Aluno salva(){
	Aluno aluno;
	
	printf ("Matricula: ");
	scanf ("%d", &aluno.matricula);
	printf ("Nome: ");
	fflush (stdin);
	fgets (aluno.nome, 50, stdin);
	printf ("*******Disciplina*********\n");
	printf ("\tCod da Disciplina: ");
	scanf ("%d", &aluno.disciplina.codigo);
	printf ("\tNome da Disciplina: ");
	fflush (stdin);
	fgets (aluno.disciplina.nome, 50, stdin);
	printf ("\t**********Professor************\n");
	printf ("\t\tNome: ");
	fflush (stdin);
	fgets (aluno.disciplina.professor.nome, 50, stdin);
	printf ("\t\tCPF: ");
	scanf ("%ld", &aluno.disciplina.professor.cpf);
	return aluno;
}

void imprime(Aluno aluno){
	printf ("Matricula: %d\n", aluno.matricula);
	printf ("Nome: %s", aluno.nome);
	printf ("*******Disciplina*********\n");
	printf ("\tCod da Disciplina: %d\n",aluno.disciplina.codigo);
	printf ("\tNome da Disciplina: %s", aluno.disciplina.nome);
	printf ("\t**********Professor************\n");
	printf ("\t\tNome: %s", aluno.disciplina.professor.nome);
	printf ("\t\tCPF: %ld\n", aluno.disciplina.professor.cpf);
}


int main(){
	Aluno aluno;
	aluno = salva();
	printf ("\n\n\n");
	imprime(aluno);
	return 0;
}

