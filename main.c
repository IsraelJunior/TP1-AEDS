#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TAD_Centro_de_Pesquisa.h"

void recarrega(Centro_de_Pesquisa *Centro, Treinador *p)
{
    printf("========================================\n");
    printf("    Treinador(a) %s SEM POKÉBOLAS\n", p->nome);
    printf("========================================\n");

    printf("Treinador(a) %s retorna ao Centro de Pesquisa.\n", p->nome);
    movimenta_local(&(p->lugar), 0, 0);
    printf("========================================\n");

    printf("Entregando Pokémon ao Centro de Pesquisa.\n");
    recebe_recuperados(Centro, p);

    recarrega_pokebolas(p);
    printf("Treinador(a) %s recebeu %d Pokébolas.\n", p->nome, p->quant_pokebolas);
    printf("----------------------------------------\n");
}

int missao_captura(Centro_de_Pesquisa *pnt, Treinador *p1, Treinador *p2)
{
    printf("========================================\n");
    printf("          INÍCIO DA MISSÃO\n");
    printf("========================================\n\n");
    printf("Treinador(a) %s: posição (%d,%d) | Pokébolas: %d\n", p1->nome, p1->lugar.x, p1->lugar.y, p1->quant_pokebolas);
    printf("Treinador(a) %s: posição (%d,%d) | Pokébolas: %d\n", p2->nome, p2->lugar.x, p2->lugar.y, p2->quant_pokebolas);
    printf("Pokémons fugitivos a serem resgatados: %d\n\n", tamanho_lista(&(pnt->fugitivos)));
    printf("----------------------------------------\n");

    while (tamanho_lista(&(pnt->fugitivos)) > 0)
    {

        printf("Pokémon alvo: %s\n", pnt->fugitivos.primeiro->proximo->info.nome);
        printf("Localização: (%d,%d)\n", pnt->fugitivos.primeiro->proximo->info.lugar.x, pnt->fugitivos.primeiro->proximo->info.lugar.y);

        double d1, d2;
        d1 = distancia(&(pnt->fugitivos.primeiro->proximo->info.lugar), &(p1->lugar));
        d2 = distancia(&(pnt->fugitivos.primeiro->proximo->info.lugar), &(p2->lugar));
        printf("Distância Treinador(a) %s: %.2lf\n", p1->nome, d1);
        printf("Distância Treinador(a) %s: %.2lf\n\n", p2->nome, d2);

        if (d1 < d2)
        {
            printf("Missão atribuída ao Treinador(a) %s.\n\n", p1->nome);
            captura_pokemon(p1, pnt->fugitivos.primeiro->proximo);
            if (p1->quant_pokebolas == 0) // Se o treinador está sem Pokebolas, ele retorna ao Centro de Pesquisa e recarrega o seu estoque de Pokebolas.
            {
                recarrega(pnt, p1);
            }
            remove_fugitivos(pnt);
        }
        else if (d1 > d2)
        {
            printf("Missão atribuída ao Treinador(a) %s.\n", p2->nome);
            captura_pokemon(p2, pnt->fugitivos.primeiro->proximo);
            if (p2->quant_pokebolas == 0) // Se o treinador está sem Pokebolas, ele retorna ao Centro de Pesquisa e recarrega o seu estoque de Pokebolas.
            {
                recarrega(pnt, p2);
            }
            remove_fugitivos(pnt);
        }
        else
        {
            printf("Missão atribuída ao Treinador(a) %s.\n", p1->nome);
            captura_pokemon(p1, pnt->fugitivos.primeiro->proximo);

            if (p1->quant_pokebolas == 0) // Se o treinador está sem Pokebolas, ele retorna ao Centro de Pesquisa e recarrega o seu estoque de Pokebolas.
            {
                recarrega(pnt, p1);
            }
            remove_fugitivos(pnt);
        }
    }

    if (tamanho_lista(&(pnt->fugitivos)) == 0)
    {
        printf("========================================\n");
        printf("  Todos Pokemons foram resgatados.\n");
        printf("========================================\n\n");
        movimenta(p1, 0, 0);
        movimenta(p2, 0, 0);
        printf("Ambos treinadores retornam ao Centro de Pesquisa.\n\n");
        printf("Treinador(a) %s devolve os Pokémon.\n", p1->nome);
        printf("Treinador(a) %s devolve os Pokémon.\n\n", p2->nome);
        recebe_recuperados(pnt, p1);
        recebe_recuperados(pnt, p2);
        printf("========================================\n");
        printf("         MISSÃO CONCLUÍDA\n");
        printf("========================================\n");
    }
    return 0;
}

int main()
{
    srand(time(NULL)); // A semente para a geração de um número pseudoaleatório deve ficar no main, a fim de evitar que um mesmo número seja gerado várias vezes e quebre a "aleatoriedade".
    Treinador T1, T2;
    Centro_de_Pesquisa *Centro;

    Centro = inicializa_centro(&T1, &T2);
    insere_fugitivos(Centro);
    imprime_fugitivos(Centro);
    missao_captura(Centro, &T1, &T2);
    imprime_relatorio(Centro);
    free(Centro);
    
    return 0;
}