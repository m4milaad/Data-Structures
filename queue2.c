#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int f = -1, r = -1;

void enqueue(int data);
int dequeue();
void prt_q();
int peek();


int main()
{
    int choice;

    do
    {
        printf("[1] Enqueue.\n");
        printf("[2] Dequeue.\n");
        printf("[3] Print queue.\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int n;
            printf("Enter data to enqueue: ");
            scanf("%d", &n);
            enqueue(n);
            break;
        case 2:
            printf("Recieved %d\n", dequeue());
            break;
        case 3:
            prt_q();
            break;
        case 4:
            printf("Peeked: %d", peek());
            break;
        case 0:
            printf("Exiting...\n");
        default:
            break;
        }

    } while (choice != 0);

    return 0;
}
void enqueue(int data)
{
    if (r == SIZE - 1)
    {
        printf("Queue is full!\n");
    }
    else
    {
        if (f == -1)
            f = 0;
        r++;
        queue[r] = data;
        printf("%d enqueued to queue\n", data);
    }
}
int dequeue()
{
    int i;
    if (f == -1)
    {
        printf("queue is empty!\n");
    }
    else
    {
        if (r == f)
            f--;
        int data = queue[f];

        for (i = f; i <= r; i++)
        {
            queue[i] = queue[i + 1];
        }
        queue[--i] = 0;
        r--;
        return data;
    }
}
void prt_q()
{
    if (f == -1)
    {
        printf("queue is empty!\n");
    }
    else
    {
        printf("The queue is: ");
        for (size_t i = f; i <= r; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int peek()
{
    if (f == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        return queue[f];
    }
}