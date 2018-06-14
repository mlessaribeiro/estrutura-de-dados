#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 3

//int vetor[tamanho];
int vetor[tamanho] = {15, 3, 9};

void imprime_vetor() {
	printf("Imprimindo Vetor: ");
	for(int i = 0; i < tamanho; i++) {
		printf("%d ", vetor[i]);
	}
	printf("\n");	
}

int matriz[tamanho][tamanho];

void imprime_matriz() {
	printf("Imprimindo Matriz: \n");
	for(int i = 0; i < tamanho; i++) {
		for(int j = 0; j < tamanho; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

struct tipo_produto {
	char nome_produto[50];
	int quantidade;
};

tipo_produto produto;
tipo_produto produtos[tamanho];

void imprime_produtos() {
	printf("Lista de produtos\n");
	for(int i = 0; i < tamanho; i++) {
		printf("Valores do Produto - Nome: %s Quantidade: %d \n", produtos[i].nome_produto, produtos[i].quantidade);
	}	
}

int main() {
	printf("Exemplo Vetores\n");
	imprime_vetor();	
	vetor[0] = 10;
	imprime_vetor();	
	vetor[1] = 8;
	imprime_vetor();	
	printf("%d ", vetor[8]);
	printf("Exemplo Vetores\n");

	printf("Exemplo Matriz\n");
	imprime_matriz();
	matriz[0][1] = 22;
	imprime_matriz();
	matriz[1][1] = 15;
	imprime_matriz();
	printf("Exemplo Matriz\n");
		

	printf("Exemplo Registro\n");
	
	strcpy(produto.nome_produto, "Celular 123");
	produto.quantidade = 15;
	
	printf("Valores do Produto - Nome: %s Quantidade: %d \n", produto.nome_produto, produto.quantidade);
	
	
	strcpy(produtos[0].nome_produto, "Celular");
	produtos[0].quantidade = 3;
	strcpy(produtos[1].nome_produto, "TV");
	produtos[1].quantidade = 1;
	strcpy(produtos[2].nome_produto, "Geladeira");
	produtos[2].quantidade = 0;
	
	imprime_produtos();
	
	printf("Exemplo Registro\n");
}
