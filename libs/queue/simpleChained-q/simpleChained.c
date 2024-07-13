#include <stdio.h>
#include <stdlib.h>

//Functions
Node* createNode(int data) { 
  Node* newNode = (Node *) malloc(sizeof(Node));

  if (newNode == NULL) {
    puts("Error Allocation Memory (createNode)");
    return NULL;
  }

  newNode -> data = data;
  newNode -> next = NULL;

  return newNode;
}

int isEmpty(Node** start) {

  if (*start == NULL) {
    return 0;
  } else {
    return 1;
  }
}

void enqueue(Node** start, Node* newNode) {
  if (isEmpty(start) == 0) {
    *start = newNode;
    return;
  } else {
    Node* temp = start;

    while (temp->next != NULL) {
      temp = temp->next;
    }

    temp -> next = newNode;
  } 
}

void dequeue(Node** start) {
  if (isEmpty(start) == 0) {
    puts("The queue is already empty");
  } else {
    Node* temp = start;
    *start = *start -> next;
    free(temp);
  } 
} 

void clearQueue(Node** start) {
  if (isEmpty(start) == 0) {
    puts("The queue is already clear");
  } else {
    Node* temp = start;
    Node* current = temp;

    while (current != NULL) {
      temp = current;
      current = current -> next;
      free(temp);
    }
    
    *start = NULL;
  }
}

void printQueue(Node** start) {
  if (isEmpty(start) == 0) {
    puts("The queue is empty");
    return;
  } else {
    Node* temp = start;

    while (temp != NULL) {
      printf("%d\n", temp->data);
      temp = temp -> next;
    }
  }
}

void printQueueInfo(Node** start) {
  if (isEmpty(start) == 0) {
    puts("The queue is empty");
    return;
  } else {
    Node* temp = start;
    int count = 0;

    while (temp != NULL) {
      temp = temp -> next;
      count++;
    }

    printf("The lenght of the list is %d\n", count);
  }
}
