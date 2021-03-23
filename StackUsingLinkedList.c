#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

/* Author : Dibyajyoti Mondal
    B.E. ETCE UG2 DSA LAB*/

/// implementing stack using linked list

/// push means insertion of new head node and pop means deletion of head node

struct Node{
    int val;
    struct Node *next;
};

typedef struct Node Node;


/// head is null initially

Node *head=NULL;


/// push into stack

void push(int value)
{
    /// dynamic memory allocation

    Node *New_Node=(Node *)malloc(sizeof(Node));
    if(!New_Node)
    {
        printf("Stack Overflow!!! ERROR: No more heap space available\n");
        return;
    }
    New_Node->val=value;
    New_Node->next=NULL;

    if(head==NULL)
        head=New_Node;
    else
    {
        New_Node->next=head;
        head=New_Node;
    }
    print_stack();
    return;
}

/// pop the topmost element

void pop()
{
    /// deleting the current head and redefining it

     if(head==NULL)
     {
         printf("Stack Underflow!!!\n");
         return;
     }
     else
     {
         Node *temp_node=head;
         head=head->next;
         free(temp_node);
         print_stack();
         return;
     }

}


/// printing the stack

void print_stack()
{
    if(head==NULL)
    {
        printf("Stack Empty!!!\n");
    }
    else
    {
        Node *temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->val);
            temp=temp->next;
        }
        printf("\n");
    }
    return;
}

int main()
{
    printf("====================Welcome to Stack Using Linked List==================\n\n\n");

    printf("Push: 1 number\nPop: 0\n");

    while(true)
    {
        int x,y;
        printf("Enter a number to perform operation\n");
        scanf("%d",&x);
        if(x==1)
        {
            scanf("%d",&y);
            push(y);
        }
        else if(x==0)
            pop();
        else
            printf("Invalid Input !!!\n");
    }

    return 0;
}
