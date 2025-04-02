#include <stdio.h>

int main(int argc, char *argv[])
{
  char* name;

  name = (char *) malloc(sizeof(char)*10);

  if (name == NULL) {
    puts("The allocation failed");
    return 0;
  }

  printf("Welcome %s - Hello World\n");

  return 0;
}
