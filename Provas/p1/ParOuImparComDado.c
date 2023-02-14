#include<stdio.h>

int ParOuImpar(int pt)
{
    if(pt%2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{
    int max, roll, ptLeonard = 0, ptSheldon = 0, turno;

    scanf("%d", &max);

    while(ptLeonard != max && ptSheldon != max)
    {
        scanf("%d", &roll);
        if(ParOuImpar(turno) == 1)
        {
            if( ParOuImpar(roll) == ParOuImpar(ptSheldon))
            {
            ptSheldon++;
            }
            else if( (ParOuImpar(roll) != ParOuImpar(ptSheldon)) && (ptSheldon != 0) )
            {
            ptSheldon--;
            }
        }
        else
        {
            if( ParOuImpar(roll) == ParOuImpar(ptLeonard))
            {
            ptLeonard++;
            }
            else if( (ParOuImpar(roll) != ParOuImpar(ptLeonard)) && (ptLeonard != 0) )
            {
            ptLeonard--;
            }
        }

        turno++;
    }

    if(ptLeonard == max)
    {
        printf("Leonard\n");
    }
    else
    {
        printf("Sheldon\n");
    }

    return 0;
}