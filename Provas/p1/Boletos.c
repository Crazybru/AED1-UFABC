#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int boletos, i, j, diferenca;

    struct boleto
    {
        char banco[100];
        char cedente[100];
        char sacado[100];
        double valor;
        int vencimento;
        int diapagamento;
        double atraso;
    };

    scanf("%d", &boletos);

    struct boleto liquidados[boletos];
    struct boleto placeholder;

    for(i=0;i<boletos;i++)
    {
        scanf("%s %s %s %lf %d %d %lf", liquidados[i].banco, liquidados[i].cedente, liquidados[i].sacado, &liquidados[i].valor, &liquidados[i].vencimento, &liquidados[i].diapagamento, &liquidados[i].atraso);
    }

    for(i=0;i<boletos;i++)
    {
        if(liquidados[i].vencimento < liquidados[i].diapagamento)
        {
            diferenca = liquidados[i].diapagamento - liquidados[i].vencimento;
            liquidados[i].valor = liquidados[i].valor + (diferenca * liquidados[i].atraso);
        }

    }

    for(i=0;i<boletos;i++)
    {
        for(j= i + 1;j<boletos;j++)
        {
            if(liquidados[i].valor < liquidados[j].valor)
            {
                placeholder = liquidados[i];
                liquidados[i] = liquidados[j];
                liquidados[j] = placeholder;
            }
        }
    }

    for(i=0;i<boletos;i++)
    {
        printf("%s ", liquidados[i].sacado);
        printf("%s ", liquidados[i].cedente);
        printf("%s ", liquidados[i].banco);
        printf("%.2lf", liquidados[i].valor);
        printf("\n");
    }


    return 0;
}