#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int numero;
    struct No* esquerda;
    struct No* direita;
} No;

typedef struct {
    No* raiz;
} Arvore;

void criaArvore(Arvore* arvore) {
    arvore->raiz = NULL;
}

int isVazia(Arvore arvore) {
    return arvore.raiz == NULL;
}

int isNulo(No* noAtual) {
    return (noAtual == NULL);
}

No* insere(No** noAtual, int elemento) {
    if (isNulo(*noAtual)) {
        No* novoNo = (No *) malloc (sizeof (No));
        novoNo->numero = elemento;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        
        (*noAtual) = novoNo;
        return novoNo;
        } else {
            if (elemento < (*noAtual)->numero) {
            return insere(&(*noAtual)->esquerda, elemento);
        } else {
            return insere(&(*noAtual)->direita, elemento);
        }
    }
}

No* busca(No* noAtual, int elemento) {
    if (isNulo(noAtual)) {
        return NULL;
    } else if (elemento == noAtual->numero) {
        return noAtual;
    } else {
    if (elemento < noAtual->numero) {
        return busca(noAtual->esquerda, elemento);
    } else {
        return busca(noAtual->direita, elemento);
    }
    }
}

void tipoNo(No* noAtual, int elemento) {
    No* noBuscado = busca(noAtual, elemento);
    if (isNulo(noBuscado)) {
        printf("Elemento não encontrado! \n");
    } else {
        if (isNulo(noBuscado->esquerda) && isNulo(noBuscado->direita)) {
            printf("O nó %d é um nó terminal. \n", noBuscado->numero);
        } else {
            printf("O nó %d é um nó não-terminal. \n", noBuscado->numero);
        }
    }
}

int main() {
    Arvore *arvore = (Arvore *) malloc(sizeof(Arvore));

    criaArvore(arvore);
    insere(&arvore->raiz, 5);
    tipoNo(arvore->raiz, 4);
    tipoNo(arvore->raiz, 5);
}