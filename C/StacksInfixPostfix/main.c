#include <stdio.h>
// for isalnum(char)
#include <ctype.h>
#include <string.h>
// for exit()
#include <stdlib.h>

#define MAX 100

char st[MAX];
int top = -1;

void push(char [], char);
char pop(char []);
int priority(char);
void infixPostfix(char [], char []);

int main()
{
    char infix[100], postfix[100];

    printf("\n Enter any infix expression : ");
    gets(infix);


    strcpy(postfix, "");

    infixPostfix(infix, postfix);
    printf("\n The corresponding postfix expression is : ");
    puts(postfix);

    return 0;
}

// Function to push in the stack
void push(char st[], char val)
{
    if(top == MAX-1)
    {
        printf("\nOverflow condition occurred");
    }
    else
    {
        top = top+1;
        st[top] = val;
    }
}

// Function to pop in the stack
char pop(char st[])
{
    char val = ' ';
    if(top==-1)
    {
        printf("\nUnderflow condition occurred");
    }
    else
    {
        val = st[top];
        top = top - 1;
    }
    return val;
}

// Function to get the priority of the operators
int priority(char op)
{
    if(op=='*' || op=='/' || op=='%')
    {
        return 1;
    }
    else if(op=='+' || op=='-')
    {
        return 0;
    }
}

// Function to convert from infix to postfix
void infixPostfix(char infix[], char postfix[])
{
    int i=0, j=0;
    char temp;

    strcpy(postfix, "");

    // Iterate through the infix notation
    while(infix[i]!='\0')
    {
        // If "(" encountered, push onto the stack
        if(infix[i]=='(')
        {
            push(st,infix[i]);
            i++;
        }
        // If operand is encountered, add to postfix
        else if(isalnum(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        // If ")" is encountered, repeatedly pop from stack and add to postfix until "(" encountered. Then discard "("
        else if(infix[i]==')')
        {
            while((top!=-1) && (st[top]!='('))
            {
                postfix[j] = pop(st);
                j++;
            }
            if(top==-1)
            {
                printf("The expression is invalid");
                exit(1);
            }
            temp = pop(st);
            i++;
        }
        // If operator "op" is encountered, repeatedly pop from stack and add to postfix the operators if they have same/higher precedence than "op", push "op" to stack
        else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='%')
        {
            while((top!=-1) && (st[top]!='(') && (priority(infix[i])<priority(st[top])))
            {
                postfix[j] = pop(st);
                j++;
            }
            push(st,infix[i]);
            i++;
        }
        else
        {
            printf("The expression is invalid");
            exit(1);
        }
    }
    // Repeatedly pop from stack and add to postfix until stack empty
    while((top!=-1) && (st[top]!='('))
    {
        postfix[j] = pop(st);
        j++;
    }
    postfix[j] = '\0';
}
