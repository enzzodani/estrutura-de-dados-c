#include <stdio.h>

void menuInicial();
void limparBufferDeEntrada();

int main(int argc, char *argv[])
{
  
  

  return 0;
}

void menuInicial(){
  char procedimento;

	printf("PROGRAMA DE DATAS\n\n");

	scanf("%c", &procedimento);
	limparBufferDeEntrada();
}


void limparBufferDeEntrada(void){
	char lixo;
	while((lixo = getchar()) != '\n' && lixo != EOF){continue;}
}
