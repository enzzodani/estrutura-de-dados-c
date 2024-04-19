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
void uniao(int array1[], int size1, int array2[], int size2, int resultado[], int *sizeResult) {
    int i;
    for (i = 0; i < size1; i++) {
        resultado[*sizeResult] = array1[i];
        (*sizeResult)++;
    }
 
    for (i = 0; i < size2; i++) {
        if (!estaPresente(array1, size1, array2[i])) {
            resultado[*sizeResult] = array2[i];
            (*sizeResult)++;
        }
    }
}
void intersecao(int array1[], int size1, int array2[], int size2, int resultado[], int *sizeResult) {
    int i;
    for (i = 0; i < size1; i++) {
        if (estaPresente(array2, size2, array1[i])) {
            resultado[*sizeResult] = array1[i];
            (*sizeResult)++;
        }
    }
}
void diferenca(int array1[], int size1, int array2[], int size2, int resultado[], int *sizeResult) {
    int i;
    for (i = 0; i < size1; i++) {
        if (!estaPresente(array2, size2, array1[i])) {
            resultado[*sizeResult] = array1[i];
            (*sizeResult)++;
        }
    }
}
int main() {
    int size1, size2;
    int array1[MAX_SIZE];
    int array2[MAX_SIZE];
    int unionResult[MAX_SIZE * 2]; 
    int resultadoIntersecao[MAX_SIZE]; 
    int resultadodiferenca1[MAX_SIZE]; 
    int resultadodiferenca2[MAX_SIZE]; 
    int sizeResult = 0;
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
    scanf("%d", &size2);
    if (size2 <= 0) {
        printf("\nO numero de elementos do vetor deve ser maior do que zero\n");
        printf("\nEntre com o numero de elementos do vetor 2: ");
    scanf("%d", &size2);
    }
    printf("\nEntre com os elementos do vetor 2: ");
    for (i = 0; i < size2; i++) {
        scanf("%d", &array2[i]);
    }
    for (i = 0; i < size2 - 1; i++) {
        for (j = i + 1; j < size2; j++) {
            while (array2[i] == array2[j]) {
                printf("\nO vetor nao pode ter elementos repetidos\n");
                printf("\nEntre com os elementos do vetor 2: ");
    for (i = 0; i < size2; i++) {
        scanf("%d", &array2[i]);
    }
                
            }
        }
    }
    uniao(array1, size1, array2, size2, unionResult, &sizeResult);
    printf("\nVetor que representa a uniao dos vetores de entrada:");
    for (i = 0; i < sizeResult; i++) {
        printf(" %d", unionResult[i]);
    }
    
    sizeResult = 0;
    intersecao(array1, size1, array2, size2, resultadoIntersecao, &sizeResult);
    printf("\n\nVetor que representa a interseccao dos vetores de entrada:");
    for (i = 0; i < sizeResult; i++) {
        printf(" %d", resultadoIntersecao[i]);
    }
    
    sizeResult = 0;
    diferenca(array1, size1, array2, size2, resultadodiferenca1, &sizeResult);
    printf("\n\nVetor que representa a diferenca entre o vetor 1 e o vetor 2:");
    for (i = 0; i < sizeResult; i++) {
        printf(" %d", resultadodiferenca1[i]);
    }
    
    sizeResult = 0;
    diferenca(array2, size2, array1, size1, resultadodiferenca2, &sizeResult);
    printf("\n\nVetor que representa a diferenca entre o vetor 2 e o vetor 1:");
    for (i = 0; i < sizeResult; i++) {
        printf(" %d", resultadodiferenca2[i]);
    }
    printf("\n");
    return 0;
}
