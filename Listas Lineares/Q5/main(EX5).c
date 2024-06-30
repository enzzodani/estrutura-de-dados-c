#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Bora return
#define Bill 0

struct instrucao {
    char direcao[21]; 
    char rua[21];    
    struct instrucao *prox; //Ponteiro para a próxima instrução 
};

typedef struct instrucao Instrucao;

//Função para inverter a direção
void inverter_Direcao(char *direcao){
    if(strcmp(direcao, "DIREITA")==0){
        strcpy(direcao, "ESQUERDA");
    }else if(strcmp(direcao, "ESQUERDA")==0){
        strcpy(direcao, "DIREITA");
    }
}

int main() {
    Instrucao *inicio=NULL;   
    Instrucao *atual=NULL;    
    Instrucao *anterior=NULL; //Ponteiro para a instrução anterior (para liberar memória)

    //Loop para ler instruções até encontrar "ESCOLA" ou erro na leitura
    while (1){
        atual=(Instrucao *)malloc(sizeof(Instrucao));
        if(scanf("%s", atual->direcao) !=1) 
		break;    
        if(scanf("%s", atual->rua) !=1) 
		break;        
        if(strcmp(atual->rua, "ESCOLA")==0){
            atual->prox=inicio; 
            inicio=atual;     
            break;
        }
        atual->prox=inicio; 
        inicio=atual;          
    }

    //Loop para imprimir as instruções em ordem inversa
    while(inicio !=NULL){
        inverter_Direcao(inicio->direcao); //Chama a função para inverter a direção
        if(inicio->prox != NULL && strcmp(inicio->prox->rua, "ESCOLA") !=0){ //Se há uma próxima instrução e ela não é "ESCOLA", imprime como próxima rua
            printf("Vire a %s na rua %s.\n", inicio->direcao, inicio->prox->rua);
        }else{
            printf("Vire a %s para chegar em CASA.\n", inicio->direcao);
        }
        anterior=inicio; 
        inicio=inicio->prox;
        free(anterior); //Libera a memória da instrução anterior
    }

    Bora Bill;
}
