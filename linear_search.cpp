#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>
#define MAX 10000000

int array[MAX];

long int linear_search(int array[], long int n, int x) {
    for (long int i = 0; i < n; i++){
        if (array[i] == x){
            return i;
        }
    }
    return -1;
}

void print_data(long int result,int data){
    if(result!=-1){
        printf("\n\nThe element %d is found at index %ld",data,result);
    }
    else{
        printf("\n\nThe element %d was not found in the array",data);
    }
}

void test_data(){
    system("cls");
    clock_t t;
    printf("\t\tSearching data in a predefined test case");
    FILE *fptr,*bin_ptr;
    int i=0,value,data;
    long int num=0;
    if ((fptr = fopen("high_integers_10000.txt","r")) == NULL){
        printf("Error! opening file");
        exit(1);
    }
    while(fscanf(fptr,"%d\n",&value)==1){
        array[i]=value;
        i++;
        num++;
    }
    fclose(fptr);
    printf("\n\nThe number of elements in the dataset are: %d",num);
    printf("\n\nEnter the element to be searched: ");
    scanf("%d",&data);
    t = clock();
    long int result=linear_search(array,num,data);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    print_data(result,data);
    bin_ptr = fopen("save_test.txt", "a+");
    fprintf(bin_ptr,"%f\n ",time_taken);
    printf("\n\nExecution Time saved in File");
    fclose(bin_ptr);
    getch();
    return;
}

void user_data(){
    system("cls");
    int i,num,data;
    clock_t t;
    printf("\t\tUser Input\n\n");
    printf("Enter the number of data: ");
    scanf("%d",&num);
    printf("\n\nEnter The data: ");
    for(i=0;i<num;i++){
        scanf("%d",&array[i]);
    }
    printf("\n\n Enter the data you want to search: ");
    scanf("%d",&data);
    t = clock();
    long int result=linear_search(array,num,data);
    t = clock() - t;
    print_data(result,data);
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nExecution time taken: %e  \n", time_taken);
    getch();
    return ;
}
int main() {
    int ch;
    do{
      system("cls");
      printf("\t\tImplementation of Linear Search");
      printf("\n\n1.User Input ");
      printf("\n\n2.Test Cases");
      printf("\n\n0.Exit");
      printf("\n\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: user_data();
                break;
            case 2: test_data();
                break;
            case 0: exit(0);
            default: printf("Invalid Choice");
                break;
        }
    }while(1);
    return 0;
}
