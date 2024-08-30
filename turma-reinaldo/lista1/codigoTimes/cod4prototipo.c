#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Contadores (C89)
int i, j;

//Declaração dos struct
struct time {
  int vitorias;
  int derrotas;
  int empates;
};

struct partida {
  int golsMandante;
  int golsVisitante;
  int diferencaGols;
};

// Utilidade Modulo
int modulo(int num) {
	if(num < 0) {
		num *= -1;
	}
	return num;
}

//Função partidas
int calculaPartidas(int n) {
	int calculo = n * (n-1); 
	return calculo;
}

// Função recebePartidas (perigoso!)
void recebePartidas(int nTimes, struct time *times, struct partida *partidas) {

	// Time i é o mandante e o Time j é o visitante
	for (i = 0; i < nTimes; i++) {
		for (j = 0; j < nTimes; j++) {
			if (i == j) {continue;}
			int golsMandante, golsVisitante, diferencaGols;
			while (1) {
				printf("\nPlacar time%d x time%d: ", i+1, j+1);
				scanf("%d %d", &golsMandante, &golsVisitante);
				
				if (golsMandante >= 0 && golsVisitante >= 0) {
					break;
				}
				printf("\nNumero de gols de cada time no placar deve ser maior ou igual a zero\n");
			}
			diferencaGols = golsMandante - golsVisitante;
			if (diferencaGols > 0) {
				times[i].vitorias++;
				times[j].derrotas++;
			} else if (diferencaGols == 0) {
				times[i].empates++;
				times[j].empates++;
			} else {
				times[i].derrotas++;
				times[j].vitorias++;
			}

			partidas[(nTimes-1)*i+j].golsMandante = golsMandante;
			partidas[(nTimes-1)*i+j].golsVisitante = golsVisitante;
			partidas[(nTimes-1)*i+j].diferencaGols = modulo(diferencaGols);
		}
	}
}


// Recebe um vetor de índices do vetor de partidas e retorna os times participantes nessas partidas  
int *achaTimes(int *vetor, int tamVetor, int tamBloco) {
	int i, timeMandante, timeVisitante;
	int *timesParticipantes = (int*)malloc(2*tamVetor*sizeof(int));

	for (i = 0; i < tamVetor; i++) {
		timeMandante = (int)floor(vetor[i]/tamBloco);
		timeVisitante = vetor[i] % tamBloco;

		if (timeMandante == 0) {
			timeVisitante++;
		} else if (timeVisitante == timeMandante) {
			timeVisitante++;
		}

		timesParticipantes[2*i] = timeMandante;
		timesParticipantes[2*i+1] = timeVisitante;
	}

	return timesParticipantes;
}

//Função para achar a Maior Diferença 
int achaMaiorDiff(struct partida *vetorPartidas, int tamanho) {
  int maiorDiff = vetorPartidas[0].diferencaGols;

  for (i = 1; i<tamanho; i++) {
    if (vetorPartidas[i].diferencaGols > maiorDiff) {
      maiorDiff = vetorPartidas[i].diferencaGols;
    }
  }
  return maiorDiff;
}
//Função para quantidade de maiorDiferença 
int qtdMaiorDiff(struct partida *vetorPartidas, int tamanho, int maiorDiff) {
  int contador = 0;
  for (i = 0; i < tamanho; i++) {
      if (vetorPartidas[i].diferencaGols == maiorDiff) {
      contador++;
    }
  }
  return contador;
}

//Função para achar a Maior Vitorias 
int achaMaiorVitoria(struct time *vetorTime, int tamanho) {
  int maiorVit = vetorTime[0].vitorias;

  for (i = 1; i < tamanho; i++) {
    if (vetorTime[i].vitorias > maiorVit) {
      maiorVit = vetorTime[i].vitorias;
    }
  }
  return maiorVit;
}

//Função para imprimir maior vitorias
void imprimeTimeVitorioso(struct time *vetorTime, int tamanho, int maior) {
  
  //Imprimir times com mais vitorias  
    printf("\n\nTime(s) com mais vitorias: ");
    
    for(i = 0; i < tamanho; i++)
    {
        if(vetorTime[i].vitorias == maior)
        {
            printf("%d ", i+1);
        }
    }
    
    printf("com %d vitorias\n", maior);
}

//Função para achar a Maior Derrota  
int achaMaiorDerrota(struct time *vetorTime, int tamanho) {
  int maiorDer = vetorTime[0].derrotas;

  for (i = 1; i < tamanho; i++) {
    if (vetorTime[i].derrotas > maiorDer) {
      maiorDer = vetorTime[i].derrotas;
    }
  }
  return maiorDer;
}

