#include <stdio.h>

int missingNumberBinary(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] != mid + 1) {
            if (mid == 0 || arr[mid - 1] == mid)
                return mid + 1;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return n + 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Missing number: %d\n", missingNumberBinary(arr, n));
    return 0;
}
