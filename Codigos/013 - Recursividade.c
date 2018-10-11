#include <stdio.h>							//Recursividade

int Soma(int *V, int size){					//Função Soma (ponteiro V e variavel size do tipo int)
	if(size == 1){							//se size igual a 1
		return V[0];						//retorna o vetor V (na posição 0)
	}else{									//Se size diferente de 1
		return V[0] + Soma(V+1, size-1);	//retorna vetor V (na posição 0) + funcao Soma(valor do ponteiro P + 1, variavel size - 1)
	}
}

int main(){
	printf("Desenvolvido por Ludwig Fonseca, Monitor da Disciplina Introdução a Informática para Automação, Algoritmos e Microprocessadores \n");
	printf("Este projeto serve apenas como exemplo \n\n");

	int tam;														//Tamanho do Vetor

	printf("Informe o tamanho do vetor: "); 						//Informacao ao usuario
	scanf(" %d", &tam);												//Captura informacao do usuario

	int V[tam];														//Vetor de tamanho tam
	for(int i = 0; i < tam; i++){									//Percorre o vetor
		printf("Informe um valor %d: ", i);							//Informacao ao usuario
		scanf(" %d", &V[i]);										//Captura informacao do usuario
	}

	printf("Soma usando recursividade: %d\n", Soma(V,tam));			//Mostra o resultado de Soma(passa os Valores do vetor V, passa o tamanho do vetor V)
}
