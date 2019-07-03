typedef struct lista Lista;
typedef struct no No;

Lista* CriarLista();
void LiberarLista(Lista*);

int Vazia(Lista*);
int Tamanho(Lista*);

void InserirNoInicio(Lista*, No*);
void InserirNoFim(Lista*, No*);
No* RemoverNoInicio(Lista*);
No* RemoverNoFim(Lista*);

void ImprimirLista(Lista*);

No* AlocarNo();
void DefinirValorNo(No*, int);
void ImprimirValorNo(No*);
void DestruirNo(No*);