#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TIPO_LIVRO {
	int isbn;
	char autor[50];	
} TIPO_LIVRO;

typedef struct NO {
	struct TIPO_LIVRO livro;
	struct NO* prox;
} NO;

typedef struct PILHA {
	struct NO* topo;
} PILHA;

PILHA *p;

void imprimir(struct NO* ptr){
	system("cls");
	while(ptr != NULL){
		printf("%d - %s\n", ptr->livro.isbn, ptr->livro.autor);
		ptr = ptr->prox;
	}
}

void empilha(int isbn, char autor[]) {
	NO* ptr = (NO *) malloc(sizeof(NO));
	ptr->livro.isbn = isbn;
	strcpy(ptr->livro.autor, autor);
	ptr->prox = p->topo;
	p->topo = ptr;
}

struct TIPO_LIVRO desempilha() {
	struct TIPO_LIVRO livro;
	NO* ptr = p->topo;
	if(ptr != NULL){
		p->topo = ptr->prox;
		ptr->prox = NULL;
		livro.isbn = ptr->livro.isbn;
		strcpy(livro.autor, ptr->livro.autor);
		free(ptr);
		return livro;
	}
}

int main() {
	
	p = (struct PILHA *) malloc(sizeof(struct PILHA));
	
	p->topo = NULL;
	
	empilha(1234, "Maria");
	empilha(4321, "Pedro");
	empilha(5679, "Marcelo");
	
	NO *it = p->topo;
	imprimir(it);
	system("pause");
	
	desempilha();
		
	it = p->topo;
	imprimir(it);
	system("pause");
	
	desempilha();
	
	it = p->topo;
	imprimir(it);
	system("pause");
	
	desempilha();
	
	it = p->topo;
	imprimir(it);
	system("pause");
	
	desempilha();
	
	it = p->topo;
	imprimir(it);
}
