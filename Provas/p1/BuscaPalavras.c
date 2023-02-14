#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n, p, i, j, qn, achei=0, igual;
    char q[26];
    char s[1000][26];

    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        scanf("%s", s[i]);
    }

    scanf("%d", &qn);

    for(i=0;i<qn;i++)
    {
        scanf("%s", q);
        for(j=0;j<n;j++)
        {
            igual = strcmp(q,s[j]);
            if(igual == 0)
            {
                achei++;
            }
        }
        printf("%d\n", achei);
        achei=0;
    }
    return 0;
}