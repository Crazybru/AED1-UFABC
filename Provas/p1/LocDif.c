#include<stdio.h>
#include<stdlib.h>


int comparator (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


int main()
{
    int *v, *w, i, j, diferente=5521, qt, qtw;

    scanf("%d", &qt);
    qtw =qt + 1;
    v = malloc(qt* sizeof(int));
    w = malloc(qtw * sizeof(int));

    for(i=0;i<qt;i++)
    {
        scanf("%d", &v[i]);
    }

    for(i=0;i<qtw;i++)
    {
        scanf("%d", &w[i]);
    }

    qsort(v, qt, sizeof(int), comparator);
    qsort(w, qtw, sizeof(int), comparator);

    for(i=0;i<qtw;i++)
    {
        if(w[i] != v[i])
        {
            diferente = w[i];
            i=qtw;
        }
    }
    if(diferente==5521)
    {
        diferente = w[qtw];
    }
    
    printf("%d\n", diferente);
    return 0;

}