#include <stdio.h>
#include <stdlib.h>

struct celula
{
    int valor;
    struct celula* proximo;
};

typedef struct celula Celula;

Celula* Alocar()
{
    Celula* aux = (Celula*) malloc(sizeof (Celula));
    aux->proximo = NULL;
    return aux;
}

/* OK */
void Enfileirar(Celula* inicioFila, Celula* fimFila, int v)
{
    Celula* aux = Alocar();
    aux->valor = v;

    if (!inicioFila->proximo && !fimFila->proximo) inicioFila->proximo = aux;
    else fimFila->proximo->proximo = aux;

    fimFila->proximo = aux;
}

int Desenfileirar(Celula* inicioFila)
{
    Celula* aux = inicioFila->proximo;
    int retorno = aux->valor;
    inicioFila->proximo = aux->proximo;
    free(aux);
    return retorno;
}

void ImprimirConteudo(Celula* inicioFila)
{
    if (inicioFila->proximo)
    {
        Celula* aux = inicioFila->proximo;
        do {
            printf("%d > ", aux->valor);
            aux = aux->proximo;
        } while (aux);
        printf("Fim da fila");
    }

    else
    {
        printf("Fila vazia!");
    }
    printf("\n");
}

void main()
{
    Celula* inicio = Alocar();
    Celula* fim = Alocar();
    int valor, cont = 0;

    ImprimirConteudo(inicio);

    printf("Enfileirando:\n");

    while (cont < 10)
    {
        printf("\nInteiro %d: ", cont);
        scanf("%d", &valor);
        Enfileirar(inicio, fim, valor);
        ImprimirConteudo(inicio);
        cont ++;
    }

    printf("\nDesenfileirando:\n");

    do
    {
        valor = Desenfileirar(inicio);
        printf("\nCaractere do inicio da fila: %d\n", valor);
        ImprimirConteudo(inicio);
    } while (inicio->proximo);

    free(inicio);
    free(fim);
}
