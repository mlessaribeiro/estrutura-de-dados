#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 3

struct tipo_livro {
	int isbn;
	char autor[50];	
};

struct tipo_pilha {
	struct tipo_livro livros[tamanho];
	int ini;
	int topo;
};

tipo_pilha pilha;

void empilha(int isbn, char autor[]) {
	if(pilha.topo == tamanho) {
		printf("Pilha cheia.\n");
		system("pause");
	} else {
		pilha.livros[pilha.topo].isbn = isbn;
		strcpy(pilha.livros[pilha.topo].autor, autor);
		pilha.topo++;
	}
}

tipo_livro desempilha(){
	tipo_livro livro;
	if(pilha.topo == pilha.ini) {
		printf("Pilha vazia.\n");
		system("pause");
	} else {
		pilha.topo--;
		livro.isbn = pilha.livros[pilha.topo].isbn;
		strcpy(livro.autor, pilha.livros[pilha.topo].autor);
		return livro;
	}
}

void imprime_livro(tipo_livro livro) {
	printf("Valor do Livro: %s - %d \n", livro.autor, livro.isbn);
}

void imprime_pilha() {
	printf("Imprimindo valores em Pilha: \n");
	for(int i = pilha.topo - 1; i >= pilha.ini; i--) {
		imprime_livro(pilha.livros[i]);
	}
	printf("\n");
}

int main() {
	pilha.topo = 0;
	pilha.ini = 0;

	empilha(1234, "Maria");
	imprime_pilha();	

	empilha(5678, "Jose");
	imprime_pilha();	

	empilha(9876, "Joao");
	imprime_pilha();	
	
	desempilha();
	imprime_pilha();	

	desempilha();
	imprime_pilha();	

	desempilha();
	imprime_pilha();	

	desempilha();
	imprime_pilha();	
}
