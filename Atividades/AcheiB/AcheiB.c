#include<stdio.h>
#include<stdlib.h>


int Busca(int num, int *v, int x);

int comparador (const void *a, const void *b);

int main()
{
    int *v;
    int n, m, mn, i, j, achei=0;

    scanf("%d", &n);

    v = malloc((n + 1) * sizeof(int));

    for(i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
    }


    qsort(v, n, sizeof(int), comparador);

    scanf("%d", &m);

    for(i=0;i<m;i++)
    {
        scanf("%d", &mn);
        achei = Busca(n, v, mn);
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

int Busca(int num, int *v, int x)
{
    int i, meio, esq=0, dir=num - 1;

    while(esq<=dir)
    {
        meio = (esq+dir)/2;
        if(v[meio] == x)
        {
            return 1;
        }
        else if(v[meio] > x)
        {
            dir = meio - 1;
        }
        else
        {
            esq = meio + 1;
        }
    }

    return -1;
}

int comparador (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}