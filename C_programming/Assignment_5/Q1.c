//1)Write a program to print all numbers from 1 to a given number.
#include<stdio.h>
int main(){
int i=0,n;
printf("enter the value of n:");
scanf("%d",&n);
while(i<n){
i++;
printf("%d\n",i);
}
return 0;
}
