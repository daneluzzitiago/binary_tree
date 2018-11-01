#ifndef ARV_BIN_H
#define ARV_BIN_H

#include <stdio.h>
#include <stdlib.h>



typedef struct No{
	int key;
	struct No *esq;
	struct No *dir;
}No;

typedef struct ArvBin{
	struct No *raiz;
}ArvBin;


ArvBin* criaArvBin();
No* criaNo();
void liberaArv(ArvBin *Arv);
void liberaNo(No *no);


#endif
