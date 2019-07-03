#include <stdio.h>
#include "lista.h"

int main()
{
    Lista* l = InicializarLista();

    if (Vazia(l)) printf("Vazia\n");

    ImprimirLista(l);

    Item* i;

    for (int cont = 0; cont < 10; cont ++)
    {
        i = AlocarItem();
        ModificarValorItem(i, cont);
        InserirNoInicio(l, i);
        ImprimirLista(l);
    }

    i = AlocarItem();
    ModificarValorItem(i, 10);
    ModificarItemNoInicio(l, i);
    ImprimirLista(l);

    i = AlocarItem();
    ModificarValorItem(i, 100);
    ModificarItemNoFim(l, i);
    ImprimirLista(l);

    i = AlocarItem();
    ModificarValorItem(i, 50);
    ModificarItemNoIndice(l, i, 5);
    ImprimirLista(l);

    DestruirLista(l);
    return 0;
}
