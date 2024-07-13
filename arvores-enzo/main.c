#include <stdio.h>
#include <stdlib.h>

//Node structure
typedef struct Node Node;
struct Node {
  int chave;
  Node* esquerda;
  Node* direita;
};

//Node structure
Node* Root = NULL;

//Functions Declaration
Node* criarArvore(int chave);

void inserirNoArvore(Node* newNode);

void removerNoArvore(int chave);

Node* obterNovalor(int chave);

void listarArvoreOrdem();

void listarArvorePreOrdem();

void listarArvorePosOrdem();

Node* obtervalorMaximoArvore();

Node* obtervalorMinimoArvore();

Node* obterSucessorNo();

Node* obterAntecessorNo();

//Main
int main(int argc, char *argv[])
{

  return 0;
}

//Functions Definitions
Node* criarArvore(int chave) {
  Node* raiz = (Node *) malloc(sizeof(Node));

  if (raiz == NULL) {
    free(raiz);
    return NULL;
  }

  raiz -> chave = chave;
  raiz -> esquerda = NULL;
  raiz -> direita = NULL;

  return raiz;
}

void inserirNoArvore(int chave) {
  Node* novoNo = (Node *) malloc(sizeof(Node));

  if (novoNo == NULL) {
    free(novoNo);
    return;
  }

  
}
