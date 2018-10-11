#include <stdio.h>

void Converte(int *Min){				//Funcao Converte(ponteiro *Min do tipo int)
	int H = *Min/60;					//Variavel H do tipo int recebe o o conteudo do ponteiro *Min/60
	int M = *Min%60;					//Variael H do tipo int recebe o resto da divisao do ponteiro *Min/60
	printf("HH:MM %d:%d\n", H,M);
}

int main(){
	printf("Desenvolvido por Ludwig Fonseca, Monitor da Disciplina Introdução a Informática para Automação, Algoritmos e Microprocessadores \n");
	printf("Este projeto serve apenas como exemplo \n\n");

	int Minutos;						//variavel minutos do tipo int
	printf("Informe os Minutos: "); 	//Informação para o usuario
	scanf("%d", &Minutos);				//Captura o valor informado pelo usuario e armazena na variavel minutos
	Converte(&Minutos);					//Chama funcao Converte(passa a variavel Minutos)
}
