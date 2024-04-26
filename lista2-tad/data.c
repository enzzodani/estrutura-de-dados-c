#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "data.h"

struct data{ //Declaração do struct data
  unsigned int dia;
  unsigned int mes;
  unsigned int ano;
};

//Função que cria uma data dinâmicamente
Data* criaData(unsigned int dia, unsigned int mes, unsigned int ano) {
  Data *d = (Data *) malloc(sizeof(Data));

  if (d != NULL) {
    d -> dia = dia;
    d -> mes = mes;
    d -> ano = ano;
  }
  return (d);
}

//Libera a memória da data criada dinâmicamente
void liberaData(Data *d) {
  if(d != NULL) {
    free(d);
  }

//Função que soma dias em uma data e retorna uma nova data
Data* somaDiasData(Data d, unsigned int dias){
  Data *novoDia = (Data *) malloc(sizeof(Data));
  }

//Função que subtrai dias em uma data e retorna uma nova data
Data *subtrairDiasData(Data d, unsigned int dias) {
  Data *novoDia = (Data *) malloc(sizeof(Data));
  }

//Função que atribui uma nova data à uma data passada e caso falhe, transforma a data passada em NULL
void atribuirData(Data *d, unsigned int dia, unsigned int mes, unsigned int ano) {
    
    d -> dia = dia;
    d -> mes = mes;
    d -> ano = ano;
 
  }

//Função que obtém o dia da data
unsigned int obtemDiaData(Data d) {
  return d.dia;
  }

//Função que obtém o mes da Data
unsigned int obtemMesData(Data d) {
  return d.mes;
}

//Função que obtém o ano da Data
unsigned int obtemAnoData(Data d) {
  return d.ano;
  }

//Função que
unsigned int bissextoData(Data d) {
  
  }

//Função que
int comparaData(Data d1, Data d2) {

  }

//Função que
unsigned int numeroDiasData(Data d1, Data d2) {
  
  }

//Função que imprime a data passada em uma formatação especifica
char* imprimeData(Data d, char *formato) {

  }
