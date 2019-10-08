#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"



int main(){
	/**
	
	1 - Recebe sequência de comandos
	1.1 - Recebe o tipo de montagem 0
	1.1.1 - ----> Montagem 0 <----
	1.1.2 - Recebe quantidade de comandos
	1.1.2.1 - Cada comando envolve uma string com 3 portas
	1.1.3 - Aloca matriz para armazenar todos os comandos
	1.2 - Faz sequência de scanfs para pegar cada linha de entrada
	1.3 - Em cada linha, acessa char a char
	1.3.1 - A cada 4 chars, começando do 0, pega a letra que representa a porta
	1.3.2 - recebe os próximos 2 chars e converte para um inteiro de indice
	1.3.3 - Armazena 2 ou 3 portas e indices, dependendo da porta 1
	1.3.4 - Usa a porta1 como referência para buscar na arvore, alocando porta2 e porta3 (essa última só se a porta 1 não for N)
	1.3.4.1 - Se a árvore está vazia, insere porta1 na raiz e segue normalmente a alocação ser # indicando fim do comando ou @ indicando fim dos comandos
	1.1
	
	1.2 - Recebe o tipo de montagem 0
	1.2.1 - ----> Montagem 0 <----
	1.2.2 - Aloca apenas uma linha na matriz de comandos, com tamanho grande o bastante para vários comandos
	1.2.3 - Sequencialmente, recebe uma porta e um índice, inserindo na árvore no primeiro lugar disponível, sempre priorizando a esquerda
	
	
	2 - Entrada de testes
	2.1 - A cada inserção de uma porta E, um contador é incrementado
	2.2 - Recebe uma quantidade de testes a serem executados
	2.3 - Libera a matriz de comandos usada anteriormente e aloca novamente, do tamanho [quantodade de entradas] x [quantidade testes]
	2.4 - Recebe em scanfs dentro de um for
	
	3 - Testes
	3.1 - Acessa cada uma das linhas de testes
	3.2 - A cada 2 chars, começando do 0, converte o valor em inteiro e insere na entrada de índice mais baixo
	3.2.1 - Um auxiliar contador ajuda a saber qual entrada deve ser buscada
	3.3 - Excecuta a lógica e traz o resultado à raiz
	3.4 - Printa resultado
	
	*/	
	
	ARVORE *arvore;
	arvore = iniciaArvore();
	
	int tipoMontagem;
	int qntdComandos;
	int qntdEntradas = 0;
	int qntdTestes;
	int i,j;
	
	char **linhaComando;

	char porta1;
	int indice1;
	char porta2;
	int indice2;
	char porta3;
	int indice3;
	
	scanf("%d",&tipoMontagem);
	
	if (tipoMontagem == 0){
		scanf("%d",&qntdComandos);
		linhaComando = (char**)malloc(sizeof (char*)*qntdComandos);
		for (i = 0; i < qntdComandos; i++){
			linhaComando[i] = (char*)malloc(sizeof (char)*11);
		}//Preciso armazenar várias linhas, onde acda linha possui 3 comandos
		for (i = 0; i < qntdComandos; i++){
			fflush(stdin); //Comando que limpa o buffer e permite receber vários comandos em sequência utilizando o scanf
			scanf("%[^\n]s",linhaComando[i]);
		}//Cada linha é interpretada, alocando a lentra em portaX e convertendo os caracteres do índice em um inteiro indiceX
		for( i = 0 ; i < qntdComandos ; i++){
			indice1 = 0;
			indice2 = 0; 	//Os índices são zerados para poder realizar operações com soma +=
			indice3 = 0;
			porta1 = linhaComando[i][0];
			indice1 += ( linhaComando[i][1] - '0')*10;
			indice1 += ( linhaComando[i][2] - '0');
			porta2 = linhaComando[i][4];
			if (porta2 == 'E'){
				qntdEntradas++;	//Soma-se a quantidade de entradas para saber quantos bits serão executados no circuito
			}
			indice2 += ( linhaComando[i][5] - '0')*10;
			indice2 += ( linhaComando[i][6] - '0');
			if (porta1 != 'N'){	//Caso a porta 1 não seja do tipo N significa que ela tem 2 filhos e deve-se considerar a porta3
				porta3 = linhaComando[i][8];
				indice3 += ( linhaComando[i][9] - '0')*10;
				indice3 += ( linhaComando[i][10] - '0');
				if (porta3 == 'E'){
					qntdEntradas++;
				}
			}
			if ( i == 0){
				insereRaiz(arvore,porta1,indice1); //na primeira linha não há nada na árvore, então deve-se inserir na raiz antes de prosseguir
			}
			insereFilhos(arvore,porta1,indice1,porta2,indice2,porta3,indice3); //insere porta 2 e 3 na porta 1 (busca-se a porta 1)
		}
		for ( i = 0; i < qntdComandos; i++){
			free(linhaComando[i]);
		}			//Será utilizada a mesma matriz de comando para armazenar os valores de teste. Free em tudo
		free(linhaComando);
	} else if(tipoMontagem == 1){
		linhaComando = (char**)malloc(sizeof(char*));
		linhaComando[0] = (char*)malloc(sizeof(char)*40);
		fflush(stdin); //Comando que limpa o buffer e permite receber vários comandos em sequência utilizando o scanf

		scanf("%[^\n]s",linhaComando[0]);
		i = 0;
		while (linhaComando[0][i] != '\0'){
			if( i%4 == 0){
				indice1 = 0;
				porta1 = linhaComando[0][i];
			}else if ((i-1)%4 == 0){
				indice1 += 10*(linhaComando[0][i] - '0');
			}else if ((i-2)%4 == 0){
				indice1 += linhaComando[0][i] - '0';
				//printf("%c%d\n",porta1,indice1);
				if ( i == 2){
					insereRaiz(arvore,porta1,indice1);
				}else{
					insereSequencial(arvore,porta1,indice1);
				}
				if (porta1 == 'E'){
					qntdEntradas++;
				}
			}
			i++;
		}
	}
	
	printaArvore(arvore);
	scanf("%d",&qntdTestes);// quantidade de linahs de teste
	
	linhaComando = (char**)malloc(sizeof (char*)*qntdTestes);
	for (i = 0; i < qntdTestes; i++){									//										  0  1  2  3  4  5
		linhaComando[i] = (char*)malloc(sizeof (char)*qntdEntradas*2); //Com 3 portas de entrada o comando será: [X][_][X][_][X][\n]
	}
	
	//recebendo os testes....
	for (i = 0; i < qntdTestes; i++){
		fflush(stdin); //Comando que limpa o buffer e permite receber vários comandos em sequência utilizando o scanf
		scanf("%[^\n]s",linhaComando[i]);
	}
	
	int aux ; //armazena indice da entrada que deve receber o valor
	for ( i = 0; i < qntdTestes; i++){
		aux = 0;
		for ( j = 0; j < qntdEntradas*2; j++){
			if (j%2 == 0){ //Passará no teste os valores nas posições 0,2,4,6....
				insereEntrada(arvore,aux,linhaComando[i][j] - '0');
				aux++;
			}
		}
		executa(arvore);
	}
	
	
	
	//insereRaiz(arvore,'a',4);
	//insereFilhos(arvore,'a',4,'b',1,'c',12);
	//insereFilhos(arvore,'b',1,'j',4,'h',7);
	//printaArvore(arvore);
	limpaArvore(arvore);
	
	return 0;
}
