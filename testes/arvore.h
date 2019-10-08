#ifndef ARVORE_H
#define ARVORE_H

typedef struct arvore ARVORE;

ARVORE* iniciaArvore();
void insereRaiz(ARVORE *a, char port, int ind);
void limpaArvore(ARVORE *a);
void printaArvore(ARVORE *a);
void printaArvore(ARVORE *a);
void insereFilhos(ARVORE *a, char ref, int indRef, char pEsq, int indEsq, char pDir, int indDir);
void insereEntrada(ARVORE *a, int indice, int valor);
void executa(ARVORE *a);
void insereSequencial(ARVORE *a, char porta, int indice);

#endif
