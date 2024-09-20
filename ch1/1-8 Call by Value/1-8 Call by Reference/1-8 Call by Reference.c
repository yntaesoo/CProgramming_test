#include <stdio.h>

int add(int *, int *);

int main()
{
    int a, b, sum;

    a = b = 10;
    sum = add(&a, &b);

    printf("the sum of a, b = % d\n", sum);
    printf("a = %d, b = %d\n", a, b);
    return 0;

}

int add(int *aa, int *bb) {
    *aa += 1; *bb += 1;
    return(*aa + *bb);
}
