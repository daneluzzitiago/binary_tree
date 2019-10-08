#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreBinaria.h"

//FILE *arq;
int main()
{
    /*int N = 8;
    ArvBin* testando = cria_ArvBin();
    


    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");

    char linha[9];
    char dado[4];
    char *pts;
    char num[2];
    int numero;
    arq = fopen("teste.ext", "rt");

    while(!feof(arq))
    {
        fgets(linha, 9, arq);
        pts = strchr(linha, 'A');///IDENTIFICA SE EH UM AND
        if(pts)
        {
            strncpy(dado, pts, 3);
            insere_ElemenNO(testando, dado, -3);
        }
        


        pts = strchr(linha, 'E');///IDENTIFICA SE EH UMA ENTRADA
        if(pts)
        {
            strncpy(dado, pts, 3);  
            fgets(linha, 9, arq);
            
            ////////////////////////////////
            strncpy(num, linha, 1);
            ////////////////////////////////

            numero = atof(num);
            insere_ElemenNO(testando, dado, numero);
        }


    }*/

    //emOrdem_String(testando);

    ArvBin* valendo = cria_ArvBin();

    int i;
    int numeroEntradas;
    int bit;
    char entrada[4];
    /*
    printf("Digite o numero de entradas: \n");
    scanf("%d", &numeroEntradas);
    
    for(i = 0; i < numeroEntradas; i++)
    {
        printf("Digite a entrada:\n");
        scanf("%s", entrada);

        if(strchr(entrada, 'E'))
        {
            printf("Digite um bit: \n");
            scanf("%d", &bit);
        }
        else
        {
            bit = -3;
        }

        insere_ElemenNO(valendo, entrada, bit);
    }*/
    insere_ElemenNO(valendo, "A00", -3);
    insere_ElemenNO(valendo, "E00", 10);
    insere_ElemenNO(valendo, "E01", 5);
    
    emOrdem_String(valendo);

    operacaoLogica(valendo);
    //printf("resultado final do circuito: %d\n", operacaoLogica(valendo));

    //libera_ArvBin(testando);
    libera_ArvBin(valendo);
    return 0;
}
