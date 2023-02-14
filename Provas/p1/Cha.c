#include<stdio.h>

int main()
{
    int t, part[5], pontos = 0, i;

    scanf("%d", &t);
    scanf("%d %d %d %d %d", &part[0], &part[1], &part[2], &part[3], &part[4]);

    for(i=0;i<5;i++)
    {
        if(part[i] == t)
        {
            pontos = pontos + 1;
        }
    }

    printf("%d\n", pontos);
    return 0;
}