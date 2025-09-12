#include <stdio.h>

int isLeapYear(int year) {
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

int isValidDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return 0;

    int maxDays;

    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            maxDays = 31; break;
        case 4: case 6: case 9: case 11:
            maxDays = 30; break;
        case 2:
            if (isLeapYear(year))
                maxDays = 29;
            else
                maxDays = 28;
            break;
        default:
            return 0;
    }

    if (day > maxDays)
        return 0;

    return 1;
}

int main() {
    int d, m, y;
    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &d, &m, &y);

    if (isValidDate(d, m, y))
        printf("Date is valid.\n");
    else
        printf("Date is not valid.\n");

    return 0;
}

