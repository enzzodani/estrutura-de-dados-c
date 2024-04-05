// Crie um programa que leia do teclado seis valores inteiros e em seguida mostre na tela os valores lidos.

#include <stdio.h>
#include <stdlib.h>

int main()
{
  
  int array[6];

  //Coleta
  printf("Write 6 numbers: \n");
  for (int i=0;i<6;i++) {
    printf("Number %d: ", i+1);
       scanf("%d", &array[i]);
  }

  //Impressão
  printf("Print array: \n");
  for (int i = 0;i<6;i++) {
    printf("\t%d", array[i]);
  }  

  printf("\n");

  return 0;
}
