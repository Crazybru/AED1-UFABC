#include<stdio.h>

float calculaMedia(float, float);
char * aprovadorep(float);

int main()
{
    float nota1, nota2;
    scanf("%f %f", &nota1, &nota2);
    printf("%s\n", aprovadorep(calculaMedia(nota1, nota2)));
    return 0;
}

float calculaMedia(float n1, float n2)
{
    return (n1 + n2) / 2.f;
}

char * aprovadorep(float media)
{
    if(media >=60.f)
    {
        return "APROVADO";
    }
    else if(media >= 40.f)
    {
        return "EXAME FINAL";
    }
    else
    {
        return "REPROVADO";
    }
}