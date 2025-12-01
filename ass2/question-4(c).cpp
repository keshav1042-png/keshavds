#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100], result[100];
    int j = 0;
    printf("Enter a string: ");
    gets(str);

    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'))
            result[j++] = str[i];
    }
    result[j] = '\0';
    printf("String without vowels: %s\n", result);
    return 0;
}
