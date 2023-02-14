#include<stdio.h>
int main()
{
    int ano_at, ano_nasc, idade;
    char nome[20];
    scanf("%d", &ano_at);
    scanf("%s", nome);
    scanf("%d", &ano_nasc);

    idade = ano_at - ano_nasc;

    printf("%s, voce completa %d anos de idade neste ano.\n", nome, idade);

    return 0;
}