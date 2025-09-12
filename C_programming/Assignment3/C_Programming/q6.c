#include <stdio.h>
#include <ctype.h>
// Checking ASSIC character  or not
int fun_alpha_num(char c) {
    if ((c >= 48 && c <=57) ||
        (c >= 65  && c <=90) ||
        (c >= 97 && c <=122 ))
        return 1;
    else
        return 0;
}

int main() {
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);

    if (fun_alpha_num(ch))
        printf("'%c' is alphanumeric.\n", ch);
    else
        printf("'%c' is NOT alphanumeric.\n", ch);

    return 0;
}

