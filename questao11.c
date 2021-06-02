//questao 11
#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct{
	char nome[50];
	float potencia; //em kW
	float tempoAtivoPorDia; //em Horas
}Eletrodomestico;

void salva(Eletrodomesto *aparelhos);
void consumoEletrico(Eletrodomestico *aparelhos, int t); //t -> tempo em dias

int main(){
	// jhdbkfj
	return 0;
}


void salva(Eletrodomesto *aparelhos){
	int i;
	for (i = 0; i < N; i++){
		printf ("Eletrodomestico %d\n", i+1);
		printf ("Nome: ");
		fflush (stdin);
		
	}
}

void consumoEletrico(Eletrodomestico *aparelhos, int t){//t -> tempo em dias
	
}
