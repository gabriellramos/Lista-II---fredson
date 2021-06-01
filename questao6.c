//questao 6
#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct{
	char marca[15];
	int ano;
	float preco;
}Carro;

void salva(Carro *carros);
void imprime(Carro *carros, float preco);

int main(){
	float p;
	Carro carros[N];
	
	salva(carros);
	
	do{
		printf ("Insira um valor: ");
		scanf ("%f", &p);
		
		if (p == 0) break;
		else imprime(carros,p);				
	}while (p!=0);
	return 0;
}

void salva(Carro *carros){
	int i;
	
	for (i = 0; i < N; i++){
		printf ("Carro %d: \n", i+1);
		printf ("Marca: ");
		fflush (stdin);
		fgets (carros[i].marca, 15, stdin);
		printf ("Ano: ");
		scanf ("%d", &carros[i].ano);
		printf ("Preco: ");
		scanf ("%f", &carros[i].preco);	
		printf ("----------------------------------------\n");
	}
}

void imprime(Carro *carros, float preco){
	int i;
	
	for (i = 0; i < N; i++){
		if (carros[i].preco < preco){
			printf ("Carro %d\n", i+1);
			printf ("Marca: %s\n", carros[i].marca);
			printf ("Ano: %d\n", carros[i].ano);
			printf ("Preco: %.2f\n", carros[i].preco);
			printf ("-----------------------------------------\n\n");
		}
	}
	
}
