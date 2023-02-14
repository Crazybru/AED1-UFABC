#include<stdio.h>
#include<stdlib.h>

int SSort(int *, int);

int main()
{
    int n, i, trocas;
    int *v;

    scanf("%d", &n);

    v = malloc((n + 1) * sizeof(int));

    for(i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
    }

    for(i=0;i<n;i++)
    {
        if(i==n-1)
        {
            printf("%d", v[i]);
        }
        else
        {
            printf("%d ", v[i]);
        }
    }
    printf("\n");

    trocas = SSort(v, n);

    for(i=0;i<n;i++)
    {
        if(i==n-1)
        {
            printf("%d", v[i]);
        }
        else
        {
            printf("%d ", v[i]);
        }
    }
    printf("\n");

    printf("%d\n", trocas);

    return 0;
}

int SSort(int *v, int n)
{
    int i, j, iprint, imin, aux, trocas=0;

    for(i=0;i<n-1;i++)
    {
        for(j=i+1, imin = i;j<n; j++)
        {
            if(v[imin] > v[j])
            {
                imin = j;
                trocas++;
            }
        }
        aux = v[imin];
        v[imin] = v[i];
        v[i] = aux;

    for(iprint=0;iprint<n;iprint++)
        {
            if(iprint==n-1)
            {
                printf("%d", v[iprint]);
            }
            else
            {
                printf("%d ", v[iprint]);
            }
        }
        printf("\n");
    }
    return trocas;
}