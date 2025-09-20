/*
Write the following program :
Declare a character array without size.
Initialize the array with characters of your name.
Print your name using for loop.
*/
#include<stdio.h>
int main(){
char a[]={'s','r','i','n','i','v','a','s'};
int i,n=sizeof(a)/sizeof(a[0]);
for(i=0;i<=n;i++){
printf("%c",a[i]);
}
}

