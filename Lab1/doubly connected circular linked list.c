/*This is the code for doubly connected circular linked list
    Done By
    RAHUL SAHA
    Roll: 001910701009
    ETCE, UG2 ; Subject : DSA Lab */

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head;

struct Node* create_node(val)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = val;
	temp->next = temp;
	temp->prev = temp;
	return temp;
}

void Print_List();
int count();

void Insert_At_Beginning()
{
    int val;
    printf("Enter the value to be inserted: ");
    scanf("%d",&val);
    struct Node* new_val = create_node(val);
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
    printf("Enter the value to be inserted: ");
    scanf("%d",&val);
    printf("Enter the position of insertion: ");
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
        Insert_At_Beginning(val);
        return;
    }
    struct Node* prev_node = head;

    for(int i=0;i<pos-2;i++)
        prev_node = prev_node->next;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    Print_List();
    return;
}

void Insert_At_End()
{
    int val;
    printf("Enter the value: ");
    scanf("%d",&val);
    struct Node* new_node = create_node(val);
    if(head == NULL)
    {
        head = new_node;
        Print_List();
        return;
    }
    struct Node* prev_node = head;
    while(prev_node->next!=head)
        prev_node = prev_node->next;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    new_node->next->prev = new_node;
    Print_List();
    return;
}

void Delete()
{
    int pos;
    printf("Enter the position of deletion: ");
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
		printf("\nUser have entered Invalid Position");
		return;
	}
	struct Node* del_node = head;
	if(pos==1)
    {
        while(del_node->next!=head)
            del_node = del_node->next;
        del_node->next = head->next;
        head->next->prev = del_node;
        free(head);

        if(c==1)
        {
            printf("List Is Empty, No Element Found For Deletion\n");
            return;
        }
        head = del_node->next;
        Print_List();
        return;
    }

    for(int j=0;j<pos-2;j++)
        del_node = del_node->next;
    struct Node* del_node1 = del_node->next;
    del_node->next = del_node1->next;
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
    struct Node*   temp_node = head;
    printf("\nThe list is: ");
    if(head!=NULL)
    {
        do
        {
            printf(" %d ",temp_node->data);
            temp_node = temp_node->next;
        }while(temp_node!=head);
    }
}

int count()
{
    struct Node* current = head;
    int cnt=0;
    if(head!=NULL)
    {
        do
        {
            cnt++;
            current = current->next;
        }while(current!=head);
    }
    return cnt;
}

int main()
{
	head = NULL;
	int choose,num=1;
	while(num==1)
    {
        printf("Enter 1 for inserting an element at the beginning\nEnter 2 for inserting at any position\nEnter 3 for inserting at end\nEnter 4 for deleting an element\nEnter 5 for viewing the latest list");
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
