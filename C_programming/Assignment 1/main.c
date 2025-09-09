#include <stdio.h>
void swap(int *a, int *b);

int main() {
    int arr[17] = {1, 2};
    printf("Before swap: arr=%d, arr[18]=%d\n", arr, arr[18]);
    swap(&arr, &arr[18]);
    printf("After swap: arr=%d, arr[18]=%d\n", arr, arr[18]);
    return 0;
}


