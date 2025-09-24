/*Read the marks for 6 subjects for n students( number of students is input) , and find their percentage and print their grade according to below grading:
80 - 100        : Honours
60 - 79         : First Division
50 - 59         : Second Division
40 - 49         : Third Division
0 - 39          : Fail
*/
#include<stdio.h>
int main(){
int  n,subjects,marks[20];
printf("enter the number of students:");
scanf("%d",&n);
printf("enter number of subjects:");
scanf("%d",&subjects);
int i,j=0;
float sum,percentage;
while(j<n){
i=0,sum=0;
printf("enter the marks of student\n");
while(i<subjects){
scanf("%d",&marks[i]);
sum=sum+marks[i];
i++;
}
percentage=(sum/(subjects*100))*100;
if(percentage<=39)
 printf(" fail:%f\n",percentage);
else if(percentage>=40 && percentage<=49)
  printf("third division:%f\n",percentage);
else if(percentage>=50 && percentage<=59)
  printf("second divison:%f\n",percentage);
else if(percentage>=60 && percentage<=79)
    printf("first division:%f\n",percentage);
else 
printf("honours:%f\n",percentage);
j++;
}
return 0;
}

