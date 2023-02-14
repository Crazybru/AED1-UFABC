#include<stdio.h>

int main()
{
    int restante, fabri, a, b;

    scanf("%d", &restante);
    scanf("%d %d", &a, &b);

    if(a+b>restante)
    {
        printf("Deixa para amanha!\n");
    }
    else
    {
        printf("Farei hoje!\n");
    }

    return 0;
}