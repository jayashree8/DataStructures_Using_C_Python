#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int st[MAX];
int top = -1;

void push(int [], int);
int pop(int[]);
int evalPost(char[]);

int main()
{
    char exp[100];
    int output;

    printf("\nEnter the expression: ");
    gets(exp);

    output = evalPost(exp);
    printf("\nThe value of the postfix expression is: %d", output);

    return 0;
}

// Function to push
void push(int st[], int val)
{
    if(top==MAX-1)
    {
        printf("\nOverflow condition");
    }
    else
    {
        top = top+1;
        st[top] = val;
    }
}

// Function to pop
int pop(int st[])
{
    int val;
    if(top==-1)
    {
        printf("\nUnderflow condition");
    }
    else
    {
        val = st[top];
        top = top-1;
    }
    return val;
}

// Function to evaluate postfix
int evalPost(char exp[])
{
    int i=0, val1, val2, ans;

    while(exp[i]!='\0')
    {
        if(isdigit(exp[i]))
        {
            push(st, ((int)(exp[i]-48)));
        }
        else
        {
            val1 = pop(st);
            val2 = pop(st);

            if(exp[i]=='+')
            {
                ans = val2+val1;
            }
            else if(exp[i]=='-')
            {
                ans = val2-val1;
            }
            else if(exp[i]=='/')
            {
                ans = val2/val1;
            }
            else if(exp[i]=='*')
            {
                ans = val2*val1;
            }
            else
            {
                ans = (int)val2%(int)val1;
            }
            push(st, ans);
        }
        i++;
    }
    return(pop(st));
}
