#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAXSIZE 5

int A[MAXSIZE];
int top = -1;

void Print()        //Function to print all the elements in the list
{
    printf("The queue is ");
    if(top==-1)
        printf("empty");
    for(int i=0;i<=top;i++)
        printf("%d ",A[i]);
}

void push()        //Function to insert an element in the list
{
    int x;
    printf("Enter the element: ");
    scanf("%d",&x);
    if(top == MAXSIZE-1)
    {
        printf("----OVERFLOW DETECTED---");
        return;
    }
    A[++top] = x;
    Print();
}

void pop()      //Function to delete an element from the list
{
    if(top == -1)
    {
        printf("---UNDERFLOW DETECTED---");
        return;
    }
    for(int i=0;i<top;i++)
        A[i]=A[i+1];
    top = top-1;
    printf("First element popped out\n");
    Print();
}

int main()
{
    int n,choice,c=1;
	while(c==1)
    {
        printf("Enter 1 to push element and 0 to pop from the stack\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice == 1)
            push();
        else if(choice == 0)
            pop();
        else
            printf("Enter valid choice\n");
        printf("\nEnter 1 to continue and 0 to exit");
        printf("\nDo you want to continue?: ");
        scanf("%d",&c);
    }
}
