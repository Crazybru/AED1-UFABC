#include<stdio.h>
#include<stdlib.h>

int ISort(int *, int);

int main()
{
    int n, i, trocas, piorcaso;
    int *v;

    scanf("%d", &n);

    v = malloc((n + 1) * sizeof(int));

    piorcaso = ((n*n) - n)/2;

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

    trocas = ISort(v, n);

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

    printf("Trocas:%d\n", trocas);

    if(trocas==0)
    {
        printf("MELHOR CASO\n");
    }
    else if(trocas==piorcaso)
    {
        printf("PIOR CASO\n");
    }
    else
    {
        printf("CASO ALEATORIO\n");
    }

    return 0;
}

int ISort(int *v, int n)
{
    int i, j, iprint, aux, trocas=0;

    for(i=1;i<n;i++)
    {
        aux = v[i];
        j = i - 1;

        while(j>=0 && v[j]>aux)
        {
            v[j + 1] = v[j];
            v[j] = aux;
            j--;
            trocas++;

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

    }
    return trocas;
}