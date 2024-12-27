#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int stack_arr[MAX];
int top = -1;

void push(int data);
int pop();
int isFull();
int isEmpty();
void prt_stack();

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
        printf("\n Enter option: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("Enter the data to push: ");
            scanf("%d", &n);
            push(n);
            break;
        case 2:
            printf("%d has been popped", pop());
            break;
        case 3:
            if (isEmpty())
            {
                printf("\t\tStack underflow\n");
                break;
            }
            printf("The value on top is: %d\n", stack_arr[top]);
            break;
        case 4:
            prt_stack();
            break;
        case 5:
            printf("Thanks for using\n");
            break;
        default:
            printf("Use your eyes Nigga\nYour eyes are gone watching hentai\n");
            break;
        }

    } while (opt != 5);

    return 0;
}
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int isFull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
        return 0;
}
void push(int data)
{
    if (isFull())
    {
        printf("\t\tStack overflow\n");
        return;
    }
    top++;
    stack_arr[top] = data;
    printf("Data pushed %d\n", data);
}
int pop()
{
    int val;
    if (isEmpty())
    {
        printf("\t\tStack underflow\n");
        exit(1);
    }
    val = stack_arr[top];
    top--;
    return val;
}
void prt_stack()
{
    if (isEmpty())
    {
        printf("\t\tStack underflow\n");
        return;
    }

    printf("The stack is: ");
    for (size_t i = 0; i <= top; i++)
    {
        printf("%d ", stack_arr[i]);
    }
    printf("\n");
}