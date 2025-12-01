#include <stdio.h>

int missingNumberLinear(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1)
            return i + 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Missing number: %d\n", missingNumberLinear(arr, n));
    return 0;
}
