//descrição
#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct {
	char nome[50];
	int matricula;
	char curso[50];
}Aluno;

void salva(Aluno *alunos);
void imprime(Aluno *alunos);

int main(){
	int i;
	Aluno alunos[N];
	salva(alunos);
	imprime(alunos);
	return 0;
}


void salva(Aluno *alunos){
	int i;
	for (i=0;i<N;i++){
		printf ("Aluno %d:\n", i+1);
		printf ("Nome: ");
		fflush(stdin);
		fgets(alunos[i].nome,50,stdin);
		
		printf ("Matricula: ");
		scanf("%d", &alunos[i].matricula);
		
		printf ("Curso: ");
		fflush(stdin);//limpa buffer da memória
		fgets(alunos[i].curso, 50, stdin);
		printf ("----------------------------------------------------\n");
	}
}

void imprime(Aluno *alunos){
	int i;
	printf ("Alunos cadastrados...\n");
	for (i=0;i<N;i++){
		printf ("Aluno %d:\n",i+1);
		printf ("Nome: %s\n", alunos[i].nome);
		printf ("Matricula: %d\n", alunos[i].matricula);
		printf ("Curso: %s\n", alunos[i].curso);
		printf ("-------------------------------------------------\n\n");
	}
}
