#include <stdio.h>

void escape(char s[], const char t[]);
void unescape(char s[], const char t[]);

int main() {
    char t[] = "Hello\tworld\nThis is a test.";   // Original string with tabs and newlines
    char escaped[100];   // To store the escaped string
    char unescaped[100]; // To store the unescaped string

    // Convert special characters into escape sequences
    escape(escaped, t);
    printf("Escaped string: %s\n", escaped);

    // Convert escape sequences back into special characters
    unescape(unescaped, escaped);
    printf("Unescaped string: %s\n", unescaped);

    return 0;
}

// Function to convert special characters into escape sequences
void escape(char s[], const char t[]) {
    int i = 0, j = 0;

    while (t[i] != '\0') {
        switch (t[i]) {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
            break;
        }
        i++;
    }
    s[j] = '\0'; // Null-terminate the result string
}

// Function to convert escape sequences into special characters
void unescape(char s[], const char t[]) {
    int i = 0, j = 0;

    while (t[i] != '\0') {
        if (t[i] == '\\' && t[i + 1] != '\0') {
            switch (t[i + 1]) {
            case 'n':
                s[j++] = '\n';
                i++;
                break;
            case 't':
                s[j++] = '\t';
                i++;
                break;
            default:
                s[j++] = t[i];
                break;
            }
        }
        else {
            s[j++] = t[i];
        }
        i++;
    }
    s[j] = '\0'; // Null-terminate the result string
}