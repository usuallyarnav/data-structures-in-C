#include <stdio.h>
/*
Stack is a Last-In-First_Out(LIFO) structure
*/
int stack[100];
int top = -1;
void push(int x)
// function to push the element at the top of the stack
{
    if (top < 99)
    {
        stack[++top] = x;
    }
    else
    {
        printf("OVERFLOW\n");
        return;
    }
}
int pop()
// function to pop the topmost element from the stack
{
    if (top > -1)
        return stack[top--];
    else
        return -1; // UNDERFLOW
}
int peek()
// function to see the topmost element of the stack
{
    if (top != -1)
        return stack[top];
    else
        return -1;
}
void printStack()
// function to print the stack
{
    for (int i = top; i >= 0; i--)
        printf("%d -> ", stack[i]);
    printf("END\n");
}
int main()
{
    char more = 'y';
    while (more == 'y')
    {
        int x;
        printf("Enter the element you want to push\n");
        scanf("%d", &x);
        push(x);
        printf("Do you want to push another element?\n");
        scanf(" %c", &more);
    }
    printStack();
    printf("Do you want to pop an element from the stack?\n");
    scanf(" %c", &more);
    while (more == 'y')
    {
        int p = pop();
        if (p != -1)
        {
            printf("The popped element is %d\n", p);
        }
        else
        {
            printf("UNDERFLOW\n");
        }
        int ch;
        printf("Enter 1 to peek at the stack.\n");
        scanf(" %d", &ch);
        if (ch == 1)
        {
            int q = peek();
            if (q != -1)
                printf("The top element of the stack is %d\n", q);
            else
            {
                printf("The stack is empty\n");
                return 1;
            }
        }
        printf("Do you want to delete another element from the stack?\n");
        scanf(" %c", &more);
    }
    printStack();
    return 0;
}