//write a program to print the multiplication table for a given number.
#include<stdio.h>
int main(){
int n;
printf("enter the n value:");
scanf("%d",&n);
int i=1,result;
while(i<=10){
result=n*i;
printf("%d*%d=%d\n",n,i,result);
i++;
}
return 0;
}
