#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int valor;
	struct no *prox;
} NoFila;

typedef struct {
	NoFila *inicio, *fim;
	int nelem;
} Fila;

typedef struct _data {
	int Value;
	struct _data *next;
} Data;

typedef struct {
	Data *head;
	Data *tail;
	int size;
} Queue;

Fila *inicializa_fila() {
	Fila *fila = (Fila *) malloc(sizeof(Fila));
	if (fila == NULL) {
		printf("Erro ao tentar alocar memoria!\n");
		exit(1);
	}
	fila->inicio = NULL;
	fila->fim = NULL;
	fila->nelem = 0;
	return fila;
}

void push_fila(Fila *fila, int v) {
	// alocar memoria para o novo n?
	NoFila *novo = (NoFila *) malloc(sizeof(NoFila));
	if (novo == NULL) {
		printf("Erro ao tentar alocar memoria!\n");
		exit(1);
	}

	// armazenar os valores
	novo->valor = v;
	novo->prox = NULL;
	// ligar os ponteiros;
	if (fila->inicio == NULL) {
		fila->inicio = novo;
		fila->fim = novo;
	} else {
		NoFila *ult = fila->fim;
		ult->prox = novo;
		fila->fim = novo;
	}
	fila->nelem++;
}

void mostra_fila(NoFila *ini) {
	printf("\n\n");
	NoFila *aux = ini;
	while (aux != NULL) {
		printf("%d,", aux->valor);
		aux = aux->prox;
	}
	printf("\n\n");

}

int peek_fila(Fila *fila) {
	if (fila->nelem == 0) {
		printf("Fila vazia!\n");
		return -1;
	}
	return fila->inicio->valor;
}

int pop_fila(Fila *fila) {
	int toret = fila->inicio->valor;
	if (fila->nelem == 1) {
		free(fila->inicio);
		fila->inicio = NULL;
		fila->fim = NULL;
	} else {
		NoFila *tofree = fila->inicio;
		fila->inicio = tofree->prox;
		free(tofree);
	}
	fila->nelem--;
	return toret;

}

void libera_fila(Fila *fila) {
	NoFila *aux = fila->inicio;
	while (aux != NULL) {
		NoFila *tofree = aux;
		aux = aux->prox;
		free(tofree);
	}
}

int main() {
	printf("Desenvolvido por Ludwig Fonseca, Monitor da Disciplina Introdução a Informática para Automação, Algoritmos e Microprocessadores \n");
	printf("Este projeto serve apenas como exemplo \n\n");

	int op, vl;

	Fila *f = inicializa_fila();

	while (op != 0) {
		printf("\n\n");
		printf("1 - push fila\n");
		printf("2 - mostra fila\n");
		printf("3 - peek fila\n");
		printf("4 - pop fila\n");
		printf("5 - libera fila\n");
		printf("0 - sair\n");
		printf("Escolha uma opcao: ");
		scanf(" %d", &op);

		if (op == 0) {
			printf("\n");
			printf("Terminou\n");
			break;
		}

		switch (op) {
		case 1:
			printf("\ndigite um valor: ");
			scanf(" %d", &vl);
			push_fila(f, vl);
			break;
		case 2:
			mostra_fila(f->inicio);
			break;
		case 3:
			printf("\n\n%d\n\n", peek_fila(f));
			break;
		case 4:
			pop_fila(f);
			break;
		case 5:
			libera_fila(f);
			break;
		default:
			printf("Valor indefinido\n");
			break;
		}
	}
}
