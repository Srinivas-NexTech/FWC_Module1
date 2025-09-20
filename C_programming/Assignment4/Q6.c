/*
 Write a program to print an array in reverse order (From last element to first)
*/
#include<stdio.h>
int main(){
int arr[]={1,2,3,4,5};
int temp;
int i,n=sizeof(arr)/sizeof(arr[0]),j=n-1;
for(i=0;i<n;i++){
if(i<j){
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
j--;
printf("%d\n",arr[i]);
}
return 0;
}
