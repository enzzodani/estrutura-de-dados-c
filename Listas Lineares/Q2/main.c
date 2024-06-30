#include <stdio.h>
#include <stdlib.h>

//Definition of the Node
typedef struct Node Node;
struct Node {
  int id;
  Node* next;
  Node* back;
};

//Definition of the Queue
typedef struct NodeQueue NodeQueue;
struct NodeQueue {
  unsigned int lenght;
  Node* start;
  Node* end;
};

//Declaration of the functions
Node* createNode(int id);

NodeQueue* createQueue();

void captureID(int numOfPersons, NodeQueue* queue);

void enqueue(Node* node, NodeQueue* queue);

void dequeueAtId();

void printQueue();

int main(int argc, char *argv[])
{
  //Captura do numero de pessoas na fila
  int numOfPersons;
  scanf("%d", &numOfPersons)
  //Captura dos id por ordem
  captureID(numOfPersons);

  //Captura da quantidade de desistentes

  //Captura dos ids dos desistentes

  //Print do estado final da fila
  printQueue();

  return 0;
}

//Definition of functions
Node* createNode (int id) {

}

NodeQueue* createQueue () {
  
  NodeQueue* newQueue = (NodeQueue *) malloc(sizeof(NodeQueue));

  if (newQueue == NULL) {
    puts("Error: Alocation Memory Failed (createQueue)");
    return NULL;
  }

  newQueue -> lenght = 0;
  newQueue -> start = NULL;
  newQueue -> end = NULL;

  return newQueue;
}

void captureID (int numOfPersons, NodeQueue* queue) {
  int i, id;
  for (i = 0; i < numOfPersons; i++) {
  
  scanf("%d", &id);
  Node* newNode = createNode(id);

  enqueue(newNode, queue);

  }
}

void enqueue (Node* node, NodeQueue* queue) {
 
  if (queue -> lenght == 0) {
    queue -> start = node;
    queue -> end = node;
    queue -> lenght = 1;
    node -> next = NULL;
    node -> back = NULL;
  } else {
    queue -> end -> next = node;
    node -> back = queue -> end;
    queue -> end = node;
    node -> next = NULL;
    queue -> lenght++;
  }
}
