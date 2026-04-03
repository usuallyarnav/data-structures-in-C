#include <stdio.h>
#include <stdlib.h>
// Node structure representing each element in the stack
typedef struct node
{
    int data;
    struct node *next;
} node;

// Stack structure holding a reference to the top node and the next stack in the list
typedef struct stack
{
    struct node *head;
    struct stack *next;
} stack;

void createStack(stack **head_stack, stack **tail_stack, node **head)
// Creates a new stack and appends it to the end of the stack list
{
    stack *new_stack = (stack *)malloc(sizeof(stack));
    new_stack->next = NULL;
    new_stack->head = *head;
    if (*tail_stack != NULL)
    {
        (*tail_stack)->next = new_stack;
    }
    else
    {
        *head_stack = new_stack;
    }
    *tail_stack = new_stack;
}

void push(node **head, node **tail, int x)
// Inserts a new element at the top of the stack
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->next = NULL;
    new_node->data = x;
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

int pop(node **head)
// Removes and returns the top element of the stack, returns -1 if empty
{
    int p = -1;
    if (*head != NULL)
    {
        p = (*head)->data;
        node *temp = (*head)->next;
        free(*head);
        *head = temp;
    }
    return p;
}

int peek(node *head)
// Returns the top element of the stack without removing it, returns -1 if empty
{
    if (head != NULL)
        return head->data;
    return -1;
}

// Prints all stacks and their elements in order
void printStacks(stack **head_stack)
{
    stack *temp_stack = *head_stack;
    int i = 0;
    while (temp_stack != NULL)
    {
        node *temp_node = temp_stack->head;
        printf("\nStack %d\n", ++i);
        while (temp_node != NULL)
        {
            printf("%d -> ", temp_node->data);
            temp_node = temp_node->next;
        }
        printf("END\n");
        temp_stack = temp_stack->next;
    }
}

void freeMemory(stack **head_stack)
// Frees all dynamically allocated memory for nodes and stacks
{
    stack *temp_stack = *head_stack;
    int i = 0;
    while (temp_stack != NULL)
    {
        node *temp_node = temp_stack->head;
        while (temp_node != NULL)
        {
            node *traversal = temp_node->next;
            free(temp_node);
            temp_node = traversal;
        }
        temp_stack = temp_stack->next;
    }
    *head_stack = NULL;
}

int main()
{
    stack *head_stack = NULL, *tail_stack = NULL;
    char more = 'y';
    int i = 0;
    while (more == 'y')
    {
        char another = 'y';
        node *head_node = NULL, *tail_node = NULL;
        printf("STACK %d\n", ++i);
        while (another == 'y')
        {
            int x;
            printf("Enter the element you want to push\n");
            scanf("%d", &x);
            push(&head_node, &tail_node, x);
            printf("Do you want to push another element?\n");
            scanf(" %c", &another);
        }
        createStack(&head_stack, &tail_stack, &head_node);
        printf("Do you want to create another stack?\n");
        scanf(" %c", &more);
    }
    printStacks(&head_stack);
    printf("Do you want to pop an element from any of the stack?\n");
    scanf(" %c", &more);
    while (more == 'y')
    {
        int x;
        printf("Enter the index of the stack you want to pop an element from. If not, enter -1\n");
        scanf("%d", &x);
        if (x != -1)
        {
            stack *temp_stack = head_stack;
            int i;
            for (i = 0; temp_stack != NULL && i < x; i++)
                temp_stack = temp_stack->next;
            if (temp_stack == NULL)
            {
                printf("The stack does not exist\n");
                break;
            }
            int p = pop(&temp_stack->head);
            if (p != -1)
            {
                printf("The popped element from Stack %d is %d\n", i + 1, p);
            }
            else
            {
                printf("UNDERFLOW\n");
            }
            int ch;
            printf("Enter 1 to peek at the stack you just popped an element from\n");
            scanf("%d", &ch);
            if (ch == 1)
                printf("The top of stack %d is %d\n", i + 1, peek(temp_stack->head));
        }
        else
            break;
        printf("Do you want to do the same for this or another stack?\n");
        scanf(" %c", &more);
    }
    printStacks(&head_stack);
    freeMemory(&head_stack);
    return 0;
}