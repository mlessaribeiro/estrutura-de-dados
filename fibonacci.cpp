#include<bits/stdc++.h>
int main(){
 
	unsigned long long int fib[65], dim, aux;
	scanf("%llu", &dim);
	memset(fib, sizeof(fib), 0);
	fib[0]=1;
	fib[1]=1;
		for (int i=2; i<60; i++)		fib[i]=fib[i-1]+fib[i-2];
		
	while(dim--){
		i=1;
		scanf("%llu",&aux);
		printf("%llu\n", fib[aux]);
	}
}
