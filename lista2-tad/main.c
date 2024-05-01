#include <stdio.h>
#include <stdlib.h>
#include "data.h"

// Lista ligada
// Node
typedef struct node Node;
struct node {
  Data *d;
  Node *proximo;
};

// Root
typedef struct root {
  Node *primeiro;
} Root;

//Constantes importantes
  //Define o numero maximo de elementos no array de datas
  #define MAX_DATAS 10
  
  //Definem os numeros para menus
  #define MENU_INICIAL 13
  #define CRIAR_DATA 1
  #define LIBERAR_DATA 2
  #define SOMAR 3
  #define SUBTRAIR 4
  #define ATRIBUIR 5
  #define DIA 6
  #define MES 7
  #define ANO 8
  #define BISSEXTO 9
  #define COMPARAR 10
  #define ENTRE_DIAS 11
  #define IMPRIMIR 12
  #define SAIR 0

//Variáveis globais
unsigned int procedimento; //Variavel para escolha de menu 
unsigned int contadorData = 0;
Root root = {.primeiro=NULL};
Node **futuroNode = &root.primeiro;

// Declaração de Funções
  //Funções auxiliares
    void limparBufferDeEntrada();//Limpa o buffer de entrada
    void limparSaida();//Limpa a saída (semelhante ao system(clear))
    void colocaData(unsigned int dia, unsigned int mes, unsigned int ano);
    void tiraData();
    void imprimiLoppDatas(); //Imprime o array global de datas
  //Funções menu 
    void menuInicial(); //chama o menu inicial
    void criaDataMenu(); //chama o menu de criação de data
    void liberaDataMenu(); //chama o menu de liberação de data
    void somaDataMenu(); //chamda o menu de soma de dias
    void subtrairDataMenu(); //chama o menu de subtração de dias
    void atribuirDataMenu(); //chma o menu de atribuição de data
    void obtemDiaMenu(); //chama o menu de obtenção de dia
    void obtemMesMenu(); //chama o menu de obtenção de mes 
    void obtemAnoMenu(); //chama o menu de obtenção de ano
    void bissextoMenu(); //chama o menu de verificador de data bissexta
    void compararMenu(); //chama o menu de compração de datas
    void entreDiasMenu(); //chama o menu de calcular dias entre datas 
    void imprimirMenu(); //chama o menu de impressão de uma data 

int main(int argc, char *argv[])
{
  	// Procedimento inicial
	procedimento = MENU_INICIAL;

	// Loop principal
	while(1){
		limparSaida(); //Limpa a saída para o menu inicial
		
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
   				    atribuirDataMenu();  
        		break;
		      	case DIA:
			        obtemDiaMenu();
		        break;
      			case MES:
			        obtemMesMenu();
        		break;
      			case ANO:
        			obtemAnoMenu();
        		break;
      			case BISSEXTO:
        			bissextoMenu();
		        break;
      			case COMPARAR:
        			compararMenu();
        		break;
      			case ENTRE_DIAS:
        			entreDiasMenu();
        		break;
      			case IMPRIMIR:
        			imprimirMenu();
			break;
      			case SAIR: //Fecha o programa 
				return 0;
      			default:
				procedimento = MENU_INICIAL;
	 
  return 0;
}

//Funções de Menu - Definição 
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
}

void criaDataMenu() {
  unsigned int dia, mes, ano;
  
  printf("Digite o dia, mês e ano separados por espaço: ");
  scanf("%d %d %d", &dia, &mes, &ano);

  colocaData(dia, mes, ano);
}

void menuLiberaData() {

}

void somaDataMenu() {

}

void subtrairDataMenu() {

}

void atribuirDataMenu() {

}

void obtemDiaMenu() {
  
}

void obtemMesMenu() {

}

void obtemAnoMenu() {

}

void bissextoMenu() {

}

void compararMenu() {

}

void entreDiasMenu() {

}

void imprimirMenu() {

}

//Funções Auxiliares - Definição
void limparBufferDeEntrada(){ //Lida com buffers relacionados a char 
	char lixo;
	while((lixo = getchar()) != '\n' && lixo != EOF){continue;}
}

void limparSaida(){ //Limpa compleetamente a saída 
	fflush(stdout);
	printf("\e[1;1H\e[2J");
}

void colocaData(unsigned int dia, unsigned int mes, unsigned int ano){
  *futuroNode = (Node *)malloc(sizeof(Node));
  if (*futuroNode != NULL){
    (*futuroNode)->d = criaData(dia, mes, ano);
    (*futuroNode)->proximo = NULL;
    futuroNode = &((*futuroNode)->proximo);
    printf("Data adicionada com sucesso\n");
  } else {
    printf("Erro: memoria insuficiente\n");
  }
}

void tiraData(unsigned int indice) {
  Node *atual = root.primeiro;
  Node *anterior;

  int i = 0;

  for (i = 0; i < indice; i++) {
    anterior = atual;
    atual = atual -> proximo;
  }

  liberaData(atual->d);

  if (indice == 0) {
    root.primeiro = atual -> proximo;
    free(atual);
  }
  else if (indice <= contadorData) {
    anterior -> proximo = atual -> proximo;
    free(atual);
  } else {
    free(atual);
    anterior -> proximo = NULL;
    futuroNode = &(anterior->proximo);
  }
  contadorData--;
}

void imprimiLoppDatas() {

}
