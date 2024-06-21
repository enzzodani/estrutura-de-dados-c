#include <stdio.h>
#include <stdlib.h>

//Definition Head
Node* head = NULL;

//Insert

    //atBeginnig
    void insertAtBeginnig (Node** head, int data) {
      Node *newNode = (Node *) malloc(sizeof(Node));

      if (newNode == NULL) {  
        puts("Error: Aloccation Memory fault");
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
    //atPosition
    void insertAtPosition (Node** head, int data, int position) {

}
