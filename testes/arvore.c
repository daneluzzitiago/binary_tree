#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore.h"

typedef struct NO{
	char porta;
	int indice;
	int valor;
	struct NO *dir;
	struct NO *esq;
}NO;

struct arvore{
	NO *raiz;	
};



ARVORE* iniciaArvore(){
	ARVORE *a = (ARVORE*)malloc(sizeof(ARVORE));
	return a;
}

void insereRaiz(ARVORE *a, char port, int ind){
	NO *novo;
	novo = (NO*)malloc(sizeof (NO));
	novo->porta=port;
	novo->indice=ind;
	novo->dir = NULL;
	novo->esq = NULL;
	a->raiz = novo;
	return;
}


void limpaNo(NO* no){
	if (no == NULL){
		return;
	}
	limpaNo (no->esq);
	limpaNo (no->dir);
	free(no);
	return;
}

void limpaArvore(ARVORE *a){
	limpaNo(a->raiz);
}

void printaNos(NO* no){
	if (no == NULL){
		return;
	}
	printf("%c%d",no->porta,no->indice);
	if(no->porta == 'E'){
		printf("(%d)",no->valor);
	}
	printaNos(no->esq);
	if (no->porta != 'N'){
		printaNos(no->dir);
	}
	return;
}
void bla(NO* no){
	if (no == NULL){
		return;
	}
	printf("end ESQ: %p // ", no->esq);
	printf("end ATUAL: %p // ", no);
	printf("end DIR: %p // ", no->dir);
	printf("porta %c\n", no->porta);
	bla(no->esq);
	bla(no->dir);
}

void printaArvore(ARVORE *a){
	printaNos(a->raiz);
	//bla(a->raiz);
	
}

NO* achaNo(NO* no, char port, int ind){
	if (no == NULL){
		return NULL;
	}
	if (no->porta == port && no->indice == ind){
		return no;
	}else{
		NO *aux;
		aux = (NO*) malloc (sizeof (NO));
		aux = achaNo(no->esq,port,ind);
		if ( aux == NULL){
			aux = achaNo(no->dir,port,ind);
		}
		return aux;
	}
	
}

void insereEntrada(ARVORE *a, int indice, int valor){
	NO *aux = (NO*)malloc(sizeof (NO));
	aux = achaNo(a->raiz,'E',indice);
	aux->valor = valor;
	return;
}

void insereFilhos(ARVORE *a, char ref, int indRef, char pEsq, int indEsq, char pDir, int indDir){
	NO *aux = (NO*)malloc(sizeof (NO));
	aux = achaNo(a->raiz,ref,indRef);
	if (aux == NULL){
		insereRaiz(a,ref,indRef);
		aux = a->raiz;
	}
	NO *esq = (NO*)malloc(sizeof (NO));
	esq->esq = NULL;
	esq->dir = NULL;
	esq->indice = indEsq;
	esq->porta = pEsq;
	NO *dir = (NO*)malloc(sizeof (NO)); 
	dir->esq = NULL;
	dir->dir = NULL;
	dir->indice = indDir;
	dir->porta = pDir;
	aux->dir = dir;
	aux->esq = esq;
	return;
}
int executaNo(NO *no){
	if (no->porta == 'E'){
		return (no->valor);
	}
	int entrada1, entrada2;
	entrada1 = executaNo(no->esq);
	if (no->porta == 'N'){
		return (1 - no->esq->valor);
	}else{
		entrada2 = executaNo(no->dir);
		switch (no->porta){
			case 'A':
				if(entrada1 && entrada2){
					return 1;
				}else{
					return 0;
				}
				break;
			case 'O':
				if (entrada1 || entrada2){
					return 1;
				}else{
					return 0;
				}
				break;
			case 'D':
				if(entrada1 && entrada2){
					return 0;
				}else{
					return 1;
				}
				break;
			case 'R':
				if (entrada1 || entrada2){
					return 0;
				} else{
					return 1;
				}
				break;
			case 'X':
				if (entrada1 == entrada2){
					return 0;
				} else{
					return 1;
				}
				break;
		}
	}
		
}

void executa(ARVORE *a){
	int final = executaNo(a->raiz);
	printf("%d\n",final);
}

NO* encontraDisponivel(NO *n){
	if(n->porta == 'E'){ //Achei espaço vazio priozizando esquerda
		return NULL;
	}else if( n->esq == NULL){//Achei uma entrada, devo voltar
		return n;
	} else {
		NO *aux = (NO*)malloc(sizeof(NO));
		aux = encontraDisponivel(n->esq);
		if (aux == NULL){
				if(n->dir == NULL){
					if(n->porta == 'N'){
						return NULL;
					}
					else return n;
				}
				return encontraDisponivel(n->dir);	
		}	else return aux;
	}
}

void insereSequencial(ARVORE *a, char p, int i){
		
		//Nó auxiliar que busca algum com um dos filhos vazios
		NO *aux = (NO*)malloc(sizeof(NO));
		aux = encontraDisponivel(a->raiz);
		
		//Nó novo
		NO *novo = (NO*)malloc(sizeof(NO));
		novo->esq = NULL;
		novo->dir = NULL;
		novo->porta = p;
		novo->indice = i;
		
		if ((aux->esq) == NULL){
			aux->esq = novo;
		}else{
			aux->dir = novo;
		}
}
