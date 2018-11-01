//Arquivo LDED.h - Lista Dinamica Encadeada Dupla

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

//////////////////////
typedef struct lista_ligada LISTA_LIGADA;

typedef struct NO {
	char *string;
	struct NO *proximo;
	struct NO *anterior;
} NO;

struct lista_ligada {
	NO *inicio;
	NO *fim;
	int tamanho;
};
/////////////////////

typedef char *Tipo_Dado;

//Definição do tipo lista
struct elemento{
    struct elemento *ant;
    Tipo_Dado dado;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento* Lista;

Lista *cria_lista();
int inserir_item_inicio(LISTA_LIGADA *lista, char *string);
int inserir_item_fim(LISTA_LIGADA *lista, char *string);
void exibe(LISTA_LIGADA *lista);

LISTA_LIGADA *criar_lista();
void libera_lista(Lista* li);
int consulta_lista_pos(Lista* li, int pos, Tipo_Dado *dt);
int consulta_lista_dado(Lista* li, Tipo_Dado dt, Elem **el);
int insere_lista_final(Lista* li, Tipo_Dado dt);
int insere_lista_inicio(Lista* li, Tipo_Dado dt);
int insere_lista_ordenada(Lista* li, Tipo_Dado dt);
int remove_lista(Lista* li, Tipo_Dado dt);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);
