#include<stdio.h>

int main()
{
    int r1, r2, r3, r4, total;

    scanf("%d %d %d %d", &r1, &r2, &r3, &r4);

    total = (r1 + r2 + r3 + r4) - 3;

    printf("%d\n", total);
    return 0;
}