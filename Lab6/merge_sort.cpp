#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define MAX 100000

int array[MAX];

//merging the subarrays
void merge(int arr[], long int l, long int m,long  int r) {
  long int n1 = m - l + 1;
  long int n2 = r - m;
  long int i,j,k;
  int L[n1], M[n2];
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    M[j] = arr[m + 1 + j];

  i=0;
  j=0;
  k = l;

  while (i < n1 && j < n2) {//placing elements in L and M in correct position at arr[p,,r]
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  while (i < n1) {//If elements in L or M run out we pick up the remaining elements and put in arr[p..r]
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// mergesort
void mergesort(int arr[], long int left, long int right) {
  if (left < right) {
    long int middle = left + (right - left) / 2;//dividing in to two subarrays by position m
    mergesort(arr, left, middle);
    mergesort(arr, middle + 1, right);
    merge(arr, left, middle, right);//merging the subarrays
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
  mergesort(array,0,num-1);
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  printf("Sorted Array in Ascending Order:\n");
  print_array(array, num);
  printf("\nExecution time taken: %e  \n", time_taken);
  system("pause");
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
  printf("\n\nThe number of elements in the data are: %ld",num);
  printf("\n\nWe won't be printing data since there are large number of inputs\n\n");
  t = clock();
  mergesort(array,0,num-1);
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  printf("\nExecution time taken: %e  \n", time_taken);
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
  printf("\n\nThe number of elements in the data are: %ld",num);
  printf("\n\nWe won't be printing data since there are large number of inputs\n\n");
  t = clock();
  mergesort(array,0,num-1);
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  printf("\nExecution time taken: %e  \n", time_taken);
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
      printf("\t\tImplementation of Merge Sort");
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
