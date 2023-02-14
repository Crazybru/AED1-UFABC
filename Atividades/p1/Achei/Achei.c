#include<stdio.h>
#include<stdlib.h>

int buscaLinear(int *v, int n, int x);

int main()
{
    int n, *vet, i, m, val;

    scanf("%d", &n);
    vet = (int*) malloc(n * sizeof(int));

    for(i=0; i<n; i++)
    {
        scanf("%d", &vet[i]);
    }

    scanf("%d", &m);
    for(i=0; i<m; i++)
    {
        scanf("%d", &val);
        if(buscaLinear(vet, n, val))
        {
            printf("ACHEI\n");
        }
        else
        {
            printf("NAO ACHEI\n");
        }
    }
    free(vet);

    return 0;
}

int buscaLinear(int *v, int n, int x)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(v[i] == x)
        {
        return 1;
        }
    }
    return 0;
}