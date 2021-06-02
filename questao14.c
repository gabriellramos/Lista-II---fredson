//questao 14
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int tipo;
	float largura, comprimento;
}Comodo;

float CalculaArea(float largura, float comprimento);
float Lampada(int tipo, float area);

int main(){
	Comodo comodo;
	float area, lampada;
	//laço sempre vai funcionar... 
	//condição de parada definida dentro do laço
	while(1){
		while (1){ //procura tipos de 0 a 4. se for diferente pede novamente
			printf ("Tipo (0 a 4 ou -1 p/ parar): ");
			scanf ("%d", &comodo.tipo);	
			if (comodo.tipo>= -1 && comodo.tipo<5) break;
		}
		
		if (comodo.tipo == -1) break;
		
		printf ("Largura: ");
		scanf ("%f", &comodo.largura);
		printf ("Comprimento: ");
		scanf ("%f", &comodo.comprimento);
		
		area = CalculaArea(comodo.largura, comodo.comprimento);
		lampada = ceil(Lampada(comodo.tipo, area));
		
		printf ("Numero de lampadas de 60W para o comodo: %.f\n\n", lampada);
	}
	
	return 0;
}

float CalculaArea(float largura, float comprimento){
	return largura*comprimento;
}

float Lampada(int tipo, float area){
	float potencia;
	
	switch(tipo){
		case 0: potencia = 12; break;
		case 1: potencia = 15; break;
		case 2: potencia = 18; break;
		case 3: potencia = 20; break;
		case 4: potencia = 22; break;
	}
	
	return area/potencia;
}
