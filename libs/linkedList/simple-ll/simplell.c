#include <stdio.h>
#include <stdlib.h>

//Definition Head
Node* head = NULL;

//Insert

    //atBeginnig
void insertAtBeginnig (Node** head, int data) {
  Node *newNode = (Node *) malloc(sizeof(Node));

  if (newNode == NULL) {  
    puts("Error: Memory Aloccation Failed");
  }

  newNode -> data = data;

  if (*head == NULL) {
    newNode -> nextNode = NULL;
    *head = newNode;
  } else {
    newNode -> nextNode = *head;
    *head = newNode;
  }

}
    
    //atEnd
void insertAtEnd(Node** head, int data) {
  Node *newNode (Node *) malloc(sizeof(Node));    

  if (newNode == NULL) {
    puts("Error: Memory Aloccation Failed");
  }

  newNode -> data = data;

  if (*head == NULL) {
    newNode -> nextNode = NULL;
    *head = newNode;
  } else {
    Node* temp = head;
    while (temp->nextNode != NULL) {
      temp = temp -> nextNode;
    }
    temp->nextNode = newNode;
    newNode -> nextNode = NULL;
  }
}

    //atPosition
void insertAtPosition (Node** head, int data, int position) {

}

//Removal
  //atBeginnig
void removalAtBeginnig (Node** head) {

}
  //atEnd
void removalAtEnd (Node** head) {

}
  //atPosition
void removalAtPosition (Node** head, int position) {

}

//Search
  //Value
Node searchAtValue (Node* head, int data) {

}
  //atPosition
Node searchAtPosition (Node* head, int position) {

}


//Update
  //atPosition
void updateAtPosition (Node* head, int data, int position) {

}

//Traversal
  //printList
void printList (Node* head) {

}
  //printListInfo
void printListInfo (Node* head) {

}

