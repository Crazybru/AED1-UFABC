#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *v;
    int n, i, j=0, checkC=-1, checkD=-1;

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
            if(v[j]>v[i])
            {
                checkD = 0;
            }
            if(v[i]>v[j])
            {
                checkC = 0;
            }
        }

        if(checkC==0 && checkD==0)
        {
            printf("N\n");
            checkC = -1;
            checkD = -1;
        }
        else
        {
            printf("S\n");
            checkC = -1;
            checkD = -1;
        }
    }
}