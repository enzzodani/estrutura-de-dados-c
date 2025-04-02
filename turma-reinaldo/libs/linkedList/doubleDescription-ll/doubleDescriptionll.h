#ifndef DOUBLE_LINKED_LIST_DESCRIPTION_H 
#define DOUBLE_LINKED_LIST_DESCRIPTION_H

//Definition of Node
typedef struct Node {
    int data;
    Node *next;
    Node *previous;
} Node;

//Definition of description Node
typedef struct descriptionNode {
  unsigned int length;
  Node *start;
  Node *end;
} descriptionNode;

//Declaration Function
  //descriptionNode
  descriptionNode* createDNode ();

  //Insert 
    //atBeginning
    void insertAtBeginning (Node* newNode, descriptionNode* dNode);
    //atEnd
    void insertAtEnd (Node* newNode, descriptionNode* dNode);
    //atPosition
    void insertAtPosition (Node* newNode, descriptionNode* dNode, int position);

  //Removal
    //atBeginning
    void removalAtBeginning (Node* newNode, descriptionNode* dNode);
    //atEnd
    void removalAtEnd (Node* newNode, descriptionNode* dNode);
    //atPosition
    void removalAtPosition (Node* newNode, descriptionNode* dNode, int position);

  //Update
    //atPosition
    void updateAtPosition (int data, descriptionNode *dNode);

  //Search
    //Value
    Node searchAtValue (descriptionNode* dNode, int data);
    //atPosition
    Node searchAtPosition (descriptionNode* dNode, int position);

  //Transversal
    //printList
    void printList (descriptionNode* dNode);

    //printListInfo
    void printListInfo (descriptionNode* dNode);

#endif
