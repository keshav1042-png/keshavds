#include <stdio.h>

int main() {
    int n = 4;
    int size = n * (n + 1) / 2; 
    int arr[size];
    printf("Lower triangular matrix stored using %d elements.\n", size);
    return 0;
}
 