//Questao 15
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1

typedef struct {
	char nome[50];
	int sexo, idade, fumante, gostaDeEsporte, praticaAtividadeFisica;
	float rendaMensal;
}Questionario;

void cadastrarNovaEntrevista(Questionario *entrevista, int indice);
int pesquisaQuestionarioPorNome(Questionario *entrevista, char *nome);
void imprimeQuestionario(Questionario *entrevista, int indice);
float percHomens(Questionario *entrevista);
float percMulheres(Questionario *entrevista);
float percIdade18a40anos(Questionario *entrevista);
float percFumantes(Questionario *entrevista);
float rendaMediaEntrevistados(Questionario *entrevista);
void mudaUltimoCaractereDaString(char *str, int tam);

int main(){
	int i;
	Questionario entrevista[N];
	float percH, percM,percPde18a40, percFuma, rendaMedia;
	char nome[50];
	
	for (i=0; i<N; i++){
		cadastrarNovaEntrevista(entrevista, i);
		printf ("\n\n");
		imprimeQuestionario(entrevista, i);
	}
	
	percM = percMulheres(entrevista);
	percH = percHomens(entrevista);

	percPde18a40 = percIdade18a40anos(entrevista);
	percFuma = percFumantes(entrevista); 
	rendaMedia = rendaMediaEntrevistados(entrevista);
	
	printf ("\n\n\nEstatisticas sobre as entrevistas: \n");
	printf ("Percentual de homens e mulheres: %.2f%% - H || %.2f%% - M\n", percH, percM); //0 - homens ---- 1 - mulheres
	printf ("Percentual de pessoas com 18 a 40 anos: %.2f%%\n", percPde18a40);
	printf ("Pencentual de fumantes: %.2f%%\n", percFuma);
	printf ("Renda media dos entrevistados: R$ %.2f\n", rendaMedia);
	
	printf ("\nInsira um nome para pesquisar o questionario: ");
	fflush (stdin);
	fgets (nome, 50, stdin);
	
	int pos = pesquisaQuestionarioPorNome(entrevista,nome);
	
	if (pos != -1)
		imprimeQuestionario(entrevista, pos);
	else ("questionario nao encontrado\n");
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
		
		if (entrevista[indice].sexo>=1 && entrevista[indice].sexo<=4) break;
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

int pesquisaQuestionarioPorNome(Questionario *entrevista, char *nome){
	char strNome[50], str[50];
	int i, pos = -1;

	mudaUltimoCaractereDaString(nome, strlen(nome));

	strcpy(strNome, nome);
	strupr(strNome);
	
	for (i=0; i<N;i++){
		strcpy(str, entrevista[i].nome);
		strupr(str);
		if (strcmp(str, strNome) == 0){
			pos = i;
		}
	}
	return pos;
}

void imprimeQuestionario(Questionario *entrevista, int indice){
	char genero[10], fuma[4], gostaEsporte[4],praticaAtividade[4];

	if (entrevista[indice].sexo==1) strcpy(genero,"Feminino");
	else if (entrevista[indice].sexo==2)  strcpy(genero,"Masculino");
	else strcpy(genero,"Outro");

	strcpy(fuma,entrevista[indice].fumante == 1 ? "Sim" : "Nao");
	strcpy(gostaEsporte,entrevista[indice].gostaDeEsporte == 1 ? "Sim" : "Nao");
	strcpy(praticaAtividade,entrevista[indice].praticaAtividadeFisica == 1 ? "Sim" : "Nao");
	
	printf ("Entrevista %d\n", indice+1);
	printf ("Nome: %s\n", entrevista[indice].nome);
	printf ("Sexo: %s\n", genero);
	printf ("Idade: %d\n", entrevista[indice].idade);
	printf ("Renda Mensal: R$ %.2f\n", entrevista[indice].rendaMensal);
	printf ("Fumante?: %s\n", fuma);
	printf ("Gosta de Esporte?: %s\n", gostaEsporte);
	printf ("Pratica Atividade Fisica?: %s\n\n", praticaAtividade);
}

float percHomens(Questionario *entrevista){
	int i, homens=0;
	
	//1 - feminino, 2 - masculino
	for (i = 0; i<N; i++){
		if(entrevista[i].sexo == 2)
			homens = homens + 1;
	}
	
	return ((float)homens/N)*100;
}


float percMulheres(Questionario *entrevista){
	
	int i, mulheres=0;
	//1 - feminino, 2 - masculino
	for (i = 0; i<N; i++){
		if(entrevista[i].sexo==1)
			mulheres = mulheres + 1;
	}
	
	return ((float)mulheres/N)*100;
}

float percIdade18a40anos(Questionario *entrevista){
	int i, cont=0;
	
	for (i=0; i<N; i++){
		if (entrevista[i].idade>=18 && entrevista[i].idade<=40)
			cont++;
	}
	
	return (cont/N) * 100;
}

float percFumantes(Questionario *entrevista){
	int i, cont=0;
	for (i=0;i<N; i++)
		if (entrevista[i].fumante==1)
			cont++;
	
	return ((float)cont/N)*100;
}

float rendaMediaEntrevistados(Questionario *entrevista){
	float soma=0.0;
	int i;
	for (i=0;i<N;i++){
		soma+=entrevista[i].rendaMensal;
	}
	return soma/N;
}

//funcao para ajudar na pesquisa por nome
void mudaUltimoCaractereDaString(char *str, int tam){
	if (str[tam-1]=='\n')
		str[tam-1] = '\0';	
}
