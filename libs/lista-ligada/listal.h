#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

#include <stdbool.h>

//Definition Node
typedef struct Node {
  int data;
  Node *nextNode;
} Node;

//Linked List Functions
  //Insert
    //atBeginnig
    void insertAtBeginnig ();
    //atEnd
    void insertAtEnd ();
    //atPosition
    void insertAtPosition ();


  //Removal
    //atBeginnig
    void removalAtBeginnig ();
    //atEnd
    void removalAtEnd ();
    //atPosition
    void removalAtPosition ();

  //Search
    //Value
    Node searchAtValue ();
    //atPosition
    Node searchAtPosition ();
  

  //Update
    //Value
    void updateValue ();

  //Traversal
    //printList
    void printList ();
    //printListInfo
    void printListInfo ();

#endif 
