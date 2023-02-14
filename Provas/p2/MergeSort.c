#include<stdio.h>
#include<stdlib.h>

void intercala(int *, int, int, int, int);
void mergeSort(int *, int, int, int);

int main()
{
    int i, n, esq, dir;
    int *v;

    scanf("%d", &n);

    v = (int*) malloc(n*sizeof(int));

    for(i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
    }

    esq = 0;
    dir = n - 1;

    for(i=0;i<n;i++)
    {
        if(i == n-1)
        {
            printf("%d", v[i]);
        }
        else
        {
            printf("%d ", v[i]);
        }

    }
    printf("\n");

    mergeSort(v, esq, dir, n);

    for(i=0;i<n;i++)
    {
        if(i == n-1)
        {
            printf("%d", v[i]);
        }
        else
        {
            printf("%d ", v[i]);
        }

    }
    printf("\n");


    return 0;
}

void mergeSort(int *v, int esq, int dir, int n)
{
    int meio, i;


    if(esq < dir)
    {
        meio = (dir + esq)/2;
        mergeSort(v, esq, meio, n);
        mergeSort(v, meio+1, dir, n);
        intercala(v, esq, meio+1, dir, n);
    }
}




void intercala(int *v, int esq, int m, int dir, int n)
{
    int *temp, i, fim_esq = m - 1, tamanho = dir-esq + 1, j, itemp;
    temp = (int*) malloc((tamanho+2) * sizeof(int));

    for(i=0;i<n;i++)
    {
        if(i == n-1)
        {
            printf("%d", v[i]);
        }
        else
        {
            printf("%d ", v[i]);
        }
    }
    printf("\n");

    for(i=esq, j=m, itemp=0; i<=fim_esq && j<=dir; itemp++)
    {
        if(v[i] < v[j])
        {
            temp[itemp] = v[i];
            i++;
        }
        else
        {
            temp[itemp] = v[j];
            j++;
        }
    }
    for(; i<= fim_esq; itemp++, i++)
        temp[itemp] = v[i];
    for(; j<=dir; j++, itemp++)
        temp[itemp] = v[j];
    for(i=esq, j=0; i<=dir; i++, j++)
        v[i] = temp[j];
    free(temp);
}