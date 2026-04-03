#include <stdio.h>
#include <stdlib.h>
/*
Queue is a First-in-First-out structure.
*/
typedef struct node
// A user-defined data structure 'node' to implement queue using Linked List
{
    int data;
    struct node *next;
} node;
void enqueue(node **front, node **rear, int x) // equivalent to adding a node at the end
// Adds an element at the end
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = x;
    new_node->next = NULL;
    if (*rear != NULL)
    {
        (*rear)->next = new_node;
    }
    else
    {
        *front = new_node;
    }
    *rear = new_node;
}
int dequeue(node **front) // equivalent to removing a node from the beginning
// Removes and returns the element at the front of the queue, returns -1 if empty
{
    if (*front == NULL)
    {
        return -1;
    }
    int p = (*front)->data;
    node *temp = (*front)->next;
    free(*front);
    *front = temp;
    return p;
}
void printQueue(node **front)
// Prints the queue
{
    node *temp = *front;
    printf("START <- ");
    while (temp != NULL)
    {
        printf("%d <- ", temp->data);
        temp = temp->next;
    }
    printf("END\n");
}
void freeMemory(node **front)
// Frees the dynamically allocated memory to the nodes
{
    node *temp = *front;
    while (temp != NULL)
    {
        node *traversal = temp->next;
        free(temp);
        temp = traversal;
    }
    *front = NULL;
}
int main()
{
    node *front = NULL, *rear = NULL;
    char more = 'y';
    while (more == 'y')
    {
        int x;
        printf("Enter the element you want to enqueue\n");
        scanf("%d", &x);
        enqueue(&front, &rear, x);
        printf("Do you want to enqueue another element? (y/n)\n");
        scanf(" %c", &more);
    }
    printQueue(&front);
    printf("Do you want to dequeue an element? (y/n)\n");
    scanf(" %c", &more);
    while (more == 'y')
    {
        int p = dequeue(&front);
        if (p == -1)
        {
            printf("UNDERFLOW\n");
            return 1;
        }
        printf("The dequeued element is %d\n", p);
        printf("Do you want to dequeue another element? (y/n)\n");
        scanf(" %c", &more);
    }
    printQueue(&front);
    freeMemory(&front);
    return 0;
}