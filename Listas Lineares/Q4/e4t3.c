#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// estrutura de nó da pilha
typedef struct No {
    char dado;
    struct No* proximo;
} No;
 
// criar um novo nó
No* criarNo(char dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (!novoNo) {
        printf("Erro de alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    novoNo->dado = dado;
    novoNo->proximo = NULL;
    return novoNo;
}
 
// verificar se a pilha ta vazia
int estaVazia(No* topo) {
    return !topo;
}
 
// empilhar um elemento
void empilhar(No** topo, char dado) {
    No* novoNo = criarNo(dado);
    novoNo->proximo = *topo;
    *topo = novoNo;
}
 
// desempilhar um elemento
char desempilhar(No** topo) {
    if (estaVazia(*topo)) {
        return '\0';
    }
    No* temp = *topo;
    char desempilhado = temp->dado;
    *topo = (*topo)->proximo;
    free(temp);
    return desempilhado;
}
 
// verificar se os parenteses são balanceados
const char* verificarExpressao(char* expressao) {
    No* pilha = NULL;
    int i;
    int tamanho = strlen(expressao);
 
    for (i = 0; i < tamanho; i++) {
        if (expressao[i] == '(') {
            empilhar(&pilha, '(');
        } else if (expressao[i] == ')') {
            if (estaVazia(pilha)) {
                return "incorreta";
            }
            desempilhar(&pilha);
        }
    }
 
    // verificação p/ parentese no final
    if (!estaVazia(pilha) && pilha->proximo == NULL && expressao[tamanho - 1] == '(') {
        desempilhar(&pilha);
    }
 
    if (estaVazia(pilha)) {
        return "correta";
    } else {
        return "incorreta";
    }
}
 
int main() {
    char expressao[1001];
    fgets(expressao, 1001, stdin);
    expressao[strcspn(expressao, "\n")] = '\0';
    printf("%s\n", verificarExpressao(expressao));
    return 0;
}
