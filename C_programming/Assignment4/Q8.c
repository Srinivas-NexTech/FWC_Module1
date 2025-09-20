/*
Write a program to print an integer in binary format.
eg., input : 17
output :   10001
*/
#include<stdio.h>
int main(){
int number;
int a[32];
int i=0,j;
printf("enter the number:");
scanf("%d",&number);
if (num == 0) {
        printf("Binary: 0\n");
        return 0;
while(number>0){
  a[i]=number%2;
  number=number/2;
  i++;
}
printf("binary format of given number is:");
for ( j = i - 1; j >= 0; j--) {
        printf("%d", a[j]);
    }
return 0;
}
