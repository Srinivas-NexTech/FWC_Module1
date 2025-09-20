/*Try experimenting with the below array syntaxes and see the results,check their sizes, try to also read values for elements and print them:
int arr[5] = {};
int arr[10] = {2.4,5.6,7.3};
int arr[3] = {1,2,3,4,5};
int arr[0] = {};
int arr[0] = {1,2,3,4,5};
int arr[] = {};
int arr[‘a’];"
*/
#include<stdio.h>
int main(){
int arr1[5]={};
int arr2[10]={2,4,5,6,7,3};
int arr3[3]={1,2,3};
int arr[0]={};
int arr4[0]={};
int arr5[] = {};
int arr6['a'];
int i,n=sizeof(arr2)/sizeof(arr2[0]);
for(i=0;i<n;i++){
printf("%d\n",arr6[i]);
printf("%d\n",arr1[i]);
printf("%d\n",arr2[i]);
printf("%d\n",arr4[i]);
printf("%d\n",arr3[i]);
printf("%d\n",arr[i]);
}
return 0;
}

