#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct queue
{
    Node *front;
    Node *rear;
} Queue;

void enqueue(Queue *queue, int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newnode;
        return;
    }
    queue->rear->next = newnode;
    queue->rear = newnode;
    printf("%d enqueued to queue\n", data);
}
int dequeue(Queue *queue)
{
    Node *temp = NULL;
    if (queue->front == NULL)
    {
        printf("Queue is empty\n");
        exit(1);
    }
    temp = queue->front;
    int val = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    return val;
}
void display(Queue *queue)
{
    Node *current = NULL;
    if (queue->front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("The queue is: ");
    for (current = queue->front; current != NULL; current = current->next)
    {
        printf("%d ", current->data);
    }
    printf("\n");
}
int peek(Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty\n");
        exit(1);
    }

    return (queue->front->data);
}
int main(int argc, char const *argv[])
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;

    int choice;
    do
    {
        printf("[1] Enqueue.\n");
        printf("[2] Dequeue.\n");
        printf("[3] Print queue.\n");
        printf("[4] Peek.\n");
        printf("[0] Exit.\n\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int n;
            printf("Enter data to enqueue: ");
            scanf("%d", &n);
            enqueue(queue, n);
            break;
        case 2:
            printf("Recieved %d\n", dequeue(queue));
            break;
        case 3:
            display(queue);
            break;
        case 4:
            printf("Peeked: %d\n", peek(queue));
            break;
        case 0:
            printf("Exiting...\n");
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}
