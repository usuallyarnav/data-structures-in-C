#include <stdio.h>
#include <stdlib.h>
typedef struct node
// creating a user-defined 'node' data structure with the alias 'node'
{
    int data;
    struct node *next;
} node;
void insertAtLast(node **tail)
// function to insert a node at the end of the Circular Linked List
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->next = NULL;
    printf("Enter the data you want to add into the node\n");
    scanf("%d", &new_node->data);
    if (*tail != NULL)
    {
        node *temp = (*tail)->next;
        (*tail)->next = new_node;
        new_node->next = temp;
        *tail = new_node;
    }
    else
    {
        *tail = new_node;
        (*tail)->next = *tail;
    }
}
void insertAtFirst(node **tail)
// function to insert a node at the beginning of the Circular Linked List
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->next = NULL;
    printf("Enter the data you want to add into the node\n");
    scanf("%d", &new_node->data);
    if (*tail != NULL)
    {
        node *temp = (*tail)->next;
        (*tail)->next = new_node;
        new_node->next = temp;
    }
    else
    {
        *tail = new_node;
        (*tail)->next = *tail;
    }
}
void deleteLast(node **tail)
// function to delete the last node of the Circular Linked List
{
    if (*tail != NULL)
    {
        node *head = (*tail)->next;
        node *temp = (*tail)->next;
        while (temp->next != *tail)
        {
            temp = temp->next;
        }
        free(*tail);
        *tail = temp;
        (*tail)->next = head;
    }
    else
    {
        printf("The list is already empty\n");
        return;
    }
}
void deleteFirst(node **tail)
// function to delete the first node of the Circular Linked List
{
    if (tail != NULL)
    {
        node *temp = (*tail)->next->next;
        free((*tail)->next);
        (*tail)->next = temp;
    }
    else
    {
        printf("The list is already empty\n");
        return;
    }
}
void printList(node *tail)
// function to print the Circular Linked List
{
    node *head = tail->next;
    node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}
void freeMemory(node **tail)
// function to free the dynamically allocated memory through malloc
{
    node *head = (*tail)->next;
    node *temp = (*tail)->next;
    do
    {
        node *traversal = temp->next;
        free(temp);
        temp = traversal;
    } while (temp != head);
    *tail = NULL;
}
int main()
{
    node *tail = NULL;
    char more = 'y';
    while (more == 'y')
    {
        int ch;
        printf("Enter 1 to insert a node at the beginning and 2 to insert at the last\n");
        scanf("%d", &ch);
        if (ch == 1)
            insertAtFirst(&tail);
        if (ch == 2)
            insertAtLast(&tail);
        printf("Do you want to add another node?\n");
        scanf(" %c", &more);
    }
    printList(tail);
    more = 'y';
    while (more == 'y')
    {
        int ch;
        printf("Enter 1 to delete a node from the beginning and 2 to delete a node from the end. Otherwise, Enter -1\n");
        scanf("%d", &ch);
        if (ch == 1)
            deleteFirst(&tail);
        else if (ch == 2)
            deleteLast(&tail);
        printf("Do want to delete another node?\n");
        scanf(" %c", &more);
    }
    printList(tail);
    freeMemory(&tail);
    return 0;
}