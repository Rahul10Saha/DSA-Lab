/*This is the code for stack implementation using array
    Done By
    RAHUL SAHA
    Roll: 001910701009
    ETCE, UG2 ; Subject : DSA Lab */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 40

int Arr[MAX];
int top = -1;

void display();

void push()
{
    int item;
    printf("Enter the element: ");
    scanf("%d",&item);
    if(top == MAX-1)
    {
        printf("\n----OVERFLOW DETECTED---\n");
        return;
    }
    Arr[++top] = item;
    display();
}

void pop()
{
    if(top == -1)
    {
        printf("\n---UNDERFLOW DETECTED---\n");
        return;
    }

    printf("\nElement %d is popped out\n", Arr[top]);
    top--;
    display();
}

void display()
{
    printf("The stack is ");

    if(top==-1)
        printf("\n STACK EMPTY");
    for(int i=top;i>=0;i--)
        printf("%d ",Arr[i]);
}

int main()
{
    int choose,num=1;
	while(num==1)
    {
        printf("\n Enter 1 to push element \n Enter 2 to pop from the stack\n Enter 3 to view the latest stack");
        printf("\n Enter your choice: ");
        scanf("%d",&choose);
        if(choose == 1)
            push();
        else if(choose == 2)
            pop();
        else if(choose == 3)
            display();
        else
            printf("Enter valid choice\n");
        printf("\nEnter 1 to continue and 0 to exit");
        printf("\nDo you want to continue?: ");
        scanf("%d",&num);
    }
}
