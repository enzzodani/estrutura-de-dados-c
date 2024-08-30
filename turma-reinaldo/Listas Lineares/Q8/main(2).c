#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO_DO_NOME 20
#define TAMANHO_DO_TELEFONE 10

struct contatos{
    char nome[TAMANHO_DO_NOME + 1];
    char telefone[TAMANHO_DO_TELEFONE + 1]; //Para obter o formato XXXX-XXXX
    int numero_De_Ligacoes;
    struct contatos *prox;
};

typedef struct contatos Contatos;

Contatos *primeiro_Contato = NULL;
int length = 0;

//Função para adicionar novo contato
Contatos *add_Novo_Contato(char *nome, char *telefone, int ligacoes, int index){
    Contatos *novo=(Contatos*)malloc(sizeof(Contatos));
    strncpy(novo->nome, nome, TAMANHO_DO_NOME);
    strncpy(novo->telefone, telefone, TAMANHO_DO_TELEFONE);
    novo->numero_De_Ligacoes=ligacoes;
    novo->prox = NULL;

    if(index == 0){
        novo->prox=primeiro_Contato;
        primeiro_Contato=novo;
    }else{
        Contatos *lista_Aux=primeiro_Contato;
        int i=0;
        while(i != index - 1 && lista_Aux != NULL){
            lista_Aux = lista_Aux->prox;
            i++;
        }
        if(lista_Aux != NULL){
            novo->prox=lista_Aux->prox;
            lista_Aux->prox=novo;
        }
    }
    length++;
    return novo;
}

//Função para remover o contato selecionado
void remover_Contato(char *nome){
    Contatos *lista_Aux=primeiro_Contato;
    Contatos *anterior=NULL;

    while(lista_Aux != NULL && strcmp(lista_Aux->nome, nome) != 0){
        anterior=lista_Aux;
        lista_Aux=lista_Aux->prox;
    }

    if(lista_Aux==NULL){
        return;
    }

    if(anterior==NULL){
        primeiro_Contato = lista_Aux->prox;
    }else{
        anterior->prox = lista_Aux->prox;
    }

    free(lista_Aux);
    length--;
}

int main(){
    
    add_Novo_Contato("Hermanoteu", "4523-2248", 300, length);
    add_Novo_Contato("Ooloneia", "4523-4887", 299, length);

    return 0;
}
