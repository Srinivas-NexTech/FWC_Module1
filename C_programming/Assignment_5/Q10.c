/*
read the dates of birth of n students, print the date in a changed format and print a message when the date of birth belongs to a leap year.

eg.,
input number of students: 3

input student1 date of birth: 2-3-2000
date is: 2 March 2000
this student is born in a leap year.

input student2 date of birth: 12-7-2001
date is: 12 July 2001

input student3 date of birth: 12-12-2024
date is: 12 December 2024
*/
#include <stdio.h>
int main() {
    int n, i = 0;
    int day, month, year;
    char *month_name;

    printf("Enter number of students: ");
    scanf("%d", &n);

    while (i < n) {
        printf("\nEnter student%d date of birth:", i + 1);
        scanf("%d-%d-%d", &day, &month, &year);

        switch (month) {
            case 1: month_name = "January"; break;
            case 2: month_name = "February"; break;
            case 3: month_name = "March"; break;
            case 4: month_name = "April"; break;
            case 5: month_name = "May"; break;
            case 6: month_name = "June"; break;
            case 7: month_name = "July"; break;
            case 8: month_name = "August"; break;
            case 9: month_name = "September"; break;
            case 10: month_name = "October"; break;
            case 11: month_name = "November"; break;
            case 12: month_name = "December"; break;
            default: month_name = "Invalid"; break;
        }

        printf("Date is: %d %s %d\n", day, month_name, year);

        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
            printf("This student is born in a leap year.\n");
        }

        i++;
    }

    return 0;
}

