#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

//A STACK TYPE STRCUTURE TO REPRESENT EACH POLE OF TOWER OF HANOI
typedef struct stack{
    int size;
    int top;
    int *node;
}
Hanoi;

//EACH NODE CREATION SIGNIFIES EACH POLES CREATED
Hanoi* stack_create(int size){
    Hanoi* pole=(Hanoi*)malloc(sizeof(Hanoi*));
    pole->size=size;
    pole->top=-1;
    pole->node=(int *)malloc(pole->size * sizeof(int));
    return pole;
}

//FUNCTION TO PUSH A DISC IN A POLE
void push(Hanoi* pole, int disk ){
    if(pole->top==pole->size-1){
        return;
    }
    else{
        pole->top++;
        pole->node[pole->top]=disk;
    }
}

//FUNCTION TO REMOVE A DISC FROM THE POLE
int pop(Hanoi* pole){
    int pop_elem;
    if(pole->top==-1){
        return -1;
    }
    else{
        pop_elem=pole->node[pole->top];
        pole->top--;
        return pop_elem;
    }
}

//FUNCTION TO MOVE A DISC BETWEEN THE POLES
void move_discs(Hanoi* pole_1, Hanoi* pole_2, char pole_name_1,char pole_name_2){
    int disc_1,disc_2;
    disc_1=pop(pole_1);
    disc_2=pop(pole_2);
    if(disc_1==-1)
    {
        push(pole_1,disc_2);
        printf("Move disk %d from %c to %c\n\n",disc_2,pole_name_1,pole_name_2);
    }
    else if(disc_2==-1)
        {
        push(pole_2,disc_1);
        printf("Move disk %d from %c to %c\n\n",disc_1,pole_name_1,pole_name_2);
    }
    else if(disc_1>disc_2){
        push(pole_1,disc_1);
        push(pole_1,disc_2);
        printf("Move disk %d from %c to %c\n\n",disc_2,pole_name_2,pole_name_1);
    }
    else if(disc_1<disc_2){
        push(pole_2,disc_2);
        push(pole_2,disc_1);
        printf("Move disk %d from %c to %c\n\n",disc_1,pole_name_1,pole_name_2);
    }
}

//FUNCTION TO IMPLEMENT THE TOWER OF HANOI PROBLEM
void Tower_of_Hanoi(Hanoi* source, Hanoi* aux, Hanoi* dest,int discs,int total_moves)
{
    char pole_source_name='A',pole_aux_name='B',pole_dest_name='C',temp;
    int i=0;
    if(discs%2==0)
        {
        temp= pole_aux_name;
        pole_aux_name=pole_dest_name;
        pole_dest_name=temp;
    }
    for(i=discs;i>=1;i--)
    {
        push(source,i);
    }
    for(i=1;i<=total_moves;i++)
    {
        if(i%3==0){
            move_discs(aux,dest,pole_aux_name,pole_dest_name);
        }
        else if(i%3==1){
            move_discs(source,dest,pole_source_name,pole_dest_name);
        }
        else if(i%3==2){
            move_discs(source,aux,pole_source_name,pole_aux_name);
        }
    }
}

//THE MAIN FUNCTION WHICH TAKES THE INPUT OF THE NUMBER OF DISCS
int main(){
    system("cls");
    printf("\t\tTOWER OF HANOI PROBLEM\n\n");
    int total_discs,total_moves;
    printf("Enter the total number of discs:");
    scanf("%d",&total_discs);
    printf("\n\n");
    total_moves=pow(2,total_discs)-1;
    Hanoi *source,*aux,*dest;
    source=stack_create(total_discs);
    aux=stack_create(total_discs);
    dest=stack_create(total_discs);
    Tower_of_Hanoi(source,aux,dest,total_discs,total_moves);
    printf("The total number of steps taken: %d\n\n", total_moves);
    printf("Shifting from Pole A to Pole C is complete\n\n");    return 0;
}
