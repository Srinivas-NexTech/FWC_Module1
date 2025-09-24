/*
Read a set of n numbers (n is input) and print if each given number is smaller or bigger than the previous number. For first number there will not be any output as there is no previous number.
eg., input number of values: 5
enter 1st value: 6
enter 2nd value: 7
7 is bigger than 6
enter 3rd value: 5
5 is smaller than 7
enter 4th value: 18
18 is bigger than 5
enter 5th value: 6
6 is smaller than 18
*/
#include<stdio.h>
int main(){
int a[50],n;
printf("input number of values:");
scanf("%d",&n);
printf("Enter first value:");
scanf("%d",&a[0]);
int i=1;
while(i<n){
printf("enter the %d value:",i+1);
scanf("%d",&a[i]);
if(a[i]>a[i-1])
  printf("%d is  bigger than %d\n",a[i],a[i-1]);
else if (a[i]<a[i-1])
  printf("%d is smaller than %d\n",a[i],a[i-1]);
else
  printf("%d is equal to %d\n",a[i],a[i-1]);
i++;
}
return 0;
}
