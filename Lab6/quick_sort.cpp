#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define MAX 100000
int array[MAX];

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
//The element is such that all the elemnts to the left of pivot are smaller than it
//All the elements to the right of pivot are greater than it
int partition(int array[], long int low, long int high) {
  long int pivot = array[high];//pivot is the rightmost element
  long int i = (low - 1);//greater element pointer
  for (long int j = low; j < high; j++) {
    if (array[j] <= pivot) {//comparing with pivot
      i++;//greater element pointer shifts
      swap(&array[i], &array[j]);//swaps with the greater element
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);//partition point
}

//quick sort
void quicksort(int array[], long int lower, long int higher) {
  if (lower < higher) {

    long int pivot = partition(array, lower, higher);
    quicksort(array, lower, pivot - 1);//selecting pivot for the left part
    quicksort(array, pivot + 1, higher);//selecting pivot for the right part
  }
}

// function to print an array
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
  quicksort(array,0,num-1);
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
  if ((fptr = fopen("integers_10000.txt","r")) == NULL){
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
  quicksort(array,0,num-1);
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds;
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
  int i=0,value,temp;
  long int num=0;
  if ((fptr = fopen("partial_integers_10000.txt","r")) == NULL){
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
  quicksort(array,0,num-1);
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
      printf("\t\tImplementation of Quick Sort");
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
