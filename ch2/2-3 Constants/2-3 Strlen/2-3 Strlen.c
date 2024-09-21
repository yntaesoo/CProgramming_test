#include <stdio.h>

int strlen(char s[]);  // strlen : return length of s

int strlen(char s[])
{
	int i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return i;
}

void main()
{
	char s[] = "I am a string";
	int length;

	length = strlen(s);
	printf("the length of string is  %d", length);

	return 0;
	
} 