#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no* esquerda;
    struct no* direita;
} No;

No* AlocarNo()
{
    No* retorno = (No*) malloc(sizeof (No));
    retorno->esquerda = NULL;
    retorno->direita = NULL;
    return retorno;
}

void SetChave(No* n, int valor)
{
    n->chave = valor;
}

void GetValor(No* n, int* qtd)
{
    printf("%d", n->chave);
    *qtd = *qtd - 1;
    if (*qtd > 0)
    {
        printf(" ");
    }
}

void InserirNoArvore(No* raiz, No* n)
{
    if (n->chave <= raiz->chave)
    {
        if (raiz->esquerda)
        {
            InserirNoArvore(raiz->esquerda, n);
        }

        else
        {
            raiz->esquerda = n;
        }
    }

    else
    {
        if (raiz->direita)
        {
            InserirNoArvore(raiz->direita, n);
        }

        else
        {
            raiz->direita = n;
        }
    }
}

void DestruirArvore(No* raiz)
{
    if (raiz)
    {
        DestruirArvore(raiz->esquerda);
        DestruirArvore(raiz->direita);
        free(raiz);
    }
}

void PosOrdem(No* raiz, int* qtd)
{
    if (raiz)
    {
        PosOrdem(raiz->esquerda, qtd);
        PosOrdem(raiz->direita, qtd);
        GetValor(raiz, qtd);
    }
}

void EmOrdem(No* raiz, int* qtd)
{
    if (raiz)
    {
        EmOrdem(raiz->esquerda, qtd);
        GetValor(raiz, qtd);
        EmOrdem(raiz->direita, qtd);
    }
}

void PreOrdem(No* raiz, int* qtd)
{
    if (raiz)
    {
        GetValor(raiz, qtd);
        PreOrdem(raiz->esquerda, qtd);
        PreOrdem(raiz->direita, qtd);
    }
}

int main()
{
    int qtd, num;
    int* p;
    No* raiz = AlocarNo();

    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i ++)
    {
        int valor;
        scanf("%d", &valor);
        if (i == 0)
        {
            SetChave(raiz, valor);
        }

        else
        {
            No* aux = AlocarNo();
            SetChave(aux, valor);
            InserirNoArvore(raiz, aux);
        }
    }

    num = qtd;
    p = &num;

    PreOrdem(raiz, p);
    printf("\n");

    num = qtd;
    EmOrdem(raiz, p);
    printf("\n");

    num = qtd;
    PosOrdem(raiz, p);

    DestruirArvore(raiz);

    return 0;
}