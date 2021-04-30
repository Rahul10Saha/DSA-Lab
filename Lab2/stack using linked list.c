/*This is the code for stack implementation using linked list
    Done By
    RAHUL SAHA
    Roll: 001910701009
    ETCE, UG2 ; Subject : DSA Lab */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top;

struct Node* create_node(val)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
};

void display();

void push()
{
    int item;
    printf("Enter the element: ");
    scanf("%d",&item);
    struct Node* new_node = create_node(item);
    if(top == NULL)
    {
        top = new_node;
        display();
        return;
    }
    new_node->next = top;
    top = new_node;
    display();
}

void pop()
{
    if(top == NULL)
    {
        printf("\n----UNDERFLOW DETECTED----\n");
        return;
    }
    struct Node* del_node = top;
    if(del_node->next == NULL)
    {
        free(del_node);
        printf("List is empty\n");
        return;
    }
    top = del_node->next;
    printf("\n Element %d is popped out", del_node->data);
    free(del_node);

    display();
}

void display()
{
    struct Node* temp = top;
    printf("\n The list is: ");
    while(temp!=NULL)
    {
        printf("\n %d ",temp->data);
        temp = temp->next;
    }
}

int main()
{
    top =NULL;  //initialize
    int choice,num=1;
	while(num==1)
    {
        printf("\n Enter 1 to push element\n Enter 2 to pop from the stack\n Enter 3 to view the latest stack");
        printf("\n Enter your choice: ");
        scanf("%d",&choice);
        if(choice == 1)
            push();
        else if(choice == 2)
            pop();
        else if(choice == 3)
            display();
        else
            printf("Enter valid choice\n");
        printf("\nEnter 1 to continue and 0 to exit");
        printf("\nDo you want to continue?: ");
        scanf("%d",&num);
    }
}
