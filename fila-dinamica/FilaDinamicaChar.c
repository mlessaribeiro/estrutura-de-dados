#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NO {
	char valor;
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
		printf("%c\n", ptr->valor);
		ptr = ptr->prox;
	}
}

void enfileira(char valor) {
	struct NO* ptr = (struct NO *) malloc(sizeof(struct NO));
	ptr->valor = valor;
	ptr->prox = NULL;
	if(f->inicio == NULL)
		f->inicio = ptr;
	else
		f->fim->prox = ptr;
	f->fim = ptr;
}

char desenfileira() {
	struct NO* ptr = f->inicio;
	char valor;
	if(ptr != NULL){
		f->inicio = ptr->prox;
		ptr->prox = NULL;
		valor = ptr->valor;
		free(ptr);
		return valor;
	}
}

int main() {
	
	f = (struct FILA *) malloc(sizeof(struct FILA));
	
	f->inicio = NULL;
	f->fim = NULL;
	
	enfileira('M');
	enfileira('a');
	enfileira('b');
	enfileira('c');

	
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
