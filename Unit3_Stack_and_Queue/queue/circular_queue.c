#include <stdio.h>
#include <stdlib.h>
int queue[7];
int front = -1;
int rear = -1;

// Inserts a new element at the rear of the circular queue
void enqueue(int x)
{
    if (front == (rear + 1) % 7)
    {
        printf("Overflow\n");
        exit(1);
    }
    if (front == -1)
        ++front;
    rear = (rear + 1) % 7;
    queue[rear] = x;
}

// Removes and returns the element at the front of the circular queue, returns -1 if empty
int dequeue()
{
    if (front == -1 || rear == -1)
        return -1;
    int p = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
        front = (front + 1) % 7;
    return p;
}

// Prints all elements in the circular queue from front to rear
void printQueue()
{
    if (front == -1 || rear == -1)
    {
        printf("The queue is empty\n");
        return;
    }
    printf("START <- ");
    for (int i = front;; i = (i + 1) % 7)
    {
        printf("%d <- ", queue[i]);
        if (i == rear)
            break;
    }
    printf("END\n");
}

int main()
{
    char more = 'y';
    char again = 'y';
    int ch;
    while (again == 'y')
    {
        printf("Enter 1 to enqueue\n");
        printf("Enter 2 to dequeue\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            more = 'y';
            while (more == 'y')
            {
                int x;
                printf("Enter the element you want to enqueue\n");
                scanf("%d", &x);
                enqueue(x);
                printf("Do you want to enqueue another element? (y/n)\n");
                scanf(" %c", &more);
            }
            break;

        case 2:
            printf("Do you want to dequeue an element? (y/n)\n");
            scanf(" %c", &more);
            while (more == 'y')
            {
                int p = dequeue();
                if (p == -1)
                {
                    printf("UNDERFLOW\n");
                    return 1;
                }
                printf("The dequeued element is %d\n", p);
                printf("Do you want to dequeue another element? (y/n)\n");
                scanf(" %c", &more);
            }
            break;

        default:
            printf("INVALID INPUT\n");
            break;
        }
        printQueue();
        printf("Do you want to repeat (y/n)?\n");
        scanf(" %c", &again);
    }
    printf("The final queue is : \n");
    printQueue();
    return 0;
}