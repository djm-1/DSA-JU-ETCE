#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

/* Author : Dibyajyoti Mondal
    B.E. ETCE UG2 DSA LAB*/

/// singly connected linear linked list


/// create node of a linked list

struct Node{

    int value;
    struct Node *next;
};


/// declaring head of a linked list

struct Node* head=NULL;




/// insertion function

void insert_node(int num)
{
    /// dynamically allocate memory for a new node

    struct Node *NewNode=(struct Node*)malloc(sizeof(struct Node));
    NewNode->value=num;
    NewNode->next=NULL;

    /// if head is NULL, i.e Linked list is empty, set the new node as head

    if(head==NULL)
        head=NewNode;
    else
    {
        /// traverse till the next node is NULL

        struct Node *temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=NewNode;
    }
    print_list();
    return;
}


/// deletion function

void delete_node(int index)
{
    /// index=1 means head node

    if(head==NULL)
    {
        printf("List is empty!!!\n");
        return;
    }
    if(index==1)
    {

        struct Node *current=head;
        head=head->next;
        free(current);
    }
    else
    {
        struct Node *current=head,*prev=NULL;
        int current_index=1;

        /// prev is used to keep track of previous node

        while(current_index<index)
        {
            if(current==NULL)
            {
                printf("Node out of range\n");
                return;
            }
            prev=current;
            current=current->next;
            current_index++;
        }

        prev->next=current->next;
        free(current);

    }
    print_list();
    return;
}

void insert_at_index(int val,int index)
{
    struct Node *curr=head,*prev=NULL;
    int curr_index=1;

    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->value=val;
    new_node->next=NULL;

    if(index==1)
    {
        new_node->next=head;
        head=new_node;
    }
    else
    {
        while(curr_index<index)
        {
            if(curr==NULL)
            {
                printf("Invalid position\n");
                return;
            }
            prev=curr;
            curr=curr->next;
            curr_index++;
        }
        prev->next=new_node;
        new_node->next=curr;
    }
    print_list();
    return;
}

/// printing the linked list

void print_list()
{
    struct Node *current=head;
    while(current!=NULL)
    {
        printf("%d-->",current->value);
        current=current->next;
    }
    printf("\n");
    return;
}

int main()
{
    printf("====================Welcome to Singly Linear Linked List==================\n\n\n");

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
