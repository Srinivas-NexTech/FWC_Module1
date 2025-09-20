/*
Write a program to swap two arrays in reverse order.
array1 : {1,2,3,4,5}
array2: {6,7,8,9,10}

after swapping output should be as below:

array1 : { 10,9,8,7,6}
array2: { 5,4,3,2,1}
*/
#include<stdio.h>
int main(){
int a[]={1,2,3,4,5};
int b[]={6,7,8,9,10};
int i,j,temp;
int n=sizeof(a)/sizeof(a[0]);
int m=sizeof(b)/sizeof(b[0]);
j=n-1;
for(i=0;i<n;i++){
if(i<j){
a[i]=a[i]+a[j];
a[j]=a[i]-a[j];
a[i]=a[i]-a[j];
}
j--;
}
j=m-1;
for(i=0;i<n;i++){
if(i<j){
b[i]=b[i]+b[j];
b[j]=b[i]-b[j];
b[i]=b[i]-b[j];
}
j--;
}
for(i=0;i<n;i++){
temp=a[i];
a[i]=b[i];
b[i]=temp;
printf("%d %d\n",a[i],b[i]);
}
return 0;
}
