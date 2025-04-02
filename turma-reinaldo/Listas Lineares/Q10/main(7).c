#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct crianca
{
    char* nome;
    int n;
    struct crianca* proximo;
    struct crianca* anterior;
    
    
}Crianca;

typedef struct rodacrianca
{
    Crianca* inicial;
    Crianca* final;
    int length;
    
}rodaCrianca;

int cont;

//função que ira criar o "box" criança
Crianca* addCrianca(int n, char* nome)
{
    Crianca *novaCrianca = (Crianca*) malloc(sizeof(Crianca));
    
    if(novaCrianca == NULL)
    {
        printf("Erro de alocação de memória (addCrianca) !");
        return NULL;
    }
    
    novaCrianca -> nome = (char *)malloc((strlen(nome) + 1)* sizeof(char));
    
    if (novaCrianca -> nome == NULL) {
     puts("Erro de alocacao de memoria para nome (criaContato)");
     free(novaCrianca);
     return NULL;
    } 
    
    strcpy(novaCrianca->nome, nome);
    
    novaCrianca->n = n;
    
    return novaCrianca;
}

rodaCrianca* criaRoda() 
{

  rodaCrianca* novaRoda = (rodaCrianca *) malloc(sizeof(rodaCrianca));

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


//na função abaixo estamos adicionando à lista a criança que acaba de ser adicionada na roda
//toda crianca adicionada sera colocada no final da lista
void organizaRodaSoma(Crianca* novaCrianca, rodaCrianca* rodaCrianca)
{
    if(rodaCrianca->length == 0)
    {
        rodaCrianca->inicial = novaCrianca;
        rodaCrianca->final = novaCrianca;
        rodaCrianca->length++;
    }
    
    else if(rodaCrianca->length == 1)
    {
        rodaCrianca->final->proximo = novaCrianca;
        novaCrianca->anterior = rodaCrianca->final;
        rodaCrianca->final = novaCrianca;
        novaCrianca->proximo = rodaCrianca->inicial;
        rodaCrianca->inicial->anterior = novaCrianca;
        rodaCrianca->length++;
    }
    
    else
    {
        rodaCrianca->final->proximo = novaCrianca;
        rodaCrianca->inicial->anterior = novaCrianca;
        novaCrianca->anterior = rodaCrianca->final;
        novaCrianca->proximo = rodaCrianca->inicial;
        rodaCrianca->final = novaCrianca;
        rodaCrianca->length++;
    }
}

void organizaRodaSubtracao(Crianca* temp, rodaCrianca* rodaCrianca)
{
    cont = temp->n;
    
    if(rodaCrianca->length == 0)
    {
        printf("Não há nenhuma criança na roda para ser retirada!");
    }
    
    else if(rodaCrianca->length == 1)
    {
        rodaCrianca->inicial = NULL;
        rodaCrianca->final = NULL;
        //resta liberar a memoria da crianca
    }
    
    
    //nessa função de remoção devemos considerar em qual posição da roda está a criança que sera removida
    //podendo ela estar no inicio da roda, no meio, ou ent no final da roda
    //caso para quando a crianca removida é a primeira da lista
    else if(temp == rodaCrianca->inicial && rodaCrianca->length != 1)
    {
        temp->proximo->anterior = rodaCrianca->final;
        rodaCrianca->final->proximo = temp ->proximo;
        rodaCrianca->inicial = temp->proximo;
        temp->proximo = NULL;
        temp->anterior = NULL;
        rodaCrianca->length--;
        //resta liberar a memoria da crianca
    }
    
    //caso para quando a crianca removida é a ultima da roda
    else if(temp == rodaCrianca->final && rodaCrianca->length != 1)
    {
        temp->anterior->proximo = rodaCrianca->inicial;
        rodaCrianca->inicial->anterior = temp->anterior;
        rodaCrianca->final = temp->anterior;
        temp->proximo = NULL;
        temp->anterior = NULL;
        rodaCrianca->length--;
        //resta liberar a memoria da crianca
    }
    
    //caso para quando a crianca removida esta no meio da roda 
    else
    {
        temp->anterior->proximo = temp->proximo;
        temp->proximo->anterior = temp->anterior;
        temp->proximo = NULL;
        temp->anterior = NULL;
        rodaCrianca->length--;
        //resta liberar a memoria da crianca
    }
}

//definira se o numero da crianca é par ou impar
int funcaoParImpar(int n)
{
    if (n % 2 == 0) 
    {
        return 2;
    }
    else
    {
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

Crianca *rodaRoda(rodaCrianca *roda) {
    Crianca *temp = roda->inicial;
    int aux = funcaoParImpar(temp->n);
    int i;
    for (i = 0; i < cont; i++) {
        if (aux == 2)
        {
            temp = temp->anterior;
        } 
        else 
        {
            temp = temp->proximo;
        }
    }
    return temp;
}


int main()
{
    int n, valorCrianca;
    rodaCrianca *roda = criaRoda();
    
    //nesse caso estou usando um vetor estatico, mas talvez seja mais interessante o uso de um malloc
    char str[31];
    
    //recebendo a quantidade de crianças que participarao
    //printf("Insira a quantidade de criancas");
    scanf("%d", &n);
    
    while(n<1 || n>100)
    {
        //printf("Insira uma quantidade valida de criancas");
        scanf("%d", &n);
    }
    
    
    
    
    //o "for" abaixo tem o intuito de criar um repetidor para adicionar as "n" crianças que participarao
    int i = 0;
    for(i = 0; i<n; i++)
    {
        
        //testar o funcionamento isso
        scanf("%31s %d", str, &valorCrianca);
        
        //como colocar a criança criada dentro da função organizaRodaSoma
        Crianca *aux = addCrianca(valorCrianca, str);
        organizaRodaSoma(aux, roda);
        
        //limpando o vetor para que possamos usá-lo novamente na proxima repetição
        clearString(str, sizeof(str));
        
    }

    cont = roda->inicial->n;
    while(roda->length > 1) {
        organizaRodaSubtracao(rodaRoda(roda), roda);
    }

    printf("%s", roda->inicial->nome);

    return 0;
}
