#include <stdio.h>
#include <stdlib.h>

//Definition of data
typedef struct data {
  int position;
  int waitingTime;
  int remaning;
  int critical;

} Data;

//Definition of Node
typedef struct Node {
  Data data;
  Node *next;
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
    //atEnd
    void insertAtEnd (descriptionNode* dNode, int data);

  //Search
    //Value
    int searchAtValue (descriptionNode* dNode, int data);

  //Update
    //UpdateCritical
    void updateCritical (descriptionNode* dNode)
  
  //Transversal
    //printListInfo
    void printListInfo (descriptionNode* dNode);

int main(int argc, char *argv[])
{
  descriptionNode* queueOfPatients = (descriptionNode *) malloc(sizeof(descriptionNode));

  int numberOfPatients; //Quantidade de pacientes
  scanf("%d", &numberOfPatients);
  int hour, minutes, remaning;;

  int i;
  for (i = 0; i < numberOfPatients;i++) {
    scanf("%d", &hour);
    scanf("%d", &minutes);
    scanf("%d", &remaning);

    if (queueOfPatients -> length == 0) {
      Node* novoPaciente = (Node *) malloc(sizeof(Node));
    }

  }

  return 0;
}

//Functions Definition
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
  Node* createNode (int position, int waitingTime, int remaning) {
  Node* newNode = (Node *) malloc(sizeof(Node));

  if (newNode = NULL) {
    puts("Allocation Memory Failed (Create Node)");
    return NULL;
  }

  newNode -> next = NULL;
  newNode -> hour = hour;
  newNode -> minutes = minutes;
  newNode -> remaning = remaning;
  newNode -> critical = 0;
  
  return newNode;
}

  //Insert 
    //atEnd
    void insertAtEnd (descriptionNode* dNode, int hour, int minutes, int remaning) {
    Node* newNode = createNode(hour, minutes, remaning);

    if (newNode == NULL) {
      puts("Error in insert at End"); 
      return;
    }
    
    newNode -> next = NULL;
    
    if (dNode -> length == 0) {
      dNode -> start = newNode;
      dNode -> end = newNode;
      dNode -> length = 1;
    } else {
      dNode -> end -> next = newNode;
      dNode -> end = newNode;
      dNode -> length += 1;
    }
}

  //Search
    //Value
    int searchAtValueNumber (descriptionNode* dNode, int data) {

}

  //Transversal
    //printListInfo
    void printListInfo (descriptionNode* dNode) {

}
