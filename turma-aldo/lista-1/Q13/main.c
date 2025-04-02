#include <stdio.h>

/*
 * Sn = Sn-1 + Sn-2
 * S1 = 1 
 * S0 = 0
 */
int fibonnaci (int n) {
  int resultado;

  if(n == 1) {
    return 1;
  } else if (n == 0) {
    return 0;
  } else {
    resultado = fibonnaci(n-1) + fibonnaci(n-2);
    return resultado;
  }
}

int main() {

  int n;

  printf("Defina o Sn que voce quer saber: ");
    scanf("%d", &n);

  printf("O Sn de n = %d eh %d\n", n, fibonnaci(n));

  return 0;
}
