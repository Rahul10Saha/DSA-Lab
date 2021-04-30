#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
struct Node* head;

struct Node* create_node(x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = temp;
    return temp;
}

int count()
{
    struct Node* curr = head;
    int c=0;
    if(head!=NULL)
    {
        do
        {
            c++;
            curr = curr->next;
        }while(curr!=head);
    }
    return c;
}

void Print_List()
{
    struct Node* temp = head;
    printf("\nThe list is: ");
    if(head!=NULL)
    {
        do
        {
            printf("\n Value: %d It's address : %u Next Node Address: %u ",temp->data,temp,temp->next);
            temp = temp->next;
        }while(temp!=head);
    }
}

void Insert_At_Beginning()
{
    int x;
    printf("\nEnter the value: ");
    scanf("%d",&x);
    struct Node* new_val = create_node(x);
    if(head == NULL)
    {
        head = new_val;
        new_val->next = head;
        Print_List();
        return;
    }
    else
    {
        struct Node* prev_node = head;
        while(prev_node->next!=head)
            prev_node = prev_node->next;
        new_val->next = head;
        prev_node->next = new_val;
        head = new_val;
        Print_List();
    }
}

void Insert_At_AnyPosition()
{
    int val,pos;
    printf("Enter the value: ");
    scanf("%d",&val);
    printf("Enter the position: ");
    scanf("%d",&pos);
    int c = count();
	if(pos<=0 || pos>=c+2)
	{
		printf("\nError! Invalid position");
		return;
	}
    struct Node* new_node = create_node(val);
    if(pos==1)
    {
        Insert_At_Beginning(pos);
        return;
    }
    struct Node* prev_val = head;
    for(int i=0;i<pos-2;i++)
        prev_val = prev_val->next;
    new_node->next = prev_val->next;
    prev_val->next = new_node;
    Print_List();
}

void Insert_At_End()    //The function is to append the new values in the list
{
    int val;
    printf("Enter the value: ");
    scanf("%d",&val);
    struct Node* new_node = create_node(val);
    if(head==NULL)
    {
        head = new_node;
        Print_List();
        return;
    }
    else
    {
        struct Node* prev_node = head;
        while(prev_node->next!=head)
            prev_node = prev_node->next;
        new_node->next = head;
        prev_node->next = new_node;
        Print_List();
    }
}

void Delete()
{
    int pos;
    printf("Enter the position: ");
    scanf("%d",&pos);
    int c = count();
    if(c==0)
    {
        printf("---------UNDERFLOW DETECTED--------\n");
        printf("---------NO ELEMENT FOUND FOR DELETION---------\n");
        return;
    }
	if(pos<=0 || pos >= c+2)   //Position 0 means no element to delete, the pointer moves before the 1st element and if greater than c +2 then pointer moves after the last element
	{
		printf("\nUser have entered Invalid Position");
		return;
	}
	struct Node* del_node = head;
	if(pos==1)
    {
        while(del_node->next!=head)
            del_node= del_node->next;
        del_node->next = head->next;
        free(head);
        head = del_node->next;
        if(c==1)
        {
            printf("List Is Empty, No Element Found For Deletion\n");
            return;
        }
        Print_List();
        return;
    }
    else
    {
        for(int i=0;i<pos-2;i++)
            del_node = del_node->next;
        struct Node* del1_node=del_node->next;
        del_node->next = del1_node->next;
        free(del1_node);
        if(c==1)
        {
            printf("List Is Empty, No Element Found For Deletion\n");
            return;
        }
        Print_List();
    }
}

int main()
{
	head = NULL;
	int choose,num=1;
	while(num==1)
    {
        printf("Enter 1 for inserting an element at the beginning of the list\nEnter 2 for inserting at any position in the list\nEnter 3 for inserting at end of the list\nEnter 4 for deleting an element from the list\nEnter 5 to view the latest list");
        printf("\nEnter your choice: ");
        scanf("%d",&choose);
        if(choose == 1)
            Insert_At_Beginning();
        else if(choose == 2)
            Insert_At_AnyPosition();
        else if(choose == 3)
            Insert_At_End();
        else if(choose == 4)
            Delete();
        else if(choose == 5)
            Print_List();
        else
            printf("Enter valid choice\n");
        printf("\nEnter 1 to continue and 0 to exit");
        printf("\nDo you want to continue?: ");
        scanf("%d",&num);
    }
}
