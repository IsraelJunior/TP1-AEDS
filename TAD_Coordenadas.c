#include <stdio.h>
#include "TAD_Coordenadas.h"
#include <math.h>

void inicializa_coordenadas(coordenadas *local) // A função recebe um ponteiro para uma struct coordenadas e, inicializa as coordenadas como nulas.
{
    local->x = local->y = 0;
}

void movimenta_local(coordenadas *local, int X, int Y) // A função recebe um ponteiro para uma struct coordenadas e dois inteiros, que representam as novas coordenadas do elemento.
{
    local->x = X; // Atualiza as coordenadas.
    local->y = Y;
}

double distancia(coordenadas *local1, coordenadas *local2) // A função recebe dois ponteiros para duas structs coordenadas, a fim de calcular a distância estre esses pontos.
{
    double d = sqrt(pow((local1->x - local2->x), 2) + pow((local1->y - local2->y), 2)); // Fórmula da distância euclidiana na linguagem C.
    return d;
}

void imprime_coordenadas(coordenadas *local) // A função recebe um ponteiro para uma struct coordenadas e, imprime a localização armazenada.
{
    printf("Localização: %d %d\n", local->x, local->y);
}
