#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TAD_Centro_de_Pesquisa.h"

int main()
{
    srand(time(NULL)); // A semente para a geração de um número pseudoaleatório deve ficar no main, a fim de evitar que um mesmo número seja gerado várias vezes e quebre a "aleatoriedade".
    Treinador T1, T2;
    inicializa_centro(&T1, &T2);

    return 0;
}