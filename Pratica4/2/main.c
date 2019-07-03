#include <stdio.h>
#include "ListaDuplamenteEncadeada.h"

int CharToInt(char cr)
{
    if (cr == '0') return 0;
    if (cr == '1') return 1;
    if (cr == '2') return 2;
    if (cr == '3') return 3;
    if (cr == '4') return 4;
    if (cr == '5') return 5;
    if (cr == '6') return 6;
    if (cr == '7') return 7;
    if (cr == '8') return 8;
    if (cr == '9') return 9;
}

void EntradaLista(Lista* e)
{
    No* n;
    char c[5];

    do
    {
        fgets(c, 5, stdin);
        if (c[0] != 'I' && c[0] != 'F')
        {   
            n = AlocarNo();
            DefinirValorNo(n, CharToInt(c[0]));
            InserirNoFim(e, n);
        }
    } while (c[0] != 'F');
}

int main()
{
    Lista* entradas1 = CriarLista();
    Lista* entradas2 = CriarLista();
    No* n;

    EntradaLista(entradas1);
    EntradaLista(entradas2);

    int tam = Tamanho(entradas2);

    for (int cont = 0; cont < tam; cont ++)
    {
        n = RemoverNoInicio(entradas2);
        InserirNoFim(entradas1, n);
    }

    ImprimirLista(entradas1);

    LiberarLista(entradas1);
    LiberarLista(entradas2);

    return 0;
}