#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BUFFER 100

typedef struct Pessoa {
    char nome[TAM_BUFFER];
    struct Pessoa *proximo;
    struct Pessoa *anterior;
} Pessoa;

typedef struct Roda {
    unsigned int tamanho;
    Pessoa *inicio;
    Pessoa *final;
} Roda;

Roda roda = {.tamanho=0, .inicio=NULL, .final=NULL};
unsigned short pontos = 0;

void addPessoa(char nome[]) {
    Pessoa *novaPessoa = (Pessoa*) malloc(sizeof(Pessoa));
    strcpy(novaPessoa->nome, nome);
    
    if (roda.tamanho > 0) {
        novaPessoa->proximo = roda.inicio;
        novaPessoa->anterior = roda.final;
        roda.inicio->anterior = novaPessoa;
        roda.final->proximo = novaPessoa;
        roda.final = novaPessoa;
    } else {
        novaPessoa->proximo = novaPessoa;
        novaPessoa->anterior = novaPessoa;
        roda.inicio = novaPessoa;
        roda.final = novaPessoa;
    }
    
    roda.tamanho++;
}

void removePessoa(Pessoa *pessoa) {
    pessoa->anterior->proximo = pessoa->proximo;
    pessoa->proximo->anterior = pessoa-> anterior;
    if (pessoa == roda.inicio) {
        roda.inicio = pessoa->proximo;
    }
    free(pessoa);
  
}

void rodaRoda(char nome[], char direcao[]) {
    Pessoa *atual = roda.inicio;
    unsigned short eliminar = 0;
    
    if (!strcmp(direcao, "horario")) {
        int i;
        for (i = 0; i < 2; i++) {
            if (!strcmp(atual->nome, nome)) {
                eliminar++;
                break;
            }
            atual = atual->proximo;
        }
    } else {
        int i;
        for (i = 0; i < 2; i++) {
            atual = atual->anterior;
            if (!strcmp(atual->nome, nome)) {
                eliminar++;
                break;
            }
        }
    }
    
    if (eliminar) {
        removePessoa(atual);
        pontos++;
    }
}

int main()
{
    char buffer[TAM_BUFFER], nome[TAM_BUFFER];
    while (1) {
        scanf("%s", buffer);
        if (!strcmp(buffer, "FIM")) {
            break;
        }
        addPessoa(buffer);
    }
    
    int i;
    for (i = 0; i < roda.tamanho; i++) {
        scanf("%s %s", nome, buffer);
        rodaRoda(nome, buffer);
    }
    
    printf("%d", pontos);
    return 0;
}