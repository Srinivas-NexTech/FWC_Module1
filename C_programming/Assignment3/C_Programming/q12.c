#include <stdio.h>

char CaseReverse(char c) {
    if (c >= 65 && c <= 90)
        return c + 32;
    else if (c >= 97 && c <= 122)
        return c - 32;
    else
        return c;
}

int main() {
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);

    char reversed = CaseReverse(ch);
    printf("Case reversed character: %c\n", reversed);

    return 0;
}

