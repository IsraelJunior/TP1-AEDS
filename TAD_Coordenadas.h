#ifndef TAD_COORDENADAS_H
#define TAD_COORDENADAS_H

typedef struct
{
    int x, y;

} coordenadas;



void inicializa_coordenadas(coordenadas *local);

void movimenta_local(coordenadas* local, int X, int Y);

double distancia(coordenadas *local1, coordenadas *local2);

void imprime_coordenadas(coordenadas *local);

#endif