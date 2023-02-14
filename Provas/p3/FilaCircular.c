#include<stdio.h>
#include<stdlib.h>

struct Item
{
    int chave;
};

struct FilaEstaticaCircular
{
    struct Item *itens;
    int tamanho;
    int inicio, fim;
};


struct FilaEstaticaCircular criaFila(int);
struct Item desenfileirar(struct FilaEstaticaCircular*);
void enfileirar(struct FilaEstaticaCircular *, struct Item);
struct Item criaItem(int);
int filaVazia(struct FilaEstaticaCircular);
int filaCheia(struct FilaEstaticaCircular);

int main()
{
    struct FilaEstaticaCircular fila;
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

struct FilaEstaticaCircular criaFila(int n)
{
    struct FilaEstaticaCircular f;
    f.itens =(struct Item*) malloc (n * sizeof(struct Item));
    f.tamanho = n;
    f.inicio = 0;
    f.fim = 0;
    return f;
}

struct Item desenfileirar(struct FilaEstaticaCircular *f)
{
    struct Item it;
    if(!filaVazia(*f))
    {
        it = f->itens[f->inicio];
        f->inicio = (f->inicio+1)%f->tamanho;
    }
    return it;
}

void enfileirar(struct FilaEstaticaCircular *f, struct Item novo)
{
    if(!filaCheia(*f))
    {
        f->itens[f->fim] = novo;
        f->fim = (f->fim + 1)%f->tamanho;
    }
}

struct Item criaItem(int chave)
{
    struct Item it;
    it.chave = chave;
    return it;
}

int filaVazia(struct FilaEstaticaCircular f)
{
    return f.inicio == f.fim;  
}

int filaCheia(struct FilaEstaticaCircular f)
{
    return (f.fim+1)%f.tamanho == f.inicio;
}