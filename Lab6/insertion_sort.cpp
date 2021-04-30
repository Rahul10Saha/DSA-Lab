#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define MAX 200000
int array[MAX];

//insertion sort
void insertionsort(int array[], long int size) {
  for (long int j = 1; j < size; j++) {
    int key = array[j];//Selecting the key
    int p = j - 1;
    while (key < array[p] && p >= 0) {//comparing the key with elements on left
      array[p + 1] = array[p];
      --p;
    }
    array[p + 1] = key;//changing key when a smaller element  is found
  }
}

//prints the array
void print_array(int array[], long int size) {
  for (long int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

//user input
void user_data(){
  system("cls");
  clock_t t;
  int i,value,num;
  printf("\t\tSorting User Inputed Data");
  printf("\n\nEnter the number of data you want to enter:");
  scanf("%d",&num);
  printf("\n\nEnter the datas: \n");
  for(i=0;i<num;i++){
      scanf("%d",&array[i]);
  }
  printf("UnSorted Array:\n");
  print_array(array, num);
  t = clock();
  insertionsort(array,num);
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  printf("Sorted Array in Ascending Order:\n");
  print_array(array, num);
  printf("\nExecution time taken: %e  \n", time_taken);
  getch();
  return ;
}

//unordered test case
void unordered_data(){
  system("cls");
  clock_t t;
  printf("\t\tSorting A predefined unordered Dataset");
  FILE *fptr,*bin_ptr;
  int i=0,value,temp;
  long int num=0;
  if ((fptr = fopen("integers_100000.txt","r")) == NULL){
    printf("Error! opening file");
    exit(1);
  }
  while(fscanf(fptr,"%d\n",&value)==1){
    array[i]=value;
    i++;
    num++;
  }
  fclose(fptr);
  printf("\n\nThe number of elements in the data are: %d",num);
  printf("\n\nWe won't be printing data since there are large number of inputs\n\n");
  t = clock();
  insertionsort(array,num);
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  bin_ptr = fopen("save_test.txt", "a+");
  fprintf(bin_ptr,"%f\t%ld\n ",time_taken,num);
  printf("Execution time stored into file");
  fclose(bin_ptr);
  getch();
  return;
}

//partially ordered test case
void partially_ordered(){
  system("cls");
  clock_t t;
  printf("\t\tSorting A predefined nearly sorted Dataset");
  FILE *fptr,*bin_ptr;
  int value,temp;
  long int num=0,i=0;
  if ((fptr = fopen("partial_integers_100000.txt","r")) == NULL){
    printf("Error! opening file");
    exit(1);
  }
  while(fscanf(fptr,"%d\n",&value)==1){
    array[i]=value;
    i++;
    num++;
  }
  fclose(fptr);
  printf("\n\nThe number of elements in the data are: %d",num);
  printf("\n\nWe won't be printing data since there are large number of inputs\n\n");
  t = clock();
  insertionsort(array,num);
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  bin_ptr = fopen("save_test_2.txt", "a+");
  fprintf(bin_ptr,"%f\t%ld\n ",time_taken,num);
  printf("Execution time stored into file");
  fclose(bin_ptr);
  getch();
  return;
}
//driver function
int main(){
    int ch;
    do{
      system("cls");
      printf("\t\tImplementation of Insertion Sort");
      printf("\n\n1.User Input ");
      printf("\n\n2.Unordered Test Cases");
      printf("\n\n3.Nearly Ordered Test Cases");
      printf("\n\n0.Exit");
      printf("\n\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: user_data();
                break;
            case 2: unordered_data();
                break;
            case 3: partially_ordered();
                break;
            case 0: exit(0);
            default: printf("Invalid Choice");
                break;
        }
    }while(1);
    return 0;
}
