#include<stdio.h>
#include<stdlib.h>

int bSort(int *, int);

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

    trocas = bSort(v, n);

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

    printf("Trocas: %d\n", trocas);

    return 0;
}

int bSort(int *v, int n)
{
    int i, j, cont, aux, trocas=0;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n - 1 - i;j++)
        {
            if(v[j]>v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;

                trocas++;

                for(cont=0;cont<n;cont++)
                {
                    if(cont==n-1)
                    {
                        printf("%d", v[cont]);
                    }
                    else
                    {
                        printf("%d ", v[cont]);
                    }
                }
                printf("\n");
            }
        }
    }

    return trocas;
}