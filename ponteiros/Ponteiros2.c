#include <stdio.h>
#include <stdlib.h>

int main() {
	int *p;
	p = (int *) malloc(4);
	if (p == NULL) {
		printf("Erro!\n");
	}
	else {
		*p = 10;
		printf("p: %d\n", *p);
		free(p);
	}	
}
