#include <stdio.h>
#include "ListaEncadeada.h"

int main()
{
    Lista* ls = CriarLista();
    No* aux;
    int inserir;

    ImprimirLista(ls);

    for (int c = 0; c < 10; c ++)
    {
        printf("Digite um numero: ");
        scanf("%d", &inserir);
        aux = CriarNo();
        SetValorNo(aux, inserir);
        InserirFim(ls, aux); 
        ImprimirLista(ls);
    }

    aux = CriarNo();
    SetValorNo(aux, 100);
    InserirInicio(ls, aux);

    ImprimirLista(ls);

    for (int c = 0; c < 3; c ++)
    {
        aux = RemoverInicio(ls);
        printf("Removi no inicio: ");
        ImprimirValorNo(aux);
        DestruirNo(aux);
        aux = RemoverFim(ls);
        printf("\nRemovi no fim: ");
        ImprimirValorNo(aux);
        printf("\n");
        DestruirNo(aux);
        ImprimirLista(ls);
    }

    LiberarLista(ls);

    return 0;
}