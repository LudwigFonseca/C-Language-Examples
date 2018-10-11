/*	Crie uma estrutura ponto contendo os campos x e y, coordenadas de um ponto dadas por
*	valores reais. Declare as variaveis p1 e p2 (dois pontos), preencha os campos para cada
*	variavel, via teclado, e calcule a distancia (euclidiana) entre p1 e p2 através de uma função.
*/
#include <stdio.h>
#include <math.h>

typedef struct {															//Cria tipo de variavel
	float x, y;																//Variavel x y do tipo float
} Pontos;																	//Tipo de variavel

int main() {
	printf("Desenvolvido por Ludwig Fonseca, Monitor da Disciplina Introdução a Informática para Automação, Algoritmos e Microprocessadores \n");
	printf("Este projeto serve apenas como exemplo \n\n");

	Pontos p1, p2;															//Variavel p1 e p2 do tipo pontos que sao uma struct

	printf("P1 X ");														//Informação para o usuario
	scanf("%f", &p1.x);														//Captua o valor informado pelo usuario
	printf("P1 Y ");														//Informação para o usuario
	scanf("%f", &p1.y);														//Captura o valor informado pelo usuario

	printf("P2 X ");														//Informação para o usuario
	scanf("%f", &p2.x);														//Captura o valor informado pelo usuario
	printf("P2 Y ");														//Informação para o usuario
	scanf("%f", &p2.y);														//Captura o valor informado pelo usuario

	printf("\n");
	printf("%.2f\t\n", sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2))); 	//Mostra o resultado do teorema de pitagoras aplicado aos valores informados  sqrt eh a formula de raiz quadrada.

}
