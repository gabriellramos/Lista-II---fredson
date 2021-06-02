//questao 11
#include <stdio.h>
#include <stdlib.h>
#define N 3

typedef struct{
	char nome[15];
	float potencia; //em kW
	float tempoAtivoPorDia; //em Horas
	
}Eletrodomestico;

void salva(Eletrodomestico *aparelhos);
void consumoEletrico(Eletrodomestico *aparelhos, int t); //t -> tempo em dias

int main(){
	Eletrodomestico eletrodomesticos[N];
	int tempo;
	salva(eletrodomesticos);
	printf ("\n\nInsira o tempo em dias de consumo dos aparelhos: ");
	scanf ("%d", &tempo);
	consumoEletrico(eletrodomesticos, tempo);
	
	return 0;
}


void salva(Eletrodomestico *aparelhos){
	int i;
	for (i = 0; i < N; i++){
		printf ("Eletrodomestico %d\n", i+1);
		printf ("Nome: ");
		fflush (stdin);
		fgets (aparelhos[i].nome, 15, stdin);
		printf ("Potencia (em kW): ");
		scanf ("%f", &aparelhos[i].potencia);
		printf ("Tempo ativo por dia(horas): ");
		scanf ("%f", &aparelhos[i].tempoAtivoPorDia);
	}
}

void consumoEletrico(Eletrodomestico *aparelhos, int t){//t -> tempo em dias
	int i;
	float consumoRelativo[N], somaConsumo=0.0, consumoTotal;
	
	for (i=0;i<N;i++){
		consumoRelativo[i] = (aparelhos[i].potencia * aparelhos[i].tempoAtivoPorDia) * t;
		somaConsumo += consumoRelativo[i];
	}
	
	consumoTotal = somaConsumo;
	printf ("Consumo Total da Casa: %.2fkW\n\n",consumoTotal);
	for (i=0; i<N; i++){
		consumoRelativo[i] = (consumoRelativo[i]/consumoTotal)*100;
		printf ("Aparelho: %s", aparelhos[i].nome);
		printf ("Consumo relativo: %.2f%%\n", consumoRelativo[i]);
	}
}
