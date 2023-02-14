#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct No
{
    int chave;
    struct No *pai;
    struct No *direita;
    struct No *esquerda;
};

struct Arvore
{
    struct No *raiz;
};


struct Arvore * criaArvore();
struct No * criaNo(int);
void inserir(struct Arvore *, struct No *);
int pegarMenor(struct No *);


int main()
{
    int chave, n, m, i;
    struct Arvore *arvore = criaArvore();

    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        scanf("%d", &chave);
        inserir(arvore,criaNo(chave));
    }

    m = pegarMenor(arvore->raiz);

    printf("%d\n", m);

    return 0;
}

struct Arvore * criaArvore()
{
    struct Arvore *t = (struct Arvore*)malloc(sizeof(struct Arvore));
    if(t!=NULL)
    {
        t->raiz=NULL;
    }
    return t;
}

struct No * criaNo(int chave)
{
    struct No *no = (struct No *)malloc(sizeof(struct No));
    if(no!=NULL)
    {
        no->chave = chave;
        no->esquerda = NULL;
        no->direita = NULL;
        no->pai = NULL;
    }
    return no;
}

void inserir(struct Arvore *t, struct No *novo)
{
    struct No *pai=NULL, *filho=t->raiz;

    while(filho!=NULL)
    {

        pai = filho;
        if(filho->chave < novo->chave)
        {
            filho = filho->direita;
        }

        else
        {
            filho = filho->esquerda;
        }
    }

    if(pai!=NULL)
    {
        novo->pai = pai;
        if(pai->chave > novo->chave)
        {
            pai->esquerda = novo;
        }
        else
        {
            pai->direita = novo;
        }
    }
    else
    {
        t->raiz = novo;
    }
}

int pegarMenor(struct No *r)
{
    struct No *antecessor=NULL;

    while(r!=NULL)
    {
        antecessor = r;
        r = r->esquerda;
    }

    return antecessor->chave;
}