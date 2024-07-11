#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 21
#define MAX_PHONE_LEN 10

//criando o tad para contato
typedef struct Contato 
{
    char* nome;
    int v;
    char* telefone;
    struct Contato* proximo;
    struct Contato* anterior;
    
    
}Contato;

//criando o tad para o nó descritivo
typedef struct ListaContato
{
    unsigned int lenght;
    Contato* inicial;
    Contato* final;
    
}ListaContato;


//função para adicionar um novo contato na lista
Contato* criaContato(char* nome, char* telefone, unsigned int v) {

    if (nome == NULL) {
      puts("Error nome (criaContato)");
      return NULL;
    }  

    if (telefone == NULL) {
      puts("Error telefone (criaContato)");
      return NULL;
    }

    Contato* novoContato = (Contato*) malloc(sizeof(Contato)); 
    
    //testando um eventual erro de alocação de memoria
    if(novoContato == NULL)
    {
        printf("Erro de alocação de memória (criaContato) !");
        return NULL;
    }
    
    //salvando o  nome recebido como entrada da função
    //a linha abaixo do codigo define um maloc para o atributo nome do contato
    novoContato -> nome = (char *)malloc((strlen(nome) + 1)* sizeof(char));
    if (novoContato -> nome == NULL) {
     puts("Erro de alocacao de memoria para nome (criaContato)");
     free(novoContato);
     return NULL;
    } 
    
    //a funçao string copy passa para o atributo nome do contato o valor recebido como entrada da função
    strcpy(novoContato->nome, nome);

    
    //fazendo o mesmo que havia sido feito com o nome para o telefone
    novoContato -> telefone = (char *)malloc((strlen(telefone) + 1)* sizeof(char));
    if (novoContato -> telefone == NULL) {
     puts("Erro de alocacao de memoria para telefone (criaContato)");
     free(novoContato -> nome);
     free(novoContato);
     return NULL;
    } 
    
    //mesma ideia do que havia sido feito para o nome
    strcpy(novoContato->telefone, telefone);
  
    novoContato -> v = v;
    novoContato -> proximo = NULL;
    novoContato -> anterior = NULL;
    
    
    return novoContato;
}

ListaContato* criaLista() {

  ListaContato* novaLista = (ListaContato *) malloc(sizeof(ListaContato));

  if (novaLista == NULL) {
    puts("Erro de alocacao de memoria (criaLista)");
    return NULL;
  }

  novaLista -> lenght = 0;
  novaLista -> inicial = NULL;
  novaLista -> final = NULL;

  return novaLista;
}

void insereLista(Contato* novoContato, ListaContato* lista)
{
    
    //organizando a lista para quando nao temos nenhum contato ainda
    if(lista->lenght == 0)
    {
        lista->inicial = novoContato;
        lista->final = novoContato;
    }
    
  
    //organizando a lista para quando temos 1 ou mais contatos ja salvos
    else
    {
       lista->final->proximo = novoContato;
       novoContato->anterior = lista->final;
       lista->final = novoContato;
    } 
    
    lista->lenght++;

}

//função responsável por remover um dos contatos da lista
//usaremos um nó temporario para achar, por meio do nome, o contato que se deseja excluir
void removerContato(char* nome, ListaContato* lista)
{
    //caso para quando se tenta remover um contato inexistente
    if(lista->lenght == 0)
    {
        printf("Não existe nenhum contato para ser removido");
        return;
    }

    Contato* temp = lista->inicial;
    
    //colocando o nó temporario para andar ate que ele encontre o nome do contato que se quer apagar
    while(strcmp(temp->nome, nome)!=0)
    {
        temp = temp->proximo;
    } 
    
    //caso para quando só existe 1 contato
    if(temp == lista->inicial && temp == lista->final)
    {
        lista->inicial = NULL;
        lista->final = NULL;
        
        lista->lenght--;
        
    }
    
    //caso para quando o contato removido for o primeiro da lista
    else if(temp == lista->inicial)
    {
        temp->proximo->anterior = NULL;
        lista->inicial = temp->proximo;
        temp->proximo = NULL;
        lista->lenght--;
    }
    
    //caso para quando o contato removido for o ultimo da lista
    else if(temp == lista->final)
    {
        temp->anterior->proximo = NULL;
        lista->final = temp->anterior;
        temp->anterior = NULL;
        lista->lenght--;
    }
    
    //caso para quando o contato removido nao for nem o ultimo nem o primeiro da lista
    else
    {
        temp->anterior->proximo = temp->proximo;
        temp->proximo->anterior = temp->anterior;
        temp->proximo = NULL;
        temp->anterior = NULL;
        lista->lenght--;
    }
    
    free(temp->nome);
    free(temp->telefone);
    free(temp);
}

