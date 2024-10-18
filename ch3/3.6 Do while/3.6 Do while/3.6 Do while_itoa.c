#include <stdio.h>
#include <string.h>

void reverse(char[]);
void itoa(int, char[]);

/*reserse : reverse string s in place*/
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* itoa : convert n to characters in s */
void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void main()
{
	int i, j; 
	char st[10];

	itoa(5, st);

	printf("the value of string %s", st);
	printf("the value of string %d", st);

}
