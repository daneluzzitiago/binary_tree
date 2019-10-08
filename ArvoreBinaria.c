#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreBinaria.h" //inclui os Protótipos

typedef struct NO{
    char portEnt[4];
    int info;	//bit resultado;
    struct NO *esq;
    struct NO *dir;
}NO;

struct arvore{
	struct NO *raiz;
}arvore; 

void insere_Raiz(ARVORE *arvore, char pE[4]){
	arvore->raiz = (NO*)malloc(sizeof(NO));
	strcopy(arvore->raiz->portEnt,pE);
	arvore->raiz->esq = NULL;
	arvore->raiz->dir = NULL;
	return;
}

void insere_Esquerda(NO *no, char pE[4]){
	NO *novo;
	novo = (NO*)malloc(sizeof (NO));
	strcopy(no->portEnt,pE);
	novo->esq = NULL;
	novo->dir = NULL;
	no->esq = novo;
}


/*
ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

void insere_Filhos(ArvBin *raiz, char porta1[4] ,char porta2[4], char porta3[4]){
	struct NO *aux;
	aux = (struct NO*)malloc(sizeof (struct NO));
	aux = consulta_ArvBin(raiz,porta1[4]);
	if (aux == NULL){
	
		insere_ElemenNO(raiz,porta1[4],0);
	}else{
		insere_ElemenNO(aux,porta2[4],-1);
		insere_ElemenNO(aux,porta3[4],1);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void insere_ElemenNO(ArvBin *no, char* pE, int pos) //insere porta/Entrada
{
	
    if(pos == 0)
        strcopy(&(*no)->portEnt,pE);
        return ;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    

    strcpy(novo->portEnt, pE);
    novo->dir = NULL;
    novo->esq = NULL;
    if (pos == -1){ //insere na esquerda
    	no->esq = novo;
	}else if(pos == 1){ //insere na direita
		no->dir = novo;
	}
	return ;

}
void emOrdem_String(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
       
        printf("porta: %s // ",(*raiz)->portEnt);
        printf("dado: %d\n", (*raiz)->info);
        emOrdem_String(&((*raiz)->dir));
        emOrdem_String(&((*raiz)->esq));
    }
}

void operacaoLogica(ArvBin *raiz)
{
    if(*raiz != NULL)
    {
        if(strchr((*raiz)->portEnt, 'A'))
        {
            printf("operacao com AND\n");
            operacaoLogica(&((*raiz)->esq));
            printf("fala manldaafaf\n");
            operacaoLogica(&((*raiz)->dir));
            printf("depois dessa\n");
            /*
            if(operacaoLogica(&((*raiz)->esq)) == 1 )
                printf("finalmenteee\n");
        }   
        if(strchr((*raiz)->portEnt, 'E'))
        {
            //printf("aqui ja eh o dado\n");
            printf("info de um lado %d\n", (*raiz)->info);
        }
        //operacaoLogica(&((*raiz)->esq));
        //operacaoLogica(&((*raiz)->dir));

    }
       
}



//////////////////////////////////////////////////////////////////////////////////////////

int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;//elemento já existe
            }

            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 é o nó anterior a r na ordem e-r-d
    // no1 é o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}
// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

ArvBin* consulta_ArvBin(ArvBin *raiz, char porta[4]){
    if(raiz == NULL){
        return NULL;
	}
	if (strcmp(&(*raiz)->portEnt,porta[4]) == 0 ){
		return raiz;
	}
	
    ArvBin* direita;
    direita = (struct NO*)malloc(sizeof(struct NO));
    
    ArvBin* esquerda;
    esquerda = (struct NO*)malloc(sizeof(struct NO));
	
	esquerda = consulta_ArvBin(esquerda,porta[4]);
	direita = consulta_ArvBin(direita,porta[4]);
	
	if (esquerda == NULL){
		if (direita == NULL){
			return NULL;
		}
		return direita;
	}
	return esquerda;
	

}

void preOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n",(*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);
    }
}

// Funcoes Adicionais de Arvore

void Procura_preOrdem_ArvBin(ArvBin *raiz, int valor, int *achou)
{
    if(raiz == NULL)
        return;
    if (*achou)
        return;
    if(*raiz != NULL)
    {
        if (valor == (*raiz)->info)
        {
            printf("Achou: %d! \n",(*raiz)->info);
            *achou=1;
        }
        Procura_preOrdem_ArvBin(&((*raiz)->esq),valor,achou);
        Procura_preOrdem_ArvBin(&((*raiz)->dir),valor,achou);
    }
}

void Exibe_emOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;

    if(*raiz != NULL)
    {
        printf("Atual: %d - Vai para Esquerda \n",(*raiz)->info);
        Exibe_emOrdem_ArvBin(&((*raiz)->esq));
        printf("Dado : %d \n",(*raiz)->info);
        printf("Atual: %d - Vai para Direita \n",(*raiz)->info);
        Exibe_emOrdem_ArvBin(&((*raiz)->dir));
        printf("Feito(%d) \n",(*raiz)->info);
    }
    else
        printf("NULL\n");

}

*/
