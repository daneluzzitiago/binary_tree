#include "ArvBin.h"

ArvBin* criaArvBin(){
	ArvBin *aux = (ArvBin*)malloc(sizeof (ArvBin));
	return aux;
}

No* criaNo(int key){
	No *aux = (No*)malloc(sizeof(No));
	aux->key = key;
	return aux;
}

void insereNo(ArvBin *Arv, int key){
	
}

void liberaArv(ArvBin *Arv){
	No* aux = Arv->raiz;
	
}

void liberaNo(No *no){
	if(no == NULL){
		return;
	}
	liberoNo(no->esq);
	liberaNo(no->dir);
	printf("Liberada chave %d\n",no->key);
	free(no);
	return;
}
