/*
Read a set of n numbers only in ascending order. While reading the numbers, if the user enters a bigger number than previous number, then continue to next number. 
If the number is smaller than previous number, then do not count it, and take input again.

eg., number of values: 5
enter 1st value: 7
enter 2nd value: 9
enter 3rd value: 5
Sorry, Thats smaller than previous number.
enter 3rd value: 7
Sorry, Thats smaller than previous number.
enter 3rd value: 10
enter 4th value: 18
enter 5th value: 6
Sorry, Thats smaller than previous number.
enter 5th value: 20
Thank you for the successful inputs.
*/
#include<stdio.h>
int main(){
int i=1,n,arr[50];
printf("enter number of values:");
scanf("%d",&n);
printf("enter  1st value:");
scanf("%d",&arr[0]);
while(i<n){
printf("enter %d value:",i+1);
scanf("%d",&arr[i]);
if(arr[i]>arr[i-1])
 i++;
else
  printf("sorry,thats smaller than previos number\n");
}
printf("Thank you for the successful inputs");
return 0;
}
