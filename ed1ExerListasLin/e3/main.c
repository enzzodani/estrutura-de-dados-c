#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct anao {
    
    int corDaTouca;
    struct anao* proximo;
    struct anao* anterior;
    
}Anao;


typedef struct filaAnao{
    
    unsigned int lenght;
    Anao* inicial;
    Anao* final;
        
}FilaAnao;

Anao* CriaAnao(int cor)
{
    Anao* nAnao = (Anao*) malloc(sizeof(Anao));
    
    if(nAnao!=NULL)
    {
        nAnao->corDaTouca = cor;
    }
    
    return nAnao;
}

void criaFilaAnao (FilaAnao* fila, int nAnoes, int i) {
    //criando a fila de anões
    int k;
    for(k=0; k<nAnoes; k++)
    {
        scanf("%d", &i);
        
        if(k==0)
        {
            Anao* novoAnao = CriaAnao(i);
            fila -> inicial = novoAnao;
            fila -> final = novoAnao;
            novoAnao->proximo = NULL;
            novoAnao->anterior = NULL;
            fila -> lenght = 1;
        }
        
        else
        {
            Anao* novoAnao = CriaAnao(i);
            fila->final->proximo = novoAnao;
            novoAnao->anterior = fila->final;
            fila->final = novoAnao;
            novoAnao->proximo = NULL;
            fila->lenght++;
        }
    }

}

int CorPredominante(int start, int end, FilaAnao* fila, int cCores)
{
    Anao* temp = fila->inicial;
    
    int contador = 1;
    
    int numeroCor;
    
    int* contadorCores = (int*) malloc(sizeof(int) * cCores);
    
    while(contador < start)
    {
        while(temp->proximo!=NULL)
        {
            temp = temp->proximo;
            contador++;
        }
    }
    
    while(contador <= end)
    {
        numeroCor = temp->corDaTouca;
        
        contadorCores[numeroCor - 1]++;
        
        temp = temp->proximo;
        contador++;
    }
    
    int maiorNumCor = contadorCores[0];
    int maiorCor = 0;
    
    int l =1;
    for(l=1; l<cCores; l++)
    {
        if(maiorNumCor<contadorCores[l])
        
        maiorNumCor = contadorCores[l];
        maiorCor = l+1;
    }
    
    if(maiorNumCor>=(ceil((end - start)/2)))
    {
        return maiorCor;
    }
    
    else
    {
        return -1;
    }
}



int main()
{
    //declarando as variáveis
    int nAnoes, cCores, nDaCor, i, nFotos;
    
    //recebendo o número de anões
    scanf("%d", &nAnoes);
    
    while(nAnoes<3 || nAnoes>1000)
    {
        scanf("%d", &nAnoes);
    }
    
    //recebendo o número de cores possíveis
    scanf("%d", &cCores);
    
    while(cCores<1 || cCores>nAnoes)
    {
        scanf("%d", &cCores);
    }
    
    
    FilaAnao* fila;
    fila -> lenght = 0;
   
    criaFilaAnao(fila, nAnoes, i); //Cria Fila de Anões
    
    //recebendo o numero de fotos
    scanf("%d", &nFotos);
    
    while(nFotos<1 || nFotos>1000)
    {
        scanf("%d", &nFotos);
    }
    
    int l , start, end;
    for(l = 0; l<nFotos; l++)
    {
        scanf("%d %d", &start, &end);
        
        int resultado = CorPredominante(start, end, fila, cCores);
        
        if(resultado== -1)
        {
            printf("feia\n");
        }
        
        else
        {
            printf("bonita %d\n", resultado);
        }

        
    }
    
    

    return 0;
}

