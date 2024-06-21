#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

#include <stdbool.h>

//Definition Node
typedef struct Node {
  int data;
  Node* nextNode;
} Node;

//Definition head
extern Node* head;

//Linked List Functions
  //Insert
    //atBeginnig
    void insertAtBeginnig (Node** head, int data);
    //atEnd
    void insertAtEnd (Node** head, int data);
    //atPosition
    void insertAtPosition (Node** head, int data, int position);


  //Removal
    //atBeginnig
    void removalAtBeginnig (Node** head);
    //atEnd
    void removalAtEnd (Node** head);
    //atPosition
    void removalAtPosition (Node** head, int position);

  //Search
    //Value
    Node searchAtValue (Node* head, int data);
    //atPosition
    Node searchAtPosition (Node* head, int position);
  

  //Update
    //atPosition
    void updateAtPosition (Node* head, int data, int position);

  //Traversal
    //printList
    void printList (Node* head);
    //printListInfo
    void printListInfo (Node* head);

#endif 
