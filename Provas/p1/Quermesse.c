#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ing, i, qt=1, ganhador=0, check=1, nTeste=0;

    while(qt!=0)
    {
        scanf("%d", &qt);

        ing = malloc(qt * sizeof(int));

        for (i=0;i<qt;i++)
        {
            scanf("%d", &ing[i]);
        }

        for (i=0;i<qt;i++)
        {
            if(ing[i] == check)
            {
                ganhador = ing[i];
            }
            check++;
        }
        check=1;
        nTeste++;
        free(ing);
        if(ganhador !=0)
        {
            printf("Teste %d\n%d\n", nTeste, ganhador);
            printf("\n");
        }
        ganhador=0;
    }
    return 0;
}