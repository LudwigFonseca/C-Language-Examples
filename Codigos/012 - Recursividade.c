#include <stdio.h>						//Recursividade

int X(int n){							//Função X(variavel n do tipo int)
	if(n==2 || n==1){					//Se n é igual a 1 ou 2 retorna ela mesma
		return n;
	}else{								//Se nao for chama a funcao X(n - 1) + (n * X(n - 2))
		return X(n-1) + n * X(n-2);
	}
}

int main(){
	printf("Desenvolvido por Ludwig Fonseca, Monitor da Disciplina Introdução a Informática para Automação, Algoritmos e Microprocessadores \n");
	printf("Este projeto serve apenas como exemplo \n\n");

	int n= 0 ;
	printf("Digite um valor: ");
	scanf(" %d", &n);

	printf("%d\n", X(n));				//Mostra o Resultado
}