void printContacts(ListaContato* lista) 
{
    if (lista -> lenght == 0) {
      puts("LIsta de contatos vazia");
      return;
    }
    Contato* temp = lista->final;
    printf("%s - %s %d", temp->nome, temp->telefone, temp->v);
    
    while (temp != NULL) {

        printf("%s - %s %d", temp->nome, temp->telefone, temp->v);
        printf("\n");
        
        temp = temp->anterior;
    }
}

//essa função ira identificar o nome de um contato e adicionar 1 ao numero de ligações
void funcaoLigacao(char* nome, ListaContato* lista)
{
    Contato* temp = lista->inicial;
    
    //colocando o nó temporario para andar ate que ele encontre o nome do contato que se quer apagar
    while(strcmp(temp->nome, nome)!=0)
    {
        temp = temp->proximo;
    }
    
    temp->v++;
}

//Funções de mergeSort declaração 
Contato* split(Contato* head);

Contato* merge(Contato* first, Contato* second);

Contato* mergeSort(Contato* head);

void sortLinkedList(ListaContato* lista);


int main()
{
  char operation;
  char name[MAX_NAME_LEN];
  char phone[MAX_PHONE_LEN];
  int calls;

  ListaContato* lista = criaLista();

  while (1) {
    scanf(" %c", &operation);
    if (operation == 'F') { 
      break;
    }

    switch (operation) {
      case 'I':
        scanf("%s %s %d", name, phone, &calls);
        Contato* novoContato = criaContato(name, phone, calls);
        insereLista(novoContato, lista);
        break;
      case 'R':
        scanf("%s", name);
        removerContato(name, lista);
        break;
      case 'L':
        scanf("%s", name);
        funcaoLigacao(name, lista);
        break;
    }
  }

  sortLinkedList(lista);
  printContacts(lista);
    

    return 0;
}

//Funções para mergeSort
Contato* split(Contato* head) {
  Contato* fast = head;
  Contato* slow = head;

  while (fast != NULL && fast-> proximo != NULL) {
    fast = fast -> proximo -> proximo;

    if (fast != NULL) {
      slow = slow -> proximo;
    }
  }

  Contato* secondHalf = slow-> proximo;
  slow->proximo = NULL;

  if (secondHalf != NULL) {
    secondHalf -> anterior = NULL;
  }

  return secondHalf;
}

Contato* mergeSort(Contato* head) {
  if (head == NULL || head -> proximo == NULL) {
    return head;
  }

  Contato* secondHalf = split(head);

  head = mergeSort(head);
  secondHalf = mergeSort(secondHalf);

  return merge(head, secondHalf);
}

Contato* merge(Contato* first, Contato* second) {
  if (first == NULL) {
    return second;
  } else if (second == NULL) {
    return first;
  }

  if (first -> v <= second -> v) {
    first -> proximo = merge(first->proximo, second);
    first -> proximo -> anterior = first;
    first -> anterior = NULL;
    return first;
  } else {
    second -> proximo = merge(first, second-> proximo);
    second -> proximo -> anterior = second;
    second -> anterior = NULL;
    return second;
  }
}

void sortLinkedList (ListaContato* lista) {
  lista->inicial = mergeSort(lista-> inicial);

  Contato* temp = lista->inicial;

  while (temp != NULL && temp -> proximo != NULL) {
    temp = temp -> proximo;
  }

  lista -> final = temp;
}
