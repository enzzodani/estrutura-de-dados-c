#include <stdio.h>

//Declaration Function
  //descriptionNode
  descriptionNode* createDNode () {
  createDNode* newDNode = (descriptionNode *) malloc(sizeof(descriptionNode));

  if (newDNode == NULL) {
    puts("Allocation Memory Failed (Create descriptionNode)");
    return NULL;
  }

  newDNode -> length = 0;
  newDNode -> start = NULL;
  newDNode -> end = NULL;

  return newDNode;
}
  //Create Node
  Node* createNode (int data) {
  Node* newNode = (Node *) malloc(sizeof(Node));

  if (newNode = NULL) {
    puts("Allocation Memory Failed (Create Node)");
    return NULL;
  }

  newNode -> next = NULL;
  
  return newNode;
}

  //Insert 
    //atBeginning
    void insertAtBeginning (descriptionNode* dNode, int data) {
    Node* newNode = createNode(data); 

    if (newNode == NULL) {
      puts("Error in insert at Beginning"); 
      return;
    }
    
    newNode -> next = dNode -> start;
    dNode -> start = newNode; 
}
    //atEnd
    void insertAtEnd (descriptionNode* dNode, int data);
    //atPosition
    void insertAtPosition (descriptionNode* dNode, int position);

  //Removal
    //atBeginning
    void removalAtBeginning (descriptionNode* dNode);
    //atEnd
    void removalAtEnd (descriptionNode* dNode);
    //atPosition
    void removalAtPosition (descriptionNode* dNode, int position);

  //Update
    //atPosition
    void updateAtPosition (int data, descriptionNode *dNode);

  //Search
    //Value
    Node* searchAtValue (descriptionNode* dNode, int data);
    //atPosition
    Node* searchAtPosition (descriptionNode* dNode, int position);

  //Transversal
    //printList
    void printList (descriptionNode* dNode);

    //printListInfo
    void printListInfo (descriptionNode* dNode);
