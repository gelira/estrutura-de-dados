#include <stdio.h>
#include <stdlib.h>
#include "ListaDuplamenteEncadeada.h"

int main()
{
    Lista* l = CriarLista();
    No* n;

    ImprimirLista(l);

    n = AlocarNo();
    DefinirValorNo(n, 10);
    InserirNoFim(l, n);
    ImprimirLista(l);

    n = AlocarNo();
    DefinirValorNo(n, 20);
    InserirNoFim(l, n);
    ImprimirLista(l);

    n = AlocarNo();
    DefinirValorNo(n, 30);
    InserirNoInicio(l, n);
    ImprimirLista(l);

    n = RemoverNoInicio(l);
    printf("Valor do no removido: ");
    ImprimirValorNo(n);
    printf("\n");
    ImprimirLista(l);
    DestruirNo(n);

    n = RemoverNoFim(l);
    printf("Valor do no removido: ");
    ImprimirValorNo(n);
    printf("\n");
    ImprimirLista(l);
    DestruirNo(n);

    LiberarLista(l);

    return 0;
}