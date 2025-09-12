#include <stdio.h>

typedef struct {
    int day, month, year;
} Date;

int FirstDateOlder(Date d1, Date d2) {
 if(d1.year==d2.year && d1.month==d2.month && d1.day==d2.day)
         return 2;
 else  if (d1.year < d2.year)
        return 1;
    else if (d1.year > d2.year)
        return 0;
    else {
        if (d1.month < d2.month)
            return 1;
        else if (d1.month > d2.month)
            return 0;
        else {
            if (d1.day < d2.day)
                return 1;
            else
                return 0;
        }
    }
}

int main() {
    Date date1, date2;
    printf("Enter first date (dd mm yyyy): ");
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);

    printf("Enter second date (dd mm yyyy): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);

    if (FirstDateOlder(date1, date2))
        printf("First date is older.\n");
    else if(FirstDateOlder(date1,date2)==2)
        printf("Both dates are same.\n");
    else
             printf("Second date is older.\n");

    return 0;
}

