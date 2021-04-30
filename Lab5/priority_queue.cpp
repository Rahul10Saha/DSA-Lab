#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100

int array[MAX];
int ptr=-1;

//FUNCTION TO SWAP ELEMENTS
void element_swap(int *elem1,int *elem2){
    int temp;
    temp=*elem1;
    *elem1=*elem2;
    *elem2=temp;
}

//FUNCTION TO FIND THE SIZE OF THE QUEUE
int size(){
    int i,count=0;
    if(ptr==-1){
        return 0;
    }
    for(i=0;i<=ptr;i++){
        count++;
    }
    return count;
}

//FUNCTION TO DISPLAY THE PRIORITY QUEUE
void display(){
    int i;
    if(ptr==-1){
        printf("The queue is empty");
        getch();
        return;
    }
    for(i=0;i<=ptr;i++){
        printf("%d ",array[i]);
    }
    getch();
    return;
}

//FUNCTION WHICH RETURNS THE INDEX OF THE PARENT NODE OF A GIVEN NODE
int parent(int index){
    return (index-1)/2;
}

//FUNCTION WHICH WHICH RETURNS THE INDEX OF THE RIGHT CHILD OF A GIVEN NODE
int right_child(int index){
    return(2*index+2);

}

//FUNCTION WHICH WHICH RETURNS THE INDEX OF THE LEFT CHILD OF A GIVEN NODE
int left_child(int index){
    return(2*index+1);
}

//FUNCTION TO RETURN THE MINIMUM PRIORITY ELEMENT
int get_min(){
    return array[0];
}

//FUNCTION TO SHIFT UP THE DOWN THE NODE MAINTAIN THE HEAP PROPERTY
void heap_minimum(int index){
    int index_left_child, index_right_child,minimum;
    index_left_child=left_child(index);
    index_right_child=right_child(index);

    minimum=index;
    if(index_left_child<=ptr and array[index_left_child]<array[minimum]){
        minimum=index_left_child;
    }

    if(index_right_child<=ptr and array[index_right_child]<array[minimum]){
        minimum=index_right_child;
    }

    if(minimum!=index){
        element_swap(&array[index],&array[minimum]);
        heap_minimum(minimum);
    }
}

//FUNCTION TO SHIFT UP THE NODE TO MAINTAIN HEAP PROPERTY
void decrease_val(int index){
    while((index>0) && (array[parent(index)]>array[index])){
        element_swap(&array[index],&array[parent(index)]);
        index=parent(index);
    }
}

//INSERTS A NEW ELEMENT TO THE BINARY HEAP
void insert(int element){
    ptr=ptr+1;
    array[ptr]=element;
    decrease_val(ptr);
}

//FUNCTION TO CREATE A PRIORITY QUEUE
void create(){
    system("cls");
    printf("\t\tCreating a Priority Queue");
    int number_of_elements,i;
    printf("\n\nEnter the number of elements to be inserted: ");
    scanf("%d",&number_of_elements);
    for(i=0;i<number_of_elements;i++){
        int element;
        printf("\n\nEnter the data:");
        scanf("%d",&element);
        insert(element);
        printf("\nThe priority Queue is...\n");
        display();
    }
}

//FUNCTION TO INSERT AN ELEMENT IN THE PRIORITY QUEUE
void op_insert(){
    system("cls");
    printf("\t\tInsertion in Priority Queue");
    int element;
    printf("\n\nEnter the Element:");
    scanf("%d",&element);
    insert(element);
    printf("\nThe priority Queue is...\n");
    display();
}

//FUNCTION TO EXTRACT THE MINIMUM PRIORITY ELEMENT
void extract_min(){
    system("cls");
    printf("\t\tExtract The minimum element in the priority Queue");
    if(ptr==-1){
        printf("\n\nThe priority Queue is empty");
        getch();
        return;
    }
    printf("\n\nPriority Queue before Extracting Minimum...\n");
    display();
    printf("\n\nThe minimum element in the priority Queue: %d",array[0]);
    array[0]=array[ptr];
    ptr--;
    heap_minimum(0);
    printf("\n\nPriority Queue after Extracting Minimum...\n");
    display();
}

//FUNCTION TO CHANGE PRIORITY OF AN ELEMENT
void change_priority(){
    system("cls");
    printf("\t\t Changing Priority of Element in the Priority Queue");
    int new_priority,position,old_priority;
    printf("\n\nEnter the new priority: ");
    scanf("%d",&new_priority);
    printf("\n\nEnter the index: ");
    scanf("%d",&position);
    if(position>size()-1){
        printf("\n\nInvalid index");
        getch();
        return;
    }
    printf("\n\nThe Queue before change in priority..\n");
    display();
    old_priority=array[position];
    array[position]=new_priority;
    if(new_priority>old_priority){
        heap_minimum(position);
    }
    else{
        decrease_val(position);
    }
    printf("\n\nThe Queue after change in priority\n");
    display();
}

//FUNCTION TO REMOVE AN ELEMENT FROM A GIVEN INDEX IN THE PRIORITY QUEUE
void remove_index(){
    system("cls");
    printf("\t\t Remove Element from a given index in the Priority Queue");
    int position;
    printf("\n\nEnter the Index: ");
    scanf("%d",&position);
    if(position>size()-1){
        printf("\n\nInvalid index");
        getch();
        return;
    }
    printf("The Element at index %d is: %d",position,array[position]);
    printf("\n\nPriority Queue before Removing the element from Index...\n");
    display();
    array[position]=get_min()-2;
    decrease_val(position);
    array[0]=array[ptr];
    ptr--;
    heap_minimum(0);
    printf("\n\nPriority Queue after Removing the element from Index...\n");
    display();
}

//THE MAIN DRIVER FUNCTION
int main(){
    int ch;
    do{
        system("cls");
        printf("\t\tImplementation of Priority Queue");
        printf("\n\n1.CREATE(Creates the priority)");
        printf("\n\n2.INSERT(Insert an element to the priority queue");
        printf("\n\n3.EXTRACT_MINIMUM(Extracts the element with minimum priority)");
        printf("\n\n4.CHANGE_PRIORITY(Changes the priority of elements)");
        printf("\n\n5.REMOVE FROM INDEX(Removes element from a given index)");
        printf("\n\n6.DISPLAY(Displays the queue elements)");
        printf("\n\n0. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: create();
                break;
            case 2: op_insert();
                break;
            case 3: extract_min();
                break;
            case 4: change_priority();
                break;
            case 5: remove_index();
                break;
            case 6: display();
                break;
            case 0: exit(0);
            default: printf("Invalid Choice");
                break;
        }
    }while(1);
}
