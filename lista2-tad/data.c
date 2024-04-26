#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "data.h"

struct data{
  unsigned int dia;
  unsigned int mes;
  unsigned int ano;
};

Data* criaData(unsigned int dia, unsigned int mes, unsigned int ano) {
  Data *d = (Data *) malloc(sizeof(Data));

  if (d != NULL) {
    d -> dia = dia;
    d -> mes = mes;
    d -> ano = ano;
  }
  return (d);
}

void liberaData(Data *d) {
  if(d != NULL) {
    free(d);
  }

Data* somaDiasData(Data d, unsigned int dias){
  Data *novoDia = (Data *) malloc(sizeof(Data));
  }
  
Data *subtrairDiasData(Data d, unsigned int dias) {
  Data *novoDia = (Data *) malloc(sizeof(Data));
  }

void atribuirData(Data *d, unsigned int dia, unsigned int mes, unsigned int ano) {
    
    d -> dia = dia;
    d -> mes = mes;
    d -> ano = ano;
 
  }

unsigned int obtemDiaData(Data d) {
  return d.dia;
  }

unsigned int obtemMesData(Data d) {
  return d.mes;
}

unsigned int obtemAnoData(Data d) {
  return d.ano;
  }

