//Questao 15
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2

typedef struct {
	char nome[50];
	int sexo, idade, fumante, gostaDeEsporte, praticaAtividadeFisica;
	float rendaMensal;
}Questionario;

void cadastrarNovaEntrevista(Questionario *entrevista, int indice);
int pesquisaQuestionarioPorNome(char *nome);
void percHomensMulheres(Questionario *entrevista, float *percentuais);
float percIdade18a40anos(Questionario *entrevista);
float percFumantes(Questionario *entrevista);
float rendaMediaEntrevistados(Questionario *entrevista);
void mudaUltimoCaractereDaString(char *str, int tam);

int main(){
	int i;
	Questionario entrevista[N];
	float percHeM[2], percPde18a40, percFuma, rendaMedia;
	for (i=0; i<N; i++){
		cadastrarNovaEntrevista(entrevista, i);
	}
	
	percHomensMulheres(entrevista);
	percPde18a40 = percIdade18a40anos(entrevista);
	percFuma = percFumantes(entrevista); 
	rendaMedia = rendaMediaEntrevistados(entrevista);
	
	printf ("Estatisticas sobre as entrevistas: \n");
	printf ("Percentual de homens e mulheres: %.2f%% - H || %.2f%% - M\n", percHeM[0], percHeM[1]); //0 - homens ---- 1 - mulheres
	printf ("Percentual de pessoas com 18 a 40 anos: %.2f%%\n", percPde18a40);
	printf ("Pencentual de fumantes: %.2f%%\n", percFuma);
	printf ("Renda media dos entrevistados: R$ %.2f\n", rendaMedia);
	return 0;
}

void cadastrarNovaEntrevista(Questionario *entrevista, int indice){
	printf ("Entrevista %d\n", indice+1);
	printf ("Nome: ");
	fflush (stdin);
	fgets (entrevista[indice].nome, 15, stdin);
	mudaUltimoCaractereDaString(entrevista[indice].nome, strlen(entrevista[indice].nome));
	
	while(1){
		printf ("Sexo (1 - Feminino / 2 - Masculino / 3 - Outro): ");
		scanf ("%d", &entrevista[indice].sexo);
		
		if (entrevista[indice].sexo>=1 && entrevista[indice].sexo<4) break;
	}
	
	printf ("Idade: ");
	scanf ("%d", &entrevista[indice].idade);
	printf ("Renda Mensal: R$ ");
	scanf ("%f", &entrevista[indice].rendaMensal);
	
	while(1){
		printf ("E fumante (1 - S/ 2 - N): ");
		scanf ("%d", &entrevista[indice].fumante);
		if (entrevista[indice].fumante>0 && entrevista[indice].fumante<3)
			break;
	}
	
	while(1){
		printf ("Gosta de espostes (1 - S/ 2 - N): ");
		scanf ("%d", &entrevista[indice].gostaDeEsporte);
		if (entrevista[indice].gostaDeEsporte>0 && entrevista[indice].gostaDeEsporte<3)
			break;
	}
	
	while(1){
		printf ("Pratica atividade fisica (1 - S/ 2 - N): ");
		scanf ("%d", &entrevista[indice].praticaAtividadeFisica);
		if (entrevista[indice].praticaAtividadeFisica>0 && entrevista[indice].praticaAtividadeFisica<3)
			break;
	}
	
	
}

int pesquisaQuestionarioPorNome(char *nome){
	char strNome[15], str[15];
	strcpy()
}

void percHomensMulheres(Questionario *entrevista, float *percentuais){
	
}

float percIdade18a40anos(Questionario *entrevista){
	
}

float percFumantes(Questionario *entrevista){
	
}

float rendaMediaEntrevistados(Questionario *entrevista){
	
}

//funcao para ajudar na pesquisa por nome
void mudaUltimoCaractereDaString(char *str, int tam){
	str[tam-1] = '\0';	
}
