#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TAD_Centro_de_Pesquisa.h"

void recarrega(Centro_de_Pesquisa *Centro, Treinador *p) // A função recebe dois ponteiros, um para um Centro de Pesquisa e outro para um Treinador. Essa função é usada quando o treinador está sem pokebolas e precisa retornar ao Centro de pesquisa.
{
    printf("========================================\n");
    printf("    Treinador(a) %s SEM POKÉBOLAS\n", p->nome);
    printf("========================================\n\n");

    printf("Treinador(a) %s retorna ao Centro de Pesquisa.\n\n", p->nome);
    movimenta_local(&(p->lugar), 0, 0); // O treinador retorna ao Centro de Pesquisa.
    printf("Entregando Pokémon ao Centro de Pesquisa.\n\n");
    recebe_recuperados(Centro, p); // Os pokemons capturados pelo treinador são postos na lista dos pokemons recuperados do Cento de Pesquisa.
    recarrega_pokebolas(p);        // O treinador tem o seu estoque de pokebolas recarregados com uma quatidade aleatória.
    printf("Treinador(a) %s recebeu %d Pokébolas.\n", p->nome, p->quant_pokebolas);
}

int missao_captura(Centro_de_Pesquisa *pnt, Treinador *p1, Treinador *p2) // A função recebe três ponteiros, um para um Centro de Pesquisa e dois para os treinadores.
{
    printf("========================================\n");
    printf("            INÍCIO DA MISSÃO\n");
    printf("========================================\n\n");
    printf("Treinador(a) %s: posição (%d,%d) | Pokébolas: %d\n", p1->nome, p1->lugar.x, p1->lugar.y, p1->quant_pokebolas);
    printf("Treinador(a) %s: posição (%d,%d) | Pokébolas: %d\n\n", p2->nome, p2->lugar.x, p2->lugar.y, p2->quant_pokebolas);
    printf("Pokémons fugitivos a serem resgatados: %d\n\n", tamanho_lista(&(pnt->fugitivos)));

    while (tamanho_lista(&(pnt->fugitivos)) > 0) // Roda enquanto ainda existem pokemons fugitivos.
    {
        printf("----------------------------------------\n");
        printf("Pokémon alvo: %s\n", pnt->fugitivos.primeiro->proximo->info.nome);
        printf("Localização: (%d,%d)\n\n", pnt->fugitivos.primeiro->proximo->info.lugar.x, pnt->fugitivos.primeiro->proximo->info.lugar.y);

        double d1, d2; // Variáveis que armazenam a distância entre o treinador(1 ou 2) e o pokemon alvo.
        d1 = distancia(&(pnt->fugitivos.primeiro->proximo->info.lugar), &(p1->lugar));
        d2 = distancia(&(pnt->fugitivos.primeiro->proximo->info.lugar), &(p2->lugar));
        printf("Distância Treinador(a) %s: %.2lf\n", p1->nome, d1);
        printf("Distância Treinador(a) %s: %.2lf\n\n", p2->nome, d2);

        if (d1 < d2) // Se o treinador 1 está mais próximo do pokemon alvo em comparação com o treinador 2.
        {
            printf("Missão atribuída ao Treinador(a) %s.\n\n", p1->nome);
            captura_pokemon(p1, pnt->fugitivos.primeiro->proximo); // O treinador captura o pokemon alvo.

            if (p1->quant_pokebolas == 0) // Se o treinador está sem Pokebolas, ele retorna ao Centro de Pesquisa e recarrega o seu estoque de Pokebolas.
            {
                recarrega(pnt, p1);
            }
            remove_fugitivos(pnt); // Atualiza a lista dos fugitivos.
        }
        else if (d1 > d2) // Se o treinador 2 está mais próximo do pokemon alvo em comparação com o treinador 1.
        {
            printf("Missão atribuída ao Treinador(a) %s.\n\n", p2->nome);
            captura_pokemon(p2, pnt->fugitivos.primeiro->proximo); // O treinador captura o pokemon alvo.

            if (p2->quant_pokebolas == 0) // Se o treinador está sem Pokebolas, ele retorna ao Centro de Pesquisa e recarrega o seu estoque de Pokebolas.
            {
                recarrega(pnt, p2);
            }
            remove_fugitivos(pnt); // Atualiza a lista dos fugitivos.
        }
        else // Se ambos os treinadores estiverem à mesma distância do Pokémon alvo, a missão será atribuída ao treinador com o menor identificador, que vem primeiro.
        {
            printf("Missão atribuída ao Treinador(a) %s.\n\n", p1->nome);
            captura_pokemon(p1, pnt->fugitivos.primeiro->proximo); // O treinador captura o Pokemon alvo.

            if (p1->quant_pokebolas == 0) // Se o treinador está sem Pokebolas, ele retorna ao Centro de Pesquisa e recarrega o seu estoque de Pokebolas.
            {
                recarrega(pnt, p1);
            }
            remove_fugitivos(pnt); // Atualiza a lista dos fugitivos.
        }
    }

    if (tamanho_lista(&(pnt->fugitivos)) == 0) // Se não há mais Pokémons fugitivos.
    {
        printf("========================================\n");
        printf("    Todos Pokemons foram resgatados.\n");
        printf("========================================\n\n");
        movimenta(p1, 0, 0); // Ambos os treinadores retornam ao Centro de Pesquisa.
        movimenta(p2, 0, 0);
        printf("Ambos treinadores retornam ao Centro de Pesquisa.\n\n");
        printf("Treinador(a) %s devolve os Pokémon.\n", p1->nome);
        printf("Treinador(a) %s devolve os Pokémon.\n\n", p2->nome);
        recebe_recuperados(pnt, p1); // Ambos os treinadores colocam os Pokémons capturados na lista dos recuperados do Centro de Pesquisa.
        recebe_recuperados(pnt, p2);
        printf("========================================\n");
        printf("           MISSÃO CONCLUÍDA\n");
        printf("========================================\n");
    }
    return 0;
}

int main()
{
    srand(time(NULL));          // A semente para a geração de um número pseudoaleatório deve ficar no main, a fim de evitar que um mesmo número seja gerado várias vezes e quebre a "aleatoriedade".
    Treinador T1, T2;           // Variáveis do tipo Treinador que serão devidamente inicializadas na função "inicializa_centro()".
    Centro_de_Pesquisa *Centro; // Cria um ponteiro para um Centro de Pesquisa.

    Centro = inicializa_centro(&T1, &T2); // Cria um Centro de Pesquisa e inicializa as informações dos treinadores passados.
    insere_fugitivos(Centro);             // Insere os Pokémons que fugiram na lista dos fugitivos.
    missao_captura(Centro, &T1, &T2);     // Começa a missão de captura dos Pokémons.
    imprime_relatorio(Centro);            // Imprime em um arquivo.txt os Pokémons recuperados.
    free(Centro);                         // Libera o espaço de memória usado para armazenar o Centro de pesquisa.

    return 0;
}