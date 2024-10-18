#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

main() {
	int start, end;
	int i = 0;
	int cnt = 0;
	printf(" Enter two numbers : ");
	scanf("%d%d", &start, &end);

	i = start;
	while (i <= end) {
		if (i % 5 == 0) {
			printf("%d\t", i);
			cnt++;
		}
		i++; 
		if (cnt == 5) {
			printf("\n");
			cnt = 0;
		}
	}
}
