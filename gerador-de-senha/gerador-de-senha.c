#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct TIPO_POST {
	char titulo[50];
	char conteudo[200];
}TIPO_POST;

void inicializarVariaveis() {
	setlocale(LC_ALL, "Portuguese");	
}

void limparConsole() {
	system("cls");
}

void limparBufferEntrada() {
	setbuf(stdin, NULL);
}

int menuInicial() {
	int esc = 0;
	printf("Escolha uma op��o!!!\n");
    printf("1 - Pegar proximo numero\n");
    printf("2 - Chamar proximo numero da fila\n");
    printf("3 - Sair\n\nR:  ");
    scanf("%i", &esc);
    limparBufferEntrada();
    limparConsole();
    
    return esc;
}

int main() {
	inicializarVariaveis();
    int esc = 0;
    while(esc != 3) {
		esc = menuInicial();
		
        switch(esc) {
            case 1: {
				cadastrarPost();
                break;
            }
            case 2: {
            	listarPostsCadastrados(filaDePosts->inicio);
                break;
            }
            default:
                break;
        }
    }	
}
