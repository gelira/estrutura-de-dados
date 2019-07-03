#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

struct lista
{
    No* inicio;
    int tamanho;
};

struct no
{
    No* proximo;
    int valor;
};

Lista* CriarLista()
{
    Lista* retorno = (Lista*) malloc(sizeof (Lista));
    retorno->inicio = NULL;
    return retorno;
}

void LiberarLista(Lista* l)
{
    No* inicio = l->inicio;
    No* aux;

    while (inicio)
    {
        aux = inicio;
        inicio = inicio->proximo;
        free(aux);
    }

    free(l);
}

int Vazia(Lista* l)
{
    return (l->tamanho == 0);
}

void InserirInicio(Lista* l, No* n)
{
    n->proximo = l->inicio;
    l->inicio = n;
    l->tamanho ++;
}

void InserirFim(Lista* l, No* n)
{
    if (Vazia(l))
    {
        InserirInicio(l, n);
        return;
    }

    No* aux = l->inicio;

    while (aux->proximo)
    {
        aux = aux->proximo;
    }

    aux->proximo = n;
    l->tamanho ++;
}

No* RemoverInicio(Lista* l)
{
    if (Vazia(l))
    {
        printf("A lista esta vazia.\n");
        return NULL;
    }

    No* retorno = l->inicio;
    l->inicio = l->inicio->proximo;
    return retorno;
}

No* RemoverFim(Lista* l)
{
    if (Vazia(l))
    {
        printf("A lista esta vazia.\n");
        return NULL;
    }

    No* ult = l->inicio;
    No* pen = NULL;

    while (ult->proximo)
    {
        pen = ult;
        ult = ult->proximo;
    }

    pen->proximo = NULL;
    return ult;
}

void ImprimirLista(Lista* l)
{
    if (Vazia(l))
    {
        printf("A lista esta vazia.\n");
        return;
    }

    No* aux = l->inicio;
    printf("Inicio | ");

    while (aux)
    {
        ImprimirValorNo(aux);
        printf(" | ");
        aux = aux->proximo;
    }

    printf("Fim\n");
}

No* CriarNo()
{
    No* retorno = (No*) malloc(sizeof (No));
    retorno->proximo = NULL;
    return retorno;
}
void SetValorNo(No* n, int v)
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