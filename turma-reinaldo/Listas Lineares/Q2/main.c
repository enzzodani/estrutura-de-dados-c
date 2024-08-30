#include <stdio.h>
#include <stdlib.h>

// Definition of the Node
typedef struct Node Node;
struct Node {
  int id;       // ID de um Nó
  Node* next;   // Ponteiro para o próximo Nó
  Node* back;   // Ponteiro para o Nó anterior
};

// Definition of the Queue
typedef struct NodeQueue NodeQueue;
struct NodeQueue {
  unsigned int length; // Tamanho da Fila de Nós
  Node* start;         // Ponteiro para o primeiro Nó da fila
  Node* end;           // Ponteiro para o último Nó da Fila
};

// Declaration of the functions
Node* createNode(int id);                // Cria um Nó com um ID
NodeQueue* createQueue();                // Cria uma fila vazia
void captureID(int numOfPersons, NodeQueue* queue); // Faz a captura de ids iniciais
void removeID(int numOfPersons, NodeQueue* queue);  // Remove IDs da fila
void enqueue(Node* node, NodeQueue* queue);         // Adiciona Nó no final da fila
int dequeueAtId(int id, NodeQueue* queue);          // Remove Nó a partir de um id fornecido, retorna 0 se funcionar, 1 se nao funcionar
void printQueue(NodeQueue* queue);                  // Printa os id em ordem da fila

int main(int argc, char *argv[]) {
  // Criação da fila
  NodeQueue* queue = createQueue();

  // Captura do numero de pessoas na fila
  int numOfPersons;
  scanf("%d", &numOfPersons);

  // Captura dos id por ordem
  captureID(numOfPersons, queue);

  // Captura da quantidade de desistentes
  int numOfLeavers;
  scanf("%d", &numOfLeavers);

  // Captura dos ids dos desistentes
  removeID(numOfLeavers, queue);

  // Print do estado final da fila
  printQueue(queue);

  return 0;
}

// Definition of functions
Node* createNode(int id) {
  Node* newNode = (Node *) malloc(sizeof(Node)); // Instancia um novo Nó

  if (newNode == NULL) { // Verifica se houve erro durante a alocação de memória
    puts("Error: Alocation Memory Failed (createNode)");
    return NULL;
  }

  newNode->id = id;  // Adiciona o id ao Nó
  newNode->next = NULL;
  newNode->back = NULL;

  return newNode; // Retorna o novo Nó ligado ao seu id
}

NodeQueue* createQueue() {
  NodeQueue* newQueue = (NodeQueue *) malloc(sizeof(NodeQueue)); // Instancia uma Nova Fila

  if (newQueue == NULL) { // Verifica se houve erro na instanciação
    puts("Error: Alocation Memory Failed (createQueue)");
    return NULL;
  }

  newQueue->length = 0; // Uma nova fila começa com tamanho 0 visto que nao temos elementos dentro dela
  newQueue->start = NULL; // Sem elementos, não tem começo
  newQueue->end = NULL;   // Nem final

  return newQueue; // Retorna a nova fila vazia
}

void captureID(int numOfPersons, NodeQueue* queue) {
  int i, id;
  for (i = 0; i < numOfPersons; i++) { // Loop de captura de id's
    scanf("%d", &id);
    Node* newNode = createNode(id); // Cria um nó para o id passado
    enqueue(newNode, queue); // Enfileira o Nó no final da fila
  }
}

void enqueue(Node* node, NodeQueue* queue) {
  if (queue->length == 0) { // Se a fila estiver vazia, ou seja, estamos add o primeiro Nó
    queue->start = node; // O começo da fila aponta para esse Nó
    queue->end = node;   // O final da fila aponta para esse Nó
    queue->length = 1;   // Agora temos 1 elemento na fila
    node->next = NULL;   // não existe proximo elemento
    node->back = NULL;   // não existe anterior ao primeiro
  } else {
    queue->end->next = node; // Fazemos o ultimo Nó da fila apontar para o novo Nó adicionado
    node->back = queue->end; // Fazemos o novo Nó apontar para o último Nó da fila
    queue->end = node;       // Fazemos o final da fila apontar para o Novo Nó
    node->next = NULL;       // Não existe ninguem depois do novo Nó, visto que ele é o novo último Nó agora
    queue->length++;         // Adicionamos 1 elemento na fila, logo ela cresce 1 de tamanho
  }
}

int dequeueAtId(int id, NodeQueue* queue) {
  Node* temp = queue->start; // Temporário para percorrer a lista, começando pelo início da fila

  while (temp != NULL) { // Percorre a lista até o final
    if (temp->id == id) { // Verifica se o identificador do nó atual é igual ao ID fornecido
      if (temp->back != NULL) { // Se o nó atual não for o primeiro da fila
        temp->back->next = temp->next; // Faz o nó anterior apontar para o próximo nó
      } else {
        queue->start = temp->next; // Se for o primeiro nó, atualiza o início da fila
      }

      if (temp->next != NULL) { // Se o nó atual não for o último da fila
        temp->next->back = temp->back; // Faz o próximo nó apontar para o nó anterior
      } else {
        queue->end = temp->back; // Se for o último nó, atualiza o final da fila
      }

      free(temp); // Libera a memória alocada para o nó removido
      queue->length--; // Diminui o tamanho da fila
      return 0; // Retorna 0 para indicar que a remoção foi bem-sucedida
    }
    temp = temp->next; // Move para o próximo nó na fila
  }

  return 1; // Se o ID não foi encontrado na fila, retorna 1
}

void removeID(int numOfPersons, NodeQueue* queue) {
  int i, id;
  for (i = 0; i < numOfPersons; i++) {
    scanf("%d", &id);
    dequeueAtId(id, queue);
  }
}

void printQueue(NodeQueue* queue) {
  Node* temp = queue->start;
  int first = 1; // Flag para controlar o espaço

  while (temp != NULL) {
    if (first) {
      first = 0;
    } else {
      printf(" "); // Adiciona espaço antes de cada id, exceto o primeiro
    }
    printf("%d", temp->id);
    temp = temp->next;
  }
}

