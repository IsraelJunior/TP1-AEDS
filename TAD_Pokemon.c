#include <stdio.h>
#include <stdlib.h>
#include "TAD_Pokemon.h"
#include <string.h>

void insere_Pdados(Pokemon *pnt, int num, char *nom, char *tip, int id, int x, int y)//Nessa função, referenciamos o ponteiro recebido e atribuimos os parâmetros as suas variáveis.
{
    pnt->ID = id;
    pnt->num_pokedex = num;
    strcpy(pnt->nome, nom);
    strcpy(pnt->tipo, tip);
    pnt->lugar.x = x;
    pnt->lugar.y = y;
}

void inicializa_pokemon(Pokemon *pnt)//Inicializo as variáveis do tipo inteiro do pokemon como nulas.
{
    pnt->ID = 0;
    pnt->lugar.x = pnt->lugar.y = 0;
    pnt->num_pokedex = 0;
}

void imprime_pokemon(Pokemon *pnt)//Uso o ponteiro para imprimir as informações de um Pokemon.
{

    printf("ID: %d\n", pnt->ID);
    printf("Número na Pokédex: %d\n", pnt->num_pokedex);
    printf("Nome: %s\n", pnt->nome);
    printf("Tipo: %s\n", pnt->tipo);
    imprime_coordenadas(&(pnt->lugar));
}

int get_id(Pokemon *pnt)//Retorna o ID do Pokemon.
{
    return (pnt->ID);
}

void set_id(Pokemon *pnt, int id)//Atribui um ID ao Pokemon.
{
    pnt->ID = id;
}

int get_num_pokedex(Pokemon *pnt)//Retorna o número da Pokédex.
{
    return (pnt->num_pokedex);
}

void set_num_pokedex(Pokemon *pnt, int num)//Atribui um valor ao número da Pokédex.
{
    pnt->num_pokedex = num;
}

void get_coordernadas(Pokemon *pnt, int *X, int *Y)//Usa um ponteiro para Pokemon e dois ponteiros para inteiro, a fim de salvar as coordenadas do Pokemon no conteúdos desses ponteiros.
{
    *X = pnt->lugar.x;
    *Y = pnt->lugar.y;
}

void set_coordernadas(Pokemon *pnt, int X, int Y)//Usa um ponteiro para Pokemon e, dois inteiros, a fim de atribuir o valor desses inteiros às coordenadas.
{
   movimenta_local(&(pnt->lugar), X, Y);
}
