#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

/* Author : Dibyajyoti Mondal
    B.E. ETCE UG2 DSA LAB*/

struct Node{
    struct Node* prev;
    int val;
    struct Node* next;
};


typedef struct Node Node;

Node *head=NULL;


void print_list()
{
    Node *temp=head;
    while(temp->next!=head)
    {
        printf("%d-->",temp->val);
        temp=temp->next;
    }
    printf("%d-->\n",temp->val);
    return;
}


/// insertion at end

void insertAtEnd(int num)
{

    Node *new_node=(Node*)malloc(sizeof(Node));

    new_node->val=num;
    new_node->prev=NULL;
    new_node->next=NULL;

    if(head==NULL)
    {
         head=new_node;
         head->prev=head;
         head->next=head;
    }

    else
    {
        Node *temp=head;
        while(temp->next!=head)
            temp=temp->next;

        temp->next=new_node;
        new_node->prev=temp;

        new_node->next=head;
        head->prev=new_node;
    }

    print_list();
    return;
}

/// insert at index

void insertAtIndex(int index,int num)
{
    /// creating a new node

    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->val=num;
    new_node->prev=NULL;
    new_node->next=NULL;


    int curr_index=1;
    if(index==1)
    {
        if(head==NULL)
        {
            head=new_node;
            head->prev=head;
            head->next=head;
            print_list();
            return;
        }
        head->prev->next=new_node;
        new_node->prev=head->prev;

        head->prev=new_node;
        new_node->next=head;

        head=new_node;
    }
    else
    {
        Node *temp=head;

        while(temp->next!=head && curr_index<index)
        {
            temp=temp->next;
            curr_index++;
        }

        if(curr_index<index)
        {
            printf("Index Out of Range!!!\n");
            return;
        }
        else
        {
            Node *prev_node=temp->prev;
            prev_node->next=new_node;
            new_node->prev=prev_node;

            new_node->next=temp;
            temp->prev=new_node;
        }
    }

    print_list();
    return;
}


/// delete at end
void deleteAtEnd()
{
    if(head==NULL)
    {
        printf("List is Empty!!!\n");
        return;
    }
    else
    {
        /// 1 node only
        Node *temp;

        if(head->next==head && head->prev==head)
        {
            temp=head;
            head=NULL;
            free(temp);
            printf("List is now Empty!!!\n");
            return;
        }

        else
        {
            /// more than 1 node

            temp=head;
            while(temp->next!=head)
                temp=temp->next;

            Node *prev_node=temp->prev;

            prev_node->next=head;
            head->prev=prev_node;

            free(temp);
        }
    }
    print_list();
    return;
}

/// delete at given index

void deleteAtIndex(int index)
{
    if(head==NULL)
    {
        printf("List is Empty!!!\n");
        return;
    }
    else
    {
        Node *temp;
        if(index==1)
        {


            /// only 1 node
            if(head->next==head && head->prev==head)
            {
                temp=head;
                head=NULL;
                free(temp);
                printf("List is now Empty!!!\n");
                return;
            }
            else
            {
                /// more than 1 node
                temp=head;
                head->prev->next=head->next;
                head->next->prev=head->prev;
                head=head->next;
                free(temp);
            }
        }
        else
        {
            int curr_index=1;
            temp=head;
            while(curr_index<index && temp->next!=head)
            {
                temp=temp->next;
                curr_index++;
            }

            if(curr_index<index)
            {
                printf("Index out of range!!!\n");
                return;
            }
            else
            {
                Node *prev_node=temp->prev,*next_node=temp->next;

                prev_node->next=next_node;
                next_node->prev=prev_node;

                free(temp);
            }
        }
    }

    print_list();
    return;
}




int main()
{

    printf("====================Welcome to Doubly Circular Linked List==================\n\n\n");

    printf("Insert At End : 1 number\nInsert At Index: 2 Index number\nDelete At Index: 3 Index\nDelete At End: 4\n");

    while(true)
    {
        int w,x,y,z;
        printf("Enter a number to perform operation\n");
        scanf("%d",&x);
        if(x==1)
        {
            scanf("%d",&y);
            insertAtEnd(y);
        }
        else if(x==2)
            {
                scanf("%d%d",&y,&z);
                insertAtIndex(y,z);
            }
        else if(x==3)
        {
            scanf("%d",&y);
            deleteAtIndex(y);
        }
        else if(x==4)
        {
            deleteAtEnd();
        }
        else
            printf("Invalid Input !!!\n");
    }


    return 0;
}
