#ifndef TAD_POKELISTA_H
#define TAD_POKELISTA_H
#include "TAD_Pokemon.h"

typedef struct Poke_celula
{

    Pokemon info;
    struct Poke_celula *proximo;

} Poke_celula; // Célula Pokemon.

typedef struct Poke_celula *Apontador;

typedef struct
{

    Apontador primeiro;
    Apontador ultimo;

} Lista;

void inicializa_lista(Lista *pLista);

int LEhVazia(Lista *pLista);

void LInsere(Lista *pLista, Pokemon *p);

int LRetira(Lista *pLista, Pokemon *p);

void LImprime(Lista *pLista);

int busca(Lista *pLista, int id);

int tamanho_lista(Lista *pLista);

#endif
