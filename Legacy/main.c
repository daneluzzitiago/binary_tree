#include <stdio.h>
#include <stdlib.h>
#include "ArvBin.h"


int main(){
	
	ArvBin *teste;
	teste = criaArvBin();
	
	
	
	free(teste);
	
	return 0;
}
