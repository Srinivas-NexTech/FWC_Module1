//find the sum of elements in a array
#include<stdio.h>
int main(){
int a[]={1,2,3,4,5};
int i,n=sizeof(a)/sizeof(a[0]),sum=0;
for(i=0;i<n;i++){
sum=sum+a[i];
}
printf("%d",sum);
return 0;
}

