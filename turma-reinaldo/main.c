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
//Cria uma arvore vazia
Node* criarArvoreVazia();

//Cria uma arvore com raiz raizData, e com subarvores a esqeurda e direita
Node* criarArvore(int raizData, Node* esquerda, Node* direita);

//Limpar arvore
void limparArvore(Node* raiz);

//Verifica se arvore é vazia
int arvoreVazia(Node* raiz);

//Verifica se um item pertence
int arvorePertence(Node* raiz, int chave);

//imprime arvore
void imprimeArvore(Node* raiz);

//Funcoes auxiliares
void inserirArvore(Node* raiz, int chave);


//Main
int main(int argc, char *argv[])
{
    Node* a1 = criarArvore(1, criarArvoreVazia(), criarArvoreVazia());
    Node* a2 = criarArvore(2, criarArvoreVazia(), a1);
    Node* a3 = criarArvore(3, criarArvoreVazia(), criarArvoreVazia());
    Node* a4 = criarArvore(4, criarArvoreVazia(), criarArvoreVazia());
    Node* a5 = criarArvore(5, a3, a4);
    Node* a = criarArvore(0, a2, a5);

// Impressão da árvore
    printf("Árvore criada:\n");
    imprimeArvore(a);
    printf("\n");

    // Testando a busca de elementos
    printf("O elemento 1 está na árvore? %s\n", arvorePertence(a, 1) ? "Sim" : "Não");
    printf("O elemento 9 está na árvore? %s\n", arvorePertence(a, 9) ? "Sim" : "Não");

    // Liberando memória
    limparArvore(a);

  return 0;
}

//Functions Definitions
Node* criarArvoreVazia() {
    return NULL;
}

Node* criarArvore(int raizData, Node* esquerda, Node* direita) {
  Node* raiz = (Node *) malloc(sizeof(Node));

  if (raiz == NULL) {
    puts("Erro na alocacao de memoria no criarArvore");
    return NULL;
  } 

  raiz -> chave = raizData;
  raiz -> esquerda = esquerda;
  raiz -> direita = direita;

  return raiz;

}

void limparArvore(Node* raiz) {
    if (arvoreVazia(raiz) == 1) {
        return;
    }

    limparArvore(raiz->esquerda);
    limparArvore(raiz->direita);

    free(raiz);
    raiz = NULL;

    return;
}

int arvoreVazia(Node* raiz) {
    if (raiz == NULL) {
        return 1;
    } else {
        return 0;
        }
    }

int arvorePertence(Node* raiz, int chave) {
    if (arvoreVazia(raiz) == 1) {
        return 0;
    }

    if (raiz->chave == chave) {
        return 1;
    
    }

    if (arvorePertence(raiz->esquerda, chave) == 1) {
        return 1; 
    } else if (arvorePertence(raiz->direita, chave) == 1) {
        return 1;
    } else {
        return 0;
    }
}

void imprimeArvore(Node* raiz) {
    if (arvoreVazia(raiz) == 1) {
        return;
    }
    printf("%d\n", raiz->chave);

    imprimeArvore(raiz->esquerda);
    imprimeArvore(raiz->direita);

}

void inserirArvore(Node* raiz, int chave) {
    if (arvoreVazia(raiz) == 1) {
        return;
    }

    if (arvoreVazia(raiz->esquerda) == 1) {
        raiz->esquerda-> chave = chave;
    } else {
        inserirArvore(raiz->esquerda, chave);
    }
}
