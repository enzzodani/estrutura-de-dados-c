#include <stdio.h>
#include <stdlib.h>

//Constantes importantes
  //Define o numero maximo de elementos no array de datas
  #define MAX_DATAS 10;
  
  //Definem os numeros para menus
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
unsigned int procedimento; //Variavel para escolha de menu 
Data *datasGlobal[MAX_DATAS]; // Array Global de ponteiros para Data 

// Declaração de Funções
  //Funções auxiliares
    void limparBufferDeEntrada();//Limpa o buffer de entrada
    void limparSaida(); //Limpa a saída (semelhante ao system(clear))
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
  // Encontrar posição disponível no array
  int posicao = -1;
  for (int i = 0; i < MAX_DATAS; i++) {
      if (datasGlobal[i] == NULL) { //Se a posição do elemento é NULL, significa que tem espaço livre nessa posição
          posicao = i; //guarda a posição que tem o espaço livre
          break;
      }
  }
  
  printf("Digite o dia, mês e ano separados por espaço: ");
  scanf("%d %d %d", &dia, &mes, &ano);

  if (posicao != -1) { //Se a posição é diferente de -1, então temos espaço livre para guardar essa nova data  
    criaData(dia, mes, ano);
  } else { //Todas as posições estão cheias
    printf("Não há espaço disponível para armazenar mais datas.\n");
  }
}

void menuLiberaData() {
 //Verificar se o array esta vazio
  int posicao = -1;
  int verificador = 0;
  for (int i = 0; i < MAX_DATAS; i++) {
    if (datasGlobal[i] != NULL) { //Se a posição é diferente de NULL, então significa que existe data nessa posição
      verificador++; //O contador é adicionado para cada data encontrada
    }
  }

  if (verificador == 0) { //O verificador so vai ser igual a 0 se todas as posições forem NULL, ou seja, não existe datas
    printf("Nao existe datas criadas com exito.\n");
  } else {
    for (int i = 0; i < MAX_DATAS; i++) { //Imprime as datas do array datasGlobal
      if (datasGlobal[i] != NULL) {
        printf("Data %d: ", i+1);
        imprimeData(**datasGlobal[i], 'ddmmaaaa');
        printf("\n");
      }
    }
    int escolhido;
    printf("Liberar Data ");
    scanf("%d", &escolhido);

    // Validar a entrada do usuário
    // verifica se escolhido está entre o range correto
    // verifica também se a data existe 
      if (escolhido >= 1 && escolhido <= MAX_DATAS && datasGlobal[escolhido - 1] != NULL) {
          liberaData(datasGlobal[escolhido - 1]); //Libera a data
          datasGlobal[escolhido - 1] = NULL; // Libera um espaço para adicionar nova data futuramente
          printf("Data liberada com sucesso.\n");
      } else {
          printf("Escolha inválida ou data não existe.\n");
      }
  }
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
