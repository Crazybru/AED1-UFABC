#include<stdio.h>
#include<stdlib.h>

struct Item
{
    int chave;
    struct Item *proximo;
};

struct Fila
{
    struct Item *inicio;
    struct Item *fim;
};

struct Fila * criaFila();
struct Item * criaItem(int);
int filaVazia(struct Fila *);
void enfileirar(struct Fila *, struct Item *);
struct Item * remover(struct Fila *);
void mostraFila(struct Fila *);


int main()
{
    struct Fila *fila = criaFila();
    struct Item *it;
    int chave;
    char op;

    while(scanf("\n%c", &op) != EOF)
    {
        if(op=='E')
        {
            scanf("%d", &chave);
            enfileirar(fila, criaItem(chave));
        }
        else if(op=='D')
        {
            it = remover(fila);
            if(it != NULL)
            {
                printf("<%d>\n", it->chave);
                free(it);
            }
        }
        else if(op=='M')
        {
            mostraFila(fila);
        }
    }


    return 0;
}

struct Fila * criaFila()
{
    struct Fila *f = (struct Fila *)malloc(sizeof(struct Fila));
    if(f!=NULL)
    {
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

struct Item * criaItem(int chave)
{
    struct Item *it = (struct Item *)malloc(sizeof(struct Item));
    if(it!=NULL)
    {
        it->chave = chave;
        it->proximo = NULL;
    }
    return it;
}

int filaVazia(struct Fila *f)
{
    return f->inicio==NULL && f->fim==NULL;
}

void enfileirar(struct Fila *f, struct Item *novo)
{
    if(filaVazia(f))
    {
        f->inicio = novo;
    }
    else
    {
        f->fim->proximo = novo;
    }
    f->fim = novo;

}

struct Item * remover(struct Fila *f)
{
    struct Item *it = f->inicio;
    if(!filaVazia(f))
    {
        f->inicio = f->inicio->proximo;
        if(f->inicio == NULL)
        {
            f->fim = NULL;
        }
    }
    return it;
}

void mostraFila(struct Fila *f)
{
    struct Item *it = f->inicio;
    while(it != NULL)
    {
        printf("%d%s", it->chave, it->proximo!=NULL?" ":"\n");
        it=it->proximo;
    }
}