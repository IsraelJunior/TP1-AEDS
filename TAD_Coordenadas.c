#include <stdio.h>
#include "TAD_Coordenadas.h"
#include <math.h>

void inicializa_coordenadas(coordenadas *local)
{
    local->x = local->y = 0;
}

float distancia(coordenadas *local1, coordenadas *local2)
{
    float d = sqrt(pow((local1->x - local2->x), 2) + pow((local1->y - local2->y), 2));
    return d;
}

void imprime_coordenadas(coordenadas *local)
{
    printf("Localização: %d %d\n", local->x, local->y);
}
