#include <stdio.h>
#include <stdlib.h>

//Declaração de Função
void recebeNota(struct *vetor, int tamanho);

float notaCaso1(struct dadosAluno aluno);

float notaCaso2(struct dadosAluno aluno);

float notaCaso3(struct dadosAluno aluno);

float notaCaso4(struct dadosAluno aluno);

float mediaGeral();

float achaMaiorMedia();

float achaMenorMedia();

void achaMelhorAluno();

void achaPiorAluno();

//Definição de struct 
struct dadosAluno {
  unsigned int matrícula;
  float notas[4];
};

int main(int argc, char *argv[])
{
  //Declaração de variáveis
  unsigned int numeroDeAlunos;

  //Coleta
  printf("Entre com o numero de alunos da turma: ");
    scanf("%d", &numeroDeAlunos);
  printf("\n");

  //Verificação do numero de alunos
  if (numeroDeAlunos <= 0 || numero > 50) {
    printf("O numero de alunos na turma deve ser maior do que zero e menor ou igual a 50\n");
    printf("Entre com o numero de alunos da turma: ");
      scanf("%d", &numeroDeAlunos);
    printf("\n");
  }  

  struct dadosAluno *alunos = malloc(numeroDeAlunos * sizeof(struct dadosAluno))



  //Liberação da memória
  free(alunos);

  return 0;
}

//Definição de Funções

void recebeNota(struct *vetor, int tamanho) {

}
