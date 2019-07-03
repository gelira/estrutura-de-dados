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

int main()
{
    Lista* entradas = CriarLista();
    Lista* saida = CriarLista();
    No* n;
    char c[5];

    do
    {
        fgets(c, 5, stdin);
        if (c[0] != 'I' && c[0] != 'F')
        {   
            n = AlocarNo();
            DefinirValorNo(n, CharToInt(c[0]));
            InserirNoFim(entradas, n);
        }
    } while (c[0] != 'F');

    int tam = Tamanho(entradas);
    int metade = tam / 2;
    if (tam % 2)
    { 
        metade ++;
    }
    
    for (int cont = 0; cont < metade; cont ++)
    {
        n = RemoverNoInicio(entradas);
        InserirNoFim(saida, n);
    }

    ImprimirLista(saida);

    if (!Vazia(entradas))
    {
        printf("\n");
        ImprimirLista(entradas);
    }

    LiberarLista(entradas);
    LiberarLista(saida);

    return 0;
}