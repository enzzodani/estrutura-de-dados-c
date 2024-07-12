#include <stdio.h>
#include <stdlib.h>

//Node structure
typedef struct Node Node;
struct Node {
  int data;
  Node* left;
  Node* right;
};

//Node structure
Node* Root = NULL;

//Functions Declaration
Node* createNode(int data);

void insertNode(Node* newNode);

void removeNode(int data);

Node* searchNode(int data);

void inOrder();

void preOrder();

void postOrder();

Node* maxNode();

Node* minNode();

int treeLenght();

Node* cleanTree();

//Main
int main(int argc, char *argv[])
{

  return 0;
}

//Functions Definitions
Node* createNode(int data) {

}

void insertNode(Node* newNode) {

}
