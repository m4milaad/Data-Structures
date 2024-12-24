#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int top = -1;
char str[MAX];

int check_balanced(char *);
int match_char(char, char);
void push(char);
char pop();
int isFull();
int isEmpty();
int main(int argc, char const *argv[])
{
    char expression[MAX];

    printf("Enter the algebric expression: ");
    scanf("%s", expression);
    puts(expression);

    int balanced = check_balanced(expression);

    if (balanced)
    {
        printf("Expression is valid\n");
    }
    else
        printf("Expression is invalid\n");
    return 0;
}
int check_balanced(char *str)
{
    char temp;

    for (size_t i = 0; i < strlen(str); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            push(str[i]);
        }
        if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (isEmpty())
            {
                printf("Right braces are more than than left braces\n");
                return 0;
            }
            else
            {
                temp = pop();
                if (!(match_char(temp, str[i])))
                {
                    printf("Mismatched bracket\n");
                    return 0;
                }
            }
        }
    }
    if (isEmpty())
    {
        printf("Braces are balanced\n");
        return 1;
    }
    else
    {
        printf("Left braces are more than right ones\n");
        return 0;
    }
}
int match_char(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    else // of if in 82
        return 0;
}
void push(char a)
{
    if (isFull())
    {
        printf("Stack ki maa chud gayi, expression gaand mei daal lo\n");
        return;
    }
    top++;
    str[top] = a;
}
char pop()
{
    if (isEmpty())
    {
        printf("Right braces are more than left ones\n");
        exit(1);
    }
    char nigga = str[top];
    top--;
    return nigga;
}
int isFull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
