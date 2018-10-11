#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("Desenvolvido por Ludwig Fonseca, Monitor da Disciplina Introdução a Informática para Automação, Algoritmos e Microprocessadores \n");
	printf("Este projeto serve apenas como exemplo \n\n");

	printf("----QUESTAO1-------\n");
	int *p = (int *)malloc(3*sizeof(int));
	p[0] = 10;
	p[1] = 3;

	printf("A: %p\t, %p\n", p, p++ ); 		//aponta para o proximo endereço de memoria p++ p=01 -> p=02
	printf("B: %d\n", 		(*p)++ ); 		//somará 1 ao conteudo de p
	printf("C: %d\n", 		*(p++) ); 		//aponta para o próximo endereço e mostra o conteudo
	printf("----------------------");

	printf("----QUESTAO2-------\n");
	int *pulo;
	pulo = (int *)malloc(sizeof(int));
	pulo[2]=10;

	printf("a: %d\n", *(pulo+2) ); 			//aponta para 3º posicao do vetor p e mostra o conteudo
	printf("b: %d\n", *(pulo+4) ); 			//aponta para 5º posicao do vetor p e mostra o conteudo
	printf("c: %p\n",   pulo+4  ); 			//aponta para 5º endereço de memoria
	printf("d: %p\n",   pulo+2  ); 			//aponta para 3º endereço de memoria
	printf("-------------------");

	printf("----QUESTAO3-------\n");
	int y, x;
	y = 0;
	p = &y; 								//p recebe o endereço de y
	x = *p;									//x recebe o valor aonde p aponta
	x = 4;  								//x recebe 4
	(*p)++; 								//aonde p aponta recebe 1, y=1
	x--;	    							//subtrai 1 em x, x=3
	(*p) += x;  							//aonde p aponta ira receber o valor que tem mais o de x *p = *p + x = 4
	printf("y = %d\n", y);
	printf("-------------------");
}
