#include <stdio.h>
#include <stdlib.h>


int main(){
	
	/**
	
	1 - Recebe sequ�ncia de comandos
	1.1 - Recebe 2 valores, um que indica o tipo de montagem e outro que indica a quantidade de comandos de cria��o que ser�o enviados a seguir
	1.2 - Aloca dinamicamente um vetor de char para armazenar cada par�metro
	1.2.1 - Regra para alocar os comandos modo 0: cada comando � 'PORTAPAI''KEY' 'PORTAFILHO_1''KEY' 'PORTAFILHO_2''KEY'
	1.2.1.1 - Exemplo: O00 A00 A01 -> OR 0 com duas ANDs ligadas 
	1.2.1.2 - Ser� armazenado da seguinte forma: |O|0|0|A|0|0|A|0|1|#|...|@|
	1.2.1.3 - A quantidade de comandos aloca 9 chars para o comando dado e mais 1 que pode ser # indicando fim do comando ou @ indicando fim dos comandos
	
	
	1.2.2
	2 - Converte comandos em chamadas de m�todos que criam a �rvore
	3 - Retorna resultado da �rvore
	
	*/
	
	int tipoMontagem;
	int qntdComandos;
	int iterador;
	char **linhaComando;
	
	scanf("%d",&tipoMontagem);
	scanf("%d",&qntdComandos);
	
	
	linhaComando = (char**)malloc(sizeof (char*)*qntdComandos);
	for (iterador = 0; iterador < qntdComandos; iterador++){
		linhaComando[iterador] = (char*)malloc(sizeof (char)*11);
	}
	//Preciso armazenar v�rias linhas, onde acda linha possui 3 comandos
	for (iterador = 0; iterador < qntdComandos; iterador++){
		fflush(stdin); //Comando que limpa o buffer e permite receber v�rios comandos em sequ�ncia utilizando o scanf
		scanf("%[^\n]s",linhaComando[iterador]);
	}
	
	printf("--MyDebugger--\nMontagem: tipo %d\nComandos: %d\nComandos:\n",tipoMontagem,qntdComandos);
	for (iterador = 0; iterador < qntdComandos; iterador++){
		printf("%s\n",linhaComando[iterador]);
	}
	
	
	return 0;
}
