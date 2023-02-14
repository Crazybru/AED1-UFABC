#include<stdio.h>
#include<stdlib.h>

int particiona(int *, int);

int main()
{
    int n, p, i, aux;
    int *v;

    scanf("%d", &n);
    scanf("%d", &p);

    v = (int *) malloc(n*sizeof(int));

    for(i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
    }

    aux = v[n-1];
    v[n-1] = v[p];
    v[p] = aux;



    particiona(v, n);

    for(i=0;i<n;i++)
    {
        printf("%d\n", v[i]);
    }

    return 0;
}

int particiona(int *v, int n)
{
    int pm =-1, i, aux;
    for(i=0;i<n-1;i++)
    {
        if(v[i] <= v[n-1])
        {
            pm++;
            aux = v[pm];
            v[pm] = v[i];
            v[i] = aux;
        }
    }
    aux = v[pm+1];
    v[pm+1] = v[n-1];
    v[n-1] = aux;
    return pm+1;
}