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

void limpaVetor(int *vetor, int size) {
    for (int i = 0; i < size; i++) {
        vetor[i] = 0;
    }
}

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

			partidas[4*i+j].golsMandante = golsMandante;
			partidas[4*i+j].golsVisitante = golsVisitante;
			partidas[4*i+j].diferencaGols = modulo(diferencaGols);
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

		if (timeVisitante == timeMandante) {
			timeVisitante++;
		}

		timesParticipantes[2*i] = timeMandante;
		timesParticipantes[2*i+1] = timeVisitante;
	}

	return timesParticipantes;
}

//Função para achar a Maior Diferença 
int achaMaiorDiferença(struct partidas *vetorPartidas, int tamanho) {
  int maiorDiferença = vetorPartidas[0];

  for (i = 1; i<tam; i++) {
    if (vetorPartidas[i] > maiorDiferença) {
      maiorDiferença = vetorPartidas[i];
    }
  }
  return maiorDiferença;
}
//Função para quantidade de maiorDiferença 


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
		printf("\nNumero de times particiantes deve ser maior ou igual a 2\n\n");
	}
  
  //Definindo o numero de partidas 
	int nPartidas = calculaPartidas(nTimes);

	struct time *times = malloc(nTimes * sizeof(struct time));
	struct partida *partidas = malloc(nPartidas * sizeof(struct partida));
    
  //Definindo o bloco
  int tamanhoBloco = nTimes - 1;
   
  //Recebe partidas
  recebePartidas(nTimes, times, partidas);

	/*
  //procurando qual o maior numero de vitorias e qual time detem esse valor
	maiorNumVit = vetorVitTimes[1];
	nTimeMaisVit[1] = 1;
    
    for(int j=2; j<nTimes+1; j++)
    {
        if(maiorNumVit<vetorVitTimes[j])
        {
            nTimeMaisVit[1] = 0;
            maiorNumVit = vetorVitTimes[j];
            
            nTimeMaisVit[j] = j;
        }
        else if (maiorNumVit==vetorVitTimes[j]){
            maiorNumVit = vetorVitTimes[j];
            
            nTimeMaisVit[j] = j;
        }
        
        else
        {
            nTimeMaisVit[j] = 0;
        }
    }
    
    printf("Time(s) com mais vitorias: ");
    
    //tratamento do vetor nTimeMaisVit para ver qual o numero do time mais vitorioso
    
    for(int j=1; j<nTimes+1; j++)
    {
        if(nTimeMaisVit[j]!=0)
        {
            printf("%d ", nTimeMaisVit[j]);
        }
    }
    
    printf("com %d vitorias\n", maiorNumVit);
    
    //a partir desse ponto ja temos a mensagem final sobre o time mais vitorioso assim como a sua quantidade de vitorias
    
    //agora devemos fazer o mesmo para as derrotas
    
    
    //vendo qual o maior numero de derrotas
    maiorNumDer = vetorDerTimes[1];
    nTimeMaisDer[1] = 1;
    
    for(int j=2; j<nTimes+1; j++)
    {
        if(maiorNumDer<vetorDerTimes[j])
        {
            nTimeMaisDer[1] = 0;
            maiorNumDer = vetorDerTimes[j];
            
            nTimeMaisDer[j] = j;
        }
        else if (maiorNumDer==vetorDerTimes[j]){
            maiorNumDer = vetorDerTimes[j];
            
            nTimeMaisDer[j] = j;
        }
        
        else
        {
            nTimeMaisDer[j] = 0;
        }
    }
    
    printf("Time(s) com mais derrotas: ");
    
    for(int j=1; j<nTimes+1; j++)
    {
        if(nTimeMaisDer[j]!=0)
        {
            printf("%d ", nTimeMaisDer[j]);
        }
    }
    
    printf("com %d derrotas\n", maiorNumDer);
    
    //a partir desse ponto as mensagens de vitoria e derrota ja estao feitas
    //resta agora fazer a mensagem de empate
    
    
    
    maiorNumEmp = vetorEmpTimes[1];
    nTimeMaisEmp[1] = 1;
    
    for(int i = 2; i<nTimes+1; i++)
    {
        if(maiorNumEmp<vetorEmpTimes[i])
        {
            nTimeMaisEmp[1] = 0;
            maiorNumEmp = vetorEmpTimes[i];
            
            nTimeMaisEmp[i] = i;
        }
        else if (maiorNumEmp==vetorEmpTimes[i]){
            maiorNumEmp = vetorEmpTimes[i];
            
            nTimeMaisEmp[i] = i;
        }
        
        else
        {
            nTimeMaisEmp[i] = 0;
        }
    }
    
    
    printf("Time(s) com mais empates: ");
    
    for(int j=1; j<nTimes+1; j++)
    {
        if(nTimeMaisEmp[j]!=0)
        {
            printf("%d ", nTimeMaisEmp[j]);
        }
    }
    
    printf("com %d empates\n", maiorNumEmp);
    
    
    
    
    
    
    maiorDifGols = vetorDifGols[1];
    
    for(int i=1; i<=nTimes; i++)
    {
        for(int j=1; j<=nTimes; j++)
        {
            if(i!=1 || j!=1)
            {
                if(maiorDifGols<vetorDifGols[((i-1)*nTimes)+j])
                {
                   maiorDifGols = vetorDifGols[((i-1)*nTimes)+j];
                   
                }
            }
        }
    }
    
    for(int i=1; i<=nTimes; i++)
    {
        for(int j=1; j<=nTimes; j++)
        {
            if(i!=1 || j!=1)
            {
                if(maiorDifGols==vetorDifGols[((i-1)*nTimes)+j])
                {
                   timeMandanteDifGols[((i-1)*nTimes)+j-1] = i;
                   
                   timeVisitanteDifGols[((i-1)*nTimes)+j-1] = j;
                }
                else
                {
                    timeMandanteDifGols[((i-1)*nTimes)+j-1] = 0;
                    
                    timeVisitanteDifGols[((i-1)*nTimes)+j-1] = 0;
                }
                
                
            }
        }
    }
    
    printf("Maior diferenca de gols foi de %d gols nos jogos: ", maiorDifGols);
    
    for(int i=1; i<= (Fat(nTimes)/Fat(nTimes-2)); i++)
    {
        if(timeMandanteDifGols[i]!=0 || timeVisitanteDifGols[i]!=0)
        {
            printf("time%d x time%d, ", timeMandanteDifGols[i], timeVisitanteDifGols[i]);
        }
    }
    */
    return 0;
}
