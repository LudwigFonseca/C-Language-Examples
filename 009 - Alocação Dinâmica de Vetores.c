#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("Desenvolvido por Ludwig Fonseca, Monitor da Disciplina Introdução a Informática para Automação, Algoritmos e Microprocessadores \n");
	printf("Este projeto serve apenas como exemplo \n\n");

	int n, i;									//Variavel n v i do tipo int

	printf("Informe o tamanho do vetor: ");		//Informacao para o usuario
	scanf("%d", &n);							//Captura o valor informado pelo usuario

	int *p = (int *)malloc(n*sizeof(int));		//Cria ponteiro p e ele recebe o valor de 4bits vezes n para alocalo dinamicamente

	for (i=0; i < n; i++){						//Laço que repetira n vezes
		printf("Valor %d: ", i);				//Informação para o usuário
		scanf("%d", p + i);						//Captura o valor informado pelo usuário e armazena no ponteiro p (na posicao i)
	}

	for(i=n-1; i>=0; i--){						//Laço que repetira ate 0
		printf("%d\t", *(p+i));					//Mostra o valor do ponteiro p (na posicao 0 + 1)
	}

	free(p);									//Limpa as informacoes do ponteiro p

	printf("\n");
}

