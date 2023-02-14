#include<stdio.h>

int main()
{
    int ano, bissexto;

    scanf("%d", &ano);

    if(ano%4 == 0)
    {
        if(ano%400 == 0)
        {
            bissexto = 1;
        }
        else if(ano%100 == 0)
        {
            bissexto = 0;
        }
        else
        {
            bissexto = 1;
        }
    }

    if(bissexto==1)
    {
        printf("ANO BISSEXTO\n");
    }
    else
    {
        printf("ANO NAO BISSEXTO\n");
    }
}