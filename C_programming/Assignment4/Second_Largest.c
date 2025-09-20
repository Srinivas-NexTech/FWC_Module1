//Find the Second Largest Number in given array
#include<stdio.h>
int main(){
int a[]={0,1,3,5,7,4,2,8,10,11,30};
int i,n=sizeof(a)/sizeof(a[0]);
int large,second_large;
if(a[0]>a[1]){
large=a[0];
second_large=a[1];
}
else{
large=a[1];
second_large=a[0];
}
for(i=2;i<n;i++){
if(a[i]>large){
second_large=large;
large=a[i];
}
else if(a[i]>second_large)
second_large=a[i];
}
printf("%d %d\n",large,second_large);
return 0;
}
