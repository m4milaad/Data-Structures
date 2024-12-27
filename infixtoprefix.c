#include <stdio.h>
#include <ctype.h> // used for testing and mapping characters
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void InfixtoPostfix(char *s, char *postfix);
int prec(char c);
void reverse(char *exp);
void infixToPrefix(char *infix, char *prefix);

int main()
{
    char infix[MAX], prefix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix); // passes infix to the function
    printf("The prefix expression: %s\n", prefix);
    return 0;
}

void infixToPrefix(char *infix, char *prefix)
{

    reverse(infix);
    printf("Modified infix after changing parentheses: %s\n", infix);

    char postfix[MAX];
    InfixtoPostfix(infix, postfix);
    reverse(postfix);
    printf("Postfix expression: %s\n", postfix);
    strcpy(prefix, postfix);
}

void InfixtoPostfix(char *infix, char *postfix)
{
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
            top--; // Pop the '(' from the stack
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

void reverse(char *exp)
{
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++)
    {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }

    // Swap parentheses during the reversal
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }
}