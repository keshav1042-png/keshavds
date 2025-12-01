#include <stdio.h>

int main() {
    int n = 4;
    int diag[4] = {1, 2, 3, 4}; // diagonal elements
    printf("Diagonal matrix stored as array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", diag[i]);
    return 0;
}
