#include <stdio.h>
#include <math.h>

typedef struct{															//Cria tipo de variavel Point
	float x, y;															//Variavel x y do tipo float
}Point;

float Comprimento(Point *P1, Point *P2){								//Funçao que retorna o valor do comprimento entre os pontos
	float Comp = sqrt(pow(P1->x - P2->x,2) + pow(P1->y - P2->y,2));		//Teorema de pitagoras
	return Comp;
}

int main(){
	printf("Desenvolvido por Ludwig Fonseca, Monitor da Disciplina Introdução a Informática para Automação, Algoritmos e Microprocessadores \n");
	printf("Este projeto serve apenas como exemplo \n\n");

	int i;																//Variavel do i do tipo i
	Point P[2];															//Variavel P (de 2 posicoes) do tipo Point

	for(i = 0; i < 3; i++){												//Laco que repetira 3 vezes
		printf("Informe X%d: ", i);										//Informacao para o usuario
		scanf("%f", &P[i].x);											//Captura o valor informado pelo usuario e armazena no vetor P (na posicao i) na struct x
		printf("Informe Y%d: ", i);										//Informacao para o usuario
		scanf("%f", &P[i].y);											//Captura o valor informado pelo usuario e armazena no vetor P (na posicao i) na struct y
	}

	printf("Comprimento entre P0 e P1: %.2f\n", Comprimento(&P[0],&P[1]));	//Comprimento entre os pontos P0 e P1
	printf("Comprimento entre P1 e P2: %.2f\n", Comprimento(&P[1],&P[2]));	//Comprimento entre os pontos P1 e P2
	printf("Comprimento entre P2 e P0: %.2f\n", Comprimento(&P[2],&P[0]));	//Comprimento entre os pontos P2 e P0
}
