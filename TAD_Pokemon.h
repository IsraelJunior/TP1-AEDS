#ifndef TAD_POKEMON_H
#define TAD_POKEMON_H
#include "TAD_Coordenadas.h"

typedef struct
{
    int ID;
    int num_pokedex;
    char nome[50];
    char tipo[50];
    coordenadas lugar;

} Pokemon; // TAD_Pokemon

void insere_Pdados(Pokemon *pnt, int num, char *nom, char *tip, int id, int x, int y);

void inicializa_pokemon(Pokemon *pnt);

void imprime_pokemon(Pokemon *pnt);

int get_id(Pokemon *pnt);

void set_id(Pokemon *pnt, int id);

int get_num_pokedex(Pokemon *pnt);

void set_num_pokedex(Pokemon *pnt, int num);

void get_nome(Pokemon *pnt, char *nome);

void set_nome(Pokemon *pnt, char *nome);

void get_tipo(Pokemon *pnt, char *nome);

void set_tipo(Pokemon *pnt, char *nome);

void get_coordernadas(Pokemon *pnt, int *X, int *Y);

void set_coordernadas(Pokemon *pnt, int X, int Y);

#endif
