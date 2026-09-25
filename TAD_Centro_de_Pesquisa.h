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

void remove_fugitivos(Centro_de_Pesquisa *Centro, Pokemon *p);

void imprime_fugitivos(Centro_de_Pesquisa *Centro);

void recebe_recuperados(Centro_de_Pesquisa *Centro, Treinador *pnt);

int recarrega_pokebolas(Treinador *pnt); // Quantidade aleatória entre 1 a 20;

#endif

// Inicialização do centro de pesquisa;
// Inserção dos registros de Pokémon fugitivos;
// Remoção de um pokémon da lista de fugitivos;
// Impressão dos pokémon que ainda não foram recuperados;
// Recebimento dos Pokémon recuperados pelos treinadores;
// Recarga de Pokébolas de um treinad (que deverá atribuir ao treinador uma
// quantidade aleatória de Pokébos, no intervalo de 1 a 20);