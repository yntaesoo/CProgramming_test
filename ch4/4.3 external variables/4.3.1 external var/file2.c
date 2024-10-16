#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 100
#define NUMBER '0'
#define MAXVAL 100      /* maximu depth of val stack*/


int getch(void);
void ungetch(int);
int getop(char[]);

char buf[BUFSIZE];          /* buffer for ungetch*/
int bufp = 0;                   /* next free position in buf*/

int sp = 0;                     /* stack pointer : defined outside of funcion*/
double val[MAXVAL];         /* value stack*/



/*push character back on input*/
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
/*get a (possibly pushed back) character*/
int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }


/* getop : get next operator or numeric operand*/
int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c; // not a number
    i = 0;
    if (c == '-' || isdigit(c)) // collect integer part along with '-'
        while (isdigit(s[++i] = c = getch()));
    if (c == '.') // collect fraction part
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    if (strcmp(s, "-") == 0)
        return '-';
    return NUMBER;
}
