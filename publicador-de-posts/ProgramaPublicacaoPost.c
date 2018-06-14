#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct TIPO_POST {
	char titulo[50];
	char conteudo[200];
}TIPO_POST;

typedef struct NO {
	struct TIPO_POST post;
	struct NO *prox;
}NO;

typedef struct PILHA {
	struct NO *topo;
}PILHA;

typedef struct FILA {
	struct NO *inicio;
	struct NO *fim;
}FILA;

struct FILA *filaDePosts;
struct PILHA *pilhaDePostsPublicados;

void inicializarVariaveis() {
	setlocale(LC_ALL, "Portuguese");
	
	filaDePosts = (struct FILA *) malloc(sizeof(struct FILA));
	filaDePosts->inicio = NULL;
	filaDePosts->fim = NULL;
	
	pilhaDePostsPublicados = (struct PILHA *) malloc(sizeof(struct PILHA));	
	pilhaDePostsPublicados->topo = NULL;
}

void limparConsole() {
	system("cls");
}

void limparBufferEntrada() {
	setbuf(stdin, NULL);
}

int menuInicial() {
	int esc = 0;
	printf("Escolha uma opção!!!\n");
    printf("1 - Cadastrar Post\n");
    printf("2 - Listar Posts Cadastrados\n");
    printf("3 - Avaliar Post\n");
    printf("4 - Listar Post Publicados\n");
    printf("5 - Sair\n\nR:  ");
    scanf("%i", &esc);
    limparBufferEntrada();
    limparConsole();
    
    return esc;
}

// está função tem a funcionalidade de enfileirar o post na fila
void inserePostParaAvaliacao(char titulo[], char conteudo[]) {
	struct NO* ptr = (struct NO *) malloc(sizeof(struct NO));
	strcpy(ptr->post.titulo, titulo);
	strcpy(ptr->post.conteudo, conteudo);
	ptr->prox = NULL;
	if(filaDePosts->inicio == NULL)
		filaDePosts->inicio = ptr;
	else
		filaDePosts->fim->prox = ptr;
	filaDePosts->fim = ptr;
}

void cadastrarPost() {
    printf("Digite o título do Post: ");
    char titulo[50];
	scanf("%[^\n]s", titulo);
	limparBufferEntrada();
    
	printf("Digite o conteúdo do Post: ");
    char conteudo[200];
	scanf("%[^\n]s", conteudo);
	limparBufferEntrada();

    inserePostParaAvaliacao(titulo, conteudo); //inserir na fila de post
    limparConsole();	
}

// essa é a função de imprimir fila
void listarPostsCadastrados(struct NO* ptr){
	limparConsole();
	printf("Listando Posts para Cadastrados\n\n");
	while(ptr != NULL) {
		printf("Título do Post: %s\nConteúdo: %s\n\n", ptr->post.titulo, ptr->post.conteudo);
		ptr = ptr->prox;
	}
	
	printf("\n\n");
}

struct TIPO_POST removerPostDaFila() {
	struct NO* ptr = filaDePosts->inicio;
	struct TIPO_POST post;
	if(ptr != NULL){
		filaDePosts->inicio = ptr->prox;
		ptr->prox = NULL;
		strcpy(post.titulo, ptr->post.titulo);
		strcpy(post.conteudo, ptr->post.conteudo);
		free(ptr);
		return post;
	}
}

// essa é a função empilhar
void publicarPost(char titulo[], char conteudo[]) {
	struct NO* ptr = (struct NO *) malloc(sizeof(struct NO));
	strcpy(ptr->post.titulo, titulo);
	strcpy(ptr->post.conteudo, conteudo);
	ptr->prox = pilhaDePostsPublicados->topo;
	pilhaDePostsPublicados->topo = ptr;
}

void avaliarPost() {
	if (filaDePosts->inicio == NULL) {
		printf("Não existem Posts para serem avaliados!\n\n");
	} else {
		struct TIPO_POST postParaAvaliar;
		postParaAvaliar = removerPostDaFila();
		printf("Título do Post: %s\nConteúdo:\n%s\n\n", postParaAvaliar.titulo, postParaAvaliar.conteudo);
		
		int opcao = 0;
	    while (opcao != 1 && opcao != 2) {
			printf("Selecione uma das opções a seguir:\n");
	        printf("1 - Aprovar Publicação do Post\n");
	        printf("2 - Reprovar Publicação do Post\n");
	        scanf("%i", &opcao);
	        limparBufferEntrada();
		}
		
		if (opcao == 1)
			publicarPost(postParaAvaliar.titulo, postParaAvaliar.conteudo);
			
	    limparConsole();
	}
}

void listarPostsPublicados(struct NO* ptr){
	limparConsole();
	printf("Listando Posts para Publicados\n\n");
	while(ptr != NULL){
		printf("Título do Post: %s\nConteúdo: %s\n\n", ptr->post.titulo, ptr->post.conteudo);
		ptr = ptr->prox;
	}
	
	printf("\n\n");
}

int main() {
	inicializarVariaveis();
    int esc = 0;
    while(esc != 5) {
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
            case 3: {
				avaliarPost();
                break;
            }
            case 4: {
            	struct NO *it = pilhaDePostsPublicados->topo;
            	listarPostsPublicados(it);
                break;
            }
            default:
                break;
        }
    }	
}
