#include <stdio.h>
#include <stdlib.h>
#include "data.h"

// Lista ligada
	// Node
	typedef struct node Node;
	struct node {
		Data *data;
		Node *proximo;
	};

	// Root
	typedef struct root {
		Node *primeiro;
	} Root;

//Constantes importantes
  //Define o numero maximo de elementos no array de datas
  #define MAX_DATAS 10
	
	//Define cores UwU
	#define KMAG "\x1B[35m"
	#define RESET "\033[0m"
  
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
	int i;
	Root root = {.primeiro=NULL};
	Node **futuroNode = &root.primeiro;

// Declaração de Funções
  //Funções auxiliares
    void limparBufferDeEntrada();//Limpa o buffer de entrada
    void limparSaida();//Limpa a saída (semelhante ao system(clear))
    void colocaData(Data *data);
    void tiraData();
		Data *achaData(unsigned int indice);
    void imprimirTodasDatas(); //Imprime a lista de datas
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
			case MENU_INICIAL: menuInicial(); break;
			case CRIAR_DATA: criaDataMenu(); break;
			case LIBERAR_DATA: liberaDataMenu(); break;
			case SOMAR: somaDataMenu(); break;
			case SUBTRAIR: subtrairDataMenu(); break;
			case ATRIBUIR: atribuirDataMenu(); break;
			case DIA: obtemDiaMenu(); break;
			case MES: obtemMesMenu(); break;
			case ANO: obtemAnoMenu(); break;
			case BISSEXTO: bissextoMenu(); break;
			case COMPARAR: compararMenu(); break;
			case ENTRE_DIAS: entreDiasMenu(); break;
			case IMPRIMIR: imprimirMenu(); break;
			case SAIR: return 0; // Fecha o programa
			default: procedimento = MENU_INICIAL;
		}
	} 
}

//Funções de Menu - Definição 
	void menuInicial(){
		puts(KMAG "PROGRAMA DE DATAS\n\n" RESET);
		puts("1 - Criar Data");
		puts("2 - Liberar Data");
		puts("3 - Somar dias a Data");
		puts("4 - Subtrair dias a Data");
		puts("5 - Atribuir uma nova data a Data");
		puts("6 - Obter o dia de uma data");
		puts("7 - Obter o mes de uma data");
		puts("8 - Obter o ano de uma data");
		puts("9 - Verificar se a data pertence a ano bissexto");
		puts("10 - Comparar 2 datas");
		puts("11 - Pegar o numero de dias entre 2 datas");
		puts("12 - Imprimir uma data");
		puts("0 - Sair do programa");
		scanf("%d", &procedimento);
	}

	void criaDataMenu() {
		unsigned int dia, mes, ano;
		
		fputs("Digite o dia, mês e ano separados por espaço: ", stdout);
		scanf("%d %d %d", &dia, &mes, &ano);
		
		if (validaData(dia, mes, ano)) {
			colocaData(criaData(dia, mes, ano));
		} else {
			puts("Data inválida");
		}
	}

	void liberaDataMenu() {
		unsigned int indice;
		imprimirTodasDatas()
		fputs("Digite o índice para selecionar a data: ", stdout);
		scanf("%d", &indice);

		if (indice < contadorData) {
			tiraData(indice);
		} else {
			puts("Índice inválido");
		}
	}

	void somaDataMenu() {
		unsigned int indice;
		imprimirTodasDatas()
		fputs("Digite o índice para selecionar a data: ", stdout);
		scanf("%d", &indice);

		if (indice < contadorData) {
			printf("Digite a quantidade de dias que deseja somar à data %s:", imprimeData())	
		} else {
			puts("Índice inválido");
		}
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
		puts("\e[1;1H\e[2J");
	}

	void colocaData(Data *data){
		*futuroNode = (Node *)malloc(sizeof(Node));
		if (*futuroNode != NULL){
			(*futuroNode)->data = data;
			(*futuroNode)->proximo = NULL;
			futuroNode = &((*futuroNode)->proximo);
			puts("Data adicionada com sucesso");
		} else {
			puts("Erro: memoria insuficiente");
		}
	}

	void tiraData(unsigned int indice) {
		Node *atual = root.primeiro;
		Node *anterior;

		for (i = 0; i < indice; i++) {
			anterior = atual;
			atual = atual -> proximo;
		}

		liberaData(atual->data);

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

	Data *achaData(unsigned int indice) {
		Node *atual = root.primeiro;
		for (i = 0; i < indice; i++) {
			atual = atual->proximo;
		}
		at
	}


	void imprimirTodasDatas() {
		puts("Datas criadas:");
		Node *atual = root.primeiro;
		for (i = 0; i < contadorData; i++){
			//TODO: Suporte para diferentes formatções
			printf("%d - %s", i+1, imprimeData(atual->data, "ddmmaaaa"));
			atual = atual->proximo;
		}
	}
