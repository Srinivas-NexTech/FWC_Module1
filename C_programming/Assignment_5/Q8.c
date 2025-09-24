//Modify the 5th program, to print the topper name after reading all students marks. no need to print grade for each student this time.
/* 5th program
Read the marks for 6 subjects for n students( number of students is input) , and find their percentage and print their grade according to below grading:
80 - 100        : Honours
60 - 79         : First Division
50 - 59         : Second Division
40 - 49         : Third Division
0 - 39          : Fail
*/
#include<stdio.h>
int main(){
int n,subjects,marks[20][20];
float sum,percentage[20];
int i,j=0,topper_position=0;
char name[20][20];
printf("enter number of students:");
scanf("%d",&n);
printf("enter number of subjects:");
scanf("%d",&subjects);
while(j<n){
 i=0, sum=0;
  printf("enter name of student:");
   scanf("%s",&name[j]);
    printf("enter the marks of Student:");
while(i<subjects){
     scanf("%d",&marks[j][i]);
 sum=sum+marks[j][i];
i++;
}
percentage[j]=(sum/(subjects*100))*100;
if(percentage[j]>percentage[topper_position]){
topper_position=j;
}
j++;
}
printf("%s is topper",name[topper_position]);

return 0;
}



