/*Write the following program :
Declare an integer array of size 100.
Assign numbers 1-100 to each element of the array.
Print all the numbers.
Print all even elements.
Print all odd elements.
Add 5 to each element and print 6 – 105 numbers.
*/
#include<stdio.h>
int main(){
int a[100];
int i,n;
printf("enter n value:");
scanf("%d",&n);
printf("Array elements are:");
for(i=0;i<n;i++){
a[i]=i+1;
printf("%d\n",a[i]);
}
for(i=0;i<n;i++){
if(a[i]%2==0)
printf("%d is even number\n",a[i]);
else
printf("%d is odd number\n",a[i]);
}
printf("array elements after adding 5 to each element");
for(i=1;i<=n;i++){
a[i]=i+5;
printf("%d\n",a[i]);
}
return 0;
}
