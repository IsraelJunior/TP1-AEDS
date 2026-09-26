#ifndef TREINADOR_H
#define TREINADOR_H
#include "TAD_Coordenadas.h"
#include "TAD_Pokelista.h"

typedef struct
{
    int identificador;
    char nome[50];
    int quant_pokebolas;
    coordenadas lugar;
    Lista Tlista;

} Treinador;


void inicializa_treinador(Treinador *pnt);

void insere_Tdados(Treinador *pnt, int quant, char *nom, int id);

void movimenta(Treinador *pnt, int a, int b);

void captura_pokemon(Treinador *pnt, Apontador p);

void retira_pokelista(Treinador *pnt, Pokemon *p);

void imprime(Treinador *pnt);

#endif