#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

main() {
	int i, j;
	int start, end;

	printf(" enter two numbers : ");
	scanf("%d %d", &start, &end);

	for (i = 1; i <= 9; i++) {
		for (j = start; j <= end; j++) {
			printf("%d X %d = %d\t", j, i, i * j);
		}
		printf("\n");
	}
}