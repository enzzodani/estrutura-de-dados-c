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
  printf("1 - Criar Data\n");
  printf("2 - Liberar Data\n");
  printf("3 - Somar dias a Data\n");
  printf("4 - Subtrair dias a Data\n");
  printf("5 - Atribuir uma nova data a Data\n");
  printf("6 - Obter o dia de uma data\n");
  printf("7 - Obter o mes de uma data\n");
  printf("8 - Obter o ano de uma data\n");
  printf("9 - Verificar se a data pertence a ano bissexto\n");
  printf("10 - Comparar 2 datas\n");
  printf("11 - Pegar o numero de dias entre 2 datas\n");
  printf("12 - Imprimir uma data\n");
  printf("0 - Sair do programa\n");
	scanf("%c", &procedimento);
	limparBufferDeEntrada();
}

void limparBufferDeEntrada(void){
	char lixo;
	while((lixo = getchar()) != '\n' && lixo != EOF){continue;}
}
