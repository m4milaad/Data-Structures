#include <stdio.h>
#include <stdlib.h>

typedef struct sll
{
    int data;
    struct sll *next;
} Node;

// functions
void create_list(Node **head);
void insert_node(Node **head);
void delete_node(Node **head);
void modify_node(Node *head);
void reverse_list(Node **head);
void sort_list(Node *head);
void concat_list(Node **head);
void free_list(Node **head, int a);
void print_list(Node *head);
int list_size(Node *head);
// loop resolve function to be added( 1->2->3->4->5->3 )

int main()
{
    printf("initializing List...\n");
    Node *head = NULL;
    create_list(&head);
    int choice;
    do
    {

        printf("\"1\" to insert node\n");
        printf("\"2\" to delete node\n");
        printf("\"3\" to modify node\n");
        printf("\"4\" to reverse list\n");
        printf("\"5\" to sort list\n");
        printf("\"6\" to merge 2 lists\n");
        printf("\"7\" to print list\n");
        printf("\"8\" to List size\n");
        printf("\"9\" to free list\n");
        printf("\"0\" to exit\n");
        printf("\n\tEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_node(&head);
            break;
        case 2:
            delete_node(&head);
            break;
        case 3:
            modify_node(head);
            break;
        case 4:
            reverse_list(&head);
            break;
        case 5:
            sort_list(head);
            break;
        case 6:
            concat_list(&head);
            break;
        case 7:
            print_list(head);
            break;
        case 8:
            printf("List size is: %d\n", list_size(head));
            break;
        case 9:
            free_list(&head, 1);
            break;
        case 0:
            printf("Freeing nodes...\n");
            free_list(&head, 0);
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option\nTry again!\n");
            break;
        }

    } while (choice != 0);

    return 0;
}

void create_list(Node **head)
{
    int no;
    printf("Enter the number of nodes: ");
    scanf("%d", &no);
    Node *current = NULL;

    for (int i = 1; i <= no; i++)
    {
        if ((*head) == NULL)
        {
            (*head) = (Node *)malloc(sizeof(Node));
            current = (*head);
        }
        else
        {
            current->next = (Node *)malloc(sizeof(Node));
            current = current->next;
        }

        printf("Enter the data in node %d: ", i);
        scanf("%d", &current->data);
        current->next = NULL;
    }

    printf("List created sucessfully\n");
}

void insert_node(Node **head)
{
    int pos;
    int size = list_size(*head);
    print_list(*head);

    printf("Enter the position where you want to add node (1-%d): ", size + 1);
    scanf("%d", &pos);
    Node *new = NULL;
    new = (Node *)malloc(sizeof(Node));
    if (new == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    new->next = NULL;
    printf("Enter data in node: ");
    scanf("%d", &new->data);

    if (pos == 1)
    {
        new->next = (*head);
        (*head) = new;
    }
    else if (pos == size + 1)
    {
        Node *current = NULL;
        for (current = (*head); current->next != NULL; current = current->next)
            ;
        current->next = new;
    }
    else if (pos > 1 && pos <= size)
    {
        Node *current = NULL;
        current = (*head);
        for (size_t i = 1; i < pos - 1; i++)
        {
            current = current->next;
        }
        new->next = current->next;
        current->next = new;
    }
    else
    {
        printf("Position doesn't exist\n");
        return;
    }

    printf("Node inserted sucessfully\n");
}

void delete_node(Node **head)
{
    if ((*head) == NULL)
    {
        printf("Linked list is already Empty\n");
        return;
    }

    int pos;
    int size = list_size(*head);
    print_list(*head);

    printf("Enter the pos of node to delete: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        Node *current = (*head);
        (*head) = current->next;
        free(current);
    }
    else if (pos == size)
    {
        Node *current = (*head);
        for (; current->next->next != NULL; current = current->next)
            ;
        free(current->next);
        current->next = NULL;
    }
    else if (pos > 1 && pos < size)
    {
        Node *current = (*head);
        for (size_t i = 1; i < pos - 1; i++)
        {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
    else
    {
        printf("Invalid Position\n");
        return;
    }

    printf("Node deleted sucessfully\n");
}

void modify_node(Node *head)
{
    int find, replace, found = 0;
    print_list(head);
    printf("Enter value to find: ");
    scanf("%d", &find);

    printf("Enter the value to replace with: ");
    scanf("%d", &replace);

    Node *current = head;
    for (; current != NULL; current = current->next)
    {
        if (current->data == find)
        {
            current->data = replace;
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Element not found!\n");
        return;
    }
}

void print_list(Node *head)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    printf("\tThe list is: ");
    Node *current = head;
    for (; current != NULL; current = current->next)
    {
        printf("%d ", current->data);
    }
    printf("\n");
    printf("\n");
}

int list_size(Node *head)
{
    int count = 0;
    Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void reverse_list(Node **head)
{
    Node *current, *prev, *upcoming;
    current = prev = upcoming = NULL;
    for (current = (*head); current != NULL; current = upcoming)
    {
        upcoming = current->next;
        current->next = prev;
        prev = current;
    }
    (*head) = prev;
    printf("\t\t\tList reversed\n");
    print_list(*head);
}

void sort_list(Node *head)
{
    int flag;
    printf("1. Accending order\n2. Decending order\nHow do you want to sort the list: ");
    scanf("%d", &flag);

    if (flag == 1 || flag == 2)
    {
        if (flag == 1)
        {
            Node *current, *current2;
            current2 = current->next;
            for (current = head; current->next != NULL; current = current->next)
            {
                for (current2 = current->next; current2 != NULL; current2 = current2->next)
                {
                    if (current->data > current2->data)
                    {
                        int swap = current->data;
                        current->data = current2->data;
                        current2->data = swap;
                    }
                }
            }
        }
        else
        {
            Node *current, *current2;
            current2 = current->next;
            for (current = head; current->next != NULL; current = current->next)
            {
                for (current2 = current->next; current2 != NULL; current2 = current2->next)
                {
                    if (current->data < current2->data)
                    {
                        int swap = current->data;
                        current->data = current2->data;
                        current2->data = swap;
                    }
                }
            }
        }
    }
    else
    {
        printf("Wrong input!\n");
        return;
    }
}

void concat_list(Node **head)
{
    Node *current = NULL, *head2 = NULL;
    int flag;
    printf("1. Current list.\n2. New List\nWhich list do you want at first: ");
    scanf("%d", &flag);

    if (flag == 1 || flag == 2)
    {
        if (flag == 1)
        {
            printf("Enter data for new list\n");
            create_list(&head2);
            for (current = (*head); current->next != NULL; current = current->next)
                ;
            current->next = head2;
        }
        else
        {
            printf("Enter data for new list\n");
            create_list(&head2);
            for (current = head2; current->next != NULL; current = current->next)
                ;
            current->next = (*head);
            (*head) = head2;
        }
    }
    else
    {
        printf("Invalid input\n");
        return;
    }
}

void free_list(Node **head, int a)
{
    Node *current = NULL;
    while ((*head) != NULL)
    {
        current = (*head);
        (*head) = (*head)->next;
        free(current);
    }

    if (!a)
        return;

    char dec;
    printf("List freed\n");
    printf("Do you want to create a new list(y/n): ");
    scanf(" %c", &dec);

    if (dec == 'y' || dec == 'Y')
        create_list(head);
    else
    {
        printf("Exiting...\n");
        exit(1);
    }
}
