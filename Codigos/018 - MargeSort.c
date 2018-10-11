#include <stdio.h>
#include <stdlib.h>

void intercala(int p, int q, int r, int v[]) {
	int *w = (int *)malloc((r - p)*sizeof(int));
	int i = p, j = q;
	int k = 0;

	while (i < q && j < r) {
		if (v[i] <= v[j])
			w[k++] = v[i++];
		else
			w[k++] = v[j++];
	}
	while (i < q)
		w[k++] = v[i++];
	while (j < r)
		w[k++] = v[j++];
	for (i = p; i < r; ++i)
		v[i] = w[i - p];
	free(w);
}

int *mergesort(int p, int r, int *v) {
	if (p < r - 1) {
		int q = (p + r) / 2;
		mergesort(p, q, v);
		mergesort(q, r, v);
		intercala(p, q, r, v);
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

	mergesort(0, n, v);

	printf("\nVetor ordenado\n");
	Mostra(v, n);
}
