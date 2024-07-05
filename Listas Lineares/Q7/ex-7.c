#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int posicao = 0;

typedef struct Inimigo {
    int posicao;
    int id;
    struct Inimigo *antInimigo;
    struct Inimigo *proxInimigo;

}Inimigo;

typedef struct {
    Inimigo *pStart; // ponteiros para o ínicio e fim da fila
    Inimigo *pEnd;

}Fila;

Fila *criarFila() {
    Fila *fila = malloc(sizeof(Fila));
    if (fila == NULL) {
        printf("alocacao falhou");
    }

    fila->pStart = NULL;
    fila->pEnd = NULL;

    return fila;
}

void enfileirar(Fila *fila, int id) {
    Inimigo *novoInimigo = malloc(sizeof(Inimigo));
    if (novoInimigo == NULL) {
        printf("alocacao falhou");
    }

    novoInimigo->posicao = posicao;
    novoInimigo->id = id;
    novoInimigo->antInimigo = fila->pEnd;
    novoInimigo->proxInimigo = NULL; // O novo inimigo é adicionado ao fim da fila, por isso o seu próximo inimigo é null

    // atualizando dados do início e fim da fila
    if (fila->pStart == NULL) { // verifica se a fila está inicialmente vazia
        fila->pStart = novoInimigo;
        fila->pEnd = novoInimigo;
    }
    else {
        fila->pEnd->proxInimigo = novoInimigo;
        fila->pEnd = novoInimigo;
    }

    posicao++;
}

Inimigo *procuraInimigo(Fila *fila, int id) {
    Inimigo *n = fila->pStart;

    while (n != NULL) { // o laço percorre toda a fila até achar o inimigo que possua aquele id
        if (n->id == id){
            break;
        }

        n = n->proxInimigo;
    }

    return n;
}

void inserir(Fila *fila, int idNovoImigo, int idReferencia) {
    Inimigo *novoInimigo = malloc(sizeof(Inimigo));
    if (novoInimigo == NULL) {
        printf("alocacao falhou");
    }

    Inimigo *inimigoReferencia = procuraInimigo(fila, idReferencia);
    if (inimigoReferencia == NULL) { // caso o nó de referência não exista, isto é, o valor de referência não consta na fila, então a função inserir é encerrada precocemente aqui
        return;
    }

    novoInimigo->posicao = inimigoReferencia->posicao + 1;
    novoInimigo->id = idNovoImigo;  // o id do novo inimigo é adicionado
    novoInimigo->proxInimigo = inimigoReferencia->proxInimigo; // o novo inimigo recebe como seu próximo inimigo o que antes era do inimigo de referência
    inimigoReferencia->proxInimigo = novoInimigo; // o próximo inimigo ao inimigo de referência é justamente esse novo inimigo criado

    // reajustando a posição de cada inimigo depois da inserção de um novo
    Inimigo *n = novoInimigo->proxInimigo;
    while (n != NULL) {
        n->posicao = n->posicao + 1;
        n = n->proxInimigo;
    }
}

void remover(Fila *fila, int id) {
    Inimigo *inimigo = procuraInimigo(fila, id);

    // reajustando a posição de cada inimigo depois da remoção de um inimigo
    Inimigo *n = inimigo->proxInimigo;
    while (n != NULL) {
        n->posicao = n->posicao - 1;
        n = n->proxInimigo;
    }

    inimigo->antInimigo->proxInimigo = inimigo->proxInimigo; // fazendo a ligação entre as duas partes que é causada pela remoção de um nó
    free(inimigo);
}

int inimigosRange(Fila *fila, int a, int b) {
    Inimigo *inimigo1 = procuraInimigo(fila, a);
    Inimigo *inimigo2 = procuraInimigo(fila, b);
    Inimigo *n;
    int qt = 0;

    if (inimigo1 != NULL && inimigo2 != NULL) {

        if (inimigo1->posicao < inimigo2->posicao) {
            n = inimigo1;
            while (n != NULL) {
                    if (n->id == inimigo2->antInimigo->id) {
                        break;
                    }

                n = n->proxInimigo;
                qt++;
            }
        }
        else if (inimigo1->posicao > inimigo2->posicao) {
            n = inimigo2;
            while (n != NULL) {
                    if (n->id == inimigo1->antInimigo->id) {
                        break;
                    }

                n = n->proxInimigo;
                qt++;
            }
        }

    }

    return qt;
}

void showFila(Fila *fila) {
    Inimigo *n = fila->pStart;

    printf("\nlista ");

    while (n != NULL) {
        printf("%d ", n->id);

        n = n->proxInimigo;

    }

    printf("\n");
}

int main() {
    Fila *fila = criarFila();
    char comando[15];
    int qtInimigos = 0;
    char inimigos[100];
    int i = 0;

    scanf("%d", &qtInimigos);
    fflush(stdin);

    fgets(inimigos, 100, stdin);
    fflush(stdin);        

    char *token = strtok(inimigos, " "); // elimina os espaços da string de entrada
    while (token != NULL) {

        int id;
        sscanf(token, "%d", &id); // converte a string para um inteiro
        enfileirar(fila, id);

        token = strtok(NULL, " "); // avança para o próximo token
    }

    while  (comando[0] != 'F') {
        char tarefa;
        int a = 0, b = 0;
        
        fgets (comando, 100, stdin);
        fflush(stdin);        

        char *token = strtok(comando, " "); // elimina os espaços da string de entrada
    
        sscanf(token, "%c", &tarefa); // converte a string para um Char
        token = strtok(NULL, " "); // avança para o próximo token
        
        if (token != NULL) {
            sscanf(token, "%d", &a);
            token = strtok(NULL, " "); // avança para o próximo token

            if (token != NULL) {
                sscanf(token, "%d", &b);
            }
        }


        switch (tarefa) {
            case 'I':
                inserir(fila, a, b);
                break;
            case 'R':
                remover(fila, a);
                break;
            case 'C':
                printf("%d", inimigosRange(fila, a, b));
            case 'M':
                showFila(fila);
                break;
        }
    }


    return 0;
}
