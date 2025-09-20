//Find the largest number in a array
#include<stdio.h>
int main(){
int a[]={1,2,4,5,7,3,9};\
int i,n=sizeof(a)/sizeof(a[0]);
int large_number=a[0];
for(i=0;i<n;i++){
if(a[i]>large_number)
large_number=a[i];
else
large_number=a[0];
}
printf("the large number in given array is:%d",large_number);
return 0;
}
