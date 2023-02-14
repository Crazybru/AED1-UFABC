#include<stdio.h>
#include<stdlib.h>


int Busca(int *v, int n, int x, int j);
int comparador(const void * a, const void * b);

int main()
{
    int *v;
    int n, m, m2, i, achei=0, j=0;

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
        scanf("%d", &m2);
        achei = Busca(v, n, m2, j);
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

int Busca(int *v, int n, int x, int j)
{

    while (j<n)
    {
        if(v[j]==x)
            {
                return 1;
            }
        else
            {
                j++;
                return Busca(v, n, x, j);
            }
    }
    return 0;
}


int comparador(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}