#include <stdio.h>
#include <math.h>

int anoMaior (int anoAtual) {
  int diferenca, prox, somaNecessaria, quociente;

  diferenca = anoAtual - 1986;
  if (diferenca < 76) {
    somaNecessaria = 76 - diferenca;
    prox = somaNecessaria + anoAtual;
    return prox;
  } else if (diferenca > 76) {
      quociente = floor(diferenca/76);
      prox = 76*(quociente+1) +1986;
  } else {
      prox = anoAtual + 76;
      return prox;
  }
}

int anoMenor (int anoAtual) {
  int diferenca, prox, quociente;

  diferenca = 1986 - anoAtual;
  if (diferenca <= 76) {
    return 1986;
  } else {
    quociente = floor(diferenca/76);
    prox = 1985 - (76*quociente);
    return prox;
  }
}

int main() {
  
  int anoAtual;

  puts("Insira o ano desejado: ");
    scanf("%d", &anoAtual);

  if (anoAtual >= 1986) {
    printf("O proximo cometa passara em %d \n", anoMaior(anoAtual));  
  } else {
    printf("O proximo cometa passra em %d \n", anoMenor(anoAtual));
  }
    return 0;
}
