#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} Node;

void create_list(Node **head, Node **last);
void insert_node(Node **head, Node **last);
void delete_node(Node **head, Node **last);
void reverse_list(Node **head, Node **last);
void print_list(Node **head, Node **last);
int list_size(Node **head);
int main()
{
    Node *head = NULL, *tail = NULL;
    int choice;
    do
    {
        printf("[1] Create List\n");
        printf("[2] Insert Node\n");
        printf("[3] Delete Node\n");
        printf("[4] Reverse List\n");
        printf("[5] Print List\n");
        printf("[6] List Size\n");
        printf("[0] Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create_list(&head, &tail);
            break;
        case 2:
            insert_node(&head, &tail);
            break;
        case 3:
            delete_node(&head, &tail);
            break;
        case 4:
            reverse_list(&head, &tail);
            break;
        case 5:
            print_list(&head, &tail);
            break;
        case 6:
            printf("List size: %d\n", list_size(&head));
            break;

        default:
            break;
        }
    } while (choice != 0);

    return 0;
}
void create_list(Node **head, Node **last)
{
    int qty;
    Node *newnode = NULL;
    printf("Nodes to be created: ");
    scanf("%d", &qty);

    for (size_t i = 0; i < qty; i++)
    {
        newnode = (Node *)malloc(sizeof(Node));
        newnode->next = newnode->prev = NULL;
        printf("Enter data to node: ");
        scanf("%d", &newnode->data);
        if (*head == NULL)
        {
            *head = *last = newnode;
        }
        else
        {
            (*last)->next = newnode;
            newnode->prev = *last;
            *last = newnode;
        }
    }
}
int list_size(Node **head)
{
    int size = 0;
    for (Node *current = (*head); current != NULL; current = current->next)
    {
        size++;
    }
    return size;
}
void insert_node(Node **head, Node **last)
{
    int pos;
    int size = list_size(head);
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->next = newnode->prev = NULL;
    printf("Enter data to insert: ");
    scanf("%d", &newnode->data);

    printf("Place to insert (1-%d): ", size);
    scanf("%d", &pos);

    if (pos == 1)
    {
        (*head)->prev = newnode;
        newnode->next = (*head);
        (*head) = newnode;
    }
    else if (pos == size + 1)
    {
        newnode->prev = (*last);
        (*last)->next = newnode;
        (*last) = newnode;
    }
    else if (pos > 1 && pos <= size)
    {
        Node *current = (*head);

        for (size_t i = 1; i < pos - 1; i++)
        {
            current = current->next;
        }
        newnode->next = current->next;
        newnode->prev = current;
        newnode->next->prev = newnode;
        current->next = newnode;
    }
    printf("Node inserted successfully with data %d\n", newnode->data);
}
void print_list(Node **head, Node **last)
{
    int choice;
    printf("Enter 1 to print from head to tail\n");
    printf("Enter 2 to print from tail to head\n\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    Node *current;
    if (choice == 1)
    {
        printf("The list is: ");
        for (current = (*head); current != NULL; current = current->next)
        {
            printf("%d ", current->data);
        }
        printf("\n");
    }
    if (choice == 2)
    {
        printf("The list is: ");
        for (current = (*last); current != NULL; current = current->prev)
        {
            printf("%d ", current->data);
        }
        printf("\n");
    }
}
void delete_node(Node **head, Node **last)
{
    Node *current = NULL;

    int pos, size = list_size(head);
    printf("The list is: ");
    for (current = (*head); current != NULL; current = current->next)
    {
        printf("%d ", current->data);
    }
    printf("\n");
    printf("Enter the position of the node to be deleted(1-%d): ", size);
    scanf("%d", &pos);
    if (pos == 1)
    {
        current = (*head);
        (*head) = (*head)->next;
        (*head)->prev = NULL;
        free(current);
    }
    else if (pos == size)
    {
        current = (*last);
        current->prev->next = NULL;
        (*last) = current->prev;
        free(current);
    }
    else if (pos > 1 && pos < size)
    {
        for (size_t i = 1; i < pos; i++)
        {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    }
    printf("Node deleted!\n");
}
void reverse_list(Node **head, Node **last)
{
    Node *current = (*head), *next_node = NULL;

    for (; current != NULL; current = next_node)
    {
        next_node = current->next;
        current->next = current->prev;
        current->prev = next_node;
    }
    current = (*head);
    (*head) = (*last);
    (*last) = current;
    printf("List has been reversed!\n");
}