#include <stdio.h>

int main(int argc, char *argv[])
{
  float n[3], media;
  
  n[0] = 20;

  for (int i = 0; i < 2; i++) {
    printf("Digite a nota %d: ", i+2);
    scanf("%f", &n[i+1]);
  }

  media = (n[1] + n[2] + n[0]) / 3;

  printf("Media: %.1f\n", media);

  return 0;
}
