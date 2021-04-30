#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define MAX 100000

int array[MAX];

//swap two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

//selection sort
void selectionsort(int array[], long int size) {
  for (long int j = 0; j < size - 1; j++) {
    int min_idx = j;
    for (long int i = j + 1; i < size; i++) {
      if (array[i] < array[min_idx])//Selecting the minimum element in each loop.
        min_idx = i;
    }
    swap(&array[min_idx], &array[j]);// put min at the correct position
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
  selectionsort(array,num);
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
  selectionsort(array,num);
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
  int i=0,value,temp;
  long int num=0;
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
  selectionsort(array,num);
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  bin_ptr = fopen("save_test_2.txt", "a+");
  fprintf(bin_ptr,"%f\t%ld\n ",time_taken,num);
  printf("Execution time stored into file");
  fclose(bin_ptr);
  getch();
  return;
}

int main(){
    int ch;
    do{
      system("cls");
      printf("\t\tImplementation of Selection Sort");
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
