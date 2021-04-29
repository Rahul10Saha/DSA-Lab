#include <stdio.h>
#include<time.h>
#include<stdlib.h>
int main() {
  
  FILE *fptr1,*fptr2,*fptr3,*fptr4,*fptr5,*fptr6,*fptr7,*fptr8,*fptr9,*fptr10;// creating a FILE variable
  long int i,num; 
  fptr1 = fopen("high_integers_10000.txt", "w");// opening the file in write mode
  if (fptr1 != NULL) {
    printf("File created successfully!\n");
  }
  else {
    printf("Failed to create the file.\n");
    return -1;
  }
  fptr2 = fopen("high_integers_20000.txt", "w");// opening the file in write mode
  if (fptr2 != NULL) {
    printf("File created successfully!\n");
  }
  else {
    printf("Failed to create the file.\n");
    return -1;
  }
  fptr3 = fopen("high_integers_30000.txt", "w");// opening the file in write mode
  if (fptr3 != NULL) {
    printf("File created successfully!\n");
  }
  else {
    printf("Failed to create the file.\n");
    return -1;
  }
  fptr4 = fopen("high_integers_40000.txt", "w");// opening the file in write mode
  if (fptr4 != NULL) {
    printf("File created successfully!\n");
  }
  else {
    printf("Failed to create the file.\n");
    return -1;
  }
  fptr5 = fopen("high_integers_50000.txt", "w");// opening the file in write mode
  if (fptr5 != NULL) {
    printf("File created successfully!\n");
  }
  else {
    printf("Failed to create the file.\n");
    return -1;
  }
  fptr6 = fopen("high_integers_100000.txt", "w");// opening the file in write mode
  if (fptr6 != NULL) {
    printf("File created successfully!\n");
  }
  else {
    printf("Failed to create the file.\n");
    return -1;
  }
  fptr7 = fopen("high_integers_200000.txt", "w");// opening the file in write mode
  if (fptr7 != NULL) {
    printf("File created successfully!\n");
  }
  else {
    printf("Failed to create the file.\n");
    return -1;
  }
  fptr8 = fopen("high_integers_350000.txt", "w");// opening the file in write mode
  if (fptr8 != NULL) {
    printf("File created successfully!\n");
  }
  else {
    printf("Failed to create the file.\n");
    return -1;
  }
  fptr9 = fopen("high_integers_500000.txt", "w");// opening the file in write mode
  if (fptr9 != NULL) {
    printf("File created successfully!\n");
  }
  else {
    printf("Failed to create the file.\n");
    return -1;
  }
  fptr10 = fopen("high_integers_1000000.txt", "w");// opening the file in write mode
  if (fptr10 != NULL) {
    printf("File created successfully!\n");
  }
  else {
    printf("Failed to create the file.\n");
    return -1;
  }
  srand(time(0));
  for(i=0;i<10000;i++){
    num=i+1;
    fprintf(fptr1,"%ld ",num);
  }
  fclose(fptr1);// close connection

  for(i=0;i<20000;i++){
    num=i+1;
    fprintf(fptr2,"%ld ",num);
  }
  fclose(fptr2);// close connection

  for(i=0;i<30000;i++){
    num=i+1;
    fprintf(fptr3,"%ld ",num);
  }
  fclose(fptr3);// close connection


  for(i=0;i<40000;i++){
    num=i+1;
    fprintf(fptr4,"%ld ",num);
  }
  fclose(fptr4);// close connection

  for(i=0;i<50000;i++){
    num=i+1;
    fprintf(fptr5,"%ld ",num);
  }
  fclose(fptr5);// close connection

  for(i=0;i<100000;i++){
    num=i+1;
    fprintf(fptr6,"%ld ",num);
  }
  fclose(fptr6);// close connection

  for(i=0;i<200000;i++){
    num=i+1;
    fprintf(fptr7,"%ld ",num);
  }
  fclose(fptr7);// close connection

  for(i=0;i<350000;i++){
    num=i+1;
    fprintf(fptr8,"%ld ",num);
  }
  fclose(fptr8);// close connection

  for(i=0;i<500000;i++){
    num=i+1;
    fprintf(fptr9,"%ld ",num);
  }
  fclose(fptr9);// close connection
  

  for(i=0;i<1000000;i++){
    num=i+1;
    fprintf(fptr10,"%ld ",num);
  }
  fclose(fptr10);// close connection
  return 0;
}
