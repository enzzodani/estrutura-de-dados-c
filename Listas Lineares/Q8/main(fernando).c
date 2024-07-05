#include <stdio.h>
#include <std.lib.h>

typedef struct contato 
{
    char* nome;
    unsigned int v;
    char* telefone;
    struct contato* proximo;
    struct contato* anterior;
    
    
}Contato;

typedef struct listaContao
{
    unsigned int lenght = 0;
    Contato* inicial;
    Contato* final;
    
}ListaContato;


Contato* criaContato(char* nome, char* telefone, unsigned int v)
{
    Contato* novoContato = (Contato*) malloc(sizeof(Contato)); 
    
    if(novoContato == NULL)
    {
        printf("Erro de alocação de memória (criaContato) !");
        return NULL;
    }
    
    if(ListaContato->lenght == 0)
    {
        ListaContato->start = novoContato;
        ListaContato->end = novoContato;
        
    }
    
    else
    {
        novoContato->anterior = ListaContato->end;
        novoContato->anterior->proximo = novoContato;
        ListaContato->end = novoContato;
    }
    
    //cuidar da questao do string (string copy?)
    novoContato->nome = nome;
    novoContato->telefone = telefone;
    novoContato->v = v;
    
    return novoContato;
}

void organizaLista()
{
    
}

void removerContato(char* nome)
{
    Contato* temp = ListaContato->start;
}



int main()
{
    

    return 0;
}
