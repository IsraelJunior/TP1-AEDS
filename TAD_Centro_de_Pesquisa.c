#include <stdio.h>
#include <stdlib.h>
#include "TAD_Centro_de_Pesquisa.h"
#include <string.h>

Centro_de_Pesquisa *inicializa_centro(Treinador *t1, Treinador *t2)
{
    Centro_de_Pesquisa *centro = (Centro_de_Pesquisa *)malloc(sizeof(Centro_de_Pesquisa));

    if (centro != NULL) // Verifica se a alocação funcionou.
    {

        inicializa_lista(&(centro->fugitivos));
        inicializa_lista(&(centro->recuperados));
        inicializa_coordenadas(&(centro->lugar));
        inicializa_treinador(t1);
        inicializa_treinador(t2);

        FILE *arquivo;
        arquivo = fopen("teste1.txt", "r");

        if (arquivo != NULL)
        {

            char palavra[50];
            int quantidade = 0;

            fscanf(arquivo, "%49s %d", palavra, &quantidade);
            insere_Tdados(t1, quantidade, palavra, 1);
            
            printf("%s %d\n", palavra, quantidade);

            fscanf(arquivo, "%49s %d", palavra, &quantidade);
            insere_Tdados(t2, quantidade, palavra, 2);

            printf("%s %d\n", palavra, quantidade);

            fclose(arquivo);

            return centro; // Retorna o endereço da memória onde as informações do centro estão armazenadas.
        }

        else // Caso a leitura do arquivo falhe.
        {
            return NULL; // O endereço de memória, que deveria armazenar as informações do centro, é retornado como nulo.
        }
    }

    else // Caso a alocação falhe.
    {
        return NULL; // O endereço de memória, que deveria armazenar as informações do centro, é retornado como nulo.
    }
}

void insere_fugitivos(Centro_de_Pesquisa *Centro)
{

    FILE *arquivo;
    arquivo = fopen("teste.txt", "r");

    if (arquivo != NULL)
    {

        char palavra[50];
        int quantidade = 0;

        int cont = 0;
        int ident = 1;
        int numero_pokedex = 0;
        char nome_p[50];
        char tipo_p[50];
        int x, y = 0;

        fscanf(arquivo, "%49s %d", palavra, &quantidade);
        fscanf(arquivo, "%49s %d", palavra, &quantidade);
        fscanf(arquivo, "%d", &cont);

        while (cont > 0)
        {
            if ((fscanf(arquivo, " %d %49s %49s %d %d", &numero_pokedex, nome_p, tipo_p, &x, &y)) == 5)
            {

                Pokemon novo_pokemon;
                inicializa_pokemon(&novo_pokemon);
                insere_Pdados(&novo_pokemon, numero_pokedex, nome_p, tipo_p, ident, x, y);
                LInsere(&Centro->fugitivos, &novo_pokemon);
                cont -= 1;
                ident += 1;
            }
        }

        fclose(arquivo);
    }
}

void remove_fugitivos(Centro_de_Pesquisa *Centro, Pokemon *p)
{
    LRetira(&(Centro->fugitivos), p);
}

void imprime_fugitivos(Centro_de_Pesquisa *Centro)
{
    LImprime(&(Centro->fugitivos));
}

void recebe_recuperados(Centro_de_Pesquisa *Centro, Treinador *pnt)
{
    int x = tamanho_lista(&(pnt->Tlista));
    while (x > 0)
    {

        Pokemon aux;
        LRetira(&(pnt->Tlista), &aux);
        LInsere(&(Centro->recuperados), &aux);
        x -= 1;
    }
}

int recarrega_pokebolas(Treinador *pnt)
{

} // Quantidade aleatória entre 1 a 20;