#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NO {
	char valor;
	struct NO* prox;
} NO;

typedef struct PILHA {
	struct NO* topo;
} PILHA;

PILHA *p;

void imprimir(struct NO* ptr){
	system("cls");
	while(ptr != NULL){
		printf("%c\n", ptr->valor);
		ptr = ptr->prox;
	}
}

void empilha(char valor) {
	NO* ptr = (NO *) malloc(sizeof(NO));
	ptr->valor = valor;
	ptr->prox = p->topo;
	p->topo = ptr;
}

char desempilha() {
	NO* ptr = p->topo;
	char valor;
	if(ptr != NULL){
		p->topo = ptr->prox;
		ptr->prox = NULL;
		valor = ptr->valor;
		free(ptr);
		return valor;
	}
}

int main() {
	
	p = (struct PILHA *) malloc(sizeof(struct PILHA));
	
	p->topo = NULL;
	
	empilha('M');
	empilha('P');
	empilha('M');
	
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
