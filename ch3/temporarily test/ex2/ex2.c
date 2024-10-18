#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

main() {
	int i;

	for (i = 1; i <= 9; i++) {
		printf("3 x %d = %d\n", i, i * 3);
	}
}