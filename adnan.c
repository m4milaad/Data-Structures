#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack_arr[MAX];
int top = -1;

void push(int data);
int pop();
int isFull();
int isEmpty();
void printTop();
void printStack();

int main(int argc, char const *argv[])
{
    int n, opt;

    do
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print top\n");
        printf("4. Print Stack\n");
        printf("5. Quit\n");
        printf("\nEnter option: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("Enter the data to push: ");
            scanf("%d", &n);
            push(n);
            break;
        case 2:
            printf("Popped value: %d\n", pop());
            break;
        case 3:
            printTop();
            break;
        case 4:
            printStack();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }

    } while (opt != 5);

    return 0;
}

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAX - 1;
}

void push(int data)
{
    if (isFull())
    {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack_arr[top] = data;
    printf("Data pushed: %d\n", data);
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack underflow\n");
        exit(1);
    }
    int val = stack_arr[top];
    top--;
    return val;
}

void printTop()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element: %d\n", stack_arr[top]);
    }
}

void printStack()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack_arr[i]);
        }
        printf("\n");
    }
}
