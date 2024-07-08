#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 21
#define MAX_PHONE_LEN 10

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
    
    novoContato -> nome = (char *)malloc((strlen(nome) + 1)* sizeof(char));
    if (novoContato -> nome == NULL) {
     puts("Erro de alocacao de memoria para nome (criaContato)");
     free(novoContato);
     return NULL;
    } 
    
    strcpy(novoContato->nome, nome);

    novoContato -> telefone = (char *)malloc((strlen(telefone) + 1)* sizeof(char));
    if (novoContato -> telefone == NULL) {
     puts("Erro de alocacao de memoria para telefone (criaContato)");
     free(novoContato -> nome);
     free(novoContato);
     return NULL;
    } 
    
    strcpy(novoContato->telefone, telefone);
  
    novoContato -> v = v;
    novoContato -> proximo == NULL;
    novoContato -> anterior == NULL;

    return novoContato;

    
    return novoContato;
}

void organizaLista()
{
    
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
}

void removerContato(char* nome)
{
    Contato* temp = ListaContato->start;
}

void printContacts() {

}

int main()
{
  char operation;
  char name[MAX_NAME_LEN];
  char phone[MAX_PHONE_LEN];
  int calls;

  while (1) {
    scanf(" %c", &operation);
    if (operation == 'F') { 
      break;
    }

    switch (operation) {
      case 'I':
        scanf("%s %s %d", name, phone, &calls);
        criaContato(name, phone, calls);
        break;
      case 'R':

        break;
      case 'L':
        
        break;
    }
  }

  printContacts();
    

    return 0;
}
