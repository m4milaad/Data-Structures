#include <stdio.h>
#include <ctype.h> // used for testing and mapping chacters
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void InfixtoPostfix(char *s);
int prec(char c);

int main()
{
    char infix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    InfixtoPostfix(infix); // passes infix to the function
    return 0;
}
void InfixtoPostfix(char *infix)
{
    char postfix[MAX]; // postfix output
    char temp;
    int j = 0;

    for (int i = 0; i < strlen(infix); i++)
    {
        char ch = infix[i];

        if (isalnum(ch)) // if scanned operator is an operand push to output
        {
            postfix[j] = ch;
            j++;
        }
        else if (ch == '(') // if scanned char is '(' push to stack
        {
            top++;
            stack[top] = ch;
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j] = stack[top];
                j++;
                top--;
            }
            top--;
        }
        else
        {
            while (top != -1 && prec(ch) <= prec(stack[top]))
            {
                postfix[j] = stack[top];
                j++;
                top--;
            }
            top++;
            stack[top] = ch;
        }
    }
    while (top != -1)
    {
        postfix[j] = stack[top];
        j++;
        top--;
    }
    postfix[j] = '\0';
    printf("The postfix expression: %s\n", postfix);
}
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
