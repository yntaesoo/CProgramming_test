#include <stdio.h>

#define NUM_CHARS 128  // ASCII characters range from 0 to 127

int main() {
    int c;
    int char_count[NUM_CHARS] = { 0 };  // Array to store the count of each character

    // Read characters from input and count frequencies
    while ((c = getchar()) != EOF) {
        if (c >= 0 && c < NUM_CHARS) {
            char_count[c]++;
        }
    }

    // Print the histogram
    printf("\nCharacter Frequency Histogram:\n");
    for (int i = 0; i < NUM_CHARS; i++) {
        if (char_count[i] > 0) {
            if (i == '\n') {
                printf("\\n : ");
            }
            else if (i == '\t') {
                printf("\\t : ");
            }
            else if (i == ' ') {
                printf("' ' : ");
            }
            else {
                printf(" %c  : ", i);
            }

            // Print the bar for the histogram
            for (int j = 0; j < char_count[i]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}