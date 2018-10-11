#include <stdio.h>
#include <stdlib.h>

typedef struct{											//Cria tipo de variavel Info
	char Nome[50];										//Variavel nome
	int  Nota;											//Variavel nota
}Info;

int main(){
	printf("Desenvolvido por Ludwig Fonseca, Monitor da Disciplina Introdução a Informática para Automação, Algoritmos e Microprocessadores \n");
	printf("Este projeto serve apenas como exemplo \n\n");

	int n = 0;											//Variavel n do tipo int

	printf("Tamanho do vetor estruturado: ");			//Informacao par ao usuario
	scanf("%d", &n);									//Captura informacao do usuario

	Info *BD = (Info *)malloc(n*sizeof(Info));			//Vetor BD (de 5 posicoes) do tipo Info

	for(int i = 0; i < n; i++){							//Laço para repetir 5 vezes
		printf("Nome: ");								//Informação para o usuário
		scanf(" %[^\n]s", BD[i].Nome);					//Recebe o valor que usuario digitou, armazena no vetor BD (na posicao i)na struct Nome
		printf("Nota: ");								//Informação para o usuario
		scanf("%d", &BD[i].Nota);						//Recebo o valor que o usuario digitou, armazena no vetor BD (posicao i) na struct nota

	}
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("Nome: %s\t", BD[i].Nome);				//Informacao para o usuario
		printf("Nota: %d\t", BD[i].Nota);				//Informacao para o usuario
		printf("\n");
	}

	free(BD);											//Limpa a memoria
	printf("\n");
}
