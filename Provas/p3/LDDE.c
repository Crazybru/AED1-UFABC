#include<stdio.h>
#include<stdlib.h>

struct Item
{
    int chave;
    struct Item *anterior, *proximo;
};

struct Lista
{
    struct Item *primeiro, *ultimo;
};

struct Lista * criaLista();
struct Item * criaItem(int);
void inserir(struct Lista *, struct Item *);
struct Item * remover(struct Lista *, int);
struct Item * buscar(struct Lista *, int);
void mostrarPrimeiroUltimo(struct Lista *);
void mostrarUltimoPrimeiro(struct Lista *);
void desalocar(struct Lista *);
int listaVazia(struct Lista *);


int main()
{
    struct Lista *lista = criaLista();
    struct Item *it;
    int chave;
    char op;

    while(scanf("\n%c", &op) != EOF)
    {
        if(op == 'I')
        {
            scanf("%d", &chave);
            inserir(lista, criaItem(chave));
        }
        else if(op == 'E')
        {
            scanf("%d", &chave);
            it = remover(lista, chave);
            if(it != NULL)
            {
                free(it);
            }
        }
        else if(op == 'M')
        {
            mostrarPrimeiroUltimo(lista);
            printf("\n");
        }
        else if(op == 'R')
        {
            mostrarUltimoPrimeiro(lista);
            printf("\n");
        }
    }

    desalocar(lista);


    return 0;
}

struct Lista * criaLista()
{
    struct Lista *l = (struct Lista *)malloc(sizeof(struct Lista));
    if(l!=NULL)
    {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return l;
}

struct Item * criaItem(int chave)
{
    struct Item *it = (struct Item *)malloc(sizeof(struct Item));
    if(it!=NULL)
    {
        it->chave = chave;
        it->anterior = NULL;
        it->proximo= NULL;
    }
    return it;
}

void inserir(struct Lista *l, struct Item *novo)
{
    struct Item *anterior= NULL, *atual = l->primeiro;
    int achei = 0;

    while(atual!=NULL && atual->chave <= novo->chave)
    {
        if(atual->chave == novo->chave)
        {
            return;
        }
        atual = atual->proximo;
    }

    if(atual != NULL)
    {
        if(atual->anterior!=NULL)
        {
            atual->anterior->proximo = novo;
        }
        else
        {
            l->primeiro = novo;
        }
        novo->anterior = atual->anterior;
        atual->anterior = novo;
        novo->proximo = atual;
    }
    else
    {
        if(!listaVazia(l))
        {
            novo->proximo = l->ultimo->proximo;
            l->ultimo->proximo = novo;
        }
        else
        {
            l->primeiro = novo;
        }

        novo->anterior = l->ultimo;

        l->ultimo = novo;
    }
}

struct Item * remover(struct Lista *l, int chave)
{
    struct Item *atual = buscar(l, chave);

    if(atual!=NULL)
    {
        if(atual->anterior!=NULL)
        {
            atual->anterior->proximo = atual->proximo;
        }
        else
        {
            l->primeiro = atual->proximo;
        }
        if(atual->proximo!=NULL)
        {
            atual->proximo->anterior = atual->anterior;
        }
        else
        {
            l->ultimo = atual->anterior;
        }
    }

    return atual;
}

void desalocar(struct Lista *l)
{
    struct Item *it = l->primeiro, *proximo;
    while(it!=NULL)
    {
        proximo = it->proximo;
        free(it);
        it = proximo;
    }
    free(l);

}

void mostrarPrimeiroUltimo(struct Lista *l)
{
    struct Item *it = l->primeiro;

    while(it != NULL)
    {
        printf("%d ", it->chave);
        it = it->proximo;
    }

}

void mostrarUltimoPrimeiro(struct Lista *l)
{
    struct Item *it = l->ultimo;
    while(it!=NULL)
    {
        printf("%d ", it->chave);
        it = it->anterior;
    }
}

int listaVazia(struct Lista *l)
{
    return l->primeiro==NULL && l->ultimo==NULL;
}

struct Item * buscar(struct Lista *l, int chave)
{
    struct Item *it = l->primeiro;

    while(it!=NULL && it->chave < chave)
    {
        it = it->proximo;
    }

    if(it!=NULL && it->chave != chave)
    {
        it = NULL;
    }

    return it;
}