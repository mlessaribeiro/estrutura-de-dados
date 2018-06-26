#include <stdio.h>
#include <stdlib.h>

#define maximo 10

int ma[maximo][maximo];
int tamanho = 5;

void inserir_aresta(int num1, int num2){
	if(num1 > tamanho-1 || 
	   num2 > tamanho-1 || 
	   num1 < 0 || num2 < 0){
		printf("Erro!");
		system("pause");
	}
	else
	{
		ma[num1][num2] = 1;
		ma[num2][num1] = 1;
	}
}

void remover_aresta(int num1, int num2){
	if(num1 > tamanho-1 || 
	   num2 > tamanho-1 || 
	   num1 < 0 || num2 < 0){
		printf("Erro!");
		system("pause");
	}
	else
	{
		ma[num1][num2] = 0;
		ma[num2][num1] = 0;
	}
}

void exibir_ma(){
	printf("Matriz de arestas:\n");
	int i;
	for(i=0; i<tamanho; i++){
		printf("[ ");
		int j;
		for(j=0; j<tamanho; j++)
		{
			printf("%d ", ma[i][j]);
		}
		printf("]\n");
	}
}

int main(){
	exibir_ma();
	
	inserir_aresta(0,2);
	inserir_aresta(1,2);
	inserir_aresta(1,3);
	inserir_aresta(2,4);
	
	exibir_ma();
	system("pause");
	
	printf("Removendo aresta 0-2...\n");
	remover_aresta(0,2);
	exibir_ma();
	system("pause");
	
	printf("Removendo aresta 1-2...\n");
	remover_aresta(1,2);
	exibir_ma();
	system("pause");
	
	printf("Removendo aresta 1-3...\n");
	remover_aresta(1,3);
	exibir_ma();
	system("pause");
	
	printf("Removendo aresta 2-4...\n");
	remover_aresta(2,4);
	exibir_ma();
	system("pause");
	
}
