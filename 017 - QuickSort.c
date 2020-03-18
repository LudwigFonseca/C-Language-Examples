#include <stdio.h>

int separa(int v[], int p, int r) {
	int c = v[p], i = p + 1, j = r, t;
	while (i <= j) {
		if (v[i] <= c)
			++i;
		else if (c < v[j])
			--j;
		else {
			t = v[i], v[i] = v[j], v[j] = t;
			++i;
			--j;
		}
	}
	v[p] = v[j], v[j] = c;
	return j;
}

int *quicksort(int *v, int p, int r) {
	int j;
	if (p < r) {
		j = separa(v, p, r);
		quicksort(v, p, j - 1);
		quicksort(v, j + 1, r);
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

	quicksort(v, 0, n-1);

	printf("\nVetor ordenado\n");
	Mostra(v, n);
}
