#include <stdio.h>

#define MAXLINE 1000    /* maximum input line length */

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";  /* pattern to search for*/

/*find all lines matching pattern*/
int main() {

    char line[MAXLINE];        /* current input line */
    int found = 0;

    while (getline(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }
    return found;
}

/* getline: read a line into line, return length */
int getline(char s[], int lim) {
    int c = 0,  i = 0;
    //while(--lim > 0 && (c=getchar()) != EOF && c != '\n')  // the same as above for loop
    //    s[i++] = c;

     for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
            s[i] = c;

     if (c == '\n') {
         s[i] = c;
         ++i;
     }

     s[i] = '\0';
     return i;

 
}

/* strindex : return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}