#ifndef TAD_COORDENADAS_H
#define TAD_COORDENADAS_H

typedef struct
{
    int x, y;

} coordenadas;

#endif

void inicializa_coordenadas(coordenadas *local);

float distancia(coordenadas *local1, coordenadas *local2);

void imprime_coordenadas(coordenadas *local);
