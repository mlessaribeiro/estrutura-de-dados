#include <stdio.h>
#include <stdlib.h>

#define tamanho 5

int main() {
	int notas_alunos[tamanho];
	
	notas_alunos[0] = 100;
	notas_alunos[1] = 99;
	notas_alunos[2] = 58;
	
	for(int i = 0; i < tamanho; i++) {
		printf("%d ", i);
		printf("%d ", notas_alunos[i]);	
	}
	printf("\n\n");
	for(int i = 0; i < tamanho; i++) {
		if (notas_alunos[i] > 70) {
			printf("%d ", notas_alunos[i]);	
		}
	}
}

