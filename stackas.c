#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 50

typedef struct stackas // structure for stack array imp
{
    int s_arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack);
void push(Stack *stack, int data);
int pop(Stack *Stack);
int peek(Stack *stack);
void print_list(Stack *stack);
bool isEmpty(Stack *stack);
bool isFull(Stack *stack);

int main(int argc, char const *argv[])
{
    Stack stack;
    initialize(&stack); // passed address
    int choice;
    do
    {

        printf("Press \"1\" to push\n");
        printf("Press \"2\" to pop\n");
        printf("Press \"3\" to peek\n");
        printf("Press \"4\" to print list\n");
        printf("Press \"0\" to quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("clear"); // use system ("cls"); in windows
            int n;
            printf("Enter the value to push: ");
            scanf("%d", &n);
            push(&stack, n);
            break;
        case 2:
            system("clear");
            printf("\t\t\tThe popped value is %d\n\n", pop(&stack));
            break;
        case 3:
            system("clear");
            printf("\t\t\tThe peeked value is %d\n\n", peek(&stack));
            break;
        case 4:
            system("clear");
            print_list(&stack);
            break;
        case 0:
            system("clear");
            printf("Thank you...\n");
            break;
        default:
            system("clear");
            printf("\t\t\t\tOption does not exist\n");
            break;
        }

    } while (choice != 0);

    return 0;
}
void initialize(Stack *stack)
{
    stack->top = -1; // set top as -1 because no element present
}
void push(Stack *stack, int data)
{

    if (isFull(stack)) // checking overflow condition
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->s_arr[stack->top] = data;
    printf("\n\t\t\tPushed: %d\n\n", data);
}
int pop(Stack *stack)
{

    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int val = stack->s_arr[stack->top];
        stack->top--;
        return val;
    }
}
int peek(Stack *stack)
{

    return (stack->s_arr[stack->top]);
}
void print_list(Stack *stack)
{

    if (stack->top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("\n\t\tThe list is: ");
    for (size_t i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->s_arr[i]);
    }
    printf("\n\n");
}
bool isEmpty(Stack *stack)
{
    return stack->top == -1; // only write condition on which it'll return a true value (1)
}
bool isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1; // only write condition on which it'll return a true value (1)
}