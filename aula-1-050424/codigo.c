#include <stdio.h>

float calcula_tempo(int vA, int vB, float D){
  float tempo = D/(vA+vB);

  return tempo;
}

float local_encontro(int vA, float tempo){

  float local = vA * tempo;

  return local;
}

int main()
{

  int velocidade_A = 0;
  int velocidade_B = 0;
  float dist = 00.0;

  printf("Entre com a distancia entre as cidades A e B: ");
    scanf("%f", &dist);
  printf("\n");

  if (dist <= 00.0) {
    printf("A distancia entre as cidades deve ser maior do que zero");
    return 0;
  }

  printf("Entre com a velocidade do automovel que parte de A para B: ");
    scanf("%d", &velocidade_A);
  printf("\n");

  if (velocidade_A <= 0) {
      printf("A velocidade do automovel deve ser maior do que zero");
      return 0;
  }

  printf("Entre com a velocidade do automovel que parte de B para A: ");
    scanf("%d", &velocidade_B);
  printf("\n");

  if (velocidade_B <= 0) {
    printf("A velocidade do automovel deve ser maior do que zero");
    return 0;
  }

  float tempo = calcula_tempo(velocidade_A, velocidade_B, dist);
  float local = local_encontro(velocidade_A, tempo);

  // Momento do encontro: 2.73 horas apos a partida dos automoveis
  printf("Momento do encontro: %.2f horas apos a partida dos automoveis\n",tempo);
  printf("\n");
  printf("Local do encontro: %.2f Km da cidade A", local);

  return 0;
}
