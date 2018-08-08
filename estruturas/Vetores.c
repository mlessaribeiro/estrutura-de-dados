#include <stdio.h>
#include <stdlib.h>

#define tamanho 7

int main() {
	int notas_alunos[tamanho];
	
	notas_alunos[0] = 9;
	notas_alunos[1] = 4;
	notas_alunos[2] = 8;
	notas_alunos[3] = 10;
	notas_alunos[4] = 10;
	notas_alunos[5] = 10;
	notas_alunos[6] = 7;


	int i;
	for(i = 0; i < tamanho; i++) {
		printf("%d ", i);
		printf("%d \n", notas_alunos[i]);	
	}
	printf("\n\n");
	for(i = 0; i < tamanho; i++) {
		if (notas_alunos[i] >= 7) {
			printf("Aprovado: %d - %d \n", i, notas_alunos[i]);	
		} else {
			printf("Reprovado: %d - %d \n", i, notas_alunos[i]);
		}
	}
}

