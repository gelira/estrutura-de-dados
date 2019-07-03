#include <stdio.h>
#include <stdlib.h>

struct no
{
    int valor;
    struct no* proximo;
};

typedef struct no No;

/* OK */
No* Alocar()
{
    No* n = (No*) malloc(sizeof (No));
    n->proximo = NULL;
    return n;
}

/* OK */
void Empilhar(No* topo, int i)
{
    No* n = Alocar();
    n->valor = i;
    n->proximo = topo->proximo;
    topo->proximo = n;
}

/* OK */
int Desempilhar(No* topo)
{
    int retorno;
    if (topo->proximo)
    {
        No* n = topo->proximo;
        retorno = n->valor;
        topo->proximo = n->proximo;
        free(n);
    }
    return retorno;
}

/* OK */
void ImprimirConteudo(No* topo)
{
    if (topo->proximo)
    {
        printf("Conteúdo da pilha: ");
        No* auxiliar = topo;
        do
        {
            auxiliar = auxiliar->proximo;
            printf("|%d|", auxiliar->valor);
        } while (auxiliar->proximo);
    }

    else
    {
        printf("Pilha sem conteúdo!");
    }
    printf("\n");
}

void main()
{
    No* topoPilha = Alocar();
    int valor, cont = 0;

    ImprimirConteudo(topoPilha);

    printf("Empilhando:\n");

    while (cont < 10)
    {
        printf("\nInteiro %d: ", cont);
        scanf("%d", &valor);
        Empilhar(topoPilha, valor);
        ImprimirConteudo(topoPilha);
        cont ++;
    }

    printf("\nDesempilhando:\n");

    do
    {
        valor = Desempilhar(topoPilha);
        printf("\nCaractere do topo: %d\n", valor);
        ImprimirConteudo(topoPilha);
    } while (topoPilha->proximo);

    free(topoPilha);
}

