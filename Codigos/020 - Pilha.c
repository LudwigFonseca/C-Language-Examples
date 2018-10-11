#include <stdio.h>
#include <stdlib.h>

typedef struct nopilha {
	int valor;
	struct nopilha *prox;
} NoPilha;

typedef struct {
	NoPilha *inicio;
	int nelem;
} Pilha;

Pilha *inicializa_pilha() {
	Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
	if (pilha == NULL) {
		printf("Erro ao tentar alocar memoria!\n");
		exit(EXIT_FAILURE);
	}
	pilha->inicio = NULL;
	pilha->nelem = 0;
	return pilha;
}

void push_pilha(Pilha *pilha, int v) {
	// alocar memoria para o novo n
	NoPilha *novo = (NoPilha *) malloc(sizeof(NoPilha));
	if (novo == NULL) {
		printf("Erro ao tentar alocar memoria!\n");
		exit(EXIT_FAILURE);
	}

	// armazenar os valores
	novo->valor = v;
	novo->prox = NULL;
	// ligar os ponteiros;
	if (pilha->inicio == NULL) {
		pilha->inicio = novo;
	} else {
		novo->prox = pilha->inicio;
		pilha->inicio = novo;
	}
	pilha->nelem++;
}

void mostra_pilha(NoPilha *ini) {
	printf("\n\n");
	NoPilha *aux = ini;
	while (aux != NULL) {
		printf("%d,", aux->valor);
		aux = aux->prox;
	}
	printf("\n\n");

}

int peek_pilha(Pilha *pilha) {
	if (pilha->nelem == 0) {
		printf("Fila vazia!\n");
		return -1;
	}
	return pilha->inicio->valor;
}

int pop_pilha(Pilha *pilha) {
	int toret = pilha->inicio->valor;
	if (pilha->nelem == 1) {
		free(pilha->inicio);
		pilha->inicio = NULL;
	} else {
		NoPilha *tofree = pilha->inicio;
		pilha->inicio = tofree->prox;
		free(tofree);
	}
	pilha->nelem--;
	return toret;

}

void libera_pilha(Pilha *pilha) {
	NoPilha *aux = pilha->inicio;
	while (aux != NULL) {
		NoPilha *tofree = aux;
		aux = aux->prox;
		free(tofree);
	}
	free(pilha);
}

int main() {
	printf("Desenvolvido por Ludwig Fonseca, Monitor da Disciplina Introdução a Informática para Automação, Algoritmos e Microprocessadores \n");
	printf("Este projeto serve apenas como exemplo \n\n");

	int op, vl;

	Pilha *p = inicializa_pilha();

	while (op != 0) {
		printf("\n\n");
		printf("1 - push pilha\n");
		printf("2 - mostra pilha\n");
		printf("3 - peek pilha\n");
		printf("4 - pop pilha\n");
		printf("5 - libera pilha\n");
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
			push_pilha(p, vl);
			break;
		case 2:
			mostra_pilha(p->inicio);
			break;
		case 3:
			printf("\n\n%d\n\n", peek_pilha(p));
			break;
		case 4:
			pop_pilha(p);
			break;
		case 5:
			libera_pilha(p);
			break;
		default:
			printf("Valor indefinido\n");
			break;
		}
	}
}
