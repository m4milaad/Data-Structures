#include <stdio.h>
#include <stdlib.h>
#define SENTINAL -9999

typedef struct tree
{
    int data;
    struct tree *left, *right;
} Tree;

Tree *create();

int main()
{
    Tree *root = NULL;
    root = create(&root);
    return 0;
}

Tree *create()
{
    Tree *newnode = NULL;
    int x;
    newnode = (Tree *)malloc(sizeof(Tree));
    printf("Enter data: ");
    scanf("%d", &x);
    if (x == SENTINAL)
    {
        return 0;
    }
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    printf("Enter left child of %d", x);
    newnode->left = create();
}