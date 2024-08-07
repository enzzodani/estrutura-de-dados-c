#ifndef LINKED_LIST_DESCRIPTION_H
#define LINKED_LIST_DESCRIPTION_H

//Definition of Node
typedef struct Node {
    int data;
    struct Node *next;
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

  //Create Node
  Node* createNode (int data);

  //Insert 
    //atBeginning
    void insertAtBeginning (descriptionNode* dNode, int data);
    //atEnd
    void insertAtEnd (descriptionNode* dNode, int data);
    //atPosition
    void insertAtPosition (descriptionNode* dNode, int position, int data);

  //Removal
    //atBeginning
    void removalAtBeginning (descriptionNode* dNode);
    //atEnd
    void removalAtEnd (descriptionNode* dNode);
    //atPosition
    void removalAtPosition (descriptionNode* dNode, int position);

  //Update
    //atPosition
    void updateAtPosition (descriptionNode *dNode, int position, int data);

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

#endif
