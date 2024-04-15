/*
 *Elabore um programa em C para receber dois vetores de números inteiros e mostrar os vetores que representam o conjunto união dos elementos, o conjunto intersecção dos elementos e o conjunto diferença dos elementos. O programa deve receber como entrada o número de elementos de cada vetor e cada um dos elementos que compõe esses vetores.

 

Considerações sobre as entradas e saídas e respectivas formatações:

·       O número de elementos dos vetores deve ser inteiro maior do que zero

·       Os elementos de cada vetor de entrada devem ser distintos
 */
#include <stdio.h>

void recebeVetor();

int main(int argc, char *argv[])
{
  int numUm;
  int numDois;

  //Coleta do Vetor 1 
  printf("Entre com o numero de elementos do vetor 1: ");
    scanf("%d", &numUm);

  int *vetorUm = malloc(numUm * sizeof(int)); 
  
  

  return 0;
}

void recebeVetor();
