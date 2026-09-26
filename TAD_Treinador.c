#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_Treinador.h"
#include "TAD_Centro_de_Pesquisa.h"

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
    if (pnt->lugar.x != a && pnt->lugar.y != b) // Se o treinador já não estiver no lugar, ele se desloca para lá.
    {
        movimenta_local(&(pnt->lugar), a, b);
    }
}

void captura_pokemon(Treinador *pnt, Apontador p) // A função recebe um ponteiro para um treinador e uma struct Pokemon.
{
    movimenta_local(&(pnt->lugar), p->info.lugar.x, p->info.lugar.y);
    printf("Treinador(a) %s se movimentou para (%d, %d).\n", pnt->nome, pnt->lugar.x, pnt->lugar.y);

    LInsere(&(pnt->Tlista), &(p->info)); // Insere o pokemon na Pokelista do treinador.
    pnt->quant_pokebolas -= 1;           // Na captura, uma pokebola do treinador é consumida.
    printf("%s capturado com sucesso !\n\n", p->info.nome);
    printf("Pokébolas restantes para o Treinador(a) %s : %d\n\n", pnt->nome, pnt->quant_pokebolas);
    
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