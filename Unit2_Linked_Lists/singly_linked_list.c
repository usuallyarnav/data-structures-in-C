#include <stdio.h>
#include <stdlib.h>
typedef struct node
// creating a user-defined 'node' data structure with the alias 'node'.
{
    int data;
    struct node *next;
} node;
void insertAtLast(node **head, node **tail)
// function to insert a node at the end of the Singly Linked List
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->next = NULL;
    printf("Enter the data you want to add into the node\n");
    scanf("%d", &new_node->data);
    if (*tail != NULL)
    {
        (*tail)->next = new_node;
    }
    else
    {
        *head = new_node;
    }
    *tail = new_node;
}
void insertAtFirst(node **head, node **tail)
// function to insert a node at the beginning of the Singly Linked List
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->next = NULL;
    printf("Enter the data you want to add into the node\n");
    scanf("%d", &new_node->data);
    if (*head != NULL)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        *head = *tail = new_node;
    }
}
void deleteFirst(node **head, node **tail)
// function to delete the first node of the Singly Linked List
{
    if (*head != NULL)
    {
        node *temp = (*head)->next;
        free(*head);
        *head = temp;
    }
    else
    {
        printf("The list is already empty\n");
        return;
    }
}
void deleteLast(node **head, node **tail)
// function to delete the first node of the Doubly Linked List
{
    if (*tail != NULL)
    {
        node *temp = *head;
        while (temp->next != *tail)
        {
            temp = temp->next;
        }
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
void concatenateLists(node **tail_1, node **head_2)
// function to concatenate two Singly Linked Lists
{
    if (*tail_1 != NULL || *head_2 != NULL)
        (*tail_1)->next = *head_2;
    else
        printf("One or both of the lists is empty\n");
}
void printList(node *head)
// function to print the Singly Linked List
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void freeMemory(node **head)
// function to free the dynamically allocated memory through malloc
{
    node *temp = *head;
    while (temp != NULL)
    {
        node *traverse = temp->next;
        free(temp);
        temp = traverse;
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
    printList(head);
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
    printList(head);
    printf("Do you want to create another list?\n");
    scanf(" %c", &more);
    node *head_2 = NULL, *tail_2 = NULL;
    while (more == 'y')
    {
        int ch;
        printf("Enter 1 to insert a node at the beginning and 2 to insert at the last\n");
        scanf("%d", &ch);
        if (ch == 1)
            insertAtFirst(&head_2, &tail_2);
        if (ch == 2)
            insertAtLast(&head_2, &tail_2);
        printf("Do you want to add another node?\n");
        scanf(" %c", &more);
    }
    concatenateLists(&tail, &head_2);
    printf("The concatenated list is :\n");
    printList(head);
    freeMemory(&head);
    return 0;
}