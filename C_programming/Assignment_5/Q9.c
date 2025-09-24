// read n number of characters as input, and print if each character is alphabet or not.
#include<stdio.h>
int main(){
int i=0,n;
char a[50];
printf("enter n value:");
scanf("%d",&n);
printf("enter a charcter:\n");
while(i<n){
  scanf(" %c",&a[i]);
if(a[i]>='A' && a[i]<='Z')
   printf("%c is alphabet\n",a[i]);
else if(a[i]>='a' && a[i]<='z')
  printf("%c is alphabet\n",a[i]);
else
 printf("not a alphabet");
i++;
}
}
