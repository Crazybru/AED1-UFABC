#include<stdio.h>

int main()
{
    char letra;
    int pos;

    scanf("%c", &letra);
    pos = letra - 'a' + 1;

    if(pos<1)
    {
        pos = letra - 'A' + 1;
    }

    printf("%d\n", pos);
    return 0;
}