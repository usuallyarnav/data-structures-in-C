#include <stdio.h>
/*
Queue is a First-In-First_Out structure
*/
int queue[100];
int rear = -1;
int front = -1;
void enqueue(int x)
// Adds an element to the end of the queue
{
    if (front < 99 && rear < 99)
    {
        if (front == -1)
            front++;
        queue[++rear] = x;
    }
    else
    {
        printf("OVERFLOW\n");
    }
}
int dequeue()
// Removes and returns the element at the front of the queue, returns -1 if empty
{
    int p = -1;
    if (front <= rear && front != -1)
    {
        p = queue[front++];
    }
    return p;
}
void printQueue()
{
    for (int i = front; i <= rear; i++)
        printf("%d <-", queue[i]);
    printf("END\n");
}
int main()
{
    char more = 'y';
    while (more == 'y')
    {
        int x;
        printf("Enter the element you want to enqueue\n");
        scanf("%d", &x);
        enqueue(x);
        printf("Do you want to enqueue another element?\n");
        scanf(" %c", &more);
    }
    printQueue();
    printf("Do you want to dequeue an element?\n");
    scanf(" %c", &more);
    while (more == 'y')
    {
        int p = dequeue();
        if (p != -1)
            printf("The dequeued element is %d\n", p);
        else
        {
            printf("UNDERFLOW\n");
            return 1;
        }
        printf("Do you want to dequeue another element?\n");
        scanf(" %c", &more);
    }
    printQueue();
    return 0;
}