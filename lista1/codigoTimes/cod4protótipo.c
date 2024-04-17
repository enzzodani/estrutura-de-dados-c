#include <stdio.h>

void limpaVetor(int *vetor, int size) {
    for (int i = 0; i < size; i++) {
        vetor[i] = 0;
    }
}

//Função partidas
int calculaPartidas(int n) {
 int calculo = n * (n-1); 

  return calculo;
}

//Declaração dos struct
struct time {
  int vitoria;
  int derrota;
  int empate;
};

struct partida {
  int golMandante;
  int golVisitante;
  int diferencaGol;
};

int main(int argc, char *argv[])
{
  //Declaração de variáveis
    int nTimes;
  
    printf("Entre com o numero de times participantes:");
      scanf("%d", &nTimes);
    
    while(nTimes<2)
    {
        printf("\n");
        
        printf("Numero de times particiantes deve ser maior ou igual a 2");
        
        printf("\n\n");
        
        printf("Entre com o numero de times participantes:");
        
        scanf("%d", &nTimes);
    }
  
  //Definindo o numero de partidas 
    int nPartidas = calculaPartidas(nTimes);

    struct time *times = malloc(nTimes * sizeof(struct time));
    struct partida *partidas = malloc(nPartidas * sizeof(struct partida));

    int vetorVitTimes[nTimes+1];
    
    int vetorDerTimes[nTimes+1];
    
    int vetorEmpTimes[nTimes+1];
    
    int vetorDifGols[(Fat(nTimes)/Fat(nTimes-2))+1];
    
    int nTimeMaisVit[nTimes+1];
    
    nTimeMaisVit[0] = 0;
    
    int nTimeMaisDer[nTimes+1];
    
    int nTimeMaisEmp[nTimes+1];
    
    int timeMandanteDifGols[(Fat(nTimes)/Fat(nTimes-2))+1];
    
    int timeVisitanteDifGols[(Fat(nTimes)/Fat(nTimes-2))+1];

    limpaVetor(vetorVitTimes ,nTimes+1);
    limpaVetor(vetorDerTimes ,nTimes+1);
    limpaVetor(vetorEmpTimes ,nTimes+1);
    limpaVetor(nTimeMaisVit ,nTimes+1);
    limpaVetor(nTimeMaisDer ,nTimes+1);
    limpaVetor(nTimeMaisEmp ,nTimes+1);
    limpaVetor(timeMandanteDifGols , (Fat(nTimes)/Fat(nTimes-2))+1);
    limpaVetor(timeVisitanteDifGols , (Fat(nTimes)/Fat(nTimes-2))+1);
    limpaVetor(vetorDifGols, (Fat(nTimes)/Fat(nTimes-2))+1);
    
    //Recebe partidas
    for(int i=1; i<=nTimes; i++)
    {
        for(int j=1; j<=nTimes; j++)
        {
            if(i!=j)
            {
               printf("Placar time%d x time%d:", i, j);
               
               scanf("%d %d", &golsMandante, &golsVisitante);
               
               if(golsMandante>golsVisitante)
               {
                   vetorVitTimes[i]++;
                   vetorDerTimes[j]++;
                   vetorDifGols[((i-1)*nTimes)+j] = golsMandante-golsVisitante;
                   
               }
               
               else if(golsVisitante>golsMandante)
               {
                   vetorVitTimes[j]++;
                   vetorDerTimes[i]++;
                   vetorDifGols[((i-1)*nTimes)+j] = golsVisitante-golsMandante;
               }
               
               else
               {
                   vetorEmpTimes[i]++;
                   vetorEmpTimes[j]++;
                   vetorDifGols[((i-1)*nTimes)+j] = 0;
               }
               
               
               
               
            }
            
            
        }
    } 
    
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
    
    return 0;
}
