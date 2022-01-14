#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

// Define the structure
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// Make start as NULL
struct node *start = NULL;

// Declaring function prototypes
struct node *create_dll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_before(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);

// Main function with the menu
int main()
{
    int choice;
    while(choice!=13)
    {
        printf("\n---------MAIN MENU---------");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a node before a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: Delete the entire list");
        printf("\n 12: Sort the list");
        printf("\n 13: EXIT");

        printf("\n\n Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1: start = create_dll(start);
        printf("\n LINKED LIST CREATED");
        break;
        case 2: start = display(start);
        break;
        case 3: start = insert_beg(start);
        break;
        case 4: start = insert_end(start);
        break;
        case 5: start = insert_before(start);
        break;
        case 6: start = insert_after(start);
        break;
        case 7: start = delete_beg(start);
        break;
        case 8: start = delete_end(start);
        break;
        case 9: start = delete_before(start);
        break;
        case 10: start = delete_after(start);
        break;
        case 11: start = delete_list(start);
        printf("\n LINKED LIST DELETED");
        break;
        case 12: start = sort_list(start);
        break;
        }
    }
    return 0;
}

// Function to create a linked list
struct node *create_dll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;

    printf("\nEnter a number to add in the linked list or -1 to end: ");
    scanf("%d",&num);

    while(num!=-1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;

        if (start==NULL)
        {
            new_node->next = NULL;
            new_node->prev = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while(ptr->next!=NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = NULL;
            new_node->prev = ptr;
        }
        printf("\nEnter a number to add in the linked list or -1 to end: ");
        scanf("%d",&num);
    }
    return start;
}

// Function to display the list
struct node *display(struct node *start)
{
    struct node *ptr;

    ptr = start;

    while(ptr!=NULL)
    {
        printf("\t%d",ptr->data);
        ptr = ptr->next;
    }
    return start;
}

// Function to insert in the beginning
struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;

    printf("Enter the number to insert: ");
    scanf("%d",&num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    start->prev = new_node;
    new_node->prev = NULL;
    new_node->next = start;
    start = new_node;

    return start;
}

// Function to insert in the end
struct node *insert_end(struct node *start)
{
    struct node *new_node, *ptr;
    int num;

    printf("Enter the number to insert: ");
    scanf("%d",&num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    ptr = start;

    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = NULL;
    new_node->prev = ptr;

    return start;
}

// Function to insert before
struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr, *pre_ptr;
    int num, val;

    printf("Enter the number to insert: ");
    scanf("%d",&num);
    printf("Enter the value of the node before which to insert: ");
    scanf("%d",&val);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    ptr=start;

    while(ptr->data!=val)
    {
        ptr = ptr->next;
    }

    pre_ptr = ptr->prev;
    pre_ptr->next = new_node;
    new_node->prev = pre_ptr;
    new_node->next = ptr;
    ptr->prev = new_node;

    return start;
}

// Function to insert after
struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr;
    int num, val;

    printf("Enter the number to insert: ");
    scanf("%d",&num);
    printf("Enter the value of the node after which to insert: ");
    scanf("%d",&val);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    ptr=start;

    while(ptr->data!=val)
    {
        ptr = ptr->next;
    }

    ptr->next->prev = new_node;
    new_node->next = ptr->next;
    ptr->next = new_node;
    new_node->prev = ptr;

    return start;
}

// Function to delete in the beginning
struct node *delete_beg(struct node *start)
{
    struct node *ptr;

    ptr = start;

    start = ptr->next;
    ptr->prev = NULL;
    free(ptr);

    return start;
}

// Function to delete in the end
struct node *delete_end(struct node *start)
{
    struct node *ptr;

    ptr=start;

    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }

    ptr->prev->next = NULL;
    free(ptr);

    return start;
}

// Function to delete a node before
struct node *delete_before(struct node *start)
{
    struct node *ptr, *pre_ptr;
    int val;

    printf("Enter the value of the node before which to be deleted: ");
    scanf("%d",&val);

    ptr = start;

    if(start->data==val)
    {
        start = delete_beg(start);
    }
    else
    {
        while(ptr->data!=val)
        {
            ptr = ptr->next;
        }

        pre_ptr = ptr->prev;

        pre_ptr->prev->next = ptr;
        ptr->prev = pre_ptr->prev;

        free(pre_ptr);
    }
    return start;
}

// Function to delete a node after
struct node *delete_after(struct node *start)
{
    struct node *ptr, *post;
    int val;

    printf("Enter the value of the node after which to be deleted: ");
    scanf("%d",&val);

    ptr=start;

    while(ptr->data!=val)
    {
        ptr = ptr->next;
    }
    post = ptr->next;
    ptr->next = post->next;
    post->next->prev = ptr;
    free(post);

    return start;
}

// Function to delete the list
struct node *delete_list(struct node *start)
{
    struct node *ptr;

    ptr=start;

    while(ptr!=NULL)
    {
        start = delete_beg(ptr);
        ptr = start;
    }
    return start;
}

// Function to sort the linked list
struct node *sort_list(struct node *start)
{
    struct node *ptr1, *ptr2;
    int temp;

    ptr1 = start;

    while(ptr1->next!=NULL)
    {
        ptr2 = ptr1->next;
        while(ptr2!= NULL)
        {
            if(ptr2->data<ptr1->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2=ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}
