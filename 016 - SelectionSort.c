#include <stdio.h>

int *selectionsort(int *v, int n) {
	for (int i = 0; i < n - 1; ++i) {
		int min = i;
		for (int j = i + 1; j < n; ++j)
			if (v[j] < v[min])
				min = j;
		int x = v[i];
		v[i] = v[min];
		v[min] = x;
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

	selectionsort(v, n);

	printf("\nVetor ordenado\n");
	Mostra(v, n);
}
