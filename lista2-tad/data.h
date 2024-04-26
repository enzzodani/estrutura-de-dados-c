#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct data Data;

Data* criaData(unsigned int dia, unsigned int mes, unsigned int ano);

void liberaData(Data *d);

Data *somaDiasData(Data d, unsigned int dias);

Data *subtrairDiasData(Data d, unsigned int dias);

void atribuirData(Data *d, unsigned int dia, unsigned int mes, unsigned int ano);

unsigned int obtemDiaData(Data d);

unsigned int obtemMesData(Data d);

unsigned int obtemAnoData(Data d);

unsigned int bissextoData(Data d);

int comparaData(Data d1, Data d2);

unsigned int numeroDiasDatas(Data d1, Data d2);

char* imprimeData(Data d, char *formato);

#endif //data.h
