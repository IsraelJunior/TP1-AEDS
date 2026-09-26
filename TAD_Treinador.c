#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_Treinador.h"

void inicializa_treinador(Treinador *pnt) // Inicializa as variáveis do tipo inteiro como nulas e, inicializa a Pokelista do Treinador.
{
    pnt->identificador = 0;
    pnt->lugar.x = pnt->lugar.y = 0;
    pnt->quant_pokebolas = 0;
    inicializa_lista(&(pnt->Tlista));
}

void insere_Tdados(Treinador *pnt, int quant, char *nom, int id) // Função que recebe as informações de um treinador e as atribui aos respectivos campos do treinador passado.
{
    pnt->identificador = id;
    pnt->quant_pokebolas = quant;
    strcpy(pnt->nome, nom);
}

void movimenta(Treinador *pnt, int a, int b) // Movimenta o treinador para um determinada coordenada representada pelos valores inteiros recebidos pela função.
{
    movimenta_local(&(pnt->lugar), a, b);
}

void captura_pokemon(Treinador *pnt, Apontador p) // A função recebe um ponteiro para um treinador e uma struct Pokemon.
{
    LInsere(&(pnt->Tlista), &(p->info)); // Insere o pokemon na Pokelista do treinador.
    pnt->quant_pokebolas -= 1;           // Na captura, uma pokebola do treinador é consumida.
    if (pnt->quant_pokebolas == 0)       // Se o treinador está sem Pokebolas, ele retorna ao Centro de Pesquisa.
    {
        movimenta_local(&(pnt->lugar), 0, 0);
    }
}

void retira_pokelista(Treinador *pnt, Pokemon *p) // A função recebe um ponteiro para um treinador e um ponteiro do tipo Pokemon, a fim de salvar as informações do Pokemon retirado da Pokelista do treinador.
{
    if (LRetira(&(pnt->Tlista), p))
    {
        printf("Pokemon retirado da Pokelista do treinador.\n");
    }
}

void imprime(Treinador *pnt) // A função recebe um ponteiro para um treinador e, imprime as suas informações.
{
    printf("Identificação: %d\n", pnt->identificador);
    printf("Nome: %s\n", pnt->nome);
    printf("Quantidade de pokebolas: %d\n", pnt->quant_pokebolas);
    imprime_coordenadas(&(pnt->lugar));
}