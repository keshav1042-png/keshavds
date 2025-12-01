#include <stdio.h>
#include <string.h>

int main() {
    char str[5][50], temp[50];
    int n = 5;

    printf("Enter 5 strings:\n");
    for (int i = 0; i < n; i++)
        gets(str[i]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("Strings in alphabetical order:\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", str[i]);

    return 0;
}
