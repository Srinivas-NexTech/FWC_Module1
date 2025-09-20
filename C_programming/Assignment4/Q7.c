 /*Write a program to reverse an array and print it. Do it without using any extra array variable ,by swapping the elements on both ends till we reach the middle of the array.
Input : array1 ={1,2,3,4,5};
Output : array1 = {5,4,3,2,1}; //array elements stored in reverse order now
*/
#include<stdio.h>
int main(){
int  a[]={1,2,3,4,5};
int i,n=sizeof(a)/sizeof(a[0]),j=n-1;
for(i=0;i<n;i++){
if(i<j){
a[i]=a[i]+a[j];
a[j]=a[i]-a[j];
a[i]=a[i]-a[j];
}
j--;
}
for(i=0;i<n;i++){
printf("%d\n",a[i]);
}
return 0;
}
