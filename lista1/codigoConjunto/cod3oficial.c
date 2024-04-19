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
void uniao(int array1[], int size1, int array2[], int tamanho2, int resultado[], int *tamanhoResultado) {
    int i;
    for (i = 0; i < size1; i++) {
        resultado[*tamanhoResultado] = array1[i];
        (*tamanhoResultado)++;
    }
 
    for (i = 0; i < tamanho2; i++) {
        if (!estaPresente(array1, size1, array2[i])) {
            resultado[*tamanhoResultado] = array2[i];
            (*tamanhoResultado)++;
        }
    }
}
void intersecao(int array1[], int size1, int array2[], int tamanho2, int resultado[], int *tamanhoResultado) {
    int i;
    for (i = 0; i < size1; i++) {
        if (estaPresente(array2, tamanho2, array1[i])) {
            resultado[*tamanhoResultado] = array1[i];
            (*tamanhoResultado)++;
        }
    }
}
void diferenca(int array1[], int size1, int array2[], int tamanho2, int resultado[], int *tamanhoResultado) {
    int i;
    for (i = 0; i < size1; i++) {
        if (!estaPresente(array2, tamanho2, array1[i])) {
            resultado[*tamanhoResultado] = array1[i];
            (*tamanhoResultado)++;
        }
    }
}
int main() {
    int size1, tamanho2;
    int array1[MAX_SIZE];
    int array2[MAX_SIZE];
    int resultadoUniao[MAX_SIZE * 2]; 
    int resultadoIntersecao[MAX_SIZE]; 
    int resultadodiferenca1[MAX_SIZE]; 
    int resultadodiferenca2[MAX_SIZE]; 
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
        scanf("%d", &array1[i]);
    }
    for (i = 0; i < size1 - 1; i++) {
        for (j = i + 1; j < size1; j++) {
            while (array1[i] == array1[j]) {
                printf("\nO vetor nao pode ter elementos repetidos\n");
                printf("\nEntre com os elementos do vetor 1: ");
                for (i = 0; i < size1; i++) {
        scanf("%d", &array1[i]);
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
        scanf("%d", &array2[i]);
    }
    for (i = 0; i < tamanho2 - 1; i++) {
        for (j = i + 1; j < tamanho2; j++) {
            while (array2[i] == array2[j]) {
                printf("\nO vetor nao pode ter elementos repetidos\n");
                printf("\nEntre com os elementos do vetor 2: ");
    for (i = 0; i < tamanho2; i++) {
        scanf("%d", &array2[i]);
    }
                
            }
        }
    }
    uniao(array1, size1, array2, tamanho2, resultadoUniao, &tamanhoResultado);
    printf("\nVetor que representa a uniao dos vetores de entrada:");
    for (i = 0; i < tamanhoResultado; i++) {
        printf(" %d", resultadoUniao[i]);
    }
    
    tamanhoResultado = 0;
    intersecao(array1, size1, array2, tamanho2, resultadoIntersecao, &tamanhoResultado);
    printf("\n\nVetor que representa a interseccao dos vetores de entrada:");
    for (i = 0; i < tamanhoResultado; i++) {
        printf(" %d", resultadoIntersecao[i]);
    }
    
    tamanhoResultado = 0;
    diferenca(array1, size1, array2, tamanho2, resultadodiferenca1, &tamanhoResultado);
    printf("\n\nVetor que representa a diferenca entre o vetor 1 e o vetor 2:");
    for (i = 0; i < tamanhoResultado; i++) {
        printf(" %d", resultadodiferenca1[i]);
    }
    
    tamanhoResultado = 0;
    diferenca(array2, tamanho2, array1, size1, resultadodiferenca2, &tamanhoResultado);
    printf("\n\nVetor que representa a diferenca entre o vetor 2 e o vetor 1:");
    for (i = 0; i < tamanhoResultado; i++) {
        printf(" %d", resultadodiferenca2[i]);
    }
    printf("\n");
    return 0;
}
