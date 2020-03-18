#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int valor;
	struct no *fe;
	struct no *fd;
} Arvore;

Arvore *insere_arvore(Arvore *arv, int x) {
	if (arv == NULL) {
		arv = (Arvore *) malloc(sizeof(Arvore));
		arv->valor = x;
		arv->fd = NULL;
		arv->fe = NULL;
	} else {
		if (x < arv->valor) {
			arv->fe = insere_arvore(arv->fe, x);
		} else {
			arv->fd = insere_arvore(arv->fd, x);
		}
	}
	return arv;
}

void mostra_arvore(Arvore *arv, int nivel) {
	int i;
	if (arv != NULL) {
		for (i = 0; i < nivel * 5; i++) {
			if (i > nivel * 5 - 5) {
				printf("-");
			} else {
				printf("-");
			}
		}
		printf(">%d\n", arv->valor);
		nivel++;
		mostra_arvore(arv->fe, nivel);
		mostra_arvore(arv->fd, nivel);
	}
}

void libera_arvore(Arvore *arv) {
	if (arv->fe != NULL) {
		libera_arvore(arv->fe);
		arv->fe = NULL;
	}
	if (arv->fd != NULL) {
		libera_arvore(arv->fd);
		arv->fd = NULL;
	}

	if (arv->fe == NULL && arv->fd == NULL) {
		//printf("Liberando: %d\n",arv->valor);
		free(arv);
	}
}

Arvore *maior_valor(Arvore *arv) {
	if (arv->fd == NULL) {
		return arv;
	} else {
		return maior_valor(arv->fd);
	}
}

Arvore *menor_valor(Arvore *arv) {
	if (arv->fe == NULL) {
		return arv;
	} else {
		return menor_valor(arv->fe);
	}
}

int altura_arvore(Arvore *arv) {
	int esq, dir;
	if (arv == NULL)
		return -1;
	if (arv->fe == NULL && arv->fd == NULL) {
		return 0;
	}
	esq = altura_arvore(arv->fe);
	dir = altura_arvore(arv->fd);
	return esq > dir ? esq + 1 : dir + 1;
}

int estanaaervore(Arvore *arv, int x) {
	if (arv == NULL) {
		return 0;
	}

	if (arv->valor == x) {
		return 1;
	}

	if (x < arv->valor) {
		estanaaervore(arv->fe, x);
	} else {
		estanaaervore(arv->fd, x);
	}
}

void mostra_PREo(Arvore *arv) {
	if (arv == NULL) {
		return;
	}
	printf("%d ", arv->valor);
	mostra_PREo(arv->fe);
	mostra_PREo(arv->fd);
}

void mostra_Eo(Arvore *arv) {
	if (arv == NULL) {
		return;
	}
	mostra_Eo(arv->fe);
	printf("%d ", arv->valor);
	mostra_Eo(arv->fd);
}

void mostra_POSo(Arvore *arv) {
	if (arv == NULL) {
		return;
	}
	mostra_POSo(arv->fe);
	mostra_POSo(arv->fd);
	printf("%d ", arv->valor);
}

int main() {
	printf("Desenvolvido por Ludwig Fonseca, Monitor da Disciplina Introdução a Informática para Automação, Algoritmos e Microprocessadores \n");
	printf("Este projeto serve apenas como exemplo \n\n");

	int op, vl, vle;

	Arvore *a = NULL;

	while (op != 0) {
		printf("\n\n");
		printf("1 - insere na arvore\n");
		printf("2 - mostra arvore\n");
		printf("3 - maior valor\n");
		printf("4 - menor valor\n");
		printf("5 - esta na arvore\n");
		printf("6 - pre ordem\n");
		printf("7 - em ordem\n");
		printf("8 - pos ordem\n");
		printf("9 - altura arvore\n");
		printf("10 - libera arvore\n");
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
			a = insere_arvore(a, vl);
			break;
		case 2:
			printf("\n");
			mostra_arvore(a, 1);
			break;
		case 3:
			printf("\nMaior %d\n", maior_valor(a)->valor);
			break;
		case 4:
			printf("\nMenor %d\n", menor_valor(a)->valor);
			break;
		case 5:
			printf("\ndigite um valor para verificar se esta na arvore: ");
			scanf(" %d", &vle);
			printf("\n");
			if (estanaaervore(a, vle) == 1) {
				printf("esta na arvore");
			} else {
				printf("nao esta na arvore");
			}
			break;
		case 6:
			printf("\n");
			mostra_PREo(a);
			break;
		case 7:
			printf("\n");
			mostra_Eo(a);
			break;
		case 8:
			printf("\n");
			mostra_POSo(a);
			break;
		case 9:
			printf("\n");
			printf("%d", altura_arvore(a));
			break;
		case 10:
			libera_arvore(a);
			a = NULL;
			break;
		default:
			printf("Valor indefinido\n");
			break;
		}
	}
}
