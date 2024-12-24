#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
void push(node **start, int data);
int pop(node **start);
int peek(node *start);
void prt_list(node *start);
int main()
{
    int opt;
    node *top = NULL;
    do
    {

        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print Stack\n");
        printf("0. Quit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            system("clear");
            int n;
            printf("Enter data to push: ");
            scanf("%d", &n);
            push(&top, n);
            break;
        case 2:
            system("clear");
            printf("Popped value is %d\n", pop(&top));
            break;
        case 3:
            system("clear");
            printf("The peeked valued is %d\n", peek(top));
            break;
        case 4:
            system("clear");
            prt_list(top);
            break;
        case 0:
            printf("Thank you for using....\n");
            break;

        default:
            printf("Invalid Input\n");
            break;
        }
    } while (opt != 0);

    return 0;
}
void push(node **start, int data)
{
    node *new = NULL;
    new = (node *)malloc(sizeof(node));

    if (new == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }
    new->next = *start;
    *start = new;
    new->data = data;
    printf("%d has been pushed\n", data);
}
int pop(node **start)
{
    if (*start == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        node *current = NULL;
        current = *start;
        *start = (*start)->next;
        int val = current->data;
        free(current);
        return val;
    }
}
int peek(node *start)
{
    if (start == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        return (start->data);
    }
}
void prt_list(node *start)
{
    if (start == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Elements of Stack are: ");
    node *current;
    for (current = start; current != NULL; current = current->next)
    {
        printf("%d ", current->data);
    }
    printf("\n");
}