#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *v;
    int n, m, m2, i, j, achei=0;

    scanf("%d", &n);

    v = malloc((n + 1) * sizeof(int));

    for(i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
    }

    scanf("%d", &m);

    for(i=0;i<m;i++)
    {
        scanf("%d", &m2);

        for(j=0;j<n;j++)
        {
            if(v[j]==m2)
            {
                achei = 1;
                break;
            }
            else
            {
                achei = 0;
            }
        }
        if(achei==1)
            {
                printf("ACHEI\n");
            }
        else
        {
            printf("NAO ACHEI\n");
        }
    }
    return 0;
}