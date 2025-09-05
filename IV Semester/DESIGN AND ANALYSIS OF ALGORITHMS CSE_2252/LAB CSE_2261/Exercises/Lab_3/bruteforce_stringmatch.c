
#include <stdio.h>
#include <string.h>

void bruteForceStringMatch(char* text, char* pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int i;
    for ( i = 0; i <= textLength - patternLength; ++i) {
        int j;
        for (j = 0; j < patternLength; ++j) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == patternLength) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[100];
    char pattern[20];

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the pattern to search: ");
    fgets(pattern, sizeof(pattern), stdin);

    // Removing newline characters from user input
    text[strcspn(text, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    bruteForceStringMatch(text, pattern);

    return 0;
}
