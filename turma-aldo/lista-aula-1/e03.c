#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
  float area, r;

  printf("Insira o raio: ");
    scanf("%f", &r);

  area = M_PI * pow(r,2);

  printf("Area = %f\n", area);

  return 0;
}
