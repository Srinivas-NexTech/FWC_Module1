// Write a program to read the number of inputs ,and then read those many numbers and print if each number is positive ,negative or zero.
#include<stdio.h>
int main(){
int arr[]={1,2,4,0,4,5,-9,-3,-2};
int i=0,n=sizeof(arr)/sizeof(arr[0]);
while(i<n){
if(arr[i]<0)
 printf("%d is negative number\n",arr[i]);
else if(arr[i]>0)
   printf("%d is positive number\n",arr[i]);
else
 printf("%d is zero\n",arr[i]);
i++;
}
return 0;
}
