#include <stdio.h>

int isLeapYear(int year) {
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if (isLeapYear(year))
                return 29;
            else
                return 28;
        default:
            return -1;  // invalid month
    }
}

int main() {
    int month, year, days;
    printf("Enter month and year: ");
    scanf("%d %d", &month, &year);

    days = daysInMonth(month, year);
    if (days == -1)
        printf("Invalid month entered.\n");
    else
        printf("Number of days in %d/%d is %d.\n", month, year, days);

    return 0;
}

