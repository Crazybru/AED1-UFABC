#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *v;
    int n, i, j=0, check=-1;

    while(scanf("%d", &n) != EOF)
    {
        v = malloc((n + 1) * sizeof(int));

        for(i=0;i<n;i++)
        {
            scanf("%d", &v[i]);
        }

        for(i=0;i<n - 1;i++)
        {
            j = i + 1;
            if(v[i]>v[j])
            {
                check = 0;
                break;
            }
        }

        if(check==0)
        {
            printf("N\n");
            check = -1;
        }
        else
        {
            printf("S\n");
            check = -1;
        }
    }
}