//Find the Second Smallest Number in given array
#include<stdio.h>
int main(){
int a[]={0,1,3,5,7,4,2,8,10,11,30};
int i,n=sizeof(a)/sizeof(a[0]);
int small,second_small;
if(a[0]<a[1]){
small=a[0];
second_small=a[1];
}
else{
small=a[1];
second_small=a[0];
}
for(i=2;i<n;i++){
if(a[i]<small){
second_small=small;
small=a[i];
}
else if(a[i]<second_small)
second_small=a[i];
}
printf("%d %d\n",small,second_small);
return 0;
}

