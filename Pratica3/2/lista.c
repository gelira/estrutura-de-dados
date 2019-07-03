#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define MaxTam 100

struct item
{
    int valor;
};

struct lista
{
    Item vetorItens[MaxTam];
    Item* pntItens;
    int tamanho;
};

/* OK */
Lista* InicializarLista()
{
    Lista* retorno = (Lista*) malloc(sizeof (Lista));
    retorno->pntItens = retorno->vetorItens;
    retorno->tamanho = 0;

    return retorno;
}

/* OK */
void EsvaziarLista(Lista* ls)
{
    ls->tamanho = 0;
}

/* OK */
int Vazia(Lista* ls)
{
    return (ls->tamanho == 0);
}


int Tamanho(Lista* ls)
{
    return ls->tamanho;
}

/* OK */
void InserirNoIndice(Lista* ls, Item* i, int posicao)
{
    if (ls->tamanho == MaxTam)
    {
        printf("Erro: lista cheia.\n");
        return;
    }

    if (posicao > MaxTam || posicao < 0)
    {
        printf("Erro: posicao fora das dimensoes da lista.\n");
        return;
    }

    int cont = ls->tamanho;
    do
    {
        *(ls->pntItens + cont) = *(ls->pntItens + cont - 1);
        cont --;
    } while(posicao < cont);

    *(ls->pntItens + posicao) = *i;
    ls->tamanho ++;
    DesalocarItem(i);
}

/* OK */
void InserirNoInicio(Lista* ls, Item* i)
{
    InserirNoIndice(ls, i, 0);
}

/* OK */
void InserirNoFim(Lista* ls, Item* i)
{
    InserirNoIndice(ls, i, ls->tamanho);
}

/* OK */
Item* RetirarNoIndice(Lista* ls, int posicao)
{
    if (Vazia(ls))
    {
        printf("Erro: lista vazia.\n");
        return NULL;
    }

    if (posicao >= MaxTam || posicao < 0)
    {
        printf("Erro: posicao fora das dimensoes da lista.\n");
        return NULL;
    }

    Item* retorno = AlocarItem();
    *(retorno)= *(ls->pntItens + posicao);
    ls->tamanho --;

    int cont = posicao;
    do
    {
        *(ls->pntItens + cont) = *(ls->pntItens + cont + 1);
        cont ++;
    } while(cont < ls->tamanho);

    return retorno;
}

/* OK */
Item* RetirarNoInicio(Lista* ls)
{
    Item* retorno = RetirarNoIndice(ls, 0);
    return retorno;
}

/* OK */
Item* RetirarNoFim(Lista* ls)
{
    Item* retorno = RetirarNoIndice(ls, ls->tamanho);
    return retorno;
}

void ModificarItemNoIndice(Lista* ls, Item* i, int posicao)
{
    if (Vazia(ls))
    {
        printf("Erro: lista vazia.\n");
        return;
    }

    if (posicao >= ls->tamanho || posicao < 0)
    {
        printf("Erro: posicao fora das dimensoes da lista.\n");
        return;
    }

    *(ls->pntItens + posicao) = *i;
    DesalocarItem(i);
}

void ModificarItemNoInicio(Lista* ls, Item* i)
{
    ModificarItemNoIndice(ls, i, 0);
}

void ModificarItemNoFim(Lista* ls, Item* i)
{
    ModificarItemNoIndice(ls, i, ls->tamanho - 1);
}

/* OK */
void ImprimirLista(Lista* ls)
{
    if (Vazia(ls))
    {
        printf("Lista vaiza.\n");
        return;
    }

    int cont = 0;
    while (cont < ls->tamanho - 1)
    {
        ImprimirItem(ls->pntItens + cont);
        printf(" ");
        cont ++;
    }
    ImprimirItem(ls->pntItens + ls->tamanho - 1);
}

/* OK */
void DestruirLista(Lista* ls)
{
    free(ls);
}

/* OK */
Item* AlocarItem()
{
    Item* retorno = (Item*) malloc(sizeof (Item));
    return retorno;
}

/* OK */
void ModificarValorItem(Item* i, int valor)
{
    i->valor = valor;
}

/* OK */
void ImprimirItem(Item* i)
{
    printf("%d", i->valor);
}

/* OK */
void DesalocarItem(Item* i)
{
    free(i);
}
