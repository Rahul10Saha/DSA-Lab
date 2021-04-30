
/*This is the code for doubly connected linear linked list
    Done By
    RAHUL SAHA
    Roll: 001910701009
    ETCE, UG2 ; Subject : DSA Lab */

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head;
struct Node* create_node(int val)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = val;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

int count();
void Print_List();


void Insert_At_Beginning()
{
    int val;
    printf("Enter the value to be inserted: ");
    scanf("%d",&val);
	struct Node* new_node = create_node(val);
	if(head == NULL)
	{
		head = new_node;
		Print_List();
		return;
	}
	head->prev = new_node;
	new_node->next = head;
	head = new_node;
	Print_List();
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
		printf("\nUser have entered Invalid Position");
		return;
	}
	struct Node* new_node = create_node(val);
	if(pos==1)
    {
        new_node->next = head;
        head = new_node;
        Print_List();
        return;
    }
    struct Node* prev_node = head;
    for(int i=0;i<pos-2;i++)
        prev_node = prev_node->next;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if(new_node->next!=NULL)
        new_node->next->prev = new_node;
    Print_List();
    return;
}

void Insert_At_End()
{
    int val;
    printf("Enter the value to be inserted: ");
    scanf("%d",&val);
    struct Node* new_node = create_node(val);
    if(head == NULL)
    {
        head = new_node;
        Print_List();
        return;
    }
    struct Node* prev_node = head;
    while(prev_node->next!=NULL)
        prev_node = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    Print_List();
    return;
}

void Delete()
{
    int pos;
    printf("Enter the position to be deleted: ");
    scanf("%d",&pos);
    int c = count();
    if(c==0)
    {
        printf("---------UNDERFLOW DETECTED--------\n");
        printf("---------NO ELEMENT FOUND FOR DELETION---------\n");
        return;
    }
	if(pos<=0 || pos>c)
	{
	    printf("%d\n",c);
		printf("\nUser have entered Invalid Position");
		return;
	}
	struct Node* del_node = head;
	if(pos==1)
    {
        head = del_node->next;
        free(del_node);
        if(c==1)
        {
            printf("List Is Empty, No Element Found For Deletion\n");
            return;
        }
        Print_List();
        return;
    }
    for(int j=0;j<pos-2;j++)
        del_node = del_node->next;
    struct Node* del_node1 = del_node->next;
    del_node->next = del_node1->next;
    if(del_node1->next!=NULL)
        del_node1->next->prev = del_node;
    free(del_node1);
    if(c==1)
    {
        printf("List Is Empty, No Element Found For Deletion\n");
        return;
    }
    Print_List();
}

void Print_List()
{
	struct Node* temp_print = head;
	printf("\nThe list is: ");
	while(temp_print!=NULL)
	{
		printf("%d ",temp_print->data);
		temp_print = temp_print->next;
	}
	printf("\n");
}

int count()
{
    struct Node* current = head;
    int cnt=0;
    while(current!=NULL)
    {
        cnt++;
        current = current->next;
    }
    return cnt;
}

int main()
{
	head = NULL;
	int choose,num=1;
	while(num==1)
    {
        printf("Enter 1 for inserting an element at the beginning\nEnter 2 for inserting at any position\nEnter 3 for inserting at end\nEnter 4 for deleting an element\nEnter 5 for viewing latest list");
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
