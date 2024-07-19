#include <stdio.h>
#include <stdlib.h>

//Estrutura do Nó
typedef struct Cliente Cliente;
struct Cliente {
  int senha;
  char grupo;
  Cliente* proximo;
  Cliente* anterior;
};

//Estrutura do Nó descritor
typedef struct Fila Fila;
struct Fila {
  Cliente* inicio;
  Cliente* final;
  int tamanhoNormal;
  int tamanhoPreferencial;
};

//Declaração das funções principais
void inserirCliente (char g);

void chamarCliente (int nc);

void configuracaoAtual ();

void encerrarAtendimento ();

//Declaração das funções auxiliares
Cliente* criarCliente ();

void removerCliente ();

//Variáveis Globais
Fila fila;
fila->inicio=NULL;
fila->final = NULL;
fila-> tamanhoNormal = 0;
fila-> tamanhoPreferencial = 0;

int senhaAtual = 0;

//Main 
int main(int argc, char *argv[])
{
  char operacao;

  switch (operacao) {

  }

  return 0;
}

//Definição das Funções Principais
void inserirCliente (char g) {
 Cliente* novoCliente = criarCliente();

  if (novoCliente == NULL) {
    puts("Erro na alocacao de memoria");
    return;
  }

  novoCliente -> grupo = g;
  novoCliente -> senha = senhaAtual + 1;

  if (fila->inicio == NULL) {
    fila->inicio = novoCliente;
    fila->final = novoCliente;
  } else {
    novoCliente -> anterior = fila -> final;
    fila->final->proximo = novoCliente;
    fila->final= novoCliente;
  }

  if (g = 'N') {
    fila->tamanhoNormal++;
  } else if (g = 'P') {
    fila->tamanhoPreferencial++;
  }
}

void chamarCliente () {

}

void configuracaoAtual () {

}

void encerrarAtendimento () {
  
}

//Declaração das Funções auxiliares
Cliente* criarCliente () {

  Cliente* novoCliente = (Cliente *) malloc(sizeof(Cliente));

  if (novoCliente == NULL) {
    puts("Erro na alocacao de memoria (criarCliente)");
    return NULL;
  }

  novoCliente -> proximo = NULL;
  novoCliente -> anterior = NULL;
  novoCliente -> senha = 0;
  
  return novoCliente;
}

void removerCliente () {

}
