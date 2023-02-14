#include<stdio.h>
#include<stdlib.h>

struct Item
{
    int chave;
};

struct Lista
{
    int tamanho, quantidade;
    struct Item *itens;
};

struct Lista criaLista(int);
struct Item criaItem(int);
void inclui(struct Lista *, struct Item);
void exclui(struct Lista *, struct Item);
int listaCheia(struct Lista);
int listaVazia(struct Lista);
void mostraLista(struct Lista);
int buscarLista(struct Lista, struct Item);


int main()
{
    struct Lista lista;
    int n, chave;
    char op;

    scanf("%d", &n);
    lista = criaLista(n);

    while(scanf("\n%c", &op) != EOF)
    {
        if(op=='E')
        {
            scanf("%d", &chave);
            exclui(&lista, criaItem(chave));
        }
        if(op=='I')
        {
            scanf("%d", &chave);
            inclui(&lista, criaItem(chave));
        }
    }
    mostraLista(lista);

    return 0;
}


struct Lista criaLista(int n)
{
    struct Lista l;
    l.quantidade = 0;
    l.tamanho = n;
    l.itens = (struct Item *) malloc (n * sizeof(struct Item));

    return l;
}

void inclui(struct Lista *l, struct Item novo)
{
    int i, achei, j;
    if(!listaCheia(*l) && buscarLista(*l, novo) == -1)
    {
        achei = 0;
        i = 0;
        while(i<l->quantidade && !achei)
        {
            if(l->itens[i].chave > novo.chave)
            {
                achei = 1;
            }
            else
            {
                i++;
            }
        }
        for(j=l->quantidade-1; j>=i; j--)
        {
            l->itens[j+1] = l->itens[j];
        }

        l->itens[i] = novo;
        l->quantidade++;
    }
}

void exclui(struct Lista *l, struct Item it)
{

    int i, j;
    if(!listaVazia(*l))
    {
        i = buscarLista(*l, it);
        if(i!=-1)
        {
            for(j=i;j<l->quantidade-1;j++)
            {
                l->itens[j] = l->itens[j+1];
            }
            l->quantidade--;
        }
    }

}

int listaCheia(struct Lista l)
{
    return l.tamanho == l.quantidade;
}

int listaVazia(struct Lista l)
{
    return l.quantidade == 0;
}

void mostraLista(struct Lista l)
{
    int i;
    for(i=0;i<l.quantidade;i++)
    {
        printf("%d\n", l.itens[i].chave);
    }
}

struct Item criaItem(int chave)
{
    struct Item it;
    it.chave = chave;
    return it;
}

int buscarLista(struct Lista l, struct Item it)
{
    int esq = 0, dir = l.quantidade-1, meio;
    while(esq <= dir)
    {
        meio = (esq+dir)/2;

        if(l.itens[meio].chave == it.chave)
        {
            return meio;
        }
        else if(l.itens[meio].chave > it.chave)
        {
            dir = meio-1;
        }
        else
        {
            esq = meio+1;
        }
    }

    return -1;
}