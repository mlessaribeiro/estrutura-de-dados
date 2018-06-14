#include <stdio.h>
#include <stdlib.h>

#define tamanho 5

int main() {
	int matriz[tamanho][tamanho];
	
	matriz[0][0] = 5;
	
	printf("%d ", matriz[0][0]);
	
	for(int i = 0; i < tamanho; i++) {
		for(int j = 0; j < tamanho; j++) {
			matriz[i][j] = 5;
		}
	}

	for(int i = 0; i < tamanho; i++) {
		for(int j = 0; j < tamanho; j++) {
			printf("%d ", matriz[i][j]);	
		}
		printf("\n");
	}
}
