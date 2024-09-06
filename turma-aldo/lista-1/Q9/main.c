#include <stdio.h>
#include <stdlib.h>

int main() {

  int t; //Definição do numero de testes
  scanf("%d", &t);

  double* num = (double *) malloc(2 * t * sizeof(double));

  for (int i = 0; i < t; i++) {
    double a, b;
    scanf("%lf %lf", &a, &b);
    num[i] = (a * b);
  }

  for (int i = 0; i < t; i++) {
    printf("%lf\n", num[i]);
  }

  return 0;
}
