#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[100];
int rear = -1;
int front = -1;

void enqueue(int[]);
int dequeue(int[]);
int peek(int[]);
void display(int[]);

int main()
{
    int choice, i, val;

    do
    {
        printf("\n\n ***** MAIN MENU *****");
        printf("\n 1. Insert an element");
        printf("\n 2. Delete an element");
        printf("\n 3. Peek");
        printf("\n 4. Display the queue");
        printf("\n 5. EXIT");

        printf("\n Enter your option : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: enqueue(queue);
            break;

            case 2: val = dequeue(queue);
            if(val!=-1)
            {
                printf("The value dequeued is: %d", val);
            }
            break;

            case 3: val = peek(queue);
            if(val!=-1)
            {
                printf("The first value in the queue is: %d", val);
            }
            break;

            case 4: display(queue);
            break;
        }
    }while(choice!=-5);
    return 0;
}

// Function to enqueue
void enqueue(int queue[])
{
    int val;
    printf("\nEnter the value to insert: ");
    scanf("%d", &val);

    if(rear==MAX-1)
    {
        printf("\nOverflow condition");
    }
    else if(front==-1 && rear==-1)
    {
        front = 0;
        rear = 0;
        queue[rear]=val;
    }
    else
    {
        rear = rear+1;
        queue[rear]=val;
    }
}

// Function to dequeue
int dequeue(int queue[])
{
    int val;
    if(front==-1 || front>rear)
    {
        printf("\nUnderflow condition");
        return -1;
    }
    else
    {
        val = queue[front];
        front = front+1;
        if(front>rear)
        {
            front = rear = -1;
        }
        return val;
    }
}

// Function to peep
int peek(int queue[])
{
    int val;
    if(front==-1 || front>rear)
    {
        printf("\nQueue is empty");
        return -1;
    }
    else
    {
        val = queue[front];
        return val;
    }
}

// Function to display
void display(int queue[])
{
    if(front==-1 || front>rear)
    {
        printf("\nQueue is empty");
    }
    else
    {
        for(int i=front; i<=rear; i++)
        {
            printf("\t %d", queue[i]);
        }
    }
}
