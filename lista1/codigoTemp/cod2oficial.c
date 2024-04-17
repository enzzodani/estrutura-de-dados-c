#include <stdio.h>
#include <stdlib.h>

void recebeTemperatura(int *v, int tam){
  printf("Temperaturas medidas (em graus Celsius):\n\n");
  
  int *ponteiroArray = v;
  int verificador = -101;
  int i;

  for (i = 0; i < tam; i++) {
    do { 
    //Coleta de Temperaturas
      printf("Dia %d: ", i+1);
        scanf("%d", &verificador);
    printf("\n");
    //Verificação de Temperatura 
    if (verificador < -100 || verificador > 100) {
      printf("Temperatura deve ser maior ou igual a -100 graus e menor ou igual a 100 graus\n\n");
      }
    } while (verificador < -100 || verificador > 100);
    
    *(ponteiroArray) = verificador;

    ponteiroArray++;
  }
}

int achaTemperatura(int *v, int tam){
  int maior = v[0];
  int i;

  for (i = 1; i<tam; i++) {
    if (maior < v[i]) {
      maior = v[i];
    }
  }
  return maior;
}

int quantidadeDias(int *v, int tam, int maiorTemp){
  int quantidade = 0;
  int i;

  for (i = 0; i < tam; i++) {
    if(v[i] == maiorTemp) {
      quantidade++;
    }
  }
  return quantidade;
}

void maiorDia(int *v, int tam, int maiorTemp, int *maiorDias){
  int contador = 0;
  int i;

  for (i = 0; i<tam; i++) {
    if (v[i] == maiorTemp) {
      maiorDias[contador] = i+1;
      contador++;
    } 
  }
}

void imprimeDias(int *v, int tam) {
  int i;

  for (i = 0; i < tam; i++) {
    printf(" %d", v[i]);
  }
}

float achaMedia(int *v, int tam){
  float media;
  float soma = 0;
  int i;
    
  for (i = 0; i < tam; i++) {
    soma = soma + v[i];
  }
  media = soma / tam;
  
  return media;
}

int main(int argc, char *argv[])
{

  int ano = 0;
  int mes = 0;
  int numDias;


// Coleta do ano
  printf("Entre com o ano da medicao das temperaturas: ");
    scanf("%d", &ano);
  printf("\n");

//Verificação do ano
  if (ano < 2000 || ano>2023){
    printf("Ano deve ser maior ou igual a 2000 e menor ou igual a 2024\n\n");
    printf("Entre com o ano da medicao das temperaturas: ");
      scanf("%d", &ano);
    printf("\n");
    }

//Coleta do Mês
  printf("Entre com o mes da medicao das temperaturas: ");
    scanf("%d", &mes);
printf("\n");
    
//Verificação do mês
  if (mes <= 0 || mes > 12){
    printf("Mes deve ser maior do que zero e menor ou igual a 12\n\n");
      printf("Entre com o mes da medicao das temperaturas: ");
    scanf("%d", &mes);
    printf("\n");
    }

  //Definição de dias no mês 
  switch(mes) {
      case 1: case 3: case 5: case 7: case 8: case 10: case 12:
          numDias = 31;
          break;
      case 4: case 6: case 9: case 11:
          numDias = 30;
          break;
      case 2:
          if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            numDias = 29;
          } else {
            numDias = 28;
          }
          break;
      default:
          printf("Mês inválido!\n");
    }

  int *temperaturas = malloc(numDias * sizeof(int));

  recebeTemperatura(temperaturas, numDias);
  int maiorTemperatura = achaTemperatura(temperaturas, numDias);

  int numMaiorDias = quantidadeDias(temperaturas, numDias, maiorTemperatura);

  int *maioresDias = malloc(numMaiorDias * sizeof(int));
  
  maiorDia(temperaturas, numDias, maiorTemperatura, maioresDias);
 
  //Impressão do Resultado
  printf("A maior temperatura maxima do mes foi de %d e aconteceu nos dias: ", maiorTemperatura);
  imprimeDias(maioresDias,numMaiorDias);
  printf("\n\n");

  printf("A temperatura maxima media no mes foi de: %.1f graus Celsius", achaMedia(temperaturas, numDias));

  //Liberação da meória alocada
  free(temperaturas);
  free(maioresDias);

  return 0;
}

