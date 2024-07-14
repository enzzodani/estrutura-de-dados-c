#include <stdio.h>
#include <stdlib.h>

//Node structure
typedef struct Node Node;
struct Node {
  int chave;
  Node* esquerda;
  Node* direita;
};

//Functions Declaration
Node* criarArvore(int chave);

void inserirNoArvore(int chave);

void removerNoArvore(int chave);

Node* obterNovalor(Node* raiz, int chave);

void listarArvoreOrdem(Node* raiz);

void listarArvorePreOrdem(Node* raiz);

void listarArvorePosOrdem(Node* raiz);

Node* obtervalorMaximoArvore(Node* raiz);

Node* obtervalorMinimoArvore(Node* raiz);

Node* obterSucessorNo(int chaveSucessora);

Node* obterAntecessorNo(Node* raiz);

//Auxliar Functions
Node* inserirRecursivo(Node* noAtual, int chave);

//Root of the Tree (must to be a global variable)
Node* raizArvore = NULL;

//Main
int main(int argc, char *argv[])
{
  int operacao;

  switch (operacao) {
    case 1:
    raizArvore = criarArvore(chave);
    break;

    case 2:
    break;
    
    case 3:
    break;
    
    case 4:
    break;
    
    case 5:
    break;
    
    case 6:
    break;
    
    case 7:
    break;
    
    case 8:
    break;
    
    case 9:
    break;
    
    case 10:
    break;
    
    case 11:
    break;
    
    case 0:
    break;
    
    default:

  }

  return 0;
}

//Functions Definitions
Node* criarArvore(int chave) {
  Node* raiz = (Node *) malloc(sizeof(Node));

  if (raiz == NULL) {
    puts("Erro na alocacao de memoria no criarArvore");
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

  Node* noAtual = raizArvore;

  while(1) {
    if (novoNo < noAtual) { 
      if (noAtual -> esquerda == NULL) {
        noAtual -> esquerda = novoNo;
        return;
      } else {
        noAtual = noAtual -> esquerda;
      }
    } else if (novoNo > noAtual) {
      if (noAtual -> direita == NULL) {
        noAtual -> direita = novoNo;
        return;
      } else {
        noAtual = noAtual -> direita;
      }
    } else {
      return;
    }
  }
  
}
