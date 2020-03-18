#include <stdio.h>

int main() {
	printf("Desenvolvido por Ludwig Fonseca, Monitor da Disciplina Introdução a Informática para Automação, Algoritmos e Microprocessadores \n");
	printf("Este projeto serve apenas como exemplo \n\n");

	int A = 0, B = 0, i;						//Variavel do A B do tipo int

	//Vetor A
	printf("Digite o Tamanho do Vetor A ");		//Informacao para o usuario
	scanf("%d", &A);							//Captura o valor que o usuario informou e armazena na variavel A

	int V1[A];									//Vetor V1 do tipo inteiro com A posicoes

	for (i = 0; i < A; i++) {					//Laço para repetir A vezes para o usuario informar valores
		printf("V1[%d]: ", i);					//Informacao para o usuario
		scanf("%d", &V1[i]);					//Captura o valor que o usuario digitou e armazena no vetor V1 (na posicao i)
	}

	//Vetor B
	printf("Digite o Tamanho do Vetor B ");		//Informacao para o usuario
	scanf("%d", &B);							//Captura o valor que o usuario informou e armazena na variavel B

	int V2[B];									//Vetor V1 do tipo inteiro com A posicoes

	for (i = 0; i < B; i++) {					//Laço para repetir A vezes para o usuario informar valores
		printf("V2[%d]: ", i);					//Informacao para o usuaio
		scanf("%d", &V2[i]);					//Captura o valor que o usuario digitou e armazena no vetor V1 (na posicao i)
	}

	int sum = A + B;							//Soma o tamanho do Vetor A com o tamanho do Vetor B
	int V3[sum];								//Cria um vetor com o tamanho sendo resultado da soma do tamanho do vetor A e B

	for (i = 0; i < sum; i++) {					//Percorre o vetor V3
		V3[i] = V1[i];							//Armazena nas primeiras posicoes do vetor V3 os valores do vetor V1 ate tamanho do vetor V1 menos 1 (A-1)
		if (i > (A - 1)) {						//Quando o vetor V3 ja foi preenchico com o vetor V1
			V3[i] = V2[i - A];					//Armazena no vetor V3 os valores do vetor V2 até tamanho do vetor V2 menos 1 (B-1)
		}
	}

	for (i = 0; i < sum; i++) {					//Percorre o vetor V3
		printf("V3: %d\n", V3[i]);				//Imprime o vetor V3
	}
}

