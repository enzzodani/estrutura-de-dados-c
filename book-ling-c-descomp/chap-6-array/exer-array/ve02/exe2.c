/*Crie um programa que leia do teclado seis valores inteiros e em seguida
mostre na tela os valores lidos na ordem inversa.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  //Variable Declaration
  int array[6];

  //Colection
  printf("Write 6 numbers: \n");
  for (int i = 0; i<6;i++) {

    printf("Number %d: ", i+1);
      scanf("%d", &array[i]);

  }
  //Print
  printf("Print the array in reverse order: \n");
    for (int i = 5;i>=0;i--) {
      printf("\t%d", array[i]);
    } 

  return EXIT_SUCCESS;
}
