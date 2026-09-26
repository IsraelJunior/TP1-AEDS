#ifndef TAD_CENTRO_DE_PESQUISA
#define TAD_CENTRO_DE_PESQUISA
#include "TAD_Pokelista.h"
#include "TAD_Treinador.h"
#include "TAD_Coordenadas.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Centro_de_Pesquisa
{

    Lista fugitivos;
    Lista recuperados;
    coordenadas lugar;

} Centro_de_Pesquisa;

Centro_de_Pesquisa *inicializa_centro(Treinador *t1, Treinador *t2);

void insere_fugitivos(Centro_de_Pesquisa *Centro);

void remove_fugitivos(Centro_de_Pesquisa *Centro);

void imprime_fugitivos(Centro_de_Pesquisa *Centro);

void recebe_recuperados(Centro_de_Pesquisa *Centro, Treinador *pnt);

void recarrega_pokebolas(Treinador *pnt);

void imprime_relatorio(Centro_de_Pesquisa *Centro);

#endif
