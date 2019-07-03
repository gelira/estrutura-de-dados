typedef struct item Item;
typedef struct lista Lista;

/* Funções da lista */
Lista* InicializarLista();
void EsvaziarLista(Lista*);
int Vazia(Lista*);

void InserirNoIndice(Lista*, Item*, int);
void InserirNoInicio(Lista*, Item*);
void InserirNoFim(Lista*, Item*);

Item* RetirarNoIndice(Lista*, int);
Item* RetirarNoInicio(Lista*);
Item* RetirarNoFim(Lista*);

void ModificarItemNoIndice(Lista*, Item*, int);
void ModificarItemNoInicio(Lista*, Item*);
void ModificarItemNoFim(Lista*, Item*);

void ImprimirLista(Lista*);
void DestruirLista(Lista*);

/* Funções dos itens */
Item* AlocarItem();
void ModificarValorItem(Item*, int);
void ImprimirItem(Item*);
void DesalocarItem(Item*);
