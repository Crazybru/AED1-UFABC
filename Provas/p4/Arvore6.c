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
void preOrder(struct No*);
struct No * remover(struct Arvore *, int);
struct No * sucessor(struct No*);


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

    scanf("%d", &m);
    for(i=0;i<m;i++)
    {
        scanf("%d", &chave);
        remover(arvore, chave);
    }

    preOrder(arvore->raiz);

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

        if(filho->chave == novo->chave)
        {
            return;
        }

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

void preOrder(struct No *r)
{
    if(r!=NULL)
    {
        printf("%d\n", r->chave);
        preOrder(r->esquerda);
        preOrder(r->direita);
    }
}

struct No * remover(struct Arvore *t, int chave)
{
    struct No *anterior=NULL, *filho=t->raiz, *subs=NULL;

    while(filho!=NULL && filho->chave != chave)
    {
        anterior = filho;
        if(filho->chave < chave)
        {
            filho = filho->direita;
        }
        else
        {
            filho = filho->esquerda;
        }
    }

    if(filho != NULL)
    {
        if(filho->esquerda==NULL && filho->direita==NULL)
        {
            if(anterior!=NULL)
            {
                if(anterior->esquerda == filho)
                {
                    anterior->esquerda = NULL;
                }
                else
                {
                    anterior->direita = NULL;
                }
            }
            else
            {
                t->raiz = NULL;
            }
        }

        else if(filho->esquerda != NULL && filho->direita != NULL)
        {
            subs = sucessor(filho->direita);

            if(anterior!=NULL)
            {
                if(anterior->esquerda==filho)
                {
                    anterior->esquerda = subs;
                }

                else
                {
                    anterior->direita = subs;
                }
            }
            else
            {
                t->raiz = subs;
            }

            subs->pai = anterior;

            subs->esquerda = filho->esquerda;
            if(filho->esquerda!=NULL)
            {
                filho->esquerda->pai = subs;
            }

            subs->direita = filho->direita;
            if(filho->direita!=NULL)
            {
                filho->direita->pai = subs;
            }
        }

        else
        {
            if(anterior!=NULL)
            {
                if(anterior->esquerda == filho)
                {
                   if(filho->esquerda!=NULL)
                   {
                       anterior->esquerda = filho->esquerda;
                       filho->esquerda->pai = anterior;
                   }

                   else
                   {
                       anterior->esquerda = filho->direita;
                       filho->direita->pai = anterior;
                   }
                }

                else
                {
                    if(filho->esquerda!=NULL)
                    {
                        anterior->direita = filho->esquerda;
                        filho->esquerda->pai = anterior;
                    }

                    else
                    {
                        anterior->direita = filho->direita;
                        filho->direita->pai = anterior;
                    }
                }
            }

            else
            {
                if(filho->esquerda != NULL)
                {
                    t->raiz = filho->esquerda;
                }
                else
                {
                    t->raiz = filho->direita;
                }
                t->raiz->pai = NULL;
            }
        }


    }
    return filho;
}

struct No * sucessor(struct No *filho)
{
    struct No *anterior=NULL;

    while(filho!=NULL)
    {
        anterior = filho;
        filho = filho->esquerda;
    }

    if(anterior->pai->esquerda == anterior)
    {
        anterior->pai->esquerda = anterior->direita;

        if(anterior->direita!=NULL)
        {
            anterior->direita->pai = anterior->pai;
        }
    }

    else
    {
        anterior->pai->direita = anterior->direita;

        if(anterior->direita!=NULL)
        {
            anterior->direita->pai = anterior->pai;
        }
    }

    return anterior;
}