#include <stdio.h>
#include <string.h>

typedef struct {									//Typedef (cria um novo tipo de variavel)
	char nome[50];									//Variavel do nome do tipo char
	int media;										//Variavel do media do tipo int
} Aluno;											//Novo identificador de variavel

int main() {
	printf("Desenvolvido por Ludwig Fonseca, Monitor da Disciplina Introdução a Informática para Automação, Algoritmos e Microprocessadores \n");
	printf("Este projeto serve apenas como exemplo \n\n");

	int temp = 0, aux = 0;							//Variavel  max e temp do tipo int

	printf("Informe a quantidade de iteracoes: ");	//Informacao ao usuario
	scanf("%d", &aux);								//Recebe do usuario a quantidade de iteracoes

	Aluno Info[aux];								//Vetor Info com n posições do tipo Aluno que e uma struct

	for (int i = 0; i < aux; i++) {					//Laco para repetir n vezes
		printf("Digite o nome: ");					//Informação para o usuario
		scanf(" %[^\n]s", Info[i].nome);			//Captura o que o usuario digitou e armazena no vetor Info (na posicao i) na struct nome
		printf("Informe a media: "); 				//Informacao para o usuario
		scanf("%d", &Info[i].media);				//Captura o que o usuario digitou e armazena no vetor Info (na posicao i) na struct media
	}

	for (int i = 0; i < aux; i++) {					//Laço para repetir n vezes
		if (Info[i].media > Info[temp].media) {		//Procura a maior media
			temp = i;
		}
	}

	printf("\n%s\t", Info[temp].nome);				//Imprime o nome
	printf("%d\n", Info[temp].media);				//Imprime a media

}
