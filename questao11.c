//questao 11
#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct{
	char nome[15];
	float potencia; //em kW
	float tempoAtivoPorDia; //em Horas
}Eletrodomestico;

void salva(Eletrodomesto *aparelhos);
void consumoEletrico(Eletrodomestico *aparelhos, int t); //t -> tempo em dias

int main(){
	// jhdbkfj
	return 0;
}


void salva(Eletrodomestico *aparelhos){
	int i;
	for (i = 0; i < N; i++){
		printf ("Eletrodomestico %d\n", i+1);
		printf ("Nome: ");
		fflush (stdin);
		fgets (aparelhos[i].nome);
		printf ("Potencia: ");
		scanf ("%f", &aparelhos[i].potencia);
		printf ("Tempo ativo por dia(horas): ");
		scanf ("%f", &aparelhos[i].tempoAtivoPorDia);
	}
}

void consumoEletrico(Eletrodomestico *aparelhos, int t){//t -> tempo em dias
	int i;
	float consulmoRelativo[N], somaConsulmo=0.0,
}
