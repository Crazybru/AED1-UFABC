#include<stdio.h>
#include<stdlib.h>
struct Item
{
    int chave;
};

struct FilaEstatica
{
    struct Item *itens;
    int tamanho;
    int inicio, fim;
};


struct FilaEstatica criaFila(int);
struct Item desenfileirar(struct FilaEstatica*);
void enfileirar(struct FilaEstatica *, struct Item);
struct Item criaItem(int);
int filaVazia(struct FilaEstatica);
int filaCheia(struct FilaEstatica);

int main()
{
    struct FilaEstatica fila;
    int n, chave;
    char op;
    
    scanf("%d", &n);
    fila = criaFila(n);
    
    
    while(scanf("\n%c", &op) != EOF)
    {
        if(op=='E')
        {
            scanf("%d", &chave);
            enfileirar(&fila, criaItem(chave));
        }
        
        if(op=='D')
        {
            if(!filaVazia(fila))
            {
                printf("%d\n", desenfileirar(&fila).chave);
            }
        }   
    }
    
    
    return 0;
}

struct FilaEstatica criaFila(int n)
{
    struct FilaEstatica f;
    f.itens =(struct Item*) malloc (n * sizeof(struct Item));
    f.tamanho = n;
    f.inicio = -1;
    f.fim = -1;
    return f;
}

struct Item desenfileirar(struct FilaEstatica *f)
{
    struct Item it;
    if(!filaVazia(*f))
    {
        it = f->itens[f->inicio];
        
        if(f->inicio != f->fim)
        {
            f->inicio++;
        }
        else
        {
            f->inicio = -1;
            f->fim = -1;
        }
    }
    
    return it;
    
}

void enfileirar(struct FilaEstatica *f, struct Item novo)
{
    if(!filaCheia(*f))
    {
        if(filaVazia(*f))
        {
            f->inicio++;
        }
        f->fim++;
        f->itens[f->fim] = novo;
    }
}

struct Item criaItem(int chave)
{
    struct Item it;
    it.chave = chave;
    return it;
}

int filaVazia(struct FilaEstatica f)
{
    return f.inicio == -1 && f.fim == -1 || f.inicio  > f.fim;   
}

int filaCheia(struct FilaEstatica f)
{
    return f.fim == f.tamanho-1;
}