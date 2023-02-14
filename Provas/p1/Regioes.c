#include<stdio.h>

int main()
{
    int n, reg;
    
    scanf("%d", &n);
    
    reg = (n*(n+1)/2) + 1;
    
    printf("%d\n", reg);
    
    return 0;
}