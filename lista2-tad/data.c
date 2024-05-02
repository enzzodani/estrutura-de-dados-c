// data.c - Implementação das funções da biblioteca

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "data.h"

struct data{ //Declaração do struct data
  unsigned int dia;
  unsigned int mes;
  unsigned int ano;
};

//Funções auxiliares
	unsigned int diasNoMes(Data d) { //Retorna a quantidade de dias no mês da data passada como parâmetro

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
				if ((d.ano % 4 == 0 && d.ano % 100 != 0) || (d.ano % 400 == 0)) { //Verificação de ano bissexto 
					quantidadeDias = 29;
				} else {
					quantidadeDias = 28;
				}
				break;
		}
		return quantidadeDias;
	}

	// unsigned int validaData(unsigned int dia, unsigned int mes, unsigned int ano){
	// 	//TODO: Implementar validação de data	
	// }

//Funções principais

  //Função que cria uma data dinâmicamente
  Data* criaData(unsigned int dia, unsigned int mes, unsigned int ano) {
    Data *d = (Data *) malloc(sizeof(Data));
  
    if (d != NULL) {
        d -> dia = dia;
        d -> mes = mes;
        d -> ano = ano;
        printf("Data criada com sucesso.\n");
    } else {
        printf("Erro ao criar a data.\n");
    }
    return (d);
  }

  //Libera a memória da data criada dinâmicamente
  void liberaData(Data *d) {
    if(d != NULL) {
      free(d);
    }
	}

  //Função que soma dias em uma data e retorna uma nova data
  Data* somaDiasData(Data d, unsigned int dias){
    Data *novoDia = (Data *) malloc(sizeof(Data));

       if (novoDia == NULL) {
        // Tratamento de erro: falha na alocação de memória
        printf("Erro: Falha na alocação de memória.\n");
        return NULL;
    }

    novoDia -> dia = (d.dia) + dias; //Faz a soma de novos dias
    novoDia -> mes = d.mes;
    novoDia -> ano = d.ano;

    int verificadorDiasnoMes = diasNoMes(*novoDia); //verifica quantos dias tem no mes 

    do {
      if (novoDia -> dia > verificadorDiasnoMes) {
        novoDia -> dia -= verificadorDiasnoMes; // Ajeita a dia caso seja maior que o numero de dias no mes
        (novoDia -> mes)++; // incrementa 1 mes para caso o dia passe dos dias do mes
        verificadorDiasnoMes = diasNoMes(*novoDia); //atualiza a quantidade de dias do mes, visto que o mes foi incrmentado
      }
    } while (novoDia -> dia > verificadorDiasnoMes); //O loop se repete ate que o dia seja uma quantidade possível, ou seja, menor que os dias do mes 

    do {
      if (novoDia -> mes > 12) { //verifica se a quanridade de meses faz sentido dentro do ano
        novoDia -> mes -= 12; // ajeita a quantidade de meses no ano
        (novoDia -> ano)++; //incrmenta 1 ano
      }
    } while (novoDia -> mes > 12); //faz isso enquanto os meses forem maior que 12

    return novoDia; 
  }

  //Função que subtrai dias em uma data e retorna uma nova data
  Data *subtrairDiasData(Data d, unsigned int dias) {
    Data *novoDia = (Data *) malloc(sizeof(Data));

       if (novoDia == NULL) {
        // Tratamento de erro: falha na alocação de memória
        printf("Erro: Falha na alocação de memória.\n");
        return NULL;
    }
   
    int verificadorDias = d.dia - dias;

    do {
      if (verificadorDias <= 0) {
        d.mes -= 1;
        if (d.mes == 0) {
          d.mes = 12;
          d.ano--;
        }
        int verificadorDiasnoMes = diasNoMes(d);
        
        verificadorDias += verificadorDiasnoMes; 
      }
    } while (verificadorDias <= 0);

    novoDia -> dia = verificadorDias;
    novoDia -> mes = d.mes;
    novoDia -> ano = d.ano;

    return novoDia; 

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
    char imprimeData(Data d, char *formato)
    {
        char *dataFormatada = malloc(sizeof(char) * 11);
        if (dataFormatada == NULL)
        {
            printf("Erro ao alocar memoria\n");
            exit(1);
        }

        if (strcmp(formato, "ddmmaaaa") == 0)
        {
            sprintf(dataFormatada, "%02d/%02d/%04d", d.dia, d.mes, d.ano);
        }
        else if (strcmp(formato, "aaaammdd") == 0)
        {
            sprintf(dataFormatada, "%04d/%02d/%02d", d.ano, d.mes, d.dia);
        }
        else if (strcmp(formato, "aaaa") == 0)
        {
            sprintf(dataFormatada, "%04d", d.ano);
        }
        else if (strcmp(formato, "mm") == 0)
        {
            sprintf(dataFormatada, "%02d", d.mes);
        }
        else if (strcmp(formato, "dd") == 0)
        {
            sprintf(dataFormatada, "%02d", d.dia);
        }
        else if (strcmp(formato, "ddmm") == 0)
        {
            sprintf(dataFormatada, "%02d%02d", d.dia, d.mes);
        }
        else
        {
            printf("Formato invalido.\n");
            free(dataFormatada);
            return NULL;
        }

        return dataFormatada;
    };
