#include <stdio.h>
#include "ListaDuplamenteEncadeada.h"
#define TAM 100

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
    Lista* entrada = CriarLista();
    Lista* inverso = CriarLista();
    No* ne; No* ni;
    char str[TAM];
    int palindromo = 1;

    fgets(str, TAM, stdin);

    int cont = 0;

    while (str[cont] != '\0' && str[cont] != '\n')
    {
        ne = AlocarNo();
        ni = AlocarNo();
        DefinirValorNo(ne, str[cont]);
        DefinirValorNo(ni, str[cont]);
        InserirNoFim(entrada, ne);
        InserirNoInicio(inverso, ni);
        cont ++;
    }

    for (int c = 0; c < cont; c ++)
    {
        ne = RemoverNoInicio(entrada);
        ni = RemoverNoInicio(inverso);

        if (GetValorNo(ne) != GetValorNo(ni))
        {
            palindromo = 0;
            c = TAM;
        }
        DestruirNo(ne);
        DestruirNo(ni);
    }

    if (palindromo) printf("sim");
    else printf("nao");

    LiberarLista(entrada);
    LiberarLista(inverso);

    return 0;
}