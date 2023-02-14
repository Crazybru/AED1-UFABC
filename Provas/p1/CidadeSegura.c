#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, **map, size, i, j, h=0,v=0,seguro,camera=0,startv=0,starth=0;

    scanf("%d", &n);
    size = n + 1;
    map = malloc(size*sizeof(int *));
    for(i=0;i<size;i++)
    {
        map[i] = (int*)malloc(size*sizeof(int));
    }

    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            scanf("%d", &map[i][j]);
        }
    }


    for(i=0;i<n;i++)
    {
        for(j=0;j < n;j++)
        {
            v=startv;
            h=starth;
            if(map[v][h]==1)
            {
                camera = camera +1;
            }
            h++;
            if(map[v][h]==1)
            {
                camera = camera +1;
            }
            h = starth;
            v++;
            if(map[v][h]==1)
            {
                camera = camera +1;
            }
            h++;
            if(map[v][h]==1)
            {
                camera = camera +1;
            }
            if(starth<n)
            {
                starth++;
            }
            if(camera>=2)
            {
                printf("S");
            }
            else
            {
                printf("U");
            }
            camera=0;
        }
        starth=0;
        startv++;
        printf("\n");
    }

    return 0;
}