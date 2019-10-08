#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"


int main(){
	
	/**
	
	1 - Recebe sequência de comandos
	1.1 - Recebe 2 valores, um que indica o tipo de montagem e outro que indica a quantidade de comandos de criação que serão enviados a seguir
	1.2 - Aloca dinamicamente um vetor de char para armazenar cada parâmetro
	1.2.1 - Regra para alocar os comandos modo 0: cada comando é 'PORTAPAI''KEY' 'PORTAFILHO_1''KEY' 'PORTAFILHO_2''KEY'
	1.2.1.1 - Exemplo: O00 A00 A01 -> OR 0 com duas ANDs ligadas 
	1.2.1.2 - Será armazenado da seguinte forma: |O|0|0|A|0|0|A|0|1|#|...|@|
	1.2.1.3 - A quantidade de comandos aloca 9 chars para o comando dado e mais 1 que pode ser # indicando fim do comando ou @ indicando fim dos comandos
	
	
	1.2.2
	
	
	2 - Converte comandos em chamadas de métodos que criam a árvore
	2.1 - Verifica char a char. 0,4,8 etc... sempre serão as letras das portas
	2.2 - Converte os próximos 2 caracteres em um inteiro para armazenar o índice
	2.3 - Chamada dos métodos que inserem elementos na árvore na posição 'INDEX'
	2.3.1 - Se for a primeira linha de comando é necessário inserir os 3 elementos
	2.3.2 - Caso contrário, busca o primeiro elemento da linha de comando e insere os outros 2
	
	3 - Retorna resultado da árvore
	
	*/
	
	int tipoMontagem;
	int qntdComandos;
	int i,j;
	char **linhaComando;
	
	char porta1;
	int indice1;
	
	char porta2;
	int indice2;
	
	char porta3;
	int indice3;
	
	
	scanf("%d",&tipoMontagem);
	scanf("%d",&qntdComandos);
	
	
	linhaComando = (char**)malloc(sizeof (char*)*qntdComandos);
	for (i = 0; i < qntdComandos; i++){
		linhaComando[i] = (char*)malloc(sizeof (char)*11);
	}
	//Preciso armazenar várias linhas, onde acda linha possui 3 comandos
	for (i = 0; i < qntdComandos; i++){
		fflush(stdin); //Comando que limpa o buffer e permite receber vários comandos em sequência utilizando o scanf
		scanf("%[^\n]s",linhaComando[i]);
	}
	
	char auxIndex[2];
	int index;
	
	
	for (i = 0; i < qntdComandos; i ++){
			porta1[0] = linhaComando[i][0];
			porta1[1] = linhaComando[i][1];
			porta1[2] = linhaComando[i][2];
			porta1[3] = '\0';
			porta2[0] = linhaComando[i][4];
			porta2[1] = linhaComando[i][5];
			porta2[2] = linhaComando[i][6];
			porta2[3] = '\0';
			porta3[0] = linhaComando[i][8];
			porta3[1] = linhaComando[i][9];
			porta3[2] = linhaComando[i][10];
			porta3[3] = '\0';
			
			
		
		
		/*
			if ( j%4 == 0){
				switch (linhaComando[i][j]){
					case 'A':
						auxIndex[0] = linhaComando[i][j+1];
						auxIndex[1] = linhaComando[i][j+2]; 
						index = (auxIndex[0] - '0')*10 + (auxIndex[1] - '0'); //Macete para converter char em int
						printf("Porta AND indice %d\n",index);
						//insereArvore(linhaComando[i][j],index);
						break;
					case 'O':
						auxIndex[0] = linhaComando[i][j+1];
						auxIndex[1] = linhaComando[i][j+2]; 
						index = (auxIndex[0] - '0')*10 + (auxIndex[1] - '0'); //Macete para converter char em int
						printf("Porta OR indice %d\n",index);
						break;
					case 'D':
						auxIndex[0] = linhaComando[i][j+1];
						auxIndex[1] = linhaComando[i][j+2]; 
						index = (auxIndex[0] - '0')*10 + (auxIndex[1] - '0'); //Macete para converter char em int
						printf("Porta NAND indice %d\n",index);
						break;
					case 'R':
						auxIndex[0] = linhaComando[i][j+1];
						auxIndex[1] = linhaComando[i][j+2]; 
						index = (auxIndex[0] - '0')*10 + (auxIndex[1] - '0'); //Macete para converter char em int
						printf("Porta NOR indice %d\n",index);
						break;
					case 'X':
						auxIndex[0] = linhaComando[i][j+1];
						auxIndex[1] = linhaComando[i][j+2]; 
						index = (auxIndex[0] - '0')*10 + (auxIndex[1] - '0'); //Macete para converter char em int
						printf("Porta XOR indice %d\n",index);
						break;
					case 'N':
						auxIndex[0] = linhaComando[i][j+1];
						auxIndex[1] = linhaComando[i][j+2]; 
						index = (auxIndex[0] - '0')*10 + (auxIndex[1] - '0'); //Macete para converter char em int
						printf("Porta NOT indice %d\n",index);
						break;
					case 'E':
						auxIndex[0] = linhaComando[i][j+1];
						auxIndex[1] = linhaComando[i][j+2]; 
						index = (auxIndex[0] - '0')*10 + (auxIndex[1] - '0'); //Macete para converter char em int
						printf("Porta ENTRADA indice %d\n",index);
						break;
							
				}
			}*/
		
		printf("\n");
	}
	
	
			
	printf("%s",porta1);
	printf("%s",porta2);
	printf("%s",porta3);
	
	
	/**printf("--MyDebugger--\nMontagem: tipo %d\nComandos: %d\nComandos:\n",tipoMontagem,qntdComandos);
	for (iterador = 0; iterador < qntdComandos; iterador++){
		printf("%s\n",linhaComando[iterador]);
	}*/
	
	
	return 0;
}
