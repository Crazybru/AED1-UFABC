#include<stdio.h>

int main()
{
    int n1, n2, resto, resultado; 
    scanf("%d %d", &n1, &n2);
    resultado = n1/n2;
    resto = n1%n2;
    
    printf("%d %d\n", resultado, resto);
    return 0;
}