#include <stdio.h>
#include <math.h>

int anoMaior (int anoAtual) {
  int diferenca, prox, somaNecessaria, quociente;

    if (anoAtual > 1986) {
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
}

int main() {
  
  int anoAtual;


  puts("Insira o ano desejado: ");
    scanf("%d", &anoAtual);

  printf("O proximo cometa passara em %d \n", anoMaior(anoAtual));  

    return 0;
}
