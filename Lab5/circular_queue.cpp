#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5

int cqueue[MAX];//INITIALIZING THE QUEUE
int rear=-1;
int front=-1;

//FUNCTION TO DISPLAY THE QUEUE
void queue_display(){
    int i;
    printf("\n\nDisplaying the elements of the queue...\n\n");
    if(front==-1){
        printf("\n\nThe queue is Empty");
        getch();
        return;
    }
    else{
        for(i=front;i!=rear;i=(i+1)%MAX){//ITERATION UNTILL i IS EQUAL TO REAR
            printf("%d ",cqueue[i]);//PRINTS THE ELEMENT AT POSITION i OF THE ARRAY
        }
        printf("%d ",cqueue[i]);//PRINTS THE REAR ELEMENT
    }
    getch();
}

//FUNCTION TO INSERT AN ELEMENT INTO THE QUEUE
void enqueue(){
    system("cls");
    printf("\t\tCircular Queue: Insert Operation");
    if((front==0 && rear==MAX-1)||(front==rear+1)){
        printf("\n\nThe Queue is overflow");
        getch();
        return;
    }
    else{
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%MAX;//IF END OF ARRAY IS REACHED THEN ELEMENT WILL BE INSERTED IN THE ARRAY BEGINNING PROVIDED THERE IS SPACE HENCE CIRCULAR
        printf("\n\nEnter the Data:");
        scanf("%d",&cqueue[rear]);
    }
    queue_display();
    return;
}

//DELETING AN ELEMENT FROM QUEUE
void dequeue(){
    system("cls");
    printf("\t\tCircular Queue: Deletion Operation");
    if(front==-1){
        printf("\n\nThe queue is Underflow");
        getch();
        return;
    }
    printf("\n\nThe deleted element from the Queue is: %d",cqueue[front]);//DELETING THE FRONT ELEMENT
    if(front==rear){//IF ONLY ONE ELEMENT IS PRESENT RESETTING THE QUEUE
        front=-1;
        rear=-1;
    }
    else{
        front=(front+1)%MAX;
    }
    queue_display();
    return;
}

//DISPLAYS THE FRONT ELEMENT OF THE QUEUE
void queue_front(){
    system("cls");
    printf("\t\tCircular Queue: Displaying the front element of the Queue ");
    if(front==-1){
        printf("\n\nThe queue is underflow");
    }
    else{
        printf("\n\nThe front element is: %d",cqueue[front]);//PRINTS THE FRONT ELEMENT
    }
    getch();
    return;
}

//DISPLAYS THE SIZE OF THE QUEUE
void queue_size(){
    system("cls");
    int i,count=0;
    printf("\t\tCircular Queue: Displaying the size of the Queue");
    if(front==-1){
        printf("\n\nThe size of the Queue is: 0");
    }
    else{
        for(i=front;i!=rear;i=(i+1)%MAX){
            count++;//INCREMENT OF THE COUNT BY 1
        }
        printf("\n\nThe size of the Queue is: %d",count+1);//PRINTS THE NUMBER OF ELEMENTS IN THE QUEUE
    }
    getch();
    return;
}
//DRIVER FUNCTION WHICH HAS THE SWITCH CASE STRUCTURE
int main(){
    int ch;
    do{
        system("cls");
        printf("\t\tImplementation of Circular Queue");
        printf("\n\n1.ENQUEUE(inserts an element in the queue)");
        printf("\n\n2.DEQUEUE(deletes an element from the queue)");
        printf("\n\n3.DISPLAY(displays the queue elements)");
        printf("\n\n4.FRONT(displays the front element without deleting it)");
        printf("\n\n5.SIZE(displays the size of the queue i.e the number of elements)");
        printf("\n\n0.EXIT");
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: enqueue();
                break;
            case 2: dequeue();
                break;
            case 3: queue_display();
                break;
            case 4: queue_front();
                break;
            case 5: queue_size();
                break;
            case 0: exit(0);

            default: printf("Invalid Choice");
                break;
        }
    }while(1);
}
