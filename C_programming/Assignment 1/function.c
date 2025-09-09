#include <stdio.h>

int* staticVarFunc() {
    static int n = 0;
    if (n != 0) {
        printf("Square: %d\n", n * n);
        n = 0;
    }
    return &n;
}

int main() {
    int arr[] = {2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(arr);
    for (int i = 0; i < size; i++) {
        int *p = staticVarFunc();
        *p = arr[i];
        staticVarFunc();
    }
    return 0;
}
