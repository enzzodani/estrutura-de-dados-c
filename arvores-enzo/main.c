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

void inserirNoArvore(Node* raiz, int chave);

void removerNoArvore(Node* raiz, int chave);

Node* obterNovalor(Node* raiz, int chave);

void listarArvoreOrdem(Node* raiz);

void listarArvorePreOrdem(Node* raiz);

void listarArvorePosOrdem(Node* raiz);

Node* obtervalorMaximoArvore(Node* raiz);

Node* obtervalorMinimoArvore(Node* raiz);

Node* obterSucessorNo(int chaveSucessora);

Node* obterAntecessorNo(Node* raiz);


//Main
int main(int argc, char *argv[])
{
  int operacao;

  switch (operacao) {
    case 1:
    Node* raizArvore = criarArvore(chave);
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

void inserirNoArvore(Node* raiz, int chave) {

  if (raiz->chave == chave) {
    
    puts("A chave ja existe");
    return;

  } else if (raiz->chave > chave) {
      if (raiz->esquerda == NULL) {
        Node* novoNo = (Node *) malloc(sizeof(Node));

        if (novoNo == NULL) {
          free(novoNo);
          return;
        }

        novoNo -> chave = chave;
        raiz->esquerda = novoNo;
        return;

      } else {
        inserirNoArvore(raiz->esquerda, chave);
      }
  } else {
      if (raiz->direita == NULL) {
          Node* novoNo = (Node *) malloc(sizeof(Node));

          if (novoNo == NULL) {
            free(novoNo);
            return;
          }

          novoNo -> chave = chave;
          raiz->direita = novoNo;
          return;

    } else {
      inserirNoArvore(raiz->direita, chave);
    }
  } 

}

void removerNoArvore(Node* raiz, int chave) {

}
