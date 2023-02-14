#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main()
{
    int size, i, j, countero=0, counterx=0, h=0, v=0, limite=0, vencedorc=0 ,vencedorl=0 , vencedordp=0, vencedords=0;
    char **tab, c[2], vencedor='n';

    scanf("%d", &size);

    tab = (char **) malloc(size* sizeof(int *));
    for(i=0;i<size;i++)
    {
        tab[i] = (char *) malloc(size* sizeof(int));
    }

    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            scanf("%1s", c);
            tab[i][j] = c[0];
        }
    }

    for(i=0;i<size;i++)
    {
         for(j=0;j<size;j++)
         {
            if(tab[i][h] == 'o')
            {
                countero++;
            }
            if(countero==size)
            {
                vencedor='o';
                vencedorl=1;
                break;
            }
            if(tab[i][h] == 'x')
            {
                counterx++;
            }
            if(counterx==size)
            {
                vencedor='x';
                vencedorl=1;
                break;
            }
            h++;
            limite++;
         }
         if(countero==size || counterx==size)
         {
             if(countero==size)
             {
                 vencedor = 'o';
                 vencedorl=1;
             }
             else
             {
                 vencedor = 'x';
                 vencedorl=1;
             }

             break;
         }
         if(limite>= size*size)
         {
             limite=0;
             countero=0;
             counterx=0;
             break;
         }
         counterx=0;
         countero=0;
         h=0;
    }

    limite=0;


    if(1==1)
    {

        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                if(tab[v][i] == 'o')
                {
                    countero++;
                }
                if(countero==size)
                {
                    vencedor='o';
                    vencedorl=1;
                    break;
                }
                if(tab[v][i] == 'x')
                {
                    counterx++;
                }
                if(counterx==size)
                {
                    vencedor='x';
                    vencedorl=1;
                    break;
                }
                v++;
                limite++;
            }
            if(countero==size || counterx==size)
            {
                if(countero==size)
                {
                    vencedor = 'o';
                    vencedorl=1;
                }
                else
                {
                    vencedor = 'x';
                    vencedorl=1;
                }

                break;
            }
            if(limite>= size*size)
            {
                limite=0;
                countero=0;
                counterx=0;
                break;
            }
            counterx=0;
            countero=0;
            v=0;
        }
    }


    if(1==1)
    {
        for(i=0;i<size;i++)
        {
            if(tab[i][i]=='o')
            {
                countero++;
            }
            if(countero==size)
            {
                vencedor='o';
                vencedordp=1;
                break;
            }
            if(tab[i][i]=='x')
            {
                counterx++;
            }
            if(counterx==size)
            {
                vencedor='x';
                vencedordp=1;
                break;
            }

            if(countero==size || counterx==size)
            {
                if(countero==size)
                {
                    vencedor = 'o';
                    vencedordp=1;
                }
                else
                {
                    vencedor = 'x';
                    vencedordp=1;
                }

                break;
            }

            limite++;
            if(limite>= size*size)
            {
                limite=0;
                countero=0;
                counterx=0;
                break;
            }
        }
        counterx=0;
        countero=0;
        limite=0;
    }

    j=0;
    if(1==1)
    {
        for(i=size;i<0;i--)
        {
            if(tab[j][i] == 'o')
            {
                countero++;
            }
            if(countero==size)
            {
                vencedor='o';
                vencedords=1;
                break;
            }
            if(tab[j][i] == 'x')
            {
                counterx++;
            }
            if(counterx==size)
            {
                vencedor='x';
                vencedords=1;
                break;
            }

            limite++;

            if(limite>=size*size)
            {
                limite=0;
                countero=0;
                counterx=0;
                break;
            }
            j++;
        }
        j=0;
        if(countero==size || counterx==size)
        {
            if(countero==size)
            {
                vencedor = 'o';
                vencedords=1;
            }
            else
            {
                vencedor = 'x';
                vencedords=1;
            }
        }
        counterx=0;
        countero=0;
        limite=0;
    }


    if(vencedorc == 1 && vencedorl == 1)
    {
        printf("empate!\n");
    }
    else if(vencedorc == 1 && vencedordp==1)
    {
        printf("empate!\n");
    }
    else if(vencedorc == 1 && vencedords==1)
    {
        printf("empate!\n");
    }
    else if(vencedorc == 1 && vencedordp==1)
    {
        printf("empate!\n");
    }
    else if(vencedorl == 1 && vencedordp==1)
    {
        printf("empate!\n");
    }
    else if(vencedorl == 1 && vencedords==1)
    {
        printf("empate!\n");
    }
    else if(vencedordp == 1 && vencedords==1)
    {
        printf("empate!\n");
    }
    else if(vencedor=='x')
    {
        printf("x venceu!\n");
    }
    else if(vencedor=='o')
    {
        printf("o venceu!\n");
    }
    else
    {
        printf("empate!\n");
    }

    return 0;
}
