// Find the missing element in n natural numbers of a array
#include<stdio.h>
int main(){
int a[]={1,2,3,4,6,7};
int i,actual_sum=0,n=sizeof(a)/sizeof(a[0]);
int missing_number,actual_n=n+1, expected_sum=(actual_n*(actual_n+1))/2;
for(i=0;i<n;i++){
actual_sum=actual_sum+a[i];
}
missing_number=expected_sum-actual_sum;
printf("%d",missing_number);
return 0;
}

