#include <stdio.h>
#include <stdlib.h>
#include "TAD_Pokelista.h"

void inicializa_lista(Lista *pLista)
{
    pLista->primeiro = (Apontador)malloc(sizeof(Poke_celula));
    pLista->ultimo = pLista->primeiro;
    pLista->primeiro->proximo = NULL;
}

int LEhVazia(Lista *pLista)
{
    if (pLista->primeiro == pLista->ultimo)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void LInsere(Lista *pLista, Pokemon *p)
{
    pLista->ultimo->proximo = (Apontador)malloc(sizeof(Poke_celula));

    pLista->ultimo = pLista->ultimo->proximo;
    pLista->ultimo->info = *p;
    pLista->ultimo->proximo = NULL;
}

int LRetira(Lista *pLista, Pokemon *p)
{
    Apontador aux;
    if (LEhVazia(pLista))
        return 0;

    *p = pLista->primeiro->proximo->info;
    aux = pLista->primeiro;
    pLista->primeiro = pLista->primeiro->proximo;
    free(aux);
    return 1;
}

void LImprime(Lista *pLista)
{
    Apontador aux;

    aux = pLista->primeiro->proximo;

    while (aux != NULL)
    {
        printf("ID: %d\n", aux->info.ID);
        printf("Número na Pokédex: %d\n", aux->info.num_pokedex);
        printf("Nome: %s\n", aux->info.nome);
        printf("Tipo: %s\n", aux->info.tipo);
        printf("Localização: %d %d\n", aux->info.lugar.x, aux->info.lugar.y);
        aux = aux->proximo;
    }
}

int busca(Lista *pLista, int id)
{
    if (LEhVazia(pLista))
    {
        return 0;
    }

    Apontador aux;
    aux = pLista->primeiro->proximo;
    while (aux != NULL)
    {
        if (aux->info.ID == id)
        {   
            printf("O elemento está na lista.\n");
            return 1;
        }
        aux = aux->proximo;
    }
    printf("O elemento não está na lista.\n");
    return 0;
}

int tamanho_lista(Lista *pLista)
{
 if (LEhVazia(pLista))
    {
        return 0;
    }

    int tam = 0;
    Apontador aux;
    aux = pLista->primeiro->proximo;

    while (aux != NULL)
    {
        tam += 1;
        aux = aux->proximo;
    }

    return tam;
}   
