/*This is the code for singly connected linear linked list
    Done By
    RAHUL SAHA
    Roll: 001910701009
    ETCE, UG2 ; Subject : DSA Lab */

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* head;
void Print_List();

void Insert_At_Beginning()
{
    int  val;
    printf("\nEnter the value to be inserted: ");
    scanf("%d",&val);
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = head;
    head = new_node;
    Print_List();
}

void Insert_At_End()
{
    int val;
    printf("Enter the value to be inserted: ");
    scanf("%d",&val);
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = NULL;
    if(head==NULL){
        head = new_node;
        Print_List();
    }
    else{
        struct Node* previ_node = head;
        while(previ_node->next!=NULL)
            previ_node=previ_node->next;
        previ_node->next = new_node;
    }
    Print_List();
}
int count()
{
    int cnt=0;
    struct Node* current = head;
    while(current!=NULL)
    {
        cnt++;
        current=current->next;
    }
    return cnt;
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
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = val;
	new_node->next=NULL;
	if(pos==1)
	{
		new_node->next = head;
		head=new_node;
		Print_List();
	}
	else
	{
		struct Node* previ_node=head;
		for(int i=0;i<pos-2;i++)
			previ_node = previ_node->next;
		new_node->next = previ_node->next;
		previ_node->next = new_node;
		Print_List();
	}
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
            printf(" List Is Empty, No Element Found For Deletion\n");
            return;
        }
        Print_List();
        return;
    }
    int i;
    for(i=0;i<pos-2;i++)
        del_node = del_node->next;
    struct Node* del1_node = del_node->next;
    del_node->next =del1_node->next;
    free(del1_node);
    if(c==1)
    {
        printf("List Is Empty, No Element Found For Deletion\n");
        return;
    }
    Print_List();
}

void Print_List()
{
	struct Node* print_node = head;
	printf("\n The list is: ");
	while(print_node!=NULL)
	{
		printf("%d ",print_node->data);
		print_node = print_node->next;
	}
}
int main()
{
	head = NULL;
	int choose,num=1;
	while(num==1)
    {
        printf("Enter 1 for inserting an element at the beginning of the list \nEnter 2 for inserting at any position in the list \nEnter 3 for inserting at end of the list \nEnter 4 for deleting an element from any position in the list \nEnter 5 for viewing the final list");
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
