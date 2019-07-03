#include <stdio.h>
#include <stdlib.h>
#include "ListaDuplamenteEncadeada.h"

struct lista
{
    No* cabeca;
    No* cauda;
    int tamanho;
};

struct no
{
    No* proximo;
    No* anterior;
    int valor;
};

Lista* CriarLista()
{
    Lista* retorno = (Lista*) malloc(sizeof (Lista));
    retorno->cabeca = AlocarNo();
    retorno->cauda = AlocarNo();

    retorno->cabeca->proximo = retorno->cauda;
    retorno->cabeca->anterior = NULL;
    retorno->cauda->anterior = retorno->cabeca;
    retorno->cauda->proximo = NULL;
    retorno->tamanho = 0;
    
    return retorno;
}

void LiberarLista(Lista* ls)
{
    No* aux;
    while (ls->cabeca->proximo != ls->cauda)
    {
        aux = ls->cabeca->proximo;
        ls->cabeca->proximo = aux->proximo;
        DestruirNo(aux);
    }

    DestruirNo(ls->cabeca);
    DestruirNo(ls->cauda);
    free(ls);
}

int Vazia(Lista* ls)
{
    return (ls->tamanho == 0);
}

int Tamanho(Lista* ls)
{
    return ls->tamanho;
}

void InserirNoInicio(Lista* ls, No* n)
{
    n->proximo = ls->cabeca->proximo;
    n->anterior = ls->cabeca;
    ls->cabeca->proximo->anterior = n;
    ls->cabeca->proximo = n;
    ls->tamanho ++;
}

void InserirNoFim(Lista* ls, No* n)
{
    n->proximo = ls->cauda;
    n->anterior = ls->cauda->anterior;
    ls->cauda->anterior->proximo = n;
    ls->cauda->anterior = n;
    ls->tamanho ++;
}

No* RemoverNoInicio(Lista* ls)
{
    if (Vazia(ls))
    {
        printf("A lista esta vazia.\n");
        return NULL;
    }

    No* retorno = ls->cabeca->proximo;
    retorno->proximo->anterior = ls->cabeca;
    ls->cabeca->proximo = retorno->proximo;
    ls->tamanho --;
    return retorno;
}

No* RemoverNoFim(Lista* ls)
{
    if (Vazia(ls))
    {
        printf("A lista esta vazia.\n");
        return NULL;
    }

    No* retorno = ls->cauda->anterior;
    retorno->anterior->proximo = ls->cauda;
    ls->cauda->anterior = retorno->anterior;
    ls->tamanho --;
    return retorno;
}

void ImprimirLista(Lista* ls)
{
    if (Vazia(ls))
    {
        printf("A lista esta vazia.\n");
        return;
    }
    
    No* aux = ls->cabeca->proximo;

    while (aux != ls->cauda->anterior)
    {
        ImprimirValorNo(aux);
        printf(" ");
        aux = aux->proximo;
    }
    
    ImprimirValorNo(aux);
}

No* AlocarNo()
{
    return (No*) malloc(sizeof (No));
}

void DefinirValorNo(No* n, int v)
{
    n->valor = v;
}

void ImprimirValorNo(No* n)
{
    printf("%d", n->valor);
}

void DestruirNo(No* n)
{
    free(n);
}