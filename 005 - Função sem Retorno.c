#include <stdio.h>

typedef struct {										//Cria tipo de variavel
	char nme[50];										//Variável nme do tipo char
	char nsc[10];										//Variável nsc do tipo char
	char csa[1];										//Variável d csa do tipo char
	float rnd;											//Variável rnd do tipo float
} List;													//Tipo de variável List

void Print(List Pt_Info) {								//Função para mostrar informacoes
	printf("Nome: %s\t", Pt_Info.nme);					//Mostra o nome
	printf("Nascimento: %s\t", Pt_Info.nsc);			//Mostra a data de nascimento
	printf("Residencia Propia: %s\t", Pt_Info.csa);		//Mostra se tem casa propria ou nao
	printf("Renda: %.2f\t\n", Pt_Info.rnd);				//Mostra a renda
}

int main() {
	printf("Desenvolvido por Ludwig Fonseca, Monitor da Disciplina Introdução a Informática para Automação, Algoritmos e Microprocessadores \n");
	printf("Este projeto serve apenas como exemplo \n\n");

	List Info[2];										//Vetor de duas posicoes do tipo List

	for (int i = 0; i < 2; i++) {						//Ira percorrer duas vezes o vetor para poder preenche-lo
		printf("Nome Completo: ");						//Informacao ao usuario
		scanf(" %[^\n]s", Info[i].nme);					//Preenche o campo nome

		printf("Nascimento: ");							//Informacao ao usuario
		scanf(" %s", Info[i].nsc);						//Preenche o campo nascimento

		printf("Casa Propia: ");						//Informacao ao usuario
		scanf(" %s", Info[i].csa);						//Preenche o campo casa

		printf("Renda: ");								//Informacao ao usuario
		scanf(" %f", &Info[i].rnd);						//Preenche o campo renda
	}

	for (int i = 0; i < 2; i++) {						//Percore o vetor
		Print(Info[i]);									//Imprime as informacoes contidas no vetor
	}
}
