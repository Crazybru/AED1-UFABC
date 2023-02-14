#include<stdio.h>
#include<stdlib.h>


int Busca(int *v, int x, int esq, int dir);

int comparador (const void *a, const void *b);

int main()
{
    int *v;
    int n, m, mn, i, achei=0, esq, dir;

    scanf("%d", &n);

    v = malloc((n + 1) * sizeof(int));

    for(i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
    }

    esq = 0;
    dir = n - 1;

    qsort(v, n, sizeof(int), comparador);

    scanf("%d", &m);

    for(i=0;i<m;i++)
    {
        scanf("%d", &mn);
        achei = Busca(v, mn, esq, dir);
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

int Busca(int *v, int x, int esq, int dir)
{
    int meio;

    if(esq<=dir)
    {
        meio = (esq+dir)/2;
        if(v[meio] == x)
        {
            return 1;
        }
        else if(v[meio] > x)
        {
            dir = meio - 1;
            return Busca(v, x, esq, dir);
        }
        else
        {
            esq = meio + 1;
            return Busca(v, x, esq, dir);
        }
    }

    return -1;
}

int comparador (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}