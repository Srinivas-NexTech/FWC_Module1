//Write a program to print all odd numbers first and even numbers next in a single program between two given numbers.
#include<stdio.h>
int main(){
int n,m;
printf("enter the values of n and m:");
scanf("%d\n%d",&n,&m);
int i=n;
while(i>=n && i<=m){
 if(i%2==1)
   printf("%d is odd number\n",i);
else
 printf("%d is even number\n",i);
i++;
}
return 0;
}


