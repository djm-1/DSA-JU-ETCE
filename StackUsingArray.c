#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

/* Author : Dibyajyoti Mondal
    B.E. ETCE UG2 DSA LAB*/

/// defining static array
/// I have kept the stack size small so that it can be tested easily for overflow condition.


#define MAX_SIZE 10

int stack[MAX_SIZE];


/// top denoting top of stack

int top=-1;


/// push function

void push(int val)
{
    if(top==MAX_SIZE-1)
    {
        printf("Stack Overflow!!!\n");
        return;
    }
    else
    {
        top++;
        stack[top]=val;
        print_stack();
        return;
    }
}

/// pop function

void pop()
{
    if(top==-1)
    {
        printf("Stack Underflow!!!\n");
        return;
    }
    else
    {
        top--;
        print_stack();
        return;
    }
}

/// print contents of stack

void print_stack()
{
    for(int i=0;i<=top;i++)
        printf("%d ",stack[i]);
    printf("\n");
}


int main()
{

    printf("====================Welcome to Stack Using Array==================\n\n\n");

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
