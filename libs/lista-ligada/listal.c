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

      newNode -> data;

      if (head == NULL) {
        newNode -> nextNode = NULL;
        head = &newNode;
      }
      
      if (head != NULL) {
        Node* temp = head;
        head = &newNode;
        newNode -> nextNode = temp;
      }
}
    //atEnd
    void insertAtEnd (Node** head, int data) {

}
    //atPosition
    void insertAtPosition (Node** head, int data, int position) {

}
