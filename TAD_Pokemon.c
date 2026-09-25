#include <stdio.h>
#include <stdlib.h>
#include "TAD_Pokemon.h"
#include <string.h>

void insere_Pdados(Pokemon *pnt, int num, char *nom, char *tip, int id, int x, int y)
{
    pnt->ID = id;
    pnt->num_pokedex = num;
    strcpy(pnt->nome, nom);
    strcpy(pnt->tipo, tip);
    pnt->lugar.x = x;
    pnt->lugar.y = y;
}

void inicializa_pokemon(Pokemon *pnt)
{
    pnt->ID = 0;
    pnt->lugar.x = pnt->lugar.y = 0;
    pnt->num_pokedex = 0;
}

void imprime_pokemon(Pokemon *pnt)
{

    printf("ID: %d\n", pnt->ID);
    printf("Número na Pokédex: %d\n", pnt->num_pokedex);
    printf("Nome: %s\n", pnt->nome);
    printf("Tipo: %s\n", pnt->tipo);
    imprime_coordenadas(&(pnt->lugar));
}

int get_id(Pokemon *pnt)
{
    return (pnt->ID);
}

void set_id(Pokemon *pnt, int id)
{
    pnt->ID = id;
}

int get_num_pokedex(Pokemon *pnt)
{
    return (pnt->num_pokedex);
}

void set_num_pokedex(Pokemon *pnt, int num)
{
    pnt->num_pokedex = num;
}

void get_nome(Pokemon *pnt, char *nome)
{
    strcpy(nome, pnt->nome);
}

void set_nome(Pokemon *pnt, char *nome)
{
    strcpy(pnt->nome, nome);
}

void get_tipo(Pokemon *pnt, char *nome)
{
    strcpy(nome, pnt->tipo);
}

void set_tipo(Pokemon *pnt, char *nome)
{
    strcpy(pnt->tipo, nome);
}

void get_coordernadas(Pokemon *pnt, int *X, int *Y)
{
    *X = pnt->lugar.x;
    *Y = pnt->lugar.y;
}

void set_coordernadas(Pokemon *pnt, int X, int Y)
{
    pnt->lugar.x = X;
    pnt->lugar.y = Y;
}
