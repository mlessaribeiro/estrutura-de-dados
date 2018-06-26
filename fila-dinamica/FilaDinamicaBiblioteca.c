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

typedef struct FILA {
	struct NO* inicio;
	struct NO* fim;
} FILA;

struct FILA *f;

void imprimir(struct NO* ptr){
	system("cls");
	while(ptr != NULL){
		printf("%d - %s\n", ptr->livro.isbn, ptr->livro.autor);
		ptr = ptr->prox;
	}
}

void enfileira(int isbn, char autor[]) {
	struct NO* ptr = (struct NO *) malloc(sizeof(struct NO));
	ptr->livro.isbn = isbn;
	strcpy(ptr->livro.autor, autor);
	ptr->prox = NULL;
	if(f->inicio == NULL)
		f->inicio = ptr;
	else
		f->fim->prox = ptr;
	f->fim = ptr;
}

struct TIPO_LIVRO desenfileira() {
	struct NO* ptr = f->inicio;
	struct TIPO_LIVRO livro;
	if(ptr != NULL){
		f->inicio = ptr->prox;
		ptr->prox = NULL;
		livro.isbn = ptr->livro.isbn;
		strcpy(livro.autor, ptr->livro.autor);
		free(ptr);
		return livro;
	}
}

int main() {
	
	f = (struct FILA *) malloc(sizeof(struct FILA));
	
	f->inicio = NULL;
	f->fim = NULL;
	
	enfileira(1234, "Maria");
	enfileira(4321, "Pedro");
	enfileira(5679, "Marcelo");
	
	struct NO *it = f->inicio;
	imprimir(it);
	system("pause");
	
	desenfileira();
		
	it = f->inicio;
	imprimir(it);
	system("pause");
	
	desenfileira();
	
	it = f->inicio;
	imprimir(it);
	system("pause");
	
	desenfileira();
	
	it = f->inicio;
	imprimir(it);
	system("pause");
	
	desenfileira();
	
	it = f->inicio;
	imprimir(it);
}