//Função imprime time com mais derrotas
void imprimeTimePerdedor(struct time *vetorTime, int tamanho, int maior) {

  //Imprimir times com mais derrotas  
    printf("\nTime(s) com mais derrotas: ");
    
    for(i=0; i<tamanho; i++)
    {
        if(vetorTime[i].derrotas == maior)
        {
            printf("%d ", i+1);
        }
    }
    
    printf("com %d derrotas\n", maior);
}

//Função para achar a Maior Vitorias 
int achaMaiorEmp(struct time *vetorTime, int tamanho) {
  int maiorEmp = vetorTime[0].empates;

  for (i = 1; i < tamanho; i++) {
    if (vetorTime[i].empates > maiorEmp) {
      maiorEmp = vetorTime[i].empates;
    }
  }
  return maiorEmp;
}

//Função para imprimir time com mais empates
void imprimeTimeEmpate(struct time *vetorTime, int tamanho, int maior) {

  //Imprimir times com mais empates  
    printf("\nTime(s) com mais empates: ");
    
    for(i=0; i<tamanho; i++)
    {
        if(vetorTime[i].empates == maior)
        {
            printf("%d ", i+1);
        }
    }
    
    printf("com %d empates\n", maior);
}

int *achaIndicesPartidasMaiorDiff(struct partida *partidas, int tamanho, int maiorDiff) {
	int quantidadePartidas = 0;
	int *vetorIndices = (int *)malloc((tamanho+1)*sizeof(int));
	
	for (i = 0; i < tamanho; i++) {
		if(partidas[i].diferencaGols == maiorDiff){
			vetorIndices[quantidadePartidas] = i;
			quantidadePartidas++;
		}
	}
	vetorIndices[tamanho] = quantidadePartidas;
	return vetorIndices;
}

// Acho que tem um memory leak pesado aqui
void imprimePartidasMaiorDiff(struct partida *partidas, int tamanho, int tamBloco) {
	int maiorDiff = achaMaiorDiff(partidas, tamanho);
	int *partidasIndices = achaIndicesPartidasMaiorDiff(partidas, tamanho, maiorDiff);
	int *times = achaTimes(partidasIndices, partidasIndices[tamanho], tamBloco);
	
	printf("\nMaior diferenca de gols foi de %d gols nos jogos:", maiorDiff);
	for (i = 0; i < 2*partidasIndices[tamanho]; i += 2) {
		printf(" time%d x time%d;", times[i]+1, times[i+1]+1);
	}
}

int main(int argc, char *argv[])
{
  //Declaração de variáveis
	int nTimes;

	// Loop para tratamento da entrada
	while(1)
	{	
		printf("Entre com o numero de times participantes:");
		scanf("%d", &nTimes);
	
		if (nTimes > 1) {		
			break;
		}
		printf("\nNumero de times participantes deve ser maior ou igual a 2\n\n");
	}
  
  //Definindo o numero de partida 
	int nPartidas = calculaPartidas(nTimes);

	struct time *times = malloc(nTimes * sizeof(struct time));
	struct partida *partidas = malloc(nPartidas * sizeof(struct partida));
    
  //Definindo o bloco
  int tamanhoBloco = nTimes - 1;
   
  //Recebe partidas
  recebePartidas(nTimes, times, partidas);

  //Maiores
  int maiorVit = achaMaiorVitoria(times, nTimes);
  int maiorDer = achaMaiorDerrota(times, nTimes);
  int maiorEmp = achaMaiorEmp(times, nTimes);

   //Impressão 
  imprimeTimeVitorioso(times, nTimes, maiorVit);
  imprimeTimePerdedor(times, nTimes, maiorDer);
  imprimeTimeEmpate(times, nTimes, maiorEmp);
	imprimePartidasMaiorDiff(partidas, nPartidas, tamanhoBloco);
    
    //Imprimir maior diferença de gols
		/*
    printf("Maior diferenca de gols foi de %d gols nos jogos: ", maiorDifGols);
    
    for(int i=1; i<= (Fat(nTimes)/Fat(nTimes-2)); i++)
    {
        if(timeMandanteDifGols[i]!=0 || timeVisitanteDifGols[i]!=0)
        {
            printf("time%d x time%d, ", timeMandanteDifGols[i], timeVisitanteDifGols[i]);
        }
    }
		*/

  //Free alocation dynamic memory
  free(times);
  free(partidas);


    return 0;
  /*Time(s) com mais vitorias: 1 com 5 vitorias

Time(s) com mais derrotas: 4 com 4 derrotas

Time(s) com mais empates: 2 com 4 empates

Maior diferenca de gols foi de 3 gols nos jogos: time2 x time1; time3 x time2;
   */
}
