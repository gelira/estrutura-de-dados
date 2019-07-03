typedef struct lista Lista;
typedef struct no No;
 
Lista* CriarLista();
void LiberarLista(Lista*);
 
int Vazia(Lista*);
 
void InserirInicio(Lista*, No*);
void InserirFim(Lista*, No*);
No* RemoverInicio(Lista*);
No* RemoverFim(Lista*);
 
void ImprimirLista(Lista*);
 
No* CriarNo();
void SetValorNo(No*, int);
void ImprimirValorNo(No*);
void DestruirNo(No*);