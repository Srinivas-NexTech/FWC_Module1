//Find the smallest number in a array
#include<stdio.h>
int main(){
int a[]={1,2,4,5,7,3,9};\
int i,n=sizeof(a)/sizeof(a[0]);
int small_number=a[0];
for(i=1;i<n;i++){
if(a[i]<small_number)
small_number=a[i];
else
small_number=a[0];
}
printf("the small number in given array is:%d",small_number);
return 0;
}

