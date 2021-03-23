#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

/* Author : Dibyajyoti Mondal
    B.E. ETCE UG2 DSA LAB*/

/// creating node

struct Node{
    struct Node *prev;
    int val;
    struct Node *next;

};

typedef struct Node Node;


/// defining head Node

Node *head=NULL;


/// insertion at end

void InsertAtEnd(int num)
{
    /// dynamic memory allocation

    Node *New_node=(Node*)malloc(sizeof(Node));
    New_node->val=num;
    New_node->prev=NULL;
    New_node->next=NULL;

    if(head==NULL)
    {
        head=New_node;
    }
    else
    {
        Node *curr=head;

        while(curr->next!=NULL)
        {
            curr=curr->next;
        }

        curr->next=New_node;
        New_node->prev=curr;
    }

    print_list();
    return;
}

/// insert at any index

void Insert(int num,int index)
{
    /// dynamic memory allocation

    Node *New_node=(Node*)malloc(sizeof(Node));
    New_node->val=num;
    New_node->prev=NULL;
    New_node->next=NULL;


    if(index==1)
    {
        if(head==NULL)
            head=New_node;
        else
        {
            head->prev=New_node;
            New_node->next=head;
            head=New_node;
        }
    }
    else
    {
        int curr_index=1;
        Node *curr=head;

        while(curr_index<index && curr!=NULL)
        {
            curr=curr->next;
            curr_index++;
        }

        if(curr==NULL)
        {
            printf("Invalid Index!!!\n");
            return;
        }

        Node *prev_node=curr->prev;

        prev_node->next=New_node;
        New_node->prev=prev_node;

        New_node->next=curr;
        curr->prev=New_node;
    }
    print_list();
    return;
}

/// deleting node at given index

void DeleteNode(int index)
{
    if(head==NULL)
    {
        printf("List is empty!!!\n");
        return;
    }
    if(index==1)
    {
        Node *temp=head;
        head=head->next;
        if(head!=NULL)
            head->prev=NULL;
        free(temp);
    }
    else
    {
        int curr_index=1;
        Node *curr=head;

        while(curr_index<index && curr!=NULL)
        {
            curr=curr->next;
            curr_index++;
        }

        if(curr==NULL)
        {
            printf("Invalid Index!!!\n");
            return;
        }

        Node *prev_node=curr->prev, *next_node=curr->next;
        prev_node->next=next_node;

        if(next_node!=NULL)
            next_node->prev=prev_node;

        free(curr);
    }
    print_list();
    return;
}

/// printing linked list

void print_list()
{
    Node *curr=head;
    while(curr!=NULL)
    {
        printf("%d-->",curr->val);
        curr=curr->next;
    }
    printf("\n");
    return;
}

/// rev printing linked list

void reverse_print_list()
{
    Node *curr=head;
    while(curr->next!=NULL)
        curr=curr->next;

    while(curr!=NULL)
    {
        printf("%d-->",curr->val);
        curr=curr->prev;
    }
    return;
}

int main()
{

    printf("====================Welcome to Doubly Linear Linked List==================\n\n\n");

    printf("Insert At End : 1 number\nInsert At Index: 2 number Index\nDelete At Index: 3 Index\nPrint In Reverse Order: 4\n");

    while(true)
    {
        int w,x,y,z;
        printf("Enter a number to perform operation\n");
        scanf("%d",&x);
        if(x==1)
        {
            scanf("%d",&y);
            InsertAtEnd(y);
        }
        else if(x==2)
            {
                scanf("%d%d",&y,&z);
                Insert(y,z);
            }
        else if(x==3)
        {
            scanf("%d",&y);
            DeleteNode(y);
        }
        else if(x==4)
        {
            reverse_print_list();
        }
        else
            printf("Invalid Input !!!\n");
    }
    return 0;
}
