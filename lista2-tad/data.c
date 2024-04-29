// data.c - Implementação das funções da biblioteca

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

//Funções auxiliares
  unsigned int diasNoMes(Data *d) {

    unsigned int quantidadeDias = 0;
    
    switch(d.mes) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            quantidadeDias = 31;
            break;
           
        case 4:
        case 6:
        case 9:
        case 11:
            quantidadeDias = 30;
            break;
           
        case 2:
          if ((d.ano % 4 == 0 && d.ano % 100 != 0) || (d.ano % 400 == 0)) {
                quantidadeDias = 29;
            } else {
                quantidadeDias = 28;
            }
            break;
    }
  return quantidadeDias;
}

//Funções principais

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

       if (novoDia == NULL) {
        // Tratamento de erro: falha na alocação de memória
        printf("Erro: Falha na alocação de memória.\n");
        return NULL;
    }

    novoDia -> dia = (d.dia) + dias; 
    novoDia -> mes = d.mes;
    novoDia -> ano = d.ano;

    verificadorDiasnoMes = diasNoMes(novoDia);

    do {
      if (novoDia -> dia > verificadorDiasnoMes) {
        novoDia -> dia -= verificadorDiasnoMes;
        (novoDia -> mes)++;
        verificadorDiasnoMes = diasNoMes(*novoDia);
      }
    } while (novoDia -> dia > verificadorDiasnoMes);

    do {
      if (novoDia -> mes > 12) {
        novoDia -> mes -= 12;
        (novoDia -> ano)++;
      }
    } while (novoDia -> mes > 12);

    return novoDia; 
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
    return d->dia;
    }

  //Função que obtém o mes da Data
  unsigned int obtemMesData(Data d) {
    return d->mes;
  }

  //Função que obtém o ano da Data
  unsigned int obtemAnoData(Data d) {
    return d->ano;
    }

  //Função que identifica se a data pertence à um ano bissexto
  unsigned int bissextoData(Data d) {
    unsigned int verificador = d.ano;
     if ((verificador % 4 == 0 && verificador % 100 != 0) || (verificador % 400 == 0)) {
      return 1;
      }
    return 0;
    }

  //Função que retorna -1 se a d1 < d2, 0 se d1=d2, e 1 se d1>d2
  int comparaData(Data d1, Data d2) {
    int diferencaAnos = d1.ano - d2.ano;
    int diferencaMeses = d1.mes - d2.mes;
    int diferencaDias = d1.dia - d2.dia;

    if(diferencaAnos < 0) {
      return -1;
    }else if (diferencaAnos > 0) {
      return 1; 
    }else if (diferencaMeses < 0) {
      return -1;
    }else if (diferencaMeses > 0) {
      return 1;
    }else if (diferencaDias < 0) {
      return -1;
    }else if (diferencaDias > 0) {
      return 1;
    }else {
      return 0;
    }
  }

  //Função que retorna o número de dias entre as datas
  unsigned int numeroDiasData(Data d1, Data d2) {
    
    }

  //Função que imprime a data passada em uma formatação especifica
  char* imprimeData(Data d, char *formato) {

    }
