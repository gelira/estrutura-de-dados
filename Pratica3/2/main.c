#include <stdio.h>
#include "lista.h"

int CharToInt(char n)
{
    if (n == '0') return 0;
    if (n == '1') return 1;
    if (n == '2') return 2;
    if (n == '3') return 3;
    if (n == '4') return 4;
    if (n == '5') return 5;
    if (n == '6') return 6;
    if (n == '7') return 7;
    if (n == '8') return 8;
    if (n == '9') return 9;
}

int main()
{
    Lista* entradas1 = InicializarLista();
    Lista* entradas2 = InicializarLista();
    Item* i;
    char op[10];

    do
    {
        fgets(op, 10, stdin);
        if (op[0] != 'I' && op[0] != 'F')
        {
            i = AlocarItem();
            ModificarValorItem(i, CharToInt(op[0]));
            InserirNoFim(entradas1, i);
        }
    } while(op[0] != 'F');

    do
    {
        fgets(op, 10, stdin);
        if (op[0] != 'I' && op[0] != 'F')
        {
            i = AlocarItem();
            ModificarValorItem(i, CharToInt(op[0]));
            InserirNoFim(entradas2, i);
        }
    } while(op[0] != 'F');

    while (!Vazia(entradas2))
    {
        i = RetirarNoInicio(entradas2);
        InserirNoFim(entradas1, i);
    }

    ImprimirLista(entradas1);

    DestruirLista(entradas1);
    DestruirLista(entradas2);
    return 0;
}
