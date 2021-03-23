#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

/* Author : Dibyajyoti Mondal
    B.E. ETCE UG2 DSA LAB*/

/// implementing singly connected circular linked list

/// defining a node

struct Node{
    int value;
    struct Node *next;
};

typedef struct Node Node;


/// defining a head pointer

Node *head=NULL;


/// inserting value

void insert_node(int val)
{
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->value=val;
    new_node->next=NULL;

    if(head==NULL)
    {
        head=new_node;
        head->next=head;
    }
    else
    {
        Node *curr=head;
        while(curr->next!=head)
            curr=curr->next;
        curr->next=new_node;
        new_node->next=head;
    }
    print_list();
    return;
}


/// printing linked list

void print_list()
{
    Node *curr=head;
    if(head==NULL)
    {
        printf("List is empty!\n");
        return;
    }
    while(curr->next!=head)
    {
        printf("%d-->",curr->value);
        curr=curr->next;
    }
    printf("%d\n",curr->value);
    return;
}


/// deleting node in a circular linked list

void delete_node(int index)
{
    Node *prev=NULL,*curr=head;
    int curr_index=1;

    /// list is empty

    if(head==NULL)
    {
        printf("List is empty!!!\n");
        return;
    }

    /// head is the only node

    else if(head->next==head && index==1)
    {
            head=NULL;
            free(curr);
            printf("all elements deleted, list is now empty!!!\n");
            return;
    }
    else if(head->next!=head && index==1)
    {
        while(curr->next!=head)
        {
            curr=curr->next;
        }
        curr->next=head->next;
        Node *temp=head;
        head=head->next;
        free(temp);
        print_list();
        return;
    }
    else
    {
        while(curr_index<index)
        {
            /// end of cycle

            if(curr->next==head)
            {
                printf("index out of range!\n");
                return;
            }
            else
            {
                prev=curr;
                curr=curr->next;
                curr_index++;
            }
        }
        prev->next=curr->next;
        free(curr);
        print_list();
        return;
    }

}


/// insert at index

void insert_at_index(int val,int index)
{
    /// dynamically allocating memory

    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->value=val;
    new_node->next=NULL;

    /// insertion in the beginning
    if(index==1)
    {
        new_node->next=head;
        Node *curr=head;
        while(curr->next!=head)
            curr=curr->next;

        curr->next=new_node;

        head=new_node;
    }
    else
    {
        int curr_index=1;
        Node *curr=head,*prev=NULL;

        while(curr_index<index)
        {
            if(curr->next==head)
            {
                printf("index out of range!\n");
                return;
            }
            else
            {
                prev=curr;
                curr=curr->next;
                curr_index++;
            }
        }
        prev->next=new_node;
        new_node->next=curr;

    }
    print_list();
    return;
}

int main()
{
    printf("====================Welcome to Singly Circular Linked List==================\n\n\n");

    printf("Insert At End : 1 number\nInsert At Index: 2 number Index\nDelete At Index: 3 Index\n");

    while(true)
    {
        int w,x,y,z;
        printf("Enter a number to perform operation\n");
        scanf("%d",&x);
        if(x==1)
        {
            scanf("%d",&y);
            insert_node(y);
        }
        else if(x==2)
            {
                scanf("%d%d",&y,&z);
                insert_at_index(y,z);
            }
        else if(x==3)
        {
            scanf("%d",&y);
            delete_node(y);
        }
        else
            printf("Invalid Input !!!\n");
    }
    return 0;
}
