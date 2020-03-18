#include <stdio.h>
#include <stdlib.h>

typedef struct _nolista {
	int valor;
	struct _nolista *prox;
} NoLista;

typedef struct {
	NoLista *inicio;
	int nlem;
} Lista;

Lista *inicializa_lista() {
	Lista *lista = (Lista *) malloc(sizeof(Lista));
	if (lista == NULL) {
		printf("Erro ao tentar alocar memoria!\n");
		exit(1);
	}
	lista->inicio = NULL;
	lista->nlem = 0;
	return lista;
}

void insere_lista(Lista *lista, int v) {

	NoLista *novo = (NoLista *) malloc(sizeof(NoLista));
	if (novo == NULL) {
		printf("Erro ao tentar alocar memoria!\n");
		exit(1);
	}
	novo->valor = v;
	novo->prox = NULL;

	if (lista->inicio == NULL) {
		lista->inicio = novo;
	} else {
		NoLista *atual = lista->inicio;
		while (atual->prox != NULL) {
			atual = atual->prox;
		}
		atual->prox = novo;
	}
	lista->nlem++;
}

void mostra_lista(Lista *lista) {
	NoLista *atual = lista->inicio;
	while (atual != NULL) {
		printf("%d,", atual->valor);
		//printf("mostrou valor %p\n", atual);
		atual = atual->prox;
	}
	printf("\n");
}

void libera_lista(Lista *lista) {
	NoLista *atual = lista->inicio;
	while (atual != NULL) {
		NoLista *n = atual;
		atual = atual->prox;
		//printf("liberando %p\n", n);
		free(n);
	}
	free(lista);
}

void remove_valor_lista(Lista *lista, int v) {
	NoLista *atual = lista->inicio, *ant = NULL;
	while (atual != NULL) {
		if (atual->valor == v) {
			NoLista *excluir = atual;
			if (atual == lista->inicio) {
				lista->inicio = lista->inicio->prox;
			} else {
				ant->prox = atual->prox;
			}
			ant = atual;
			atual = atual->prox;

			free(excluir);
			lista->nlem--;
		} else {
			ant = atual;
			atual = atual->prox;
		}
	}
}

int main() {
	printf("Desenvolvido por Ludwig Fonseca, Monitor da Disciplina Introdução a Informática para Automação, Algoritmos e Microprocessadores \n");
	printf("Este projeto serve apenas como exemplo \n\n");

	int op, vl, vlr;

	Lista *l = inicializa_lista();

	while (op != 0) {
		printf("\n\n");
		printf("1 - insere lista\n");
		printf("2 - mostra lista\n");
		printf("3 - remove lista\n");
		printf("4 - libera lista\n");
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
			insere_lista(l, vl);
			break;
		case 2:
			printf("\n");
			mostra_lista(l);
			break;
		case 3:
			printf("\ndigite um valor para ser removido: ");
			scanf(" %d", &vlr);
			remove_valor_lista(l, vlr);
			break;
		case 4:
			libera_lista(l);
			break;
		default:
			printf("Valor indefinido\n");
			break;
		}
	}
}
