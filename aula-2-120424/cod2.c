/*
 * Elabore um programa na linguagem C para receber a temperatura máxima de cada um dos dias de um mês de um ano e exibir as seguintes informações: a) o(s) dia(s) que teve(tiveram) a maior temperatura máxima registrada e qual foi essa temperatura; b) a média da temperatura máxima no mês. O algoritmo deve receber inicialmente o ano que será considerado, o mês dento do ano que será considerado e finalmente cada um dos dias com a respectiva temperatura máxima registrada. (++)

 

Considerações sobre as entradas e saídas e respectivas formatações:

·       O ano de referência deve ter valor inteiro, maior ou igual a 2000 e menor do que 2024.

·       O mês de referência informado deve ser valor inteiro maior do que zero e menor do que 12. Assim o número 1 se refere a janeiro, o 2 se refere a fevereiro e assim sucessivamente.

·       A temperatura de máxima informada para cada dia do mês de referência deve ser valor inteiro maior do que -100 e menor do que 100

·       A temperatura máxima média deve ser valor real com precisão de uma casa decimal
 */

#include <stdio.h>

void recebeTemperatura(int *v, int tam){
  printf("Temperaturas medidas (em graus Celsius):\n");
  int *ponteiroArray = v;
  for (int i = 0; i < tam; i++) {
    printf("Dia %d: ", i+1);
    scanf("%d", ponteiroArray);
    ponteiroArray++;
    printf("\n");
  }
}

int achaTemperatura(int *v, int tam){
  int *ponteiroArray = v;
  int maior = *ponteiroArray;

  for (int i = 0; i<tam; i++) {
    if (maior < *(ponteiroArray + 1)) {
      maior = *(ponteiroArray +1);
    }
  return maior;
  }
}

int* maiorDia(int *v, int tam, int maiorTemp){
  int *ponteiroArray = v;
  int maiorDias[29];

  for (int i = 0; i<tam; i++) {
  
  }
  return maiorDias;
}

int main(int argc, char *argv[])
{

  int ano, mes;
  int temperaturas[29];

  int tamamhoArray = sizeof(temperaturas)/sizeof(temperaturas[0]);
// Coleta do ano

  printf("Entre com o ano da medicao das temperaturas: ");
    scanf("%d", &ano);
  printf("Entre com o mes da medicao das temperaturas: ");
    scanf("%d", &mes);

  printf("");

  recebeTemperatura(temperaturas, tamamhoArray);
  int maiorTemperatura = achaTemperatura(temperaturas, tamamhoArray);

  return 0;
}
