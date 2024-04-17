#include <stdio.h>
#define MAX_SIZE 100 
int estaPresente(int vetor[], int tamanho, int elemento) {
    int i;
    for (i = 0; i < tamanho; i++) {
        if (vetor[i] == elemento) {
            return 1;
        }
    }
    return 0;
}
void uniao(int vetor1[], int size1, int vetor2[], int tamanho2, int resultado[], int *tamanhoResultado) {
    int i;
    for (i = 0; i < size1; i++) {
        resultado[*tamanhoResultado] = vetor1[i];
        (*tamanhoResultado)++;
    }
 
    for (i = 0; i < tamanho2; i++) {
        if (!estaPresente(vetor1, size1, vetor2[i])) {
            resultado[*tamanhoResultado] = vetor2[i];
            (*tamanhoResultado)++;
        }
    }
}
void intersecao(int vetor1[], int size1, int vetor2[], int tamanho2, int resultado[], int *tamanhoResultado) {
    int i;
    for (i = 0; i < size1; i++) {
        if (estaPresente(vetor2, tamanho2, vetor1[i])) {
            resultado[*tamanhoResultado] = vetor1[i];
            (*tamanhoResultado)++;
        }
    }
}
void diff(int vetor1[], int size1, int vetor2[], int tamanho2, int resultado[], int *tamanhoResultado) {
    int i;
    for (i = 0; i < size1; i++) {
        if (!estaPresente(vetor2, tamanho2, vetor1[i])) {
            resultado[*tamanhoResultado] = vetor1[i];
            (*tamanhoResultado)++;
        }
    }
}
int main() {
    int size1, tamanho2;
    int vetor1[MAX_SIZE];
    int vetor2[MAX_SIZE];
    int resultadoUniao[MAX_SIZE * 2]; 
    int resultadoIntersecao[MAX_SIZE]; 
    int resultadodiff1[MAX_SIZE]; 
    int resultadodiff2[MAX_SIZE]; 
    int tamanhoResultado = 0;
    int i, j, k;
    printf("Entre com o numero de elementos do vetor 1: ");
    scanf("%d", &size1);
    while (size1 <= 0) {
        printf("\nO numero de elementos do vetor deve ser maior do que zero\n");
    printf("\nEntre com o numero de elementos do vetor 1: ");
    scanf("%d", &size1);
    }
    printf("\nEntre com os elementos do vetor 1: ");
    for (i = 0; i < size1; i++) {
        scanf("%d", &vetor1[i]);
    }
    for (i = 0; i < size1 - 1; i++) {
        for (j = i + 1; j < size1; j++) {
            while (vetor1[i] == vetor1[j]) {
                printf("\nO vetor nao pode ter elementos repetidos\n");
                printf("\nEntre com os elementos do vetor 1: ");
                for (i = 0; i < size1; i++) {
        scanf("%d", &vetor1[i]);
    }
            }
        }
    }
    printf("\nEntre com o numero de elementos do vetor 2: ");
    scanf("%d", &tamanho2);
    if (tamanho2 <= 0) {
        printf("\nO numero de elementos do vetor deve ser maior do que zero\n");
        printf("\nEntre com o numero de elementos do vetor 2: ");
    scanf("%d", &tamanho2);
    }
    printf("\nEntre com os elementos do vetor 2: ");
    for (i = 0; i < tamanho2; i++) {
        scanf("%d", &vetor2[i]);
    }
    for (i = 0; i < tamanho2 - 1; i++) {
        for (j = i + 1; j < tamanho2; j++) {
            while (vetor2[i] == vetor2[j]) {
                printf("\nO vetor nao pode ter elementos repetidos\n");
                printf("\nEntre com os elementos do vetor 2: ");
    for (i = 0; i < tamanho2; i++) {
        scanf("%d", &vetor2[i]);
    }
                
            }
        }
    }
    uniao(vetor1, size1, vetor2, tamanho2, resultadoUniao, &tamanhoResultado);
    printf("\nVetor que representa a uniao dos vetores de entrada:");
    for (i = 0; i < tamanhoResultado; i++) {
        printf(" %d", resultadoUniao[i]);
    }
    
    tamanhoResultado = 0;
    intersecao(vetor1, size1, vetor2, tamanho2, resultadoIntersecao, &tamanhoResultado);
    printf("\n\nVetor que representa a interseccao dos vetores de entrada:");
    for (i = 0; i < tamanhoResultado; i++) {
        printf(" %d", resultadoIntersecao[i]);
    }
    
    tamanhoResultado = 0;
    diff(vetor1, size1, vetor2, tamanho2, resultadodiff1, &tamanhoResultado);
    printf("\n\nVetor que representa a diff entre o vetor 1 e o vetor 2:");
    for (i = 0; i < tamanhoResultado; i++) {
        printf(" %d", resultadodiff1[i]);
    }
    
    tamanhoResultado = 0;
    diff(vetor2, tamanho2, vetor1, size1, resultadodiff2, &tamanhoResultado);
    printf("\n\nVetor que representa a diff entre o vetor 2 e o vetor 1:");
    for (i = 0; i < tamanhoResultado; i++) {
        printf(" %d", resultadodiff2[i]);
    }
    printf("\n");
    return 0;
}
