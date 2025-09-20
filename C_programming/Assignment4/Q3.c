/*
Declare an array of size 10. Enter 10 elements and save them in the array.  Print the array .
Find out the biggest and smallest numbers and print the biggest number and its position in the array, smallest number and its position in the array.
Find both using a single loop.
*/
#include<stdio.h>
int main(){
int a[10]={1,2,3,2,5,6,7,9,0,10};
int i,n=sizeof(a)/sizeof(a[0]);
int large=a[0];
printf("The given array is");
for(i=0;i<n;i++){
printf("%d\n",a[i]);
if(a[0]>a[i])
large=a[0];
else
large=a[i];
}
printf("%d is largest element in the array",large);
return 0;
}
