#include <stdio.h>
#include <stdlib.h>

int *p;
int x;

int main() {
	x = 10;
	p = &x;
	x = 20;
	*p = 30;
	
	printf("x = %d - *p = %d\n\n", x, *p);
	printf("&x = %d - p = %d\n\n", &x, p);
}
