#include <stdio.h>

//Constantes importantes
#define MENU_INICIAL 13;
#define CRIAR_DATA 1;
#define LIBERAR_DATA 2;
#define SOMAR 3;
#define SUBTRAIR 4;
#define ATRIBUIR 5;
#define DIA 6;
#define MES 7;
#define ANO 8;
#define BISSEXTO 9;
#define COMPARAR 10;
#define ENTRE_DIAS 11;
#define IMPRIMIR 12;
#define SAIR 0;

//Variáveis globais
unsigned int procedimento;

// Declaração de Funções
void menuInicial();
void limparBufferDeEntrada();

int main(int argc, char *argv[])
{
  	// Procedimento inicial
	procedimento = MENU_INICIAL;

	// Loop principal
	while(1){
		limparSaida();
		switch(procedimento){
			case MENU_INICIAL:
				menuInicial();
				break;
			case CRIAR_DATA:
        criaDataMenu();
				break;
			case LIBERAR_DATA:
        liberaDataMenu();
				break;
			case SOMAR:
        somaDataMenu();
				break;
      case SUBTRAIR:
        subtrairDataMenu();
        break;
      case ATRIBUIR:
        
        break;
      case DIA:
        break;
      case MES:
        break;
      case ANO:
        break;
      case BISSEXTO:
        break;
      case COMPARAR:
        break;
      case ENTRE_DIAS:
        break;
      case IMPRIMIR:
        break;
			case SAIR:
				return 0;
			default:
				procedimento = MENU_INICIAL;
	 
  return 0;
}

void menuInicial(){
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
	scanf("%d", &procedimento);
	limparBufferDeEntrada();
}

void limparBufferDeEntrada(){
	char lixo;
	while((lixo = getchar()) != '\n' && lixo != EOF){continue;}
}

void limparSaida(){
	fflush(stdout);
	printf("\e[1;1H\e[2J");
}
