#include <stdio.h>
#include <stdlib.h>

#define tamanho 5

int main() {
	int matriz[2][7];
	
	matriz[0][0] = 9;
	matriz[0][1] = 4;
	matriz[0][2] = 8;
	matriz[0][3] = 10;
	matriz[0][4] = 10;
	matriz[0][5] = 10;
	matriz[0][6] = 7;
	matriz[1][0] = 9;
	matriz[1][1] = 4;
	matriz[1][2] = 8;
	matriz[1][3] = 10;
	matriz[1][4] = 10;
	matriz[1][5] = 10;
	matriz[1][6] = 7;

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 7; j++) {
			printf("i=%d j=%d - nota=%d \n", i, j, matriz[i][j]);	
		}
	}

	// i=0 j=0 nota=9
	// i=0 j=1 nota=4

	// for(int i = 0; i < tamanho; i++) {
	// 	for(int j = 0; j < tamanho; j++) {
	// 		printf("%d ", matriz[i][j]);	
	// 	}
	// 	printf("\n");
	// }
}
