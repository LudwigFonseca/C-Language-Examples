#include <stdio.h>

void Mostra(int V[], int tam) {			//Mostra Vetor
	int i;								//Variavel i do tipo int
	printf("Elementos do Vetor: ");		//Informacao passada ao usuario
	for (i = 0; i < tam; i++) {			//Laco que se repetira n vezes para mostrar o vetor
		printf("%d ", V[i]);			//Sera mostrado o vetor da posição 1 a n
	}
	printf("\n");						//Informacao passada ao usuario
}

int Soma(int V[], int tam) {			//Soma vetor
	int i, Soma = 0;					//Variavel  i e soma do tipo int
	for (i = 0; i < tam; i++) {			//Laço que se repetira n vezes para somar os vetores
		Soma += V[i];					//Variavel soma recebe ela mesma mais o Vetor de 1 a n
	}
	return Soma;						//Retorna variavel Soma
}

int Maior(int V[], int tam) {			//Maior
	int i, Max = V[0];					//Variavel i e vetor V[0] (na posicao 0) do tipo int
	for (i = 1; i < tam; i++) {			//Laco que se repetira n vezes para vereficar o maior numero
		if (V[i] > Max) {				//Se o valor do vetor V (na posicao i) for maior que o vetor V (na posicao 0)
			Max = V[i];					//Variavel Max recebe o maior valor
		}
	}
	return Max;							//Retorna a variavel Max
}

int Menor(int V[], int tam) {			//Menor
	int i, Min = V[0];					//Variavel i e vetor V (na posicao 0) do tipo int
	for (i = 1; i < tam; i++) {			//Laco que se repetira n vezes para verificar o menor numero
		if (V[i] < Min) {				//Se o valor do vetor V (na posicao i) for menor que o vetor V (na posicao 0)
			Min = V[i];					//Variavel Min recebe o menor valor
		}
	}
	return Min;							//Retorna a variavel Min
}

int N_Par(int V[], int tam) {			//Numero de Par
	int i, Par = 0;						//Variavel i e Par do tipo int
	for (i = 0; i < tam; i++) {			//Laço de repetição que repetira n vezes para verificar se existe numero par
		if (V[i] % 2 == 0) {			//Se o valor do vetor V (na posição 0) tiver o resto da divisao igual a 0
			Par++;						//Variável Par recebe o valor dela mesma mais 1
		}
	}
	return Par;							//Retorna a variavel Par
}

int main() {
	printf("Desenvolvido por Ludwig Fonseca, Monitor da Disciplina Introdução a Informática para Automação, Algoritmos e Microprocessadores \n");
	printf("Este projeto serve apenas como exemplo \n\n");

	int aux = 0;											//Variavel aux do tipo int

	printf("Tamanho do Vetor: ");							//Informacao passada para o usuario
	scanf("%d", &aux);										//Recebe o que o usuario informou e

	int Vetor[aux];											//Vetor Vetor do tipo int com n posicoes para armazenar informacoes

	printf("\n");

	for (int i = 0; i < aux; i++) {							//Laço de repeticao para o usuario informar valores
		printf("Digite um Valor %d: ", i);					//Informacao passada para o usuario
		scanf("%d", &Vetor[i]);								//Recebe o que o usuario informou e armazena no vetor Vetor (na posicao i)
	}
	int tam = sizeof(Vetor)/sizeof(Vetor[0]);						//Calcula o tamanho do vetor

	Mostra(Vetor, tam);												//Mostra Vetor

	printf("\nSoma do Vetor: %d\n", Soma(Vetor, tam));				//Soma do Vetor

	printf("Media do Vetor: %.2f\n", (float) Soma(Vetor, tam)/aux);	//Media Vetor

	printf("Maior Elemento: %d\n", Maior(Vetor, tam));				//Maior

	printf("Menor Elemento: %d\n", Menor(Vetor, tam));				//Menor

	printf("Quantidade de Numero Par: %d\n ", N_Par(Vetor, tam));	//Numero de Par
}

