#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 3

struct tipo_livro {
	int isbn;
	char autor[50];	
};

struct tipo_fila {
	struct tipo_livro livros[tamanho];
	int ini;
	int fim;
};

tipo_fila fila;

void enfileira(int isbn, char autor[]) {
	if(fila.fim == tamanho) {
		printf("Fila cheia.\n");
		system("pause");
	} else {
		fila.livros[fila.fim].isbn = isbn;
		strcpy(fila.livros[fila.fim].autor, autor);
		fila.fim++;
	}
}

tipo_livro desenfileira(){
	tipo_livro livro;
	if(fila.fim == fila.ini) {
		printf("Fila vazia.\n");
		system("pause");
	} else {
		livro.isbn = fila.livros[fila.ini].isbn;
		strcpy(livro.autor, fila.livros[fila.ini].autor);
		for(int i = 0; i < tamanho - 1; i++) {
			fila.livros[i].isbn = fila.livros[i+1].isbn;
			strcpy(fila.livros[i].autor, fila.livros[i+1].autor);			
		}
		fila.fim--;
		return livro;
	}
}

void imprime_fila() {
	printf("Imprimindo os valores da Fila: \n");
	for(int i = 0; i < fila.fim; i++) {
		printf("%d - %s\n", fila.livros[i].isbn, fila.livros[i].autor);
	}
	printf("\n");
}

int main() {
	fila.fim = 0;
	fila.ini = 0;
	
	printf("Testando fila de tamanho 3...\n\n");
	printf("Enfileirando o 10.\n");
	enfileira(10, "Maria");
	imprime_fila();
	printf("Enfileirando o 20.\n");
	enfileira(20, "Pedro");
	imprime_fila();
	printf("Enfileirando o 30.\n");
	enfileira(30, "Marcelo");
	imprime_fila();
	printf("Enfileirando o 40.\n");
	enfileira(40, "Fabio");
	imprime_fila();
	
	printf("Tentando desenfileirar 3x seguidas.\n");
	desenfileira();
	imprime_fila();
	desenfileira();
	imprime_fila();
	desenfileira();
	imprime_fila();
}

