#include <stdio.h>
#include <stdlib.h>
/*
The deque is structured in this way :
    Left end(front)-> =============================== <- Right end(rear)
*/
/* CHECK ONCE!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;
void enqueue_right(node **front, node **rear, int x) // insert node at the end
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->next = new_node->prev = NULL;
    new_node->data = x;
    if (*rear != NULL)
    {
        (*rear)->next = new_node;
        new_node->prev = *rear;
    }
    else
    {
        *front = new_node;
    }
    *rear = new_node;
}
void enqueue_left(node **front, node **rear, int x) // insert node at the beginning
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->next = new_node->prev = NULL;
    new_node->data = x;
    if (*front != NULL)
    {
        new_node->next = *front;
        (*front)->prev = new_node;
        *front = new_node;
    }
    else
    {
        *front = *rear = new_node;
    }
}
int dequeue_right(node **front, node **rear) // remove from end
{
    if (*front == NULL || *rear == NULL)
        return -1;
    int p = (*rear)->data;
    if (*front == *rear) // when the deque contains only one node
    {
        free(*rear);
        *front = *rear = NULL;
    }
    else
    {
        node *temp = (*rear)->prev;
        free(*rear);
        *rear = temp;
        (*rear)->next = NULL;
    }
    return p;
}
int dequeue_left(node **front, node **rear) // remove from beginning
{
    if (*front == NULL || *rear == NULL)
        return -1;
    int p = (*front)->data;
    if (*front == *rear) // when the deque contains only one node
    {
        free(*front);
        *front = *rear = NULL;
    }
    else
    {
        node *temp = (*front)->next;
        free(*front);
        *front = temp;
        (*front)->prev = NULL;
    }
    return p;
}
void printDeque(node **front)
{
    node *temp = *front;
    printf("<- ");
    while (temp != NULL)
    {
        printf("%d - ", temp->data);
        temp = temp->next;
    }
    printf("-> \n");
}
void freeMemory(node **front)
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
    int ch;
    char more;
    printf("Enter 1 to enqueue\n");
    printf("Enter 2 to dequeue\n");
    scanf("%d", &ch);
    if (ch != 1 && ch != 2)
    {
        printf("INVALID INPUT\n");
        return 1;
    }
    while (ch == 1)
    {
        char x;
        printf("Enter L to enqueue left\n");
        printf("Enter R to enqueue right\n");
        scanf(" %c", &x);
        while (x == 'L')
        {
            int a;
            printf("Enter the data you want to enqueue left\n");
            scanf("%d", &a);
            enqueue_left(&front, &rear, a);
            printf("Enter L to enqueue another element to the left. Enter N for no.\n");
            scanf(" %c", &x);
        }
        printf("Enter L to enqueue left\n");
        printf("Enter R to enqueue right\n");
        scanf(" %c", &x);
        while (x == 'R')
        {
            int a;
            printf("Enter the data you want to enqueue right\n");
            scanf("%d", &a);
            enqueue_right(&front, &rear, a);
            printf("Enter R to enqueue another element to the right. Enter N for no.\n");
            scanf(" %c", &x);
        }
        printf("Enter 1 to continue enqueuing. Enter 2 to move to dequeing.\n");
        scanf("%d", &ch);
    }
    printDeque(&front);
    while (ch == 2)
    {
        char x;
        printf("Enter L to dequeue left\n");
        printf("Enter R to dequeue right\n");
        scanf(" %c", &x);
        while (x == 'L')
        {
            int p = dequeue_left(&front, &rear);
            if (p == -1)
            {
                printf("UNDERFLOW\n");
                return 1;
            }
            printf("The dequed element is %d\n", p);
            printf("Enter L to dequeue another element from left. Enter N for no.\n");
            scanf(" %c", &x);
        }
        printf("Enter L to dequeue left\n");
        printf("Enter R to dequeue right\n");
        scanf(" %c", &x);
        while (x == 'R')
        {
            int p = dequeue_right(&front, &rear);
            if (p == -1)
            {
                printf("UNDERFLOW\n");
                return 1;
            }
            printf("The dequed element is %d\n", p);
            printf("Enter R to dequeue another element from right. Enter N for no.\n");
            scanf(" %c", &x);
        }
        printf("Enter 2 to continue dequeing. Enter -1 to exit.\n");
        scanf("%d", &ch);
    }
    if (front != NULL && rear != NULL)
        printDeque(&front);
    else
        printf("The deque is empty\n");
    freeMemory(&front);
    return 0;
}