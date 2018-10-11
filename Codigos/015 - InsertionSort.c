#include <stdio.h>

int *insertionsort(int *v, int n) {
	for (int j = 1; j < n; ++j) {
		int x = v[j];
		int i;
		for (i = j - 1; i >= 0 && v[i] > x; --i)
			v[i + 1] = v[i];
		v[i + 1] = x;
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

	insertionsort(v, n);

	printf("\nVetor ordenado\n");
	Mostra(v, n);
}
