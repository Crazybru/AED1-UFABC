#include<stdio.h>
#include<stdlib.h>

void intercala(int *, int, int, int);

int main()
{
    int n1, n2, n3, i, j, esq, m, dir;
    int *v;

    scanf("%d", &n1);
    scanf("%d", &n2);

    n3 = n1 + n2;

    v = (int*) malloc(n3*sizeof(int));

    for(i=0;i<n1;i++)
    {
        scanf("%d", &v[i]);
    }
    for(i=n1;i<n3;i++)
    {
        scanf("%d", &v[i]);
    }
    esq = 0;
    dir = n3;
    m = n1;

    intercala(v, esq, m, dir);

    for(i=0;i<n3;i++)
    {
        printf("%d\n", v[i]);
    }


    return 0;
}

void intercala(int *v, int esq, int m, int dir)
{
    int *temp, i, fim_esq = m - 1;
    temp = (int*) malloc(dir * sizeof(int));
    for(i=0; esq<=fim_esq && m<dir ;i++)
    {
        if(v[esq] < v[m])
        {
            temp[i] = v[esq];
            esq++;
        }
        else
        {
            temp[i] = v[m];
            m++;
        }
    }
    for(; esq<= fim_esq; esq++, i++)
        temp[i] = v[esq];
    for(; m<dir; m++, i++)
        temp[i] = v[m];
    for(i=0; i<dir; i++)
        v[i] = temp[i];
    free(temp);
}