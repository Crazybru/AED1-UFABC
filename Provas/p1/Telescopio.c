#include<stdio.h>

int main()
{
    int abertura, fotons, estrelas, i, visivel=0;

    scanf("%d", &abertura);
    scanf("%d", &estrelas);

    for(i=0;i<estrelas;i++)
    {
        scanf("%d", &fotons);
        if(fotons*abertura >= 40000000)
        {
            visivel++;
        }
    }

    printf("%d\n", visivel);
}