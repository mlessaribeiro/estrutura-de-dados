#include <stdio.h>
#include <stdlib.h>

#define true  1
#define false 0
typedef unsigned char bool;

typedef struct{
	int num;
}t_elemento;

typedef struct NO t_no;

struct NO {
	t_no *esq;
	t_elemento dado;
	t_no *dir;
};

typedef t_no* t_arvore;

int menu (void) {
	int op = 0;
	
	system("cls");
	fflush(stdin);
	printf("\t\tEDITOR DE ARVORE\n\n");
	printf("1 - INSERIR\n");
	printf("2 - REMOVER\n");
	printf("3 - PESQUISAR\n");
	printf("4 - ESVAZIAR\n");
	printf("5 - EXIBIR\n");
	printf("0 - SAIR\n\n");
	printf("DIGITE SUA OPCAO: ");
	scanf("%d", &op);
	fflush(stdin);

	if((op < 0) || (op > 5))
		op = menu();

	return op;
}

t_no *criaNo (void) {
	t_no *novo = NULL;

	novo = (t_no *) malloc (sizeof(t_no));
	if(novo != NULL) {
		novo->esq = novo->dir = NULL;
		novo->dado.num = 0;
	}

	return novo;
}

bool isVazia (t_no *no) {
	bool result = true;

	if(no == NULL)
		result = false;

	return result;
}

int compara (t_elemento item1, t_elemento item2) {
	int result = 0;

	if(item1.num > item2.num)
		result = 1;
	else if(item1.num < item2.num)
		result = -1;

	return result;
}

t_no *busca (t_arvore raiz, t_elemento dado) {
	t_no *no = NULL;

	if(raiz != NULL) {
		if(compara(raiz->dado, dado) == 0)
			no = raiz;
		else {
			no = busca(raiz->esq, dado);

			if(no == NULL)
				no = busca(raiz->dir, dado);
		}
	}

	return no;
}

t_no *buscaSetPai (t_arvore raiz, t_elemento dado, t_no **pai) {
	t_no *no = NULL;

	if(raiz == NULL)
		*pai = NULL;
	else {
		if(compara(raiz->dado, dado) == 0)
			no = raiz;
		else {
			*pai = raiz;

			if(compara(raiz->dado, dado) > 0)
				no = buscaSetPai(raiz->esq, dado, pai);
			else
				no = buscaSetPai(raiz->dir, dado, pai);
		}
	}

	return no;
}

bool inserir (t_arvore *raiz, t_elemento item) {
	bool result = false;

	if(*raiz == NULL) {
		*raiz = criaNo();

		if(*raiz != NULL) {
			(*raiz)->dado = item;
			result = true;
		}
	}
	else {
		if(compara((*raiz)->dado, item) > 0)
			result = inserir(&((*raiz)->esq), item);
		else if(compara((*raiz)->dado, item) < 0)
			result = inserir(&((*raiz)->dir), item);
	}

	return result;
}

bool remover (t_arvore *raiz, t_elemento item) {
	bool result = false;
	t_no *no, *pai, *sub, *paiSuc, *suc;

	no = pai = sub = paiSuc = suc = NULL;

	no = buscaSetPai(*raiz, item, &pai);
	if(no != NULL) {
		if(no->esq == NULL)
			sub = no->dir;
		else {
			if(no->dir == NULL)
				sub = no->esq;
			else {
				paiSuc = no;
				sub = no->dir;
				suc = sub->esq;

				while(suc != NULL) {
					paiSuc = sub;
					sub = suc;
					suc = sub->esq;
				}

				if(paiSuc != no) {
					paiSuc->esq = sub->dir;
					sub->dir = no->dir;
				}

				sub->esq = no->esq;
			}
		}

		if(pai == NULL)
			*raiz = sub;
		else {
			if(no == pai->esq)
				pai->esq = sub;
			else
				pai->dir = sub;

			free(no);
			result = true;
		}

	}

	return result;
}

void esvaziar (t_arvore *raiz) {
	if(*raiz != NULL) {
		esvaziar(&(*raiz)->esq);
		esvaziar(&(*raiz)->dir);
		free(*raiz);
		*raiz = NULL;
	}
}

int main (int argc, char *argv[]) {
	int op = 0;
	t_elemento dado;
	t_arvore raiz = NULL;

	do
	{
		op = menu();

		system("cls");
		switch(op)
		{
			case 1: /* INSERIR */
			{
				printf("\t\tINSERIR\n\n");
				printf("Digite o numero que deseja inserir: ");
				scanf("%d", &dado.num);

				if(inserir(&raiz, dado))
					printf("\nDADO INSERIDO COM SUCESSO!\n\n");
				else
					printf("\nERRO AO INSERIDO O DADO!\n\n");
				system("pause");
				break;
			}
			case 2: /* REMOVER */
			{
				printf("\t\tREMOVER\n\n");
				printf("Digite o numero que deseja remover: ");
				scanf("%d", &dado.num);

				if(remover(&raiz, dado))
					printf("O NUMERO INFORMADO FOI REMOVIDO COM SUCESSO!\n\n");
				else
					printf("O NUMERO INFORMADO NAO PODE SER REMOVIDO!\n\n");
				system("pause");
				break;
			}
			break;
			
			case 3: /* PROCURAR */
			{
			
				printf("\t\tPROCURAR\n\n");
				printf("Digite o numero que deseja procurar: ");
				scanf("%d", &dado.num);

				if(busca(raiz, dado) != NULL)
					printf("O NUMERO INFORMADO ENCONTRA-SE NA ARVORE!\n\n");
				else
					printf("O NUMERO INFORMADO NAO ENCONTRA-SE NA ARVORE!\n\n");
				system("pause");
		    }
			case 4: /* ESVAZIAR */
			{
				esvaziar(&raiz);
				printf("A ARVORE FOI ESVAZIADA COM SUCESSO!\n\n");
				system("pause");
				break;
			}
			case 5: /* EXIBIR */
			{
				printf("\n\n\t\tEXIBICAO PRE ORDEM\n\n");
				exibirPreOrdem(raiz);
				printf("\n\n\t\tEXIBICAO IN ORDEM\n\n");
				exibirInOrdem(raiz);
				printf("\n\n\t\tEXIBICAO POS ORDEM\n\n");
				exibirPosOrdem(raiz);
				printf("\n\n\n");
				system("pause");
				break;
			}
			case 0: /* SAIR */
			{
				printf("SAINDO...");
				break;
			}
		}
	} while(op != 0);

	return 0;
}