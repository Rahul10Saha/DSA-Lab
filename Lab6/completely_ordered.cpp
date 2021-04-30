#include <stdio.h>
#include<time.h>
#include<stdlib.h>

int main() {
  FILE *fptr1,*fptr2,*fptr3,*fptr4,*fptr5,*fptr6;// creating a FILE variable
  long int i,num;
  fptr1 = fopen("complete_integers_10000.txt", "w");// opening the file in write mode
  if (fptr1 != NULL) {
    printf("File created successfully!\n");
  }
  else {
    printf("Failed to create the file.\n");
    return -1;
  }
  fptr2 = fopen("complete_integers_15000.txt", "w");// opening the file in write mode
  if (fptr2 != NULL) {
    printf("File created successfully!\n");
  }
  else {
    printf("Failed to create the file.\n");
    return -1;
  }
  fptr3 = fopen("complete_integers_25000.txt", "w");// opening the file in write mode
  if (fptr3 != NULL) {
    printf("File created successfully!\n");
  }
  else {
    printf("Failed to create the file.\n");
    return -1;
  }
  fptr4 = fopen("complete_integers_50000.txt", "w");// opening the file in write mode
  if (fptr4 != NULL) {
    printf("File created successfully!\n");
  }
  else {
    printf("Failed to create the file.\n");
    return -1;
  }
  fptr5 = fopen("complete_integers_75000.txt", "w");// opening the file in write mode
  if (fptr5 != NULL) {
    printf("File created successfully!\n");
  }
  else {
    printf("Failed to create the file.\n");
    return -1;
  }
  fptr6 = fopen("complete_integers_100000.txt", "w");// opening the file in write mode
  if (fptr6 != NULL) {
    printf("File created successfully!\n");
  }
  else {
    printf("Failed to create the file.\n");
    return -1;
  }

  //10000 elements
  for(i=0;i<10000;i++){
    num=i+1;
    fprintf(fptr1,"%d\n",num);
  }
  fclose(fptr1);// close connection

  //15000 elements
  for(i=0;i<15000;i++){
    num=i+1;
    fprintf(fptr2,"%d\n",num);
  }
  fclose(fptr2);// close connection

  //25000 elements
  for(i=0;i<25000;i++){
    num=i+1;
    fprintf(fptr3,"%d\n",num);
  }
  fclose(fptr3);// close connection


  //50000 elements
  for(i=0;i<50000;i++){
    num=i+1;
    fprintf(fptr4,"%d\n",num);
  }
  fclose(fptr4);// close connection

  //75000 elements
  for(i=0;i<75000;i++){
    num=i+1;
    fprintf(fptr5,"%d\n",num);
  }
  fclose(fptr5);// close connection

  //100000 elements
  for(i=0;i<100000;i++){
    num=i+1;
    fprintf(fptr6,"%d\n",num);
  }
  fclose(fptr6);// close connection
  return 0;
}
