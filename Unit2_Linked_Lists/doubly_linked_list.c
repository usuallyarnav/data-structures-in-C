#include <stdio.h>
#include <stdlib.h>
typedef struct node
// creating a user-defined 'node' data structure with the alias 'node'.
{
    int data;
    struct node *next;
    struct node *prev;
} node;
void insertAtLast(node **head, node **tail)
// function to insert a node at the end of the Doubly Linked List
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->next = new_node->prev = NULL;
    printf("Enter the data you want to add into the node\n");
    scanf("%d", &new_node->data);
    if (*tail != NULL)
    {
        (*tail)->next = new_node;
        new_node->prev = *tail;
        *tail = new_node;
    }
    else
    {
        *head = *tail = new_node;
    }
}
void insertAtFirst(node **head, node **tail)
// function to insert a node at the beginning of the Doubly Linked List
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->prev = new_node->next = NULL;
    printf("Enter the data you want to add into the node\n");
    scanf("%d", &new_node->data);
    if (*head != NULL)
    {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
    }
    else
    {
        *head = *tail = new_node;
    }
}
void deleteLast(node **head, node **tail)
// function to delete the last node of the Doubly Linked List
{
    if (*tail != NULL)
    {
        node *temp = (*tail)->prev;
        free(*tail);
        *tail = temp;
        (*tail)->next = NULL;
    }
    else
    {
        printf("The list is already empty\n");
        return;
    }
}
void deleteFirst(node **head, node **tail)
// function to delete the first node of the Circular Linked List
{
    if (*head != NULL)
    {
        node *temp = (*head)->next;
        free(*head);
        *head = temp;
        (*head)->prev = NULL;
    }
    else
    {
        printf("The list is already empty\n");
        return;
    }
}
void printListForward(node *head)
// function to print the Doubly Linked List in forward direction
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void printListBackward(node *tail)
// function to print the Doubly Linked List in backward direction
{
    node *temp = tail;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
void freeMemory(node **head)
// function to free the dynamically allocated memory through malloc
{
    node *temp = *head;
    while (temp != NULL)
    {
        node *traversal = temp->next;
        free(temp);
        temp = traversal;
    }
    *head = NULL;
}
int main()
{
    node *head = NULL, *tail = NULL;
    char more = 'y';
    while (more == 'y')
    {
        int ch;
        printf("Enter 1 to insert a node at the beginning and 2 to insert at the last\n");
        scanf("%d", &ch);
        if (ch == 1)
            insertAtFirst(&head, &tail);
        if (ch == 2)
            insertAtLast(&head, &tail);
        printf("Do you want to add another node?\n");
        scanf(" %c", &more);
    }
    printf("The list printed in forward direction :\n");
    printListForward(head);
    printf("The list printed in backward direction :\n");
    printListBackward(tail);
    more = 'y';
    while (more == 'y')
    {
        int ch;
        printf("Enter 1 to delete a node from the beginning and 2 to delete a node from the end. Otherwise, Enter -1\n");
        scanf("%d", &ch);
        if (ch == 1)
            deleteFirst(&head, &tail);
        else if (ch == 2)
            deleteLast(&head, &tail);
        printf("Do want to delete another node?\n");
        scanf(" %c", &more);
    }
    printf("The list printed in forward direction :\n");
    printListForward(head);
    printf("The list printed in backward direction :\n");
    printListBackward(tail);
    freeMemory(&head);
    return 0;
}