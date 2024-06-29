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

void insertAtStart();

void removalAtID();

void printQueue();

int main(int argc, char *argv[])
{
  //Captura do numero de pessoas na fila

  //Captura dos id por ordem

  //Captura da quantidade de desistentes

  //Captura dos ids dos desistentes

  //Print do estado final da fila
  printQueue();

  return 0;
}
