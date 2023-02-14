#include<stdio.h>

int main()
{
    int num, numMaior, primeiro=1;
    
    scanf("%d", &num);
    while(num>=0)
    {
        if(primeiro || num > numMaior)
        {
            numMaior = num;
            primeiro = 0;
        }
        scanf("%d", &num);
    }
    if(!primeiro)
    {
        printf("%d\n", numMaior);
    }
    else
    {
        printf("nenhum numero informado\n");    
    }
    return 0;
}