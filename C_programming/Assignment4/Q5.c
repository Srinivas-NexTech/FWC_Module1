/* Write a program to search for a specific element given by the user, in an array and display where it was found in the array (index).
If the element is available multiple times, then print all positions. also print how many times the element was repeated, at the end. Try to do it in a single loop. Make array size as a variable and take array size as input from the user.

eg., input array: 1 2 4 6 2 7 3 7 2 3
enter number to search: 7
output:
7 is found at 6th position
7 is found at 8th position
7 was repeated 2 times*/
#include<stdio.h>
int main(){
int arr[]={1,2,4,6,2,7,3,7,2,3};
int i,n=sizeof(arr)/sizeof(arr[0]);
int count=0;
int number;
printf("enter the number to search in array:");
scanf("%d",&number);
for(i=0;i<n;i++){
if(arr[i]==number){
printf("%d is  found at %d%sposition:\n",number,i,(i == 1) ? "st" : (i  == 2) ? "nd" :
                   (i == 3) ? "rd" : "th");
count++;
}
}
printf("%d is repeated %d%s :\n",number,count,(count==1)?"time":"times");
return 0;
}
