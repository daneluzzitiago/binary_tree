#include <stdio.h>
#include <stdlib.h>


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
	3 - Retorna resultado da árvore
	
	*/
	
	int tipoMontagem;
	int qntdComandos;
	int iterador;
	char *comandos;
	
	scanf("%d",&tipoMontagem);
	scanf("%d",&qntdComandos);
	
	comandos = (char*)malloc(sizeof (char)*10*qntdComandos);
	
	fgets(comandos,9,stdin);
	
	//for (iterador = 0 ; iterador < 10*qntdComandos; iterador++){
	//	scanf("%c",comandos[iterador]);
	//}
	
	printf("--MyDebugger--\nMontagem: tipo %d\nComandos: %d\nComando: %s",tipoMontagem,qntdComandos,comandos);
	
	
	
	
	return 0;
}
