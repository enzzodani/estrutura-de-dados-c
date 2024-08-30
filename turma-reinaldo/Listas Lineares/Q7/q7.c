#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
void insertAfter(Node *head, int newValue, int afterValue)
{
    Node *current = head;
    while (current != NULL && current->value != afterValue)
    {
        current = current->next;
    }
    if (current != NULL)
    {
        Node *newNode = createNode(newValue);
        newNode->next = current->next;
        current->next = newNode;
        printf("inserido %d\n", newValue);
    }
}
void removeNode(Node **head, int value)
{
    Node *current = *head;
    Node *prev = NULL;

    if (current != NULL && current->value == value)
    {
        *head = current->next;
        free(current);
        printf("removido %d\n", value);
        return;
    }

    while (current != NULL && current->value != value)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
        return;

    prev->next = current->next;
    free(current);
    printf("removido %d\n", value);
}
void countBetween(Node *head, int a, int b)
{
    Node *current = head;
    int start = -1, end = -1;
    int index = 0;

    while (current != NULL)
    {
        if (current->value == a)
            start = index;
        if (current->value == b)
            end = index;
        current = current->next;
        index++;
    }

    if (start > end)
    {
        int temp = start;
        start = end;
        end = temp;
    }

    int count = end - start - 1;
    printf("quantidade %d\n", count);
}
void showList(Node *head)
{
    Node *current = head;
    if (current == NULL)
    {
        printf("lista vazia\n");
        return;
    }
    printf("lista ");
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
int main()
{
    int n;
    scanf("%d", &n);
    Node *head = NULL;
    Node *tail = NULL;
    int i;
    for (i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        Node *newNode = createNode(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    char operation;
    while (scanf(" %c", &operation) != EOF)
    {
        if (operation == 'I')
        {
            int p, e;
            scanf("%d %d", &p, &e);
            insertAfter(head, p, e);
        }
        else if (operation == 'R')
        {
            int p;
            scanf("%d", &p);
            removeNode(&head, p);
        }
        else if (operation == 'C')
        {
            int a, b;
            scanf("%d %d", &a, &b);
            countBetween(head, a, b);
        }
        else if (operation == 'M')
        {
            showList(head);
        }
        else if (operation == 'F')
        {
            printf("fim\n");
            break;
        }
    }
    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->next;
        free(current);
        current = next;
    }
    return 0;
}