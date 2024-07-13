#include <stdio.h>
#include <stdlib.h>

//Declaration Function
  //descriptionNode
  descriptionNode* createDNode () {
    descriptionNode* newDNode = (descriptionNode *) malloc(sizeof(descriptionNode));

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

    if (newNode == NULL) {
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
      
      if (dNode -> length == 0) {
        dNode -> start = newNode;
        dNode -> end = newNode;
        dNode -> length = 1;
      } else {
        newNode -> next = dNode -> start;
        dNode -> start = newNode; 
        dNode -> length += 1;
      }
    }
    //atEnd
    void insertAtEnd (descriptionNode* dNode, int data) {
      Node* newNode = createNode(data);

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
    //atPosition
    void insertAtPosition (descriptionNode* dNode, int position, int data) {

      Node* newNode = createNode(data);

      if (newNode==NULL) {
        puts("Error in insert at position");
        return;
      }

      if (position < 1 || position > dNode->length) {
        puts("The position doesn't exist");
        return;
      } else if (position == 1) {
        insertAtBeginning(dNode, data);
      } else {
        Node* temp= dNode->start;
        int count = 1;

        while (count != position - 1) {
          temp = temp -> next;
          count++;
        }

        newNode -> next = temp-> next;
        temp -> next = newNode;
        dNode->length++;
      }

    }

  //Removal
    //atBeginning
    void removalAtBeginning (descriptionNode* dNode) {
    
      if (dNode -> length == 0) {
        puts("The List is already empty"); 
        return;
      } else if (dNode -> length == 1) {
        free(dNode -> start);
        dNode -> start = NULL;
        dNode -> end = NULL;
      } else {
        Node* temp = dNode -> start;
        dNode -> start = dNode -> start -> next;
        free(temp);
    }
      dNode -> length--;
    }
    //atEnd
    void removalAtEnd (descriptionNode* dNode) {
      
      if (dNode -> length == 0) {
        puts("The List is already empty"); 
        return;
      } else if (dNode -> length == 1) {
        free(dNode -> start);
        dNode -> start = NULL;
        dNode -> end = NULL;
      } else {
        Node* temp = dNode -> start;
        while (temp -> next -> next != NULL) {
          temp = temp -> next;
        }
        dNode -> end = temp;
        free(dNode -> end -> next);
        dNode -> end -> next = NULL;
       }
      dNode->length--;
    }
    //atPosition
    void removalAtPosition (descriptionNode* dNode, int position) {

      if (position < 1 || position > dNode->length) {
        puts("The position doesn't exist");
        return;
      } else if (position == 1) {
        removalAtBeginning(dNode);
      } else if (position == dNode -> length) { 
        removalAtEnd(dNode);
      } else {
        
        Node* temp = dNode->start;
        
        for (int i = 0;i < position - 1; i++) {
          temp = temp -> next;
        }
        
        Node* toDelete = temp->next;
        temp -> next = toDelete -> next;
        free(toDelete);
        
        dNode->length--;
      }
    }

  //Update
    //atPosition
    void updateAtPosition (descriptionNode *dNode, int data, int position) {

      if(position < 1 || position > dNode->length) {
        puts("The position doesn't exist");
        return; 
      }

      Node* temp = dNode -> start;
      int count = 1;

      while (count != position) {
        temp = temp -> next;
        count++;
      }
       
      temp -> data = data;
    }

  //Search
    //Value
    Node* searchAtValue (descriptionNode* dNode, int data) {
      if (dNode -> length == 0) {
        puts("The list is empty");
        return NULL;
      } else {
        Node* temp = dNode -> start;
        
        while (temp-> data != data && temp -> next != NULL) {
          temp = temp -> next;
        }
        
        if(temp -> data != data && temp -> next == NULL) {
          puts("The data doesn't exist");
          return NULL;
        }
        
        if (temp -> next == NULL && temp-> data != data) {
          puts("The data doesn't exist");
          return NULL;
        }
        
        return temp;
      }
    }
    //atPosition
    Node* searchAtPosition (descriptionNode* dNode, int position) {
    
      if (position < 0 || position > dNode -> length) {
        puts("The position doesn't exist");
        return NULL;
      }
      
      Node* temp = dNode -> start;
      int count = 1;

      while(count != position) {
        temp = temp -> next;
        count++;
      }

      return temp;

    }

  //Transversal
    //printList
    void printList (descriptionNode* dNode) {
      if (dNode -> length == 0) {
        puts("The list is empty");
      } else {
        Node* temp = dNode -> start;
        while (temp -> next != NULL) {
        printf("Node data: %d\n", temp->data);
        temp = temp -> next;
        }
        printf("Last Node data: %d\n", temp-> data);
      }
    }

    //printListInfo
    void printListInfo (descriptionNode* dNode) {
      if (dNode -> length == 0) {
        puts("The list is empty");
      } else {
        printf("List's length: %d\n", dNode-> length);
        printf("First Node: %d\n", dNode->start->data);
        printf("Last Node: %d\n", dNode->end->data);
      }
    }
