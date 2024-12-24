#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void create();
void printlist();
void insert_node();
void del_node();
void reverse();
void freelist();
void sort_list();
void concat_list();

int main()
{
    int check;

    do
    {
        printf("\n\nWhat do you want to do\n\n");
        printf("Press \"1\" to create list\n");
        printf("Press \"2\" to insert a node in the list\n");
        printf("Press \"3\" to delete a nodes in the list\n");
        printf("Press \"4\" to reverse the list\n");
        printf("Press \"5\" to print the list\n");
        printf("Press \"6\" to free the list\n");
        printf("Press \"7\" to sort the list\n");

        printf("Press \"0\" to end\n");

        printf("\nEnter the value of opertion to execute: ");
        scanf("%d", &check);

        switch (check)
        {
        case 0:
            printf("\nThank you for using this\n");
            freelist();
            break;
        case 1:
            create();
            break;
        case 2:
            insert_node();
            break;
        case 3:
            del_node();
            break;
        case 4:
            reverse();
            break;
        case 5:
            printlist();
            break;
        case 6:
            freelist();
            break;
        case 7:
            sort_list();
            break;
        default:
            printf("\n\tOperation not valid\n");
            printf("\nEnter the value of opertion to execute\n");
            printf("\n or Press \"0\" to end: ");
            scanf("%d", &check);
            break;
        }
    } while (check != 0);
    return 0;
}

void create()
{
    if (head != NULL)
    {
        printf("List is already created\n");
        printf("You can now add or delete nodes: ");
    }

    int no;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &no);

    if (no <= 0)
    {
        printf("Invalid input. Number of nodes should be a positive integer.\n");
        return;
    }

    head = (struct node *)malloc(sizeof(struct node));
    struct node *current = head;

    for (int i = 1; i <= no; i++)
    {
        printf("Enter the data in node %d: ", i);
        scanf("%d", &current->data);

        if (i < no)
        {
            current->next = (struct node *)malloc(sizeof(struct node));
            current = current->next;
        }
        else
            current->next = NULL;
    }
}
void printlist()
{
    if (head == NULL)
    {
        printf("\n\tNo nodes created.\n");
        return;
    }

    struct node *temp = head;
    printf("The linked list is: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}
void insert_node()
{
    if (head == NULL)
    {
        printf("No nodes created\nPlease create the Linked List first");
        return;
    }

    struct node *new_node, *current = head;
    int pos, count = 0;

    current = head;
    while (current != NULL)
    {
        current = current->next;
        count++;
    }
    current = head;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the position you want to add node at (1-%d): ", count);
    scanf("%d", &pos);

    printf("Enetr the data you want to add in new node: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (pos == 1)
    {
        new_node->next = head;
        head = new_node;
    }
    else if (pos > 1 && pos <= count)
    {
        for (size_t i = 1; i < pos - 1; i++)
        {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }
    else if (pos == count + 1)
    {

        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
    else
        printf("Position does not exist\n");
}
void del_node()
{

    if (head == NULL)
    {
        printf("No nodes available to delete\n");
        return;
    }

    struct node *previous, *current = head;
    int pos, count = 0, psave;

    while (current != NULL)
    {
        current = current->next;
        count++;
    }

    printf("Enter the node you want to delete(1 - %d): ", count);
    scanf("%d", &pos);

    psave = pos - 1;
    if (pos == 1)
    {
        current = head;
        head = head->next;
        free(current);
    }
    else if (pos > 1 && pos < count)
    {
        for (current = head; pos != 1; pos--)
        {
            current = current->next;
        }
        for (previous = head; psave != 1; psave--)
        {
            previous = previous->next;
        }

        previous->next = current->next;
        free(current);
    }
    else if (pos == count)
    {
        current = head;
        while (current->next->next != NULL)
        {
            current = current->next;
        }

        free(current->next);
        current->next = NULL;
    }
    else
        printf("Invalid position\n");
}
void reverse()
{
    struct node *current = head, *prev = NULL, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void freelist()
{
    struct node *current;
    while (head != NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }
}
void sort_list()
{
    int count, swap;
    struct node *current, *current2;
    for (current = head, count = 0; current != NULL; current = current->next, count++)
        ;
    for (current = head; current->next != NULL; current = current->next)
    {
        for (current2 = current->next; current2 != NULL; current2 = current2->next)
        {
            if (current->data > current2->data)
            {
                swap = current->data;
                current->data = current2->data;
                current2->data = swap;
            }
        }
    }
    printf("The linked list is sorted\n");
}
void  concat_list()
{
    if (head==NULL)
    {
        printf("No previous list created");
        printf("Create a list first to concat");
        return;
    }
    
    
}