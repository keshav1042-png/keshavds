#include <stdio.h>

int countDistinct(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < i; j++)
            if (arr[i] == arr[j])
                break;
        if (j == i) count++;
    }
    return count;
}

int main() {
    int arr[] = {10, 20, 20, 10, 30, 40, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Distinct elements: %d\n", countDistinct(arr, n));
    return 0;
}
