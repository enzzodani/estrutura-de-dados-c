/*
 * Elabore um programa na linguagem C para receber a temperatura máxima de cada um dos dias de um mês de um ano e exibir as seguintes informações: a) o(s) dia(s) que teve(tiveram) a maior temperatura máxima registrada e qual foi essa temperatura; b) a média da temperatura máxima no mês. O algoritmo deve receber inicialmente o ano que será considerado, o mês dento do ano que será considerado e finalmente cada um dos dias com a respectiva temperatura máxima registrada. (++)

 

Considerações sobre as entradas e saídas e respectivas formatações:

·       O ano de referência deve ter valor inteiro, maior ou igual a 2000 e menor do que 2024. (feita)

·       (feita)O mês de referência informado deve ser valor inteiro maior do que zero e menor do que 12. Assim o número 1 se refere a janeiro, o 2 se refere a fevereiro e assim sucessivamente.

·       A temperatura de máxima informada para cada dia do mês de referência deve ser valor inteiro maior do que -100 e menor do que 100

·       A temperatura máxima média deve ser valor real com precisão de uma casa decimal
 */

#include <stdio.h>
#include <stdlib.h>

void recebeTemperatura(int *v, int tam){
  printf("Temperaturas medidas (em graus Celsius):\n");
  
  int *ponteiroArray = v;
  int verificador = -101;

  for (int i = 0; i < tam; i++) {
    do { 
    //Coleta de Temperaturas
      printf("Dia %d: ", i+1);
        scanf("%d", &verificador);
    //Verificação de Temperatura 
    if (verificador < -100 || verificador > 100) {
      printf("Temperatura deve ser maior ou igual a -100 graus e menor ou igual a 100 graus\n");
      }
    } while (verificador < -100 || verificador > 100);
    
    *(ponteiroArray) = verificador;

    ponteiroArray++;
    printf("\n");
  }
}

int achaTemperatura(int *v, int tam){
  int maior = v[0];

  for (int i = 1; i<tam; i++) {
    if (maior < v[i]) {
      maior = v[i];
    }
  }
  return maior;
}

int* maiorDia(int *v, int tam, int maiorTemp){
  int *ponteiroArray = v;
  int maiorDias[];

  for (int i = 0; i<tam; i++) {
  
  }
  return maiorDias;
}

int main(int argc, char *argv[])
{

  int ano = 0;
  int mes = 0;
  int temperaturas[29];
  int maioresDias[];

  int tamamhoArray = sizeof(temperaturas)/sizeof(temperaturas[0]);

  do {

// Coleta do ano
  printf("Entre com o ano da medicao das temperaturas: ");
    scanf("%d", &ano);
  printf("\n");

//Verificação do ano
  if (ano < 2000 || ano>2023){
    printf("Ano deve ser maior ou igual a 2000 e menor ou igual a 2024\n");
    }
  } while (ano < 2000 || ano > 2023);

  do {
//Coleta do Mês
  printf("Entre com o mes da medicao das temperaturas: ");
    scanf("%d", &mes);

//Verificação do mês
  if (mes <= 0 || mes > 12){
    printf("Mes deve ser maior do que zero e menor ou igual a 12\n");
    }
  } while (mes <= 0 || mes > 12);

//  recebeTemperatura(temperaturas, tamamhoArray);
 // int maiorTemperatura = achaTemperatura(temperaturas, tamamhoArray);

  return 0;
}
