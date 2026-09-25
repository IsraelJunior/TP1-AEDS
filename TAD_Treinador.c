#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_Treinador.h"

void inicializa_treinador(Treinador *pnt)
{
    pnt->identificador = 0;
    pnt->lugar.x = pnt->lugar.y = 0;
    pnt->quant_pokebolas = 0;
    inicializa_lista(&(pnt->Tlista));
}

void insere_Tdados(Treinador *pnt, int quant, char *nom, int id)
{
    pnt->identificador = id;
    pnt->quant_pokebolas = quant;
    strcpy(pnt->nome, nom);
}

void movimenta(Treinador *pnt, coordenadas *local)
{
    pnt->lugar.x = local->x;
    pnt->lugar.y = local->y;
}

void captura_pokemon(Treinador *pnt, Apontador p)
{
    LInsere(&(pnt->Tlista), &(p->info));
    pnt->quant_pokebolas -= 1;
}

void retira_pokelista(Treinador *pnt, Pokemon *p)
{
    int x = LRetira(&(pnt->Tlista), p);
}

void imprime(Treinador *pnt)
{
    printf("Identificação: %d\n", pnt->identificador);
    printf("Nome: %s\n", pnt->nome);
    printf("Quantidade de pokebolas: %d\n", pnt->quant_pokebolas);
    imprime_coordenadas(&(pnt->lugar));
}