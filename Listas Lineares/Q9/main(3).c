#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct neto
{
    struct neto * proximo;
    struct neto * anterior;
    char* nome;
    
    
}Neto;

typedef struct roda
{
    int length;
    Neto * inicial;
    Neto * final;
       
}Roda;


Neto * criaNeto(char * nome)
{
    Neto* novoNeto = (Neto*) malloc(sizeof(Neto));
    
    if(novoNeto == NULL)
    {
        printf("Erro de alocação de memória (criaNeto) !");
        return NULL;
    }
    
    novoNeto->nome = (char *)malloc((strlen(nome) + 1)* sizeof(char));
    
    if (novoNeto -> nome == NULL) 
    {
     puts("Erro de alocacao de memoria para nome (criaNeto)");
     free(novoNeto);
     return NULL;
    }
    
    strcpy(novoNeto->nome, nome);
    
    return novoNeto;
}


Roda* criaRoda() 
{

  Roda* novaRoda = (Roda *) malloc(sizeof(Roda));

  if (novaRoda == NULL) 
  {
    puts("Erro de alocacao de memoria (criaRoda)");
    return NULL;
  }

  novaRoda -> length = 0;
  novaRoda -> inicial = NULL;
  novaRoda -> final = NULL;

  return novaRoda;
}

void addNeto(Neto* novoNeto, Roda* roda)
{
    if(roda->length == 0)
    {
        roda->inicial = novoNeto;
        roda->final = novoNeto;
        roda->length++;
    }
    
    else
    {
        roda->final->proximo = novoNeto;
        novoNeto->anterior = roda->final;
        roda->final = novoNeto;
        roda->length++;
    }
    
}

void removeNeto(Neto* netoEliminado, Roda* roda)
{
    if(roda->length == 1)
    {
        roda->inicial = NULL;
        roda->final = NULL;
        roda->length--;
        //limpar o espaço de memoria
    }
    
    else if(netoEliminado == roda->final)
    {
        netoEliminado->anterior->proximo = NULL;
        roda->final = netoEliminado->anterior;
        netoEliminado->anterior = NULL;
        roda->length--;
        //limpar o espaço de memoria
    }
    
    else
    {
        netoEliminado->anterior->proximo = netoEliminado->proximo;
        netoEliminado->proximo->anterior = netoEliminado->anterior;
        netoEliminado->anterior = NULL;
        netoEliminado->proximo = NULL;
        roda->length--;
        //limpar o espaço de memoria
        
    }
}


//função responsavel por girar o temporario e comparar se o nome dito esta entre os netos percorridos
int play(char* nomeChute, char* orientacao, Roda* roda)
{
    
    
    if(strcmp(orientacao, "horario") == 0)
    {
        Neto* temp = roda->inicial;
        int i;
        for(i = 0; i<2; i++)
        {
            temp = temp->proximo;
            
            if(strcmp(nomeChute, temp->nome) == 0)
            {
                removeNeto(temp, roda);
                
                return 2;
            }
            
            
        }
        
        return 1;
    }
    
    
    //aqui iremos tratar o sentido anti-horario. Sendo assim iniciamos a analise no final da lista
    //e precisaremos percorrer apenas mais uma passo
    else
    {
        Neto* temp = roda->final;
        int j;
        for(j = 0; j<1; j++)
        {
            if(strcmp(nomeChute, temp->nome) == 0)
            {
                removeNeto(temp, roda);
                
                return 2;
            }
            temp = temp->anterior;
        }
        
        return 1;
    }
    
    
}

void clearString(char* str, int size)
{
    int j = 0;
    for(j = 0; j<size; j++)
    {
        str[j] = '\0';
    }
}


int main()
{
    char nomeRecebido[100];
    
    char orientacao[15];
    
    int contador, pontos, resultado;
    
    clearString(nomeRecebido, sizeof(nomeRecebido));
    
    Roda* rodaNetos = criaRoda();
    
    
    while(strcmp(nomeRecebido, "FIM") != 0)
    {
        scanf("%100s", nomeRecebido);
        
        if(strcmp(nomeRecebido, "FIM") != 0)
        {
            Neto* netoaux = criaNeto(nomeRecebido);
            addNeto(netoaux, rodaNetos);
            clearString(nomeRecebido, sizeof(nomeRecebido));
        }
    }
    
    clearString(nomeRecebido, sizeof(nomeRecebido));
    
    contador = rodaNetos->length;
    
    int i;
    for(i = 0; i<contador; i++)
    {
        scanf("%100s %15s", nomeRecebido, orientacao);
        
        resultado = play(nomeRecebido, orientacao, rodaNetos);
        
        if(resultado == 2)
        {
            pontos++;
        }
    }
    
    printf("%d", pontos);
    
    
    

    return 0;
}
