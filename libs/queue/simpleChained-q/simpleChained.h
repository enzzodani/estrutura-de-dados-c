#ifdef SIMPLE_CHAINED_H
#define SIMPLE_CHAINED_H

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef Node* Start;

//Functions
Node* createNode(int data);

int isEmpty(Node* start);

void enqueue(Node* start);

void dequeue(Node* start);

void clearQueue(Node* start);

void printQueue(Node* start);

void printQueueInfo(Node* start);

#endif
