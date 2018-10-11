#include <stdio.h>
#include <stdlib.h>

int **Matriz(int Linha, int Coluna) {						//Funcao que retorna uma matriz alocada

	int **M = (int **)malloc(Linha * sizeof(int*));			//Aloca dinamicamente a linhas da matriz

	for (int i = 0; i < Linha; i++) {						//Percorre as linhas da matriz para aloca-las dinamicamente
		M[i] = (int *)malloc(Coluna * sizeof(int));			//Aloca dinamicamente as colunas da matriz
	}

	for(int i = 0; i < Linha; i++){
		for(int j = 0; j < Coluna; j++){
			M[i][j] = 0;
		}
	}
	return M;												//Retorna a matriz alocada dinamicamente
}

void Mostra(int **M, int qrow, int  qcol){
	for(int i = 0; i < qrow; i++){
		for(int j = 0; j < qcol; j++){
			printf("%d\t", M[i][j]);						//Mostra as informacoes da matriz
		}
		printf("\n");
	}
	printf("\n");
}


void Limpa(int **Matriz, int Linha){						//Desaloca dinamicamente a matriz
	for(int i = 0; i<Linha; i++){							//Percorre a matriz
		free(Matriz[i]);									//Libera espaco da memoria alocado pelas linhas da matriz
	}
	free(Matriz);											//Libera espaco alocado pela matriz
}

int main(){
	printf("Desenvolvido por Ludwig Fonseca, Monitor da Disciplina Introdução a Informática para Automação, Algoritmos e Microprocessadores \n");
	printf("Este projeto serve apenas como exemplo \n\n");


	int **MatrizA;													//Ponteiro para ponteiro, representacao de matriz
	int qrow = 0, qcol = 0;

	printf("Quantidade de Linhas: ");								//Informacao para o usuario
	scanf(" %d", &qrow);											//Captura informacao do usuario
	printf("Quantidade de Colunas: ");								//Informacao para o usuario
	scanf(" %d", &qcol);

	MatrizA = Matriz(qrow, qcol);									//Aloca dinamicamente a matriz

	printf("\n");

	Mostra(MatrizA, qrow, qcol);									//Mostra os elementos da matriz

	for(int i = 0; i < qrow; i++){									//Ira percorrer as linhas
		for(int j = 0; j < qcol; j++){								//Ira percorrer as colunas
			printf("Informe um valor Matriz[%d, %d]: ", i, j);		//Informacao passada para o usuario
			scanf(" %d", &MatrizA[i][j]);							//Recebe do usuario a quantidade de linhas
		}
	}

	printf("\n");

	Mostra(MatrizA, qrow, qcol);									//Mostra os elementos da matriz

	for(int i = 0; i < qrow; i++){
		Limpa(MatrizA, qrow);										//Libera espaco de memoria alocado pela matriz
	}
}
