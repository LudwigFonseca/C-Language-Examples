#include <stdio.h>

int *bubblesort(int *v, int d) {
	int temp;

	for (int i = d - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {

			if (v[j] > v[j + 1]) {
				temp = v[j + 1];
				v[j + 1] = v[j];
				v[j] = temp;
			}
		}
	}
	return v;
}

void Mostra(int *V, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\t", V[i]);
	}
	printf("\n");
}

int main() {
	printf("Desenvolvido por Ludwig Fonseca, Monitor da Disciplina Introdução a Informática para Automação, Algoritmos e Microprocessadores \n");
	printf("Este projeto serve apenas como exemplo \n\n");

	int n;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);

	int v[n];

	printf("\nPreencha o vetor\n");
	for (int i = 0; i < n; i++) {
		printf("V[%d]: ", i);
		scanf("%d", &v[i]);
	}

	printf("\nVetor desordenado\n");
	Mostra(v, n);

	bubblesort(v, n);

	printf("\nVetor ordenado\n");
	Mostra(v, n);
}
